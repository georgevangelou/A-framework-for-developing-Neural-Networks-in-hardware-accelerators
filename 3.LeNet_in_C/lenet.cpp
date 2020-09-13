#include "weights.h"
#include "dimensions.h"
#include "layers.h"
#include "lenet.h"

/* LeNet 5 Architecture:
	Layer 1: CONV2D_1, RELU
	Layer 2: AVG_POOLING_1 (2X2)
	Layer 3: CONV2D_2, RELU	
	Layer 4: AVG_POOLING_2 (2X2)
	Layer 5: FLATTEN
	Layer 6: DENSE_1, RELU
	Layer 7: DENSE_2, RELU
	Layer 8: DENSE_3, SOFTMAX
*/


/**
 * The top-level function of our LeNet-5 implementation in C/C++
 */
void ActivateNetwork(
		CL1_inp_t input_image[INPUT_DIMENSION][INPUT_DIMENSION], // Input image (feature map)
		DL3_out_t output8[OUTPUT8_LENGTH]) // Output probabilities
{
	// Intermediate parameters
	CL1_out_t output1[CONV1_NEURONS][OUTPUT1_DIM][OUTPUT1_DIM];
	PL1_out_t output2[CONV1_NEURONS][OUTPUT2_DIM][OUTPUT2_DIM];
	CL2_out_t output3[CONV2_NEURONS][OUTPUT3_DIM][OUTPUT3_DIM];
	PL2_out_t output4[CONV2_NEURONS][OUTPUT4_DIM][OUTPUT4_DIM];
	FL1_out_t output5[OUTPUT5_LENGTH];
	DL1_out_t output6[OUTPUT6_LENGTH];
	DL2_out_t output7[OUTPUT7_LENGTH];

	// Activation of each consecutive layer of the network
	conv_layer1(input_image, output1); // Activation of Convolutional Layer 1
	avg_pooling_layer1(output1, output2); // Activation of Average Pooling Layer 1
	conv_layer2(output2, output3); // Activation of Convolutional Layer 2
	avg_pooling_layer2(output3, output4); // Activation of Average Pooling Layer 1
	flattening_layer(output4, output5); // Activation of Flattening Layer
	dense_layer1(output5, output6); // Activation of Fully Connected Layer 1
	dense_layer2(output6, output7); // Activation of Fully Connected Layer 2
	dense_layer3(output7, output8); // Activation of Fully Connected Layer 3
}
