// ==============================================================
// File generated on Tue Jun 02 21:19:44 EEST 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XACTIVATENETWORK_H
#define XACTIVATENETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xactivatenetwork_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Lenet_axi_BaseAddress;
} XActivatenetwork_Config;
#endif

typedef struct {
    u32 Lenet_axi_BaseAddress;
    u32 IsReady;
} XActivatenetwork;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XActivatenetwork_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XActivatenetwork_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XActivatenetwork_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XActivatenetwork_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XActivatenetwork_Initialize(XActivatenetwork *InstancePtr, u16 DeviceId);
XActivatenetwork_Config* XActivatenetwork_LookupConfig(u16 DeviceId);
int XActivatenetwork_CfgInitialize(XActivatenetwork *InstancePtr, XActivatenetwork_Config *ConfigPtr);
#else
int XActivatenetwork_Initialize(XActivatenetwork *InstancePtr, const char* InstanceName);
int XActivatenetwork_Release(XActivatenetwork *InstancePtr);
#endif

void XActivatenetwork_Start(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_IsDone(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_IsIdle(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_IsReady(XActivatenetwork *InstancePtr);
void XActivatenetwork_EnableAutoRestart(XActivatenetwork *InstancePtr);
void XActivatenetwork_DisableAutoRestart(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Get_return(XActivatenetwork *InstancePtr);

u32 XActivatenetwork_Get_input_image_V_BaseAddress(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Get_input_image_V_HighAddress(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Get_input_image_V_TotalBytes(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Get_input_image_V_BitWidth(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Get_input_image_V_Depth(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_Write_input_image_V_Words(XActivatenetwork *InstancePtr, int offset, int *data, int length);
u32 XActivatenetwork_Read_input_image_V_Words(XActivatenetwork *InstancePtr, int offset, int *data, int length);
u32 XActivatenetwork_Write_input_image_V_Bytes(XActivatenetwork *InstancePtr, int offset, char *data, int length);
u32 XActivatenetwork_Read_input_image_V_Bytes(XActivatenetwork *InstancePtr, int offset, char *data, int length);

void XActivatenetwork_InterruptGlobalEnable(XActivatenetwork *InstancePtr);
void XActivatenetwork_InterruptGlobalDisable(XActivatenetwork *InstancePtr);
void XActivatenetwork_InterruptEnable(XActivatenetwork *InstancePtr, u32 Mask);
void XActivatenetwork_InterruptDisable(XActivatenetwork *InstancePtr, u32 Mask);
void XActivatenetwork_InterruptClear(XActivatenetwork *InstancePtr, u32 Mask);
u32 XActivatenetwork_InterruptGetEnabled(XActivatenetwork *InstancePtr);
u32 XActivatenetwork_InterruptGetStatus(XActivatenetwork *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
