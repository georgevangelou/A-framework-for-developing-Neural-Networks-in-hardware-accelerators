#ifndef ACTIVATE_NETWORK
#define ACTIVATE_NETWORK
#include "dimensions.h"
#include <ap_fixed.h>

//Convolutional Layer 1
#define CL1_INP_BW 16
#define CL1_INP_IW 8
#define CL1_WEI_BW 16
#define CL1_WEI_IW 8
#define CL1_OUT_BW 16
#define CL1_OUT_IW 8
typedef ap_ufixed<CL1_INP_BW, CL1_INP_IW, AP_RND, AP_SAT> CL1_inp_t;
typedef ap_fixed<CL1_WEI_BW, CL1_WEI_IW, AP_RND, AP_SAT> CL1_wei_t;
typedef ap_fixed<CL1_OUT_BW, CL1_OUT_IW, AP_RND, AP_SAT> CL1_out_t;

//Average Pooling Layer 1
#define PL1_INP_BW 16
#define PL1_INP_IW 8
#define PL1_OUT_BW 16
#define PL1_OUT_IW 8
typedef ap_fixed<PL1_INP_BW, PL1_INP_IW, AP_RND, AP_SAT> PL1_inp_t;
typedef ap_fixed<PL1_OUT_BW, PL1_OUT_IW, AP_RND, AP_SAT> PL1_out_t;

//Convolutional Layer 2
#define CL2_INP_BW 16
#define CL2_INP_IW 8
#define CL2_WEI_BW 16
#define CL2_WEI_IW 8
#define CL2_OUT_BW 16
#define CL2_OUT_IW 8
typedef ap_fixed<CL2_INP_BW, CL2_INP_IW, AP_RND, AP_SAT> CL2_inp_t;
typedef ap_fixed<CL2_WEI_BW, CL2_WEI_IW, AP_RND, AP_SAT> CL2_wei_t;
typedef ap_fixed<CL2_OUT_BW, CL2_OUT_IW, AP_RND, AP_SAT> CL2_out_t;

//Average Pooling Layer 2
#define PL2_INP_BW 16
#define PL2_INP_IW 8
#define PL2_OUT_BW 16
#define PL2_OUT_IW 8
typedef ap_fixed<PL2_INP_BW, PL2_INP_IW, AP_RND, AP_SAT> PL2_inp_t;
typedef ap_fixed<PL2_OUT_BW, PL2_OUT_IW, AP_RND, AP_SAT> PL2_out_t;

//Flattening Layer
#define FL1_INP_BW 16
#define FL1_INP_IW 8
#define FL1_OUT_BW 16
#define FL1_OUT_IW 8
typedef ap_fixed<FL1_INP_BW, FL1_INP_IW, AP_RND, AP_SAT> FL1_inp_t;
typedef ap_fixed<FL1_OUT_BW, FL1_OUT_IW, AP_RND, AP_SAT> FL1_out_t;

//Dense Layer 1
#define DL1_INP_BW 16
#define DL1_INP_IW 8
#define DL1_WEI_BW 16
#define DL1_WEI_IW 8
#define DL1_OUT_BW 16
#define DL1_OUT_IW 8
typedef ap_fixed<DL1_INP_BW, DL1_INP_IW, AP_RND, AP_SAT> DL1_inp_t;
typedef ap_fixed<DL1_WEI_BW, DL1_WEI_IW, AP_RND, AP_SAT> DL1_wei_t;
typedef ap_fixed<DL1_OUT_BW, DL1_OUT_IW, AP_RND, AP_SAT> DL1_out_t;

//Dense Layer 2
#define DL2_INP_BW 16
#define DL2_INP_IW 8
#define DL2_WEI_BW 16
#define DL2_WEI_IW 8
#define DL2_OUT_BW 16
#define DL2_OUT_IW 8
typedef ap_fixed<DL2_INP_BW, DL2_INP_IW, AP_RND, AP_SAT> DL2_inp_t;
typedef ap_fixed<DL2_WEI_BW, DL2_WEI_IW, AP_RND, AP_SAT> DL2_wei_t;
typedef ap_fixed<DL2_OUT_BW, DL2_OUT_IW, AP_RND, AP_SAT> DL2_out_t;

//Dense Layer 3
#define DL3_INP_BW 16
#define DL3_INP_IW 8
#define DL3_WEI_BW 16
#define DL3_WEI_IW 8
#define DL3_OUT_BW 16
#define DL3_OUT_IW 8
typedef ap_fixed<DL3_INP_BW, DL3_INP_IW, AP_RND, AP_SAT> DL3_inp_t;
typedef ap_fixed<DL3_WEI_BW, DL3_WEI_IW, AP_RND, AP_SAT> DL3_wei_t;
typedef ap_fixed<DL3_OUT_BW, DL3_OUT_IW, AP_RND, AP_SAT> DL3_out_t;

#endif
