#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <ntddk.h>
#include <wdm.h>
#include <dispmprt.h>
#pragma comment(lib, "displib.lib") //Also set "Linker->Additional Dependencies" to "$(DDK_LIB_PATH)displib.lib;%(AdditionalDependencies)" for All Configurations and Platforms

DRIVER_INITIALIZE   DriverEntry;
DRIVER_UNLOAD       DriverUnload;
VOID                DriverDebug(LPSTR format, ...);

#ifdef NDEBUG
#define debug(...)
#else
#define debug(...)   DriverDebug(__VA_ARGS__);
#endif//NDEBUG

#include "display.h"

#endif//MAIN_H