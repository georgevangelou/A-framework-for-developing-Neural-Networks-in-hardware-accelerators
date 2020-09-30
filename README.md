# A framework for developing Neural Networks in hardware accelerators
## Description
This framework was part of the **Diploma thesis** titled "Architectures and Implementations of the Neural Network LeNet-5 in FPGAs".

The **main goal** of this thesis was to create a LeNet-5 implementation in an FPGA development board, but also form a reusable framework/workflow which can be modified to model and develop other Neural Networks too.

The **authors** of this thesis were (in alphabetical order):
- George Evangelou (Dipl. Eng. Electrical and Computer Engineering Department, Univ. of Patras, Greece)
  - Email: george_evangelou@windowslive.com
  - [LinkedIn profile](https://www.linkedin.com/in/georgios-evangelou-2a389b167/)
- Nick Roussos (Dipl. Eng. Electrical and Computer Engineering Department, Univ. of Patras, Greece)
  - Email: up1046939@upnet.gr

**Duration** of the thesis: May 2019 - July 2020
## Instructions
Most code is commented or self-descriptive.

In order to replicate our workflow, start developing in the order of the folders' indices.

Frameworks used:
- Caffe
- Python 3.8
- Keras
- C/C++
- Vivado Design Suite (Vivado HLS, Vivado, Xilinx SDK)
## Contents
The folders contained within this repository are the following:
- **0.Resources**: The MNIST dataset used to train, evaluate and use our implementations. It can also be downloaded from the official website.
- **1.LeNet_in_Python**: Our LeNet-5 implementation in Python and a script to estimate its average execution time per image.
- **2.LeNet_weights_extraction**: Two-stage process of extracting the network's weights from the Python implementation to be later used by our C/C++ implementation.
- **3.LeNet_in_C**: Our LeNet-5 implementation in C/C++ and various configuration files.
- **4.LeNet_Debugger**: Some scripts that assisted in developments and debugging.
- **5.Excel_Visualization**: 
  - An excel document that assisted in developments and debugging.
  - Two excel documents containing the accumulative evaluation results of our C/C++ implementation.
- **6.Testbench**: A script that generates files to be utilized by the Vivado HLS testbench we have created (_see 3.LeNet_in_C_).
- **8.Zynq**: 
  - The IP produced using Vivado and Vivado HLS.
  - The SDK project produced.
  - The PC<->Board testbench script.

# 
This repository is _work in progress_. Please contact the authors for any issue.