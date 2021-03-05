// ==============================================================
// File generated on Tue Jun 02 21:19:44 EEST 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xactivatenetwork.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XActivatenetwork_CfgInitialize(XActivatenetwork *InstancePtr, XActivatenetwork_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Lenet_axi_BaseAddress = ConfigPtr->Lenet_axi_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XActivatenetwork_Start(XActivatenetwork *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL) & 0x80;
    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL, Data | 0x01);
}

u32 XActivatenetwork_IsDone(XActivatenetwork *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XActivatenetwork_IsIdle(XActivatenetwork *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XActivatenetwork_IsReady(XActivatenetwork *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XActivatenetwork_EnableAutoRestart(XActivatenetwork *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL, 0x80);
}

void XActivatenetwork_DisableAutoRestart(XActivatenetwork *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_CTRL, 0);
}

u32 XActivatenetwork_Get_return(XActivatenetwork *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_AP_RETURN);
    return Data;
}
u32 XActivatenetwork_Get_input_image_V_BaseAddress(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE);
}

u32 XActivatenetwork_Get_input_image_V_HighAddress(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH);
}

u32 XActivatenetwork_Get_input_image_V_TotalBytes(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH - XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + 1);
}

u32 XActivatenetwork_Get_input_image_V_BitWidth(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XACTIVATENETWORK_LENET_AXI_WIDTH_INPUT_IMAGE_V;
}

u32 XActivatenetwork_Get_input_image_V_Depth(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XACTIVATENETWORK_LENET_AXI_DEPTH_INPUT_IMAGE_V;
}

u32 XActivatenetwork_Write_input_image_V_Words(XActivatenetwork *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH - XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XActivatenetwork_Read_input_image_V_Words(XActivatenetwork *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH - XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + (offset + i)*4);
    }
    return length;
}

u32 XActivatenetwork_Write_input_image_V_Bytes(XActivatenetwork *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH - XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XActivatenetwork_Read_input_image_V_Bytes(XActivatenetwork *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_HIGH - XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Lenet_axi_BaseAddress + XACTIVATENETWORK_LENET_AXI_ADDR_INPUT_IMAGE_V_BASE + offset + i);
    }
    return length;
}

void XActivatenetwork_InterruptGlobalEnable(XActivatenetwork *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_GIE, 1);
}

void XActivatenetwork_InterruptGlobalDisable(XActivatenetwork *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_GIE, 0);
}

void XActivatenetwork_InterruptEnable(XActivatenetwork *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_IER);
    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_IER, Register | Mask);
}

void XActivatenetwork_InterruptDisable(XActivatenetwork *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_IER);
    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_IER, Register & (~Mask));
}

void XActivatenetwork_InterruptClear(XActivatenetwork *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XActivatenetwork_WriteReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_ISR, Mask);
}

u32 XActivatenetwork_InterruptGetEnabled(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_IER);
}

u32 XActivatenetwork_InterruptGetStatus(XActivatenetwork *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XActivatenetwork_ReadReg(InstancePtr->Lenet_axi_BaseAddress, XACTIVATENETWORK_LENET_AXI_ADDR_ISR);
}

