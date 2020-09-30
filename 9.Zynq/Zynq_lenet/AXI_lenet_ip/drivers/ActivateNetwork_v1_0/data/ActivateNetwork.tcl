# ==============================================================
# File generated on Tue Jun 02 21:19:44 EEST 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XActivatenetwork" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_LENET_AXI_BASEADDR" \
        "C_S_AXI_LENET_AXI_HIGHADDR"

    xdefine_config_file $drv_handle "xactivatenetwork_g.c" "XActivatenetwork" \
        "DEVICE_ID" \
        "C_S_AXI_LENET_AXI_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XActivatenetwork" \
        "DEVICE_ID" \
        "C_S_AXI_LENET_AXI_BASEADDR" \
        "C_S_AXI_LENET_AXI_HIGHADDR"
}

