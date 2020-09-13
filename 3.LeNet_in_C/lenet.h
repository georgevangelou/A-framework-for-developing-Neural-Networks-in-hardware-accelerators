#ifndef LENET_H
#define LENET_H

// Definitions of the networks and its dimensions according to different arithmetics.
// By uncommenting a line, its configuration is used.
// Be advised, that most of the below use libraries only supported in Vivado HLS running in Linux OS.
//#include "lenet_float(16).h" // Uniform 16-bit floating-point arithmetic
//#include "lenet_float(32).h" // Uniform 32-bit floating-point arithmetic
//#include "lenet_fixed(8).h" // Uniform 8-bit fixed-point arithmetic
//#include "lenet_fixed(16,8).h" // Uniform 16-bit fixed-point arithmetic
//#include "lenet_fixed(32,16).h" // Uniform 32-bit fixed-point arithmetic
//#include "lenet_fixed(judd_uniform).h" // Uniform fixed-point arithmetic (custom 1)
//#include "lenet_fixed(judd_mixed).h" // Non-Uniform fixed-point arithmetic (custom 2)
//#include "lenet_fixed(ristretto_like).h" // Non-Uniform fixed-point arithmetic (custom 3)

void ActivateNetwork(CL1_inp_t input_image[INPUT_DIMENSION][INPUT_DIMENSION], 
                     DL3_out_t output8[OUTPUT8_LENGTH]);
#endif



