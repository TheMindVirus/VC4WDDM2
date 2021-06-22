# VC4WDDM2/Pi4DXGK-dev
Skeleton DXGK Driver for developing Broadcom VideoCoreIV/VI GPU in Windows for Raspberry Pi 4

## Status
This is a skeleton driver demonstrating how to implement the boilerplate of callback functions provided by DXGK for developing Graphics Drivers.
Further development is required to bring to fruition the features that DirectX can provide, and to perform Hardware Acceleration using the VideoCore VPU.

## Please use with caution, this repository is indended for educational purposes and testing. ##

This project may be used as a template to aid the development and prototyping of graphics drivers for ARM64 platforms similar to the Raspberry Pi 4 and VideoCore QPU.

## Requirements ##

Visual Studio 2019 Community Edition with ARM64 WDK Installed (and C++ ARM64 Build Tools with Spectre Mitigated Libs)

Test Signing On with Windows 10 ARM Insider Build 21337 in Test Mode

Inf2Cat On with /uselocaltime

Wpp Tracing Off in favour of WinDbg/KD

Additional information about WDDMv2 and DirectX DXGK DDI, or the Direct3D D3DDDI API's, can be found at the following link:
  https://docs.microsoft.com/en-us/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow
