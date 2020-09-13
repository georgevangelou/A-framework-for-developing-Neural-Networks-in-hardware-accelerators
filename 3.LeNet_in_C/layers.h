#ifndef ALL_LAYERS
#define ALL_LAYERS
#include "lenet.h"
#endif

#ifndef DENSE_LAYERS
#define DENSE_LAYERS
void dense_layer1(DL1_inp_t input[OUTPUT5_LENGTH], DL1_out_t output[DENSE1_NEURONS]);
void dense_layer2(DL2_inp_t input[OUTPUT6_LENGTH], DL2_out_t output[DENSE2_NEURONS]);
void dense_layer3(DL3_inp_t input[OUTPUT7_LENGTH], DL3_out_t output[DENSE3_NEURONS]);
#endif

#ifndef CONVOLUTIONAL_LAYERS
#define CONVOLUTIONAL_LAYERS
void conv_layer1(CL1_inp_t input[INPUT_DIMENSION][INPUT_DIMENSION], CL1_out_t output[CONV1_NEURONS][OUTPUT1_DIM][OUTPUT1_DIM]);
void conv_layer2(CL2_inp_t input[CONV1_NEURONS][OUTPUT2_DIM][OUTPUT2_DIM], CL2_out_t output[CONV2_NEURONS][OUTPUT3_DIM][OUTPUT3_DIM]);
#endif

#ifndef AVERAGE_POOLING_LAYERS
#define AVERAGE_POOLING_LAYERS
void avg_pooling_layer1(PL1_inp_t input[CONV1_NEURONS][OUTPUT1_DIM][OUTPUT1_DIM], PL1_out_t output[CONV1_NEURONS][OUTPUT2_DIM][OUTPUT2_DIM]);
void avg_pooling_layer2(PL2_inp_t input[CONV2_NEURONS][OUTPUT3_DIM][OUTPUT3_DIM], PL2_out_t output[CONV2_NEURONS][OUTPUT4_DIM][OUTPUT4_DIM]);
#endif

#ifndef FLATENNING_LAYER
#define FLATENNING_LAYER
void flattening_layer(FL1_inp_t input[CONV2_NEURONS][OUTPUT4_DIM][OUTPUT4_DIM], FL1_out_t output[OUTPUT5_LENGTH]);
#endif







