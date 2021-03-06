// This file contains the improved implementations of the NN's layers with directives.

#include "dimensions.h"
#include "lenet.h"
#include "weights.h"

/***************************************************************************
The functions below model a Neural Network Layer consisting of Dense Neurons
***************************************************************************/
void dense_layer1(DL1_inp_t input[OUTPUT5_LENGTH], DL1_out_t output[DENSE1_NEURONS]) {
#pragma HLS INLINE off
    
    //Simulating each neuron
	dense_layer1_outer_loop:
	for (int p = 0 ; p<DENSE1_NEURONS; p++) {
        DL1_out_t inner_state = dense_1_biases[p];
        dense_layer1_inner_loop:
		for(int i=0;i<DENSE1_WEIGHTS_PER_NEURON;i++) {
            inner_state += (DL1_out_t) (input[i] * dense_1_weights[p][i]); //Calculating inner state
        }
        output[p] = (inner_state > ((DL1_out_t) 0))?(DL1_out_t)inner_state:((DL1_out_t) 0); //Applying RELU
    }
}

void dense_layer2(DL2_inp_t input[OUTPUT6_LENGTH], DL2_out_t output[DENSE2_NEURONS]) {
#pragma HLS INLINE off
    
    //Simulating each neuron
	dense_layer2_outer_loop:
	for (int p = 0 ; p<DENSE2_NEURONS; p++) {
        DL2_out_t inner_state = dense_2_biases[p];
        dense_layer2_inner_loop:
        for(int i=0;i<DENSE2_WEIGHTS_PER_NEURON;i++) {
            inner_state += (DL2_out_t) (input[i] * dense_2_weights[p][i]); //Calculating inner state
        }
        output[p] = (inner_state > ((DL2_out_t) 0))?(DL2_out_t)inner_state:((DL2_out_t) 0); //Applying RELU
    }
}

void dense_layer3(DL3_inp_t input[OUTPUT7_LENGTH], DL3_out_t output[DENSE3_NEURONS]) {
#pragma HLS INLINE off

	DL3_out_t temp[DENSE3_NEURONS] = {0}, sum = 0, read_value = 0;
    
    //Simulating each neuron
	dense_layer3_outer_loop:
	for (int p = 0 ; p<DENSE3_NEURONS; p++) {    
        DL3_out_t inner_state = dense_3_biases[p];
        dense_layer3_inner_loop:
        for(int i=0;i<DENSE3_WEIGHTS_PER_NEURON;i++) {
            inner_state += (DL3_out_t) (input[i] * dense_3_weights[p][i]); //Calculating inner state
        }
        //output[p] = (inner_state > ((DL3_out_t) 0))?(DL3_out_t)inner_state:((DL3_out_t) 0); //Applying RELU
        if(inner_state < 0) inner_state = 0;
		//Softmax accumulation
		read_value = 1+inner_state; //first order Taylor of exp
		//read_value = 1+read_value+read_value*read_value/2; //second order Taylor of exp
		//read_value = hls::exp(output[p]);
		sum += read_value;
		temp[p] = read_value;
    }
	//Softmax output for each neuron
	dense_layer3_softmax_loop:
	for (int j = 0; j < DENSE3_NEURONS; j++) {
		output[j] = temp[j] / sum;
	}

}


/****************************************************************************************** 
The functions below model a Neural Network Layer consisting of Convolutional Neurons
******************************************************************************************/
void conv_layer1(CL1_inp_t input[INPUT_DIMENSION][INPUT_DIMENSION], CL1_out_t output[CONV1_NEURONS][OUTPUT1_DIM][OUTPUT1_DIM]) {
#pragma HLS INLINE off

	int IS_VALID = 1;
	int H = INPUT_DIMENSION - IS_VALID;
	int W = INPUT_DIMENSION - IS_VALID;

    //Simulating each neuron
	conv_layer1_neurons_loop:
	for (int p = 0; p < CONV1_NEURONS; p ++) { 
                
        //Applying the filters
        conv_layer1_kernel_0_loop:
        for ( int ker = 0; ker < CONV1_FM_INPUTS; ker++ ) {
        	conv_layer1_kernel_1_loop:
			for ( int row = IS_VALID; row < H; row++ ) {
				conv_layer1_kernel_2_loop:
				for ( int col = IS_VALID; col < W; col++ ) {
                    CL1_out_t accumulation = 0;
                    conv_layer1_kernel_3_loop:
					for ( int i = -1; i <= 1; i++ ) {
						conv_layer1_kernel_4_loop:
						for ( int j = -1; j <= 1; j++ ) {
                            accumulation += (CL1_out_t) (input/*[ker]*/[row+i][col+j] * conv_1_weights[p][ker][i+1][j+1]);
                        }
                    }
					if (ker==0) {
						output[p][row-IS_VALID][col-IS_VALID] = (CL1_out_t) conv_1_biases[p] + accumulation;
					} else {
						output[p][row-IS_VALID][col-IS_VALID] += accumulation;
					}
                }
            }
        }	

        //Applying RELU
        conv_layer1_relu_outer_loop:
		for (int row=0; row<OUTPUT1_DIM; row++) {
			conv_layer1_relu_inner_loop:
            for (int col=0; col<OUTPUT1_DIM; col++) {
                output[p][row][col] = (output[p][row][col]>((CL1_out_t) 0)) ? output[p][row][col] : ((CL1_out_t) 0);
            }
        }
    }
}

void conv_layer2(CL2_inp_t input[CONV1_NEURONS][OUTPUT2_DIM][OUTPUT2_DIM], CL2_out_t output[CONV2_NEURONS][OUTPUT3_DIM][OUTPUT3_DIM]) {
#pragma HLS INLINE off

	int IS_VALID = 1;
	int H = OUTPUT2_DIM - IS_VALID;
	int W = OUTPUT2_DIM - IS_VALID;

    //Simulating each neuron
	conv_layer2_neurons_loop:
	for (int p = 0; p < CONV2_NEURONS; p ++) {
                
        //Applying the filters
		conv_layer2_kernel_0_loop:
		for ( int ker = 0; ker < CONV2_FM_INPUTS; ker++ ) {
			conv_layer2_kernel_1_loop:
            for ( int row = IS_VALID; row < H; row++ ) {
            	conv_layer2_kernel_2_loop:
				for ( int col = IS_VALID; col < W; col++ ) {
                    CL2_out_t accumulation = 0;
                    conv_layer2_kernel_3_loop:
                    for ( int i = -1; i <= 1; i++ ) {
                    	conv_layer2_kernel_4_loop:
						for ( int j = -1; j <= 1; j++ ) {
                            accumulation += (CL2_out_t) (input[ker][row+i][col+j] * conv_2_weights[p][ker][i+1][j+1]);
                        }
                    }
					if (ker==0) {
						output[p][row-IS_VALID][col-IS_VALID] = (CL2_out_t) conv_2_biases[p] + accumulation;
					} else {
						output[p][row-IS_VALID][col-IS_VALID] += accumulation;
					}
                }
            }
        }	

        //Applying RELU
        conv_layer2_relu_outer_loop:
		for (int row=0; row<OUTPUT3_DIM; row++) {
        	conv_layer2_relu_inner_loop:
            for (int col=0; col<OUTPUT3_DIM; col++) {
                output[p][row][col] = (output[p][row][col]>((CL2_out_t) 0)) ? output[p][row][col] : ((CL2_out_t) 0);
            }
        }
    }
}


/****************************************************************************
The functions below model a Neural Network Layer applying Average Pooling to an input
****************************************************************************/
void avg_pooling_layer1(PL1_inp_t input[CONV1_NEURONS][OUTPUT1_DIM][OUTPUT1_DIM], PL1_out_t output[CONV1_NEURONS][OUTPUT2_DIM][OUTPUT2_DIM]) {
#pragma HLS INLINE off

	int OUTPUT_DIM = OUTPUT1_DIM >> 1;
    int bound = STRIDE >> 1;
    int divisor = STRIDE * STRIDE;
    avg_pooling_layer1_0_loop:
    for(int fmap = 0; fmap < CONV1_NEURONS; fmap++){
    	avg_pooling_layer1_1_loop:
        for(int height = 0; height < OUTPUT1_DIM-bound; height += STRIDE){
        	avg_pooling_layer1_2_loop:
            for(int width = 0; width < OUTPUT1_DIM-bound; width += STRIDE){
                output[fmap][(height>>1)][(width>>1)] = (PL1_out_t) (
                		input[fmap][height][width] + input[fmap][height][width+1] + input[fmap][height+1][width] + input[fmap][height+1][width+1]) / divisor;
            }
        }
    }
}


void avg_pooling_layer2(PL2_inp_t input[CONV2_NEURONS][OUTPUT3_DIM][OUTPUT3_DIM], PL2_out_t output[CONV2_NEURONS][OUTPUT4_DIM][OUTPUT4_DIM]) {
#pragma HLS INLINE off

	int OUTPUT_DIM = OUTPUT3_DIM >> 1;
    int bound = STRIDE >> 1;
    int divisor = STRIDE * STRIDE;
    avg_pooling_layer2_0_loop:
    for(int fmap = 0; fmap < CONV2_NEURONS; fmap++){
    	avg_pooling_layer2_1_loop:
        for(int height = 0; height < OUTPUT3_DIM-bound; height += STRIDE){
        	avg_pooling_layer2_2_loop:
            for(int width = 0; width < OUTPUT3_DIM-bound; width += STRIDE){
                output[fmap][(height>>1)][(width>>1)] = (PL2_out_t) (
                		input[fmap][height][width] + input[fmap][height][width+1] + input[fmap][height+1][width] + input[fmap][height+1][width+1]
                        ) / divisor;
            }
        }
    }
}


/************************************************************
The function below models a Neural Network Layer Flattenning an input
************************************************************/
void flattening_layer(FL1_inp_t input[CONV2_NEURONS][OUTPUT4_DIM][OUTPUT4_DIM], FL1_out_t output[OUTPUT5_LENGTH]) {
#pragma HLS INLINE off
	
	flattening_layer_0_loop:
	for (int y=0; y<OUTPUT4_DIM; y++) {
		flattening_layer_1_loop:
        for (int x=0; x<OUTPUT4_DIM;  x++) {
        	flattening_layer_2_loop:
            for (int i=0; i<CONV2_NEURONS; i++) {
                output[y*OUTPUT4_DIM*CONV2_NEURONS+x*CONV2_NEURONS+i] = (FL1_out_t) input[i][y][x];
            }
        }
	}
}


