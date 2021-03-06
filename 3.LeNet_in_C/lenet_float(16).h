#ifndef ACTIVATE_NETWORK
#define ACTIVATE_NETWORK
#include "dimensions.h"
#include "hls_half.h"


//Convolutional Layer 1
#define CL1_INP_BW 8
#define CL1_INP_IW 8
#define CL1_WEI_BW 4
#define CL1_WEI_IW 1
#define CL1_OUT_BW 8
#define CL1_OUT_IW 8
typedef half CL1_inp_t;
typedef half CL1_wei_t;
typedef half CL1_out_t;

//Average Pooling Layer 1
#define PL1_INP_BW 8
#define PL1_INP_IW 8
#define PL1_OUT_BW 8
#define PL1_OUT_IW 8
typedef half PL1_inp_t;
typedef half PL1_out_t;

//Convolutional Layer 2
#define CL2_INP_BW 8
#define CL2_INP_IW 8
#define CL2_WEI_BW 4
#define CL2_WEI_IW 0
#define CL2_OUT_BW 8
#define CL2_OUT_IW 8
typedef half CL2_inp_t;
typedef half CL2_wei_t;
typedef half CL2_out_t;

//Average Pooling Layer 2
#define PL2_INP_BW 8
#define PL2_INP_IW 8
#define PL2_OUT_BW 8
#define PL2_OUT_IW 7
typedef half PL2_inp_t;
typedef half PL2_out_t;

//Flattening Layer
#define FL1_INP_BW 8
#define FL1_INP_IW 7
#define FL1_OUT_BW 8
#define FL1_OUT_IW 7
typedef half FL1_inp_t;
typedef half FL1_out_t;

//Dense Layer 1
#define DL1_INP_BW 8
#define DL1_INP_IW 7
#define DL1_WEI_BW 4
#define DL1_WEI_IW 0
#define DL1_OUT_BW 8
#define DL1_OUT_IW 8
typedef half DL1_inp_t;
typedef half DL1_wei_t;
typedef half DL1_out_t;

//Dense Layer 2
#define DL2_INP_BW 8
#define DL2_INP_IW 8
#define DL2_WEI_BW 4
#define DL2_WEI_IW 0
#define DL2_OUT_BW 8
#define DL2_OUT_IW 8
typedef half DL2_inp_t;
typedef half DL2_wei_t;
typedef half DL2_out_t;

//Dense Layer 3
#define DL3_INP_BW 8
#define DL3_INP_IW 8
#define DL3_WEI_BW 4
#define DL3_WEI_IW 0
#define DL3_OUT_BW 8
#define DL3_OUT_IW 7
typedef half DL3_inp_t;
typedef half DL3_wei_t;
typedef half DL3_out_t;

#endif
