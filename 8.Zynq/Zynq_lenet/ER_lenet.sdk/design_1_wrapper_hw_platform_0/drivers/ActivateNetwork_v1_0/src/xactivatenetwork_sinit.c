// ==============================================================
// File generated on Tue Jun 02 21:19:44 EEST 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xactivatenetwork.h"

extern XActivatenetwork_Config XActivatenetwork_ConfigTable[];

XActivatenetwork_Config *XActivatenetwork_LookupConfig(u16 DeviceId) {
	XActivatenetwork_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XACTIVATENETWORK_NUM_INSTANCES; Index++) {
		if (XActivatenetwork_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XActivatenetwork_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XActivatenetwork_Initialize(XActivatenetwork *InstancePtr, u16 DeviceId) {
	XActivatenetwork_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XActivatenetwork_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XActivatenetwork_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

