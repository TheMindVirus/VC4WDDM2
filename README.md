# VC4WDDM2
Skeleton DXGK Driver on top of ACPI\VC4 for developing Broadcom VideoCoreIV/VI GPU in Windows

Continuation of KMDF-X and UDF-Python: Windows Diagnostic and Compute/Render/Display Drivers for Raspberry Pi 4 in Low Peripheral Mode

## Status
This is a skeleton driver demonstrating how to implement the boilerplate of callback functions provided by DXGK for developing Graphics Drivers.
Further development is required to bring to fruition the features that DirectX can provide, and to perform Hardware Acceleration using the VideoCore VPU.

## Please use with caution, this repository is indended for educational purposes and testing. ##

This project may be used as a template to aid the development and prototyping of graphics drivers for ARM64 platforms similar to the Raspberry Pi 4 and VideoCore QPU.

## Requirements ##

Visual Studio 2019 Community Edition with ARM64 WDK Installed (and C++ ARM64 Build Tools with Spectre Mitigated Libs)

Test Signing On with Windows 10 ARM Insider Build 21277 in Test Mode

Inf2Cat On with /uselocaltime

Wpp Tracing Off in favour of Text File Debug

Additional information about WDDMv2 and DirectX DXGK DDI, or the Direct3D D3DDDI API's, can be found at the following link:
  https://docs.microsoft.com/en-us/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow

## Installation ##

The Driver gets installed on top of the device in Device Manager that identifies from UEFI as "ACPI\VC4". Right-click to Update its drivers.

Alternatively, it can be installed standalone alongside whichever device is already using "ACPI\VC4" if any.

Certain .inf directives may cause the driver to be hidden from initial view. To unhide it, remove "excludefromselect=\*" and select "View->Show hidden devices".

A log file called "VC4WDDM2.TXT" gets created in "C:\Windows" by default. Open this text file to view the text file log output of the driver.

Alternatively, you may opt to reinstate Wpp Tracing or use Kernel Debugging, in which case you may find "DlDebugPrint()" is more useful to you.

To uninstall the driver, use Device Manager to right-click and uninstall the device, then optionally delete or archive the Log file.

### You may be prompted with a security warning if driver signature enforcement is enabled. ###
### Please only follow these instructions if you are testing Windows and you know what you are doing. ###
