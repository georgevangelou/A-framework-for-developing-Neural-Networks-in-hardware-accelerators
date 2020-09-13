// ==============================================================
// File generated on Tue Jun 02 21:19:44 EEST 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// LENET_AXI
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x010 : Data signal of ap_return
//         bit 7~0 - ap_return[7:0] (Read)
//         others  - reserved
// 0x400 ~
// 0x7ff : Memory 'input_image_V' (1024 * 8b)
//         Word n : bit [ 7: 0] - input_image_V[4n]
//                  bit [15: 8] - input_image_V[4n+1]
//                  bit [23:16] - input_image_V[4n+2]
//                  bit [31:24] - input_image_V[4n+3]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL            0x000
#define XACTIVATENETWORK_LENET_AXI_ADDR_GIE                0x004
#define XACTIVATENETWORK_LENET_AXI_ADDR_IER                0x008
#define XACTIVATENETWORK_LENET_AXI_ADDR_ISR                0x00c
#define XACTIVATENETWORK_LENET_AXI_ADDR_AP_RETURN          0x010
#define XACTIVATENETWORK_LENET_AXI_BITS_AP_RETURN          8
#define XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE 0x400
#define XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH 0x7ff
#define XACTIVATENETWORK_LENET_AXI_WIDTH_INPUT_IMAGE_V     8
#define XACTIVATENETWORK_LENET_AXI_DEPTH_INPUT_IMAGE_V     1024

