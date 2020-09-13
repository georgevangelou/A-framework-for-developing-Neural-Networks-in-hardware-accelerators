#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "lenet.h"
#include "dimensions.h"

//#define TOP 3 //COMMENT THIS FOR TOP-1 ACCURACY

#define ERROR_THRESHOLD 0.1
#define MAX_ERROR_COUNT 5
#define MIN_ACCURACY 90

#define TEST_INPUTS_NUMBER 100
//#define CURRENT_PATH "C:\\Users\\George\\Documents\\Workspaces\\Diploma_Local\\3.LeNet_ER_source_code\\"
//#define TEST_INPUT_FILE CURRENT_PATH "input.dat"
//#define TEST_OUTPUT_GOLDEN_FILE CURRENT_PATH "output_golden.dat"
//#define TEST_LABEL_GOLDEN_FILE CURRENT_PATH "labels_golden.dat"
//#define TEST_OUTPUT_SYNTHESIZED_FILE CURRENT_PATH "output_synthesized.dat"

#define TEST_INPUT_FILE "input.dat"
#define TEST_OUTPUT_GOLDEN_FILE "output_golden.dat"
#define TEST_LABEL_GOLDEN_FILE "labels_golden.dat"
#define TEST_OUTPUT_SYNTHESIZED_FILE "output_synthesized.dat"

using namespace std;

CL1_inp_t test_input[TEST_INPUTS_NUMBER][INPUT_DIMENSION][INPUT_DIMENSION] = {0};
DL3_out_t test_output_golden[TEST_INPUTS_NUMBER][OUTPUT8_LENGTH] = {0};
DL3_out_t test_output_synthesized[TEST_INPUTS_NUMBER][OUTPUT8_LENGTH] = {0};

int test_labels_golden[TEST_INPUTS_NUMBER] = {0};
#ifndef TOP
int test_labels_synthesized[TEST_INPUTS_NUMBER] = {0};
#else
int top_labels_synthesized[TEST_INPUTS_NUMBER][TOP] = {0};
#endif

int main() {

	std::ifstream input_file(TEST_INPUT_FILE);
	std::ifstream golden_output_file(TEST_OUTPUT_GOLDEN_FILE);
	std::ifstream golden_labels_file(TEST_LABEL_GOLDEN_FILE);
	//std::ofstream synthesized_output_file(TEST_OUTPUT_SYNTHESIZED_FILE);

	printf("Now testing...\n");

	printf("Reading the inputs file...\n");
	for (int i=0; i<TEST_INPUTS_NUMBER*INPUT_DIMENSION*INPUT_DIMENSION; i++) {
		int image = 0, x = 0, y = 0, value = 0;
		input_file >> image >> x >> y >> value;
		//printf("INPUT: %d %d %d %d\n", image, x, y, value);
		test_input[image][x][y] = (CL1_inp_t) value;
	}


	printf("Reading the golden outputs file...\n");
	for (int i=0; i<TEST_INPUTS_NUMBER; i++) {
		for (int w=0; w<OUTPUT8_LENGTH; w++) {
			int image = 0, x = 0;
			DL3_out_t value = 0;
			golden_output_file >> image >> x >> value;
			test_output_golden[i][w] = value;
			//printf("> GOLDEN OUTPUT: %d %d %f\n", i,x, value);
		}
	}

	printf("Reading the golden labels file...\n");
	for (int i=0; i<TEST_INPUTS_NUMBER; i++) {
		int image = 0, value = 0;
		golden_labels_file >> image >> value;
		test_labels_golden[i] = value;
		//printf("> GOLDEN LABEL: %d %d\n", i, value);
	}

	printf("Running the design and gathering its output...\n");
	#ifndef TOP
	
	for (int i=0; i<TEST_INPUTS_NUMBER; i++) {
		ActivateNetwork(test_input[i], test_output_synthesized[i]);
		DL3_out_t max_temp = 0.0;
		for (int w=0; w<OUTPUT8_LENGTH; w++) {
			if (test_output_synthesized[i][w] > max_temp) {
				max_temp = test_output_synthesized[i][w];
				test_labels_synthesized[i] = w;
			}
			//synthesized_output_file << i <<" " << w << " " << test_output_synthesized[i][w] << "\n";
			//printf("> SYNTHESIZED OUTPUT: %d %d %f\n", i, w, test_output_synthesized[i][w]);
		}
		//printf("> SYNTHESIZED LABEL: %d %d\n", i, test_labels_synthesized[i]);
	} 
	
	/*
	int error_count = 0;
	for (int i=0; i<TEST_INPUTS_NUMBER; i++) {
		for (int w=0; w<OUTPUT8_LENGTH; w++) {
			float a = (float) test_output_golden[i][w];
			float b = (float) test_output_synthesized[i][w];
			float error = (a-b>0)?(a-b):(b-a);
			if (error > ERROR_THRESHOLD) {
				error_count++;
			}
		}
	}
	int results = TEST_INPUTS_NUMBER*OUTPUT8_LENGTH;
	int correct_results = results - error_count;
	printf("\n###### RESULTS ######\n");
	printf("TESTS IMAGES USED: %d\n",TEST_INPUTS_NUMBER);
	printf("> TOTAL RESULTS: %d   CORRECT RESULTS: %d\n", results, correct_results);
	printf("> ACCURACY: %.2f%%\n",100*(correct_results/((float)results)));
	if (error_count>MAX_ERROR_COUNT) {
		printf("TEST FAILED !!!\n");
		printf("# DEVIATIONS: %d", error_count);
		return 1;
	} else {
		printf("TEST PASSED !!!\n");
	}*/


	int error_count = 0;
	for (int i=0; i<TEST_INPUTS_NUMBER; i++) {
		error_count += (test_labels_golden[i]==test_labels_synthesized[i])?0:1;
	}

	#else

	DL3_out_t maxes[TOP];
	for(int i=0;i<TEST_INPUTS_NUMBER;i++){
		ActivateNetwork(test_input[i], test_output_synthesized[i]);
		//maxes init
		for(int j=0;j<TOP;j++){
			maxes[j] = 0.0;
		}
		for(int w=0;w<OUTPUT8_LENGTH;w++){
			for(int j=0;j<TOP;j++){

				/*if it enters on j=0, the value is bigger than biggest max.
				if it enters on j=1, the value is between the two biggerst maxes.
				etc.
				*/

				if(test_output_synthesized[i][w] > maxes[j]){
					//shift the previous maxes & labels accordingly
					for(int k=j+1;k<TOP;k++){
						maxes[k] = maxes[k-1];
						top_labels_synthesized[i][k] = top_labels_synthesized[i][k-1];

					}
					//and alter first max & label found
					maxes[j] = test_output_synthesized[i][w];
					top_labels_synthesized[i][j] = w;
					break;
				}
			}
		}

	}

	int error_count = 0;
	for(int i=0;i<TEST_INPUTS_NUMBER;i++){
		int best_found_flag = 0;
		for(int j=0;j<TOP;j++){
			if(test_labels_golden[i]==top_labels_synthesized[i][j]){
				best_found_flag = 1;
				break;
			}
		}
		if(best_found_flag == 0) error_count++;
	}

	#endif

	int results = TEST_INPUTS_NUMBER;
	int correct_results = results - error_count;
	float accuracy = 100*(correct_results/((float)results));
	printf("\n###### RESULTS ######\n");
	printf("TESTS IMAGES USED: %d\n",TEST_INPUTS_NUMBER);
	printf("> TOTAL RESULTS: %d   CORRECT RESULTS: %d\n", results, correct_results);
	#ifndef TOP
	printf("> ACCURACY: %.2f%%\n", accuracy);
	#else
	printf("> TOP %d ACCURACY: %.2f%%\n", TOP, accuracy);
	#endif
	if (accuracy<MIN_ACCURACY) {
		printf("TEST FAILED !!!\n");
		printf("# DEVIATIONS: %d", error_count);
		return 1;
	} else {
		printf("TEST PASSED !!!\n");
	}

	input_file.close();
	golden_output_file.close();
	golden_labels_file.close();
	//synthesized_output_file.close();

	return 0;

}
