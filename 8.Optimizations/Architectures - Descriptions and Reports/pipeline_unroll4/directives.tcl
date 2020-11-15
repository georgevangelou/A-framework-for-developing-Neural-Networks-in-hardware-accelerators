############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_pipeline "dense_layer2/dense_layer2_inner_loop"
set_directive_pipeline "avg_pooling_layer1/avg_pooling_layer1_2_loop"
set_directive_pipeline "avg_pooling_layer2/avg_pooling_layer2_2_loop"
set_directive_pipeline "flattening_layer/flattening_layer_2_loop"
set_directive_pipeline "dense_layer3/dense_layer3_inner_loop"
set_directive_array_partition -type complete -dim 3 "avg_pooling_layer2" input
set_directive_array_reshape -type cyclic -factor 2 -dim 3 "avg_pooling_layer1" input
set_directive_array_partition -type cyclic -factor 2 -dim 2 "conv_layer1" input
set_directive_array_partition -type complete -dim 3 "conv_layer2" input
set_directive_pipeline "conv_layer1/conv_layer1_relu_inner_loop"
set_directive_pipeline "conv_layer2/conv_layer2_relu_inner_loop"
## den paizoun rolo afou exoun sbhstei ta bias loop
set_directive_pipeline "conv_layer1/conv_layer1_biases_inner_loop"
set_directive_pipeline "conv_layer2/conv_layer2_biases_inner_loop"
set_directive_unroll -factor 36 "dense_layer1/dense_layer1_inner_loop"
set_directive_pipeline "conv_layer2/conv_layer2_kernel_1_loop"
set_directive_pipeline "conv_layer1/conv_layer1_kernel_1_loop"
