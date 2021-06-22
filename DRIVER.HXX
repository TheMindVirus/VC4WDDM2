#ifndef _DRIVER_HXX_
#define _DRIVER_HXX_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BDDTAG   (ULONG)'DDBS'

extern "C"
{
#include <ntddk.h>
#include <wdm.h>
#include <guiddef.h>
#include <initguid.h>
#include <dispmprt.h>
#pragma comment(lib, "displib.lib") //Also set "Linker->Additional Dependencies" to "$(DDK_LIB_PATH)displib.lib;%(AdditionalDependencies)" for All Configurations and Platforms

	DRIVER_INITIALIZE   DriverEntry;
	DRIVER_UNLOAD       DriverUnload;

#ifndef DBG
#define debug(...)
#else
#define debug(...)   \
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__)); \
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "\n"));
#endif

//--------------------------------------------------------------------------------------------------------
#pragma region //Forward Declarations

	typedef NTSTATUS DXGKDDI_SUBMITRENDER(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_CREATEALLOCATION2(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_DESCRIBEPAGETABLE(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_UPDATEPAGETABLE(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_UPDATEPAGEDIRECTORY(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_MOVEPAGEDIRECTORY(IN_CONST_HANDLE, PVOID);
	typedef NTSTATUS DXGKDDI_RESERVED(VOID);
	typedef NTSTATUS DXGKDDI_RESERVED1(VOID);
	typedef NTSTATUS DXGKDDI_RESERVED2(VOID);
	typedef NTSTATUS DXGKDDI_RESERVED3(VOID);
	
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_EVAL_ACPI_METHOD(HANDLE, ULONG, PACPI_EVAL_INPUT_BUFFER_COMPLEX, ULONG, PACPI_EVAL_OUTPUT_BUFFER, ULONG);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_GET_DEVICE_INFORMATION(HANDLE, PDXGK_DEVICE_INFO);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_INDICATE_CHILD_STATUS(HANDLE, PDXGK_CHILD_STATUS);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_MAP_MEMORY(HANDLE, PHYSICAL_ADDRESS, ULONG, BOOLEAN, BOOLEAN, MEMORY_CACHING_TYPE, PVOID*);
	typedef BOOLEAN APIENTRY INTERFACE_DXGKCB_QUEUE_DPC(HANDLE);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_QUERY_SERVICES(HANDLE, DXGK_SERVICES, PINTERFACE);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_READ_DEVICE_SPACE(HANDLE, ULONG, PVOID, ULONG, ULONG, PULONG);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_SYNCHRONIZE_EXECUTION(HANDLE, PKSYNCHRONIZE_ROUTINE, PVOID, ULONG, PBOOLEAN);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_UNMAP_MEMORY(HANDLE, PVOID);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_WRITE_DEVICE_SPACE(HANDLE, ULONG, PVOID, ULONG, ULONG, PULONG);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_IS_DEVICE_PRESENT(HANDLE, PPCI_DEVICE_PRESENCE_PARAMETERS, PBOOLEAN);
	typedef VOID* APIENTRY CALLBACK INTERFACE_DXGKCB_GETHANDLEDATA(IN_CONST_PDXGKARGCB_GETHANDLEDATA);
	typedef D3DKMT_HANDLE APIENTRY CALLBACK INTERFACE_DXGKCB_GETHANDLEPARENT(IN_D3DKMT_HANDLE);
	typedef D3DKMT_HANDLE APIENTRY CALLBACK INTERFACE_DXGKCB_ENUMHANDLECHILDREN(IN_CONST_PDXGKARGCB_ENUMHANDLECHILDREN);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_NOTIFY_INTERRUPT(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_NOTIFY_INTERRUPT_DATA);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_NOTIFY_DPC(IN_CONST_HANDLE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_QUERYVIDPNINTERFACE(IN_CONST_D3DKMDT_HVIDPN, IN_CONST_DXGK_VIDPN_INTERFACE_VERSION, DEREF_OUT_CONST_PPDXGK_VIDPN_INTERFACE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_QUERYMONITORINTERFACE(IN_CONST_HANDLE, IN_CONST_DXGK_MONITOR_INTERFACE_VERSION, DEREF_OUT_CONST_PPDXGK_MONITOR_INTERFACE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_GETCAPTUREADDRESS(INOUT_PDXGKARGCB_GETCAPTUREADDRESS);
	typedef VOID APIENTRY INTERFACE_DXGKCB_LOG_ETW_EVENT(const LPCGUID, UCHAR, USHORT, PVOID);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_EXCLUDE_ADAPTER_ACCESS(HANDLE, ULONG, DXGKDDI_PROTECTED_CALLBACK, PVOID);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WIN8
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_CREATECONTEXTALLOCATION(INOUT_PDXGKARGCB_CREATECONTEXTALLOCATION);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_DESTROYCONTEXTALLOCATION(IN_CONST_HANDLE, IN_CONST_HANDLE);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_SETPOWERCOMPONENTACTIVE(IN_CONST_HANDLE, UINT);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_SETPOWERCOMPONENTIDLE(IN_CONST_HANDLE, UINT);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP(HANDLE, PDXGK_DISPLAY_INFORMATION);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_POWERRUNTIMECONTROLREQUEST(IN_CONST_HANDLE, LPCGUID, PVOID, SIZE_T, PVOID, SIZE_T, PSIZE_T);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_SETPOWERCOMPONENTLATENCY(IN_CONST_HANDLE, UINT, ULONGLONG);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_SETPOWERCOMPONENTRESIDENCY(IN_CONST_HANDLE, UINT, ULONGLONG);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_COMPLETEFSTATETRANSITION(IN_CONST_HANDLE, UINT);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM1_3
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_COMPLETEPSTATETRANSITION(IN_CONST_HANDLE, UINT, UINT);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_0
	typedef D3DGPU_VIRTUAL_ADDRESS APIENTRY CALLBACK INTERFACE_DXGKCB_MAPCONTEXTALLOCATION(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_MAPCONTEXTALLOCATION);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_UPDATECONTEXTALLOCATION(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_UPDATECONTEXTALLOCATION);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE(IN_CONST_HANDLE, INOUT_PDXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE);
	typedef VOID* APIENTRY CALLBACK INTERFACE_DXGKCB_ACQUIREHANDLEDATA(IN_CONST_PDXGKARGCB_GETHANDLEDATA, PDXGKARG_RELEASE_HANDLE);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_RELEASEHANDLEDATA(IN_CONST_DXGKARGCB_RELEASEHANDLEDATA);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN(IN_CONST_HANDLE, UINT);
    //DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_1
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_MULTIPLANEOVERLAYDISABLED(IN_CONST_HANDLE, UINT);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_DXGKCB_MITIGATEDRANGEUPDATE(IN_CONST_HANDLE, ULONG);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_2
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_INVALIDATEHWCONTEXT(IN_CONST_PDXGKARGCB_INVALIDATEHWCONTEXT);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_INDICATE_CONNECTOR_CHANGE(IN_CONST_HANDLE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_UNBLOCKUEFIFRAMEBUFFERRANGES(IN_CONST_HANDLE, IN_CONST_PDXGK_SEGMENTMEMORYSTATE);
	typedef NTSTATUS APIENTRY INTERFACE_DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP2(HANDLE, PDXGK_DISPLAY_INFORMATION, PDXGK_DISPLAY_OWNERSHIP_FLAGS);
    //DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_3
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_SETPROTECTEDSESSIONSTATUS(IN_CONST_PDXGKARGCB_PROTECTEDSESSIONSTATUS);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_4
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_ALLOCATECONTIGUOUSMEMORY(IN_CONST_HANDLE, INOUT_PDXGKARGCB_ALLOCATECONTIGUOUSMEMORY);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_FREECONTIGUOUSMEMORY(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_FREECONTIGUOUSMEMORY);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_ALLOCATEPAGESFORMDL(IN_CONST_HANDLE, INOUT_PDXGKARGCB_ALLOCATEPAGESFORMDL);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_FREEPAGESFROMMDL(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_FREEPAGESFROMMDL);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_PINFRAMEBUFFERFORSAVE(IN_CONST_HANDLE, INOUT_PDXGKARGCB_PINFRAMEBUFFERFORSAVE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_UNPINFRAMEBUFFERFORSAVE(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_UNPINFRAMEBUFFERFORSAVE);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_MAPFRAMEBUFFERPOINTER(IN_CONST_HANDLE, INOUT_PDXGKARGCB_MAPFRAMEBUFFERPOINTER);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_UNMAPFRAMEBUFFERPOINTER(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_UNMAPFRAMEBUFFERPOINTER);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_MAPMDLTOIOMMU(IN_CONST_HANDLE, INOUT_PDXGKARGCB_MAPMDLTOIOMMU);
	typedef VOID APIENTRY CALLBACK INTERFACE_DXGKCB_UNMAPMDLFROMIOMMU(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_UNMAPMDLFROMIOMMU);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_REPORT_DIAGNOSTIC(HANDLE, IN_PDXGK_DIAGNOSTIC_HEADER);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_5
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_SIGNALEVENT(IN_CONST_PDXGKARGCB_SIGNALEVENT);
	//DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_6)
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_ISFEATUREENABLED(INOUT_PDXGKARGCB_ISFEATUREENABLED);
	typedef NTSTATUS APIENTRY CALLBACK INTERFACE_DXGKCB_SAVEMEMORYFORHOTUPDATE(IN_CONST_HANDLE, IN_CONST_PDXGKARGCB_SAVEMEMORYFORHOTUPDATE);
	//more to go here in WDDM2_7 onwards...

	typedef VOID INTERFACE_I2C_REFERENCE(PVOID);
	typedef VOID INTERFACE_I2C_DEREFERENCE(PVOID);
	typedef NTSTATUS INTERFACE_I2C_TRANSMIT_DATA_TO_DISPLAY(PVOID, D3DDDI_VIDEO_PRESENT_TARGET_ID, ULONG, ULONG, const void*);
	typedef NTSTATUS INTERFACE_I2C_RECEIVE_DATA_FROM_DISPLAY(PVOID, D3DDDI_VIDEO_PRESENT_TARGET_ID, ULONG, ULONG, ULONG, PVOID);

	typedef VOID INTERFACE_OPM_REFERENCE(PVOID);
	typedef VOID INTERFACE_OPM_DEREFERENCE(PVOID);
	typedef NTSTATUS INTERFACE_OPM_GET_CERTIFICATE_SIZE(PVOID, DXGKMDT_CERTIFICATE_TYPE, PULONG);
	typedef NTSTATUS INTERFACE_OPM_GET_CERTIFICATE(PVOID, DXGKMDT_CERTIFICATE_TYPE, ULONG, PVOID);
	typedef NTSTATUS INTERFACE_OPM_CREATE_PROTECTED_OUTPUT(PVOID, D3DDDI_VIDEO_PRESENT_TARGET_ID, DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS, PHANDLE);
	typedef NTSTATUS INTERFACE_OPM_GET_RANDOM_NUMBER(PVOID, HANDLE, PDXGKMDT_OPM_RANDOM_NUMBER);
	typedef NTSTATUS INTERFACE_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS(PVOID, HANDLE, const DXGKMDT_OPM_ENCRYPTED_PARAMETERS*);
	typedef NTSTATUS INTERFACE_OPM_GET_INFORMATION(PVOID, HANDLE, const DXGKMDT_OPM_GET_INFO_PARAMETERS*, PDXGKMDT_OPM_REQUESTED_INFORMATION);
	typedef NTSTATUS INTERFACE_OPM_GET_COPP_COMPATIBLE_INFORMATION(PVOID, HANDLE, const DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS*, PDXGKMDT_OPM_REQUESTED_INFORMATION);
	typedef NTSTATUS INTERFACE_OPM_CONFIGURE_PROTECTED_OUTPUT(PVOID, HANDLE, const DXGKMDT_OPM_CONFIGURE_PARAMETERS*, ULONG, const void*);
	typedef NTSTATUS INTERFACE_OPM_DESTROY_PROTECTED_OUTPUT(PVOID, HANDLE);
	typedef NTSTATUS INTERFACE_OPM_CREATE_PROTECTED_OUTPUT_NONLOCAL_DISPLAY(PVOID, DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS, UINT64, DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT*, UINT64, DXGKMDT_OPM_CONNECTOR_TYPE, PHANDLE);
	typedef NTSTATUS INTERFACE_OPM_SET_SRM_LIST(PVOID, ULONG, PVOID);
	typedef NTSTATUS INTERFACE_OPM_GET_SRM_LIST_VERSION(PVOID, PULONG, PVOID);

	typedef VOID INTERFACE_MIRACAST_REFERENCE(PVOID);
	typedef VOID INTERFACE_MIRACAST_DEREFERENCE(PVOID);
	typedef NTSTATUS INTERFACE_MIRACAST_QUERY_CAPS(PVOID, ULONG, PDXGK_MIRACAST_CAPS);
	typedef NTSTATUS INTERFACE_MIRACAST_CREATE_CONTEXT(PVOID, PDXGK_MIRACAST_DISPLAY_CALLBACKS, PVOID*, PULONG);
	typedef NTSTATUS INTERFACE_MIRACAST_HANDLE_IO_CONTROL(PVOID, PVOID, ULONG, PVOID, ULONG, PVOID, PULONG);
	typedef VOID INTERFACE_MIRACAST_DESTROY_CONTEXT(PVOID, PVOID);

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Device Section

	DXGKDDI_CREATEDEVICE                                   DxgkDdiCreateDevice;
	DXGKDDI_ADD_DEVICE                                     DxgkDdiAddDevice;
	DXGKDDI_LINK_DEVICE                                    DxgkDdiLinkDevice;
	DXGKDDI_START_DEVICE                                   DxgkDdiStartDevice;
	DXGKDDI_RESET_DEVICE                                   DxgkDdiResetDevice;
	DXGKDDI_STOP_DEVICE                                    DxgkDdiStopDevice;
	DXGKDDI_REMOVE_DEVICE                                  DxgkDdiRemoveDevice;
	DXGKDDI_DESTROYDEVICE                                  DxgkDdiDestroyDevice;
	DXGKDDI_UNLOAD                                         DxgkDdiUnload;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Present Section

	DXGKDDI_PRESENT                                        DxgkDdiPresent;
	DXGKDDI_RENDER                                         DxgkDdiRender;
	DXGKDDI_RENDER                                         DxgkDdiRenderKm;
	DXGKDDI_RENDERGDI                                      DxgkDdiRenderGdi;
//	PVOID                                                   DxgkDdiSubmitRender;
	DXGKDDI_SUBMITRENDER                                   DxgkDdiSubmitRender;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Command Section

	DXGKDDI_PATCH                                          DxgkDdiPatch;
	DXGKDDI_PREEMPTCOMMAND                                 DxgkDdiPreemptCommand;
	DXGKDDI_SUBMITCOMMAND                                  DxgkDdiSubmitCommand;
	DXGKDDI_SUBMITCOMMANDVIRTUAL                           DxgkDdiSubmitCommandVirtual;
	DXGKDDI_VALIDATESUBMITCOMMAND                          DxgkDdiValidateSubmitCommand;
	DXGKDDI_CANCELCOMMAND                                  DxgkDdiCancelCommand;
	DXGKDDI_BUILDPAGINGBUFFER                              DxgkDdiBuildPagingBuffer;
	DXGKDDI_RESETFROMTIMEOUT                               DxgkDdiResetFromTimeout;
	DXGKDDI_RESTARTFROMTIMEOUT                             DxgkDdiRestartFromTimeout;
	DXGKDDI_ESCAPE                                         DxgkDdiEscape;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Calibration Section

	DXGKDDI_EXCHANGEPRESTARTINFO                           DxgkDdiExchangePreStartInfo;
	DXGKDDI_FORMATHISTORYBUFFER                            DxgkDdiFormatHistoryBuffer;
	DXGKDDI_CONTROLDIAGNOSTICREPORTING                     DxgkDdiControlDiagnosticReporting;
	DXGKDDI_COLLECTDIAGNOSTICINFO                          DxgkDdiCollectDiagnosticInfo;
	DXGKDDI_CALIBRATEGPUCLOCK                              DxgkDdiCalibrateGpuClock;
	DXGKDDI_CONTROLMODEBEHAVIOR                            DxgkDdiControlModeBehavior;
	DXGKDDI_UPDATEMONITORLINKINFO                          DxgkDdiUpdateMonitorLinkInfo;
	DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY               DxgkDdiValidateUpdateAllocationProperty;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Calibration Section

	DXGKDDI_SETUPPRIORITYBANDS                             DxgkDdiSetupPriorityBands;
	DXGKDDI_SETCONTEXTSCHEDULINGPROPERTIES                 DxgkDdiSetContextSchedulingProperties;
	DXGKDDI_SETSCHEDULINGLOGBUFFER                         DxgkDdiSetSchedulingLogBuffer;
	DXGKDDI_SETTARGETGAMMA                                 DxgkDdiSetTargetGamma;
	DXGKDDI_SETTARGETCONTENTTYPE                           DxgkDdiSetTargetContentType;
	DXGKDDI_SETTARGETANALOGCOPYPROTECTION                  DxgkDdiSetTargetAnalogCopyProtection;
	DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY                   DxgkDdiSetTargetAdjustedColorimetry;
	DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2                  DxgkDdiSetTargetAdjustedColorimetry2;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Section

	DXGKDDI_SETPALETTE                                     DxgkDdiSetPalette;
	DXGKDDI_SETPOINTERPOSITION                             DxgkDdiSetPointerPosition;
	DXGKDDI_SETPOINTERSHAPE                                DxgkDdiSetPointerShape;
	DXGKDDI_SET_POWER_STATE                                DxgkDdiSetPowerState;
	DXGKDDISETPOWERPSTATE                                  DxgkDdiSetPowerPState;
	DXGKDDISETPOWERCOMPONENTFSTATE                         DxgkDdiSetPowerComponentFState;
	DXGKDDI_SETSTABLEPOWERSTATE                            DxgkDdiSetStablePowerState;
	DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL                   DxgkDdiSetTrackedWorkloadPowerLevel;
	DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT                  DxgkDdiSetDisplayPrivateDriverFormat;
	DXGKDDI_SETVIDEOPROTECTEDREGION                        DxgkDdiSetVideoProtectedRegion;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Get Section

	DXGKDDI_GETSCANLINE                                    DxgkDdiGetScanLine;
	DXGKDDI_GETNODEMETADATA                                DxgkDdiGetNodeMetadata;
	DXGKDDI_GET_CHILD_CONTAINER_ID                         DxgkDdiGetChildContainerId;
	DXGKDDI_GETPOSTCOMPOSITIONCAPS                         DxgkDdiGetPostCompositionCaps;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Notify Section

	DXGKDDI_NOTIFY_ACPI_EVENT                              DxgkDdiNotifyAcpiEvent;
	DXGKDDI_NOTIFYFOCUSPRESENT                             DxgkDdiNotifyFocusPresent;
	DXGKDDI_NOTIFY_SURPRISE_REMOVAL                        DxgkDdiNotifySurpriseRemoval;
	DXGKDDIPOWERRUNTIMECONTROLREQUEST                      DxgkDdiPowerRuntimeControlRequest;
	DXGKDDI_POWERRUNTIMESETDEVICEHANDLE                    DxgkDdiPowerRuntimeSetDeviceHandle;
	DXGKDDI_CREATEPERIODICFRAMENOTIFICATION                DxgkDdiCreatePeriodicFrameNotification;
	DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION               DxgkDdiDestroyPeriodicFrameNotification;
	DXGKDDI_SIGNALMONITOREDFENCE                           DxgkDdiSignalMonitoredFence;
	DXGKDDI_DISPLAYDETECTCONTROL                           DxgkDdiDisplayDetectControl;
	DXGKDDI_RECOMMENDMONITORMODES                          DxgkDdiRecommendMonitorModes;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Query Section

	DXGKDDI_QUERY_INTERFACE                                DxgkDdiQueryInterface;
	DXGKDDI_QUERYADAPTERINFO                               DxgkDdiQueryAdapterInfo;
	DXGKDDI_QUERYCURRENTFENCE                              DxgkDdiQueryCurrentFence;
	DXGKDDI_QUERY_DEVICE_DESCRIPTOR                        DxgkDdiQueryDeviceDescriptor;
	DXGKDDI_QUERYVIDPNHWCAPABILITY                         DxgkDdiQueryVidPnHWCapability;
	DXGKDDI_QUERY_CHILD_RELATIONS                          DxgkDdiQueryChildRelations;
	DXGKDDI_QUERY_CHILD_STATUS                             DxgkDdiQueryChildStatus;
	DXGKDDI_QUERYCONNECTIONCHANGE                          DxgkDdiQueryConnectionChange;
	DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT                    DxgkDdiQueryDiagnosticTypesSupport;
	DXGKDDI_QUERYDEPENDENTENGINEGROUP                      DxgkDdiQueryDependentEngineGroup;
	DXGKDDI_QUERYENGINESTATUS                              DxgkDdiQueryEngineStatus;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Video Present Network (VidPn) Section

	DXGKDDI_COMMITVIDPN                                    DxgkDdiCommitVidPn;
	DXGKDDI_ISSUPPORTEDVIDPN                               DxgkDdiIsSupportedVidPn;
	DXGKDDI_ENUMVIDPNCOFUNCMODALITY                        DxgkDdiEnumVidPnCofuncModality;
	DXGKDDI_RECOMMENDFUNCTIONALVIDPN                       DxgkDdiRecommendFunctionalVidPn;
	DXGKDDI_GETMULTIPLANEOVERLAYCAPS                       DxgkDdiGetMultiPlaneOverlayCaps;
	DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT                   DxgkDdiPostMultiPlaneOverlayPresent;
	DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT                  DxgkDdiCheckMultiPlaneOverlaySupport;
	DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2                 DxgkDdiCheckMultiPlaneOverlaySupport2;
	DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3                 DxgkDdiCheckMultiPlaneOverlaySupport3;
	DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY     DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay;
	DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2    DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2;
	DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3    DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3;
	DXGKDDI_SETVIDPNSOURCEADDRESS                          DxgkDdiSetVidPnSourceAddress;
	DXGKDDI_SETVIDPNSOURCEVISIBILITY                       DxgkDdiSetVidPnSourceVisibility;
	DXGKDDI_SETTIMINGSFROMVIDPN                            DxgkDdiSetTimingsFromVidPn;
	DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH                   DxgkDdiUpdateActiveVidPnPresentPath;
	DXGKDDI_RECOMMENDVIDPNTOPOLOGY                         DxgkDdiRecommendVidPnTopology;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Engine Section

	DXGKDDI_RESETENGINE                                    DxgkDdiResetEngine;
	DXGKDDI_RESUMEHWENGINE                                 DxgkDdiResumeHwEngine;
	DXGKDDI_RESETHWENGINE                                  DxgkDdiResetHwEngine;
	DXGKDDI_CREATEPROCESS                                  DxgkDdiCreateProcess;
	DXGKDDI_DESTROYPROCESS                                 DxgkDdiDestroyProcess;
	DXGKDDI_STOPCAPTURE                                    DxgkDdiStopCapture;
	DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP DxgkDdiStopDeviceAndReleasePostDisplayOwnership;
	DXGKDDI_SYSTEM_DISPLAY_ENABLE                          DxgkDdiSystemDisplayEnable;
	DXGKDDI_SYSTEM_DISPLAY_WRITE                           DxgkDdiSystemDisplayWrite;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Interrupt Section

	DXGKDDI_DPC_ROUTINE                                    DxgkDdiDpcRoutine;
	DXGKDDI_INTERRUPT_ROUTINE                              DxgkDdiInterruptRoutine;
	DXGKDDI_DISPATCH_IO_REQUEST                            DxgkDdiDispatchIoRequest;
	DXGKDDI_CONTROLINTERRUPT                               DxgkDdiControlInterrupt;
	DXGKDDI_CONTROLINTERRUPT2                              DxgkDdiControlInterrupt2;
	DXGKDDI_CONTROLINTERRUPT3                              DxgkDdiControlInterrupt3;
	DXGKDDI_CONTROL_ETW_LOGGING                            DxgkDdiControlEtwLogging;
	DXGKDDI_COLLECTDBGINFO                                 DxgkDdiCollectDbgInfo;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Allocation Section

	DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA                DxgkDdiGetStandardAllocationDriverData;
	DXGKDDI_DESCRIBEALLOCATION                             DxgkDdiDescribeAllocation;
	DXGKDDI_CREATEALLOCATION                               DxgkDdiCreateAllocation;
//  PVOID                                                   DxgkDdiCreateAllocation2;
	DXGKDDI_CREATEALLOCATION2                              DxgkDdiCreateAllocation2;
	DXGKDDI_OPENALLOCATIONINFO                             DxgkDdiOpenAllocation;
	DXGKDDI_CLOSEALLOCATION                                DxgkDdiCloseAllocation;
	DXGKDDI_DESTROYALLOCATION                              DxgkDdiDestroyAllocation;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Context Section

	DXGKDDI_CREATECONTEXT                                  DxgkDdiCreateContext;
	DXGKDDI_SUSPENDCONTEXT                                 DxgkDdiSuspendContext;
	DXGKDDI_RESUMECONTEXT                                  DxgkDdiResumeContext;
	DXGKDDI_DESTROYCONTEXT                                 DxgkDdiDestroyContext;
	DXGKDDI_CREATEHWCONTEXT                                DxgkDdiCreateHwContext;
	DXGKDDI_DESTROYHWCONTEXT                               DxgkDdiDestroyHwContext;
	DXGKDDI_CREATEHWQUEUE                                  DxgkDdiCreateHwQueue;
	DXGKDDI_PRESENTTOHWQUEUE                               DxgkDdiPresentToHwQueue;
	DXGKDDI_UPDATEHWCONTEXTSTATE                           DxgkDdiUpdateHwContextState;
	DXGKDDI_SUBMITCOMMANDTOHWQUEUE                         DxgkDdiSubmitCommandToHwQueue;
	DXGKDDI_SWITCHTOHWCONTEXTLIST                          DxgkDdiSwitchToHwContextList;
	DXGKDDI_DESTROYHWQUEUE                                 DxgkDdiDestroyHwQueue;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Overlay Section

	DXGKDDI_CREATEOVERLAY                                  DxgkDdiCreateOverlay;
	DXGKDDI_UPDATEOVERLAY                                  DxgkDdiUpdateOverlay;
	DXGKDDI_FLIPOVERLAY                                    DxgkDdiFlipOverlay;
	DXGKDDI_DESTROYOVERLAY                                 DxgkDdiDestroyOverlay;
	DXGKDDI_MAPCPUHOSTAPERTURE                             DxgkDdiMapCpuHostAperture;
	DXGKDDI_UNMAPCPUHOSTAPERTURE                           DxgkDdiUnmapCpuHostAperture;
	DXGKDDI_ACQUIRESWIZZLINGRANGE                          DxgkDdiAcquireSwizzlingRange;
	DXGKDDI_RELEASESWIZZLINGRANGE                          DxgkDdiReleaseSwizzlingRange;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Exclusive Section

	DXGKDDI_CREATEPROTECTEDSESSION                         DxgkDdiCreateProtectedSession;
	DXGKDDI_DESTROYPROTECTEDSESSION                        DxgkDdiDestroyProtectedSession;
	DXGKDDI_SETVIRTUALMACHINEDATA                          DxgkDdiSetVirtualMachineData;
	DXGKDDI_BEGINEXCLUSIVEACCESS                           DxgkDdiBeginExclusiveAccess;
	DXGKDDI_ENDEXCLUSIVEACCESS                             DxgkDdiEndExclusiveAccess;
	DXGKDDI_SAVEMEMORYFORHOTUPDATE                         DxgkDdiSaveMemoryForHotUpdate;
	DXGKDDI_RESTOREMEMORYFORHOTUPDATE                      DxgkDdiRestoreMemoryForHotUpdate;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Reserved Section

	DXGKDDI_SETROOTPAGETABLE                               DxgkDdiSetRootPageTable;
	DXGKDDI_GETROOTPAGETABLESIZE                           DxgkDdiGetRootPageTableSize;
//	PVOID                                                   DxgkDdiDescribePageTable;
//	PVOID                                                   DxgkDdiUpdatePageTable;
//	PVOID                                                   DxgkDdiUpdatePageDirectory;
//	PVOID                                                   DxgkDdiMovePageDirectory;
//	PVOID                                                   Reserved;
//	PVOID                                                   Reserved1;
//	PVOID                                                   Reserved2;
//	PVOID                                                   Reserved3;
	DXGKDDI_DESCRIBEPAGETABLE                              DxgkDdiDescribePageTable;
	DXGKDDI_UPDATEPAGETABLE                                DxgkDdiUpdatePageTable;
	DXGKDDI_UPDATEPAGEDIRECTORY                            DxgkDdiUpdatePageDirectory;
	DXGKDDI_MOVEPAGEDIRECTORY                              DxgkDdiMovePageDirectory;
	DXGKDDI_RESERVED                                       DxgkDdiReserved;
	DXGKDDI_RESERVED1                                      DxgkDdiReserved1;
	DXGKDDI_RESERVED2                                      DxgkDdiReserved2;
	DXGKDDI_RESERVED3                                      DxgkDdiReserved3;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
}

#define PERI_BASE      0xFE000000   // Low-Peripheral Mode
#define MBOX_BASE      0x0000B880 + PERI_BASE
#define MBOX_MAX       0x30000000   // Highest Valid Address
#define MBOX_SIZE            0x48
#define MBOX_MTU             1500   // MTU = 1500 bytes

#define MBOX_READ               0   // 0x00
#define MBOX_PEEK               4   // 0x10
#define MBOX_SENDER             5   // 0x14 // Must not be set to 2
#define MBOX_STATUS             6   // 0x18
#define MBOX_CONFIG             7   // 0x1C
#define MBOX_WRITE              8   // 0x20
#define MBOX_PEEK2             12   // 0x30
#define MBOX_SENDER2           13   // 0x34
#define MBOX_STATUS2           14   // 0x38
#define MBOX_CONFIG2           15   // 0x3C

#define MBOX_DEFCONFIG      0x400   // Shouldn't be anything else
#define MBOX_DEFCONFIG2     0x401   // This can be 0x401 or 0x501

#define MBOX_RETRIES         1000   // times
#define MBOX_TIMEOUT          100   // microseconds

#define MBOX_REQUEST   0x00000000
#define MBOX_EMPTY     0x40000000
#define MBOX_FULL      0x80000000
#define MBOX_SUCCESS   0x80000000
#define MBOX_FAILURE   0x80000001

#define mmio_read(base, offset)           READ_REGISTER_ULONG((PULONG)(base + offset))
#define mmio_write(base, offset, value)   WRITE_REGISTER_ULONG((PULONG)(base + offset), value)

#define mbox_peek()                       mmio_read(mbox_handle, MBOX_STATUS)
#define mbox_read()                       mmio_read(mbox_handle, MBOX_READ)
#define mbox_write(addrech)               mmio_write(mbox_handle, MBOX_WRITE, addrech)

extern "C"
{
	VOID mbox_mmio_setup();
	VOID mbox_mmio_cleanup();

	UINT32 mbox_setup(BYTE channel);
	UINT32 mbox_get_num_displays();
	VOID mbox_set_display(UINT32 display);
	BOOLEAN mbox_get_display_info();

	extern PULONG            mbox_handle;
	extern __declspec(align(16)) volatile PULONG
                             mbox_packet;

	extern ULONG_PTR         dev_framebuffer1;
	extern UINT32            dev_pitchspace1;
	extern UINT32            dev_width1;
	extern UINT32            dev_height1;

	extern ULONG_PTR         dev_framebuffer2;
	extern UINT32            dev_pitchspace2;
	extern UINT32            dev_width2;
	extern UINT32            dev_height2;

	extern volatile UINT32   t1;
	extern volatile UINT32   t2;
	extern volatile UINT32   t3;
}

//--------------------------------------------------------------------------------------------------------
#pragma region //BDD Nonsense

typedef struct _BDD_FLAGS
{
	UINT32 DriverStarted : 1; // ( 1) 1 after StartDevice and 0 after StopDevice
	UINT32 EDID_Retrieved : 1; // ( 2) EDID was successfully retrieved
	UINT32 EDID_ValidChecksum : 1; // ( 3) Retrieved EDID has a valid checksum
	UINT32 EDID_ValidHeader : 1; // ( 4) Retrieved EDID has a valid header
	UINT32 EDID_Attempted : 1; // ( 5) 1 if an attempt was made to retrieve the EDID, successful or not

	// IMPORTANT: All new flags must be added to just before _LastFlag (i.e. right above this comment), this allows different versions of diagnostics to still be useful.
	UINT32 _LastFlag : 1; // ( 6) Always set to 1, is used to ensure that diagnostic version matches binary version
	UINT32 Unused : 26;
}   BDD_FLAGS, *PBDD_FLAGS, **LPBDD_FLAGS, ***RLPBDD_FLAGS, ****IRLPBDD_FLAGS, *****EIRLPBDD_FLAGS, ******VEIRLPBDD_FLAGS;

typedef struct _CURRENT_BDD_MODE
{
	// The source mode currently set for HW Framebuffer
	// For sample driver this info filled in StartDevice by the OS and never changed.
	DXGK_DISPLAY_INFORMATION DispInfo;

	// The rotation of the current mode. Rotation is performed in software during Present call
	D3DKMDT_VIDPN_PRESENT_PATH_ROTATION Rotation;

	D3DKMDT_VIDPN_PRESENT_PATH_SCALING Scaling;
	// This mode might be different from one which are supported for HW frame buffer
	// Scaling/displasment might be needed (if supported)
	UINT32 SrcModeWidth;
	UINT32 SrcModeHeight;

	// Various boolean flags the struct uses
	struct _CURRENT_BDD_MODE_FLAGS
	{
		UINT32 SourceNotVisible : 1; // 0 if source is visible
		UINT32 FullscreenPresent : 1; // 0 if should use dirty rects for present
		UINT32 FrameBufferIsActive : 1; // 0 if not currently active (i.e. target not connected to source)
		UINT32 DoNotMapOrUnmap : 1; // 1 if the FrameBuffer should not be (un)mapped during normal execution
		UINT32 IsInternal : 1; // 1 if it was determined (i.e. through ACPI) that an internal panel is being driven
		UINT32 Unused : 27;
	}   Flags;

	// The start and end of physical memory known to be all zeroes. Used to optimize the BlackOutScreen function to not write
	// zeroes to memory already known to be zero. (Physical address is located in DispInfo)
	PHYSICAL_ADDRESS ZeroedOutStart;
	PHYSICAL_ADDRESS ZeroedOutEnd;

	// Linear frame buffer pointer
	// A union with a ULONG64 is used here to ensure this struct looks the same on 32bit and 64bit builds
	// since the size of a VOID* changes depending on the build.
	union
	{
		PVOID Ptr;
		ULONG64 Force8Bytes;
	}   FrameBuffer;
}   CURRENT_BDD_MODE;

#pragma endregion
//--------------------------------------------------------------------------------------------------------

//Overrides
extern "C"
{
	DXGKDDI_ADD_DEVICE                 BddDdiAddDevice;
	DXGKDDI_LINK_DEVICE                  BddDdiLinkDevice;
	DXGKDDI_QUERY_INTERFACE              BddDdiQueryInterface;
	DXGKDDI_QUERYADAPTERINFO           BddDdiQueryAdapterInfo;
	DXGKDDI_START_DEVICE               BddDdiStartDevice;
	DXGKDDI_QUERY_CHILD_RELATIONS      BddDdiQueryChildRelations;
	DXGKDDI_QUERY_CHILD_STATUS         BddDdiQueryChildStatus; //Not Being Called...
	DXGKDDI_QUERY_DEVICE_DESCRIPTOR    BddDdiQueryDeviceDescriptor;
	DXGKDDI_RECOMMENDMONITORMODES      BddDdiRecommendMonitorModes;
	DXGKDDI_ISSUPPORTEDVIDPN           BddDdiIsSupportedVidPn;
	DXGKDDI_ENUMVIDPNCOFUNCMODALITY    BddDdiEnumVidPnCofuncModality;
	DXGKDDI_COMMITVIDPN                BddDdiCommitVidPn;
	DXGKDDI_SETVIDPNSOURCEVISIBILITY   BddDdiSetVidPnSourceVisibility;
	DXGKDDI_SETPOINTERPOSITION         BddDdiSetPointerPosition;
	DXGKDDI_PRESENT                    BddDdiPresent; ///!!!Different from BddDdiPresentDisplayOnly???

	INTERFACE_DXGKCB_EVAL_ACPI_METHOD         DxgkCbEvalAcpiMethod;
	INTERFACE_DXGKCB_GET_DEVICE_INFORMATION   DxgkCbGetDeviceInformation;
	INTERFACE_DXGKCB_INDICATE_CHILD_STATUS    DxgkCbIndicateChildStatus;
	INTERFACE_DXGKCB_MAP_MEMORY               DxgkCbMapMemory;
	INTERFACE_DXGKCB_QUEUE_DPC                DxgkCbQueueDpc;
	INTERFACE_DXGKCB_QUERY_SERVICES           DxgkCbQueryServices;
	INTERFACE_DXGKCB_READ_DEVICE_SPACE        DxgkCbReadDeviceSpace;
	INTERFACE_DXGKCB_SYNCHRONIZE_EXECUTION    DxgkCbSynchronizeExecution;
	INTERFACE_DXGKCB_UNMAP_MEMORY             DxgkCbUnmapMemory;
	INTERFACE_DXGKCB_WRITE_DEVICE_SPACE       DxgkCbWriteDeviceSpace;
	INTERFACE_DXGKCB_IS_DEVICE_PRESENT        DxgkCbIsDevicePresent;
	INTERFACE_DXGKCB_GETHANDLEDATA            DxgkCbGetHandleData;
	INTERFACE_DXGKCB_GETHANDLEPARENT          DxgkCbGetHandleParent;
	INTERFACE_DXGKCB_ENUMHANDLECHILDREN       DxgkCbEnumHandleChildren;
	INTERFACE_DXGKCB_NOTIFY_INTERRUPT         DxgkCbNotifyInterrupt;
	INTERFACE_DXGKCB_NOTIFY_DPC               DxgkCbNotifyDpc;
	INTERFACE_DXGKCB_QUERYVIDPNINTERFACE      DxgkCbQueryVidPnInterface;
	INTERFACE_DXGKCB_QUERYMONITORINTERFACE    DxgkCbQueryMonitorInterface;
	INTERFACE_DXGKCB_GETCAPTUREADDRESS        DxgkCbGetCaptureAddress;
	INTERFACE_DXGKCB_LOG_ETW_EVENT            DxgkCbLogEtwEvent;
	INTERFACE_DXGKCB_EXCLUDE_ADAPTER_ACCESS   DxgkCbExcludeAdapterAccess;

	INTERFACE_DXGKCB_CREATECONTEXTALLOCATION          DxgkCbCreateContextAllocation;
	INTERFACE_DXGKCB_DESTROYCONTEXTALLOCATION         DxgkCbDestroyContextAllocation;
	INTERFACE_DXGKCB_SETPOWERCOMPONENTACTIVE          DxgkCbSetPowerComponentActive;
	INTERFACE_DXGKCB_SETPOWERCOMPONENTIDLE            DxgkCbSetPowerComponentIdle;
	INTERFACE_DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP   DxgkCbAcquirePostDisplayOwnership;
	INTERFACE_DXGKCB_POWERRUNTIMECONTROLREQUEST       DxgkCbPowerRuntimeControlRequest;
	INTERFACE_DXGKCB_SETPOWERCOMPONENTLATENCY         DxgkCbSetPowerComponentLatency;
	INTERFACE_DXGKCB_SETPOWERCOMPONENTRESIDENCY       DxgkCbSetPowerComponentResidency;
	INTERFACE_DXGKCB_COMPLETEFSTATETRANSITION         DxgkCbCompleteFStateTransition;

	INTERFACE_DXGKCB_COMPLETEPSTATETRANSITION   DxgkCbCompletePStateTransition;

	INTERFACE_DXGKCB_MAPCONTEXTALLOCATION                DxgkCbMapContextAllocation;
	INTERFACE_DXGKCB_UPDATECONTEXTALLOCATION             DxgkCbUpdateContextAllocation;
	INTERFACE_DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE       DxgkCbReserveGpuVirtualAddressRange;
	INTERFACE_DXGKCB_ACQUIREHANDLEDATA                   DxgkCbAcquireHandleData;
	INTERFACE_DXGKCB_RELEASEHANDLEDATA                   DxgkCbReleaseHandleData;
	INTERFACE_DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN   DxgkCbHardwareContentProtectionTeardown;

	INTERFACE_DXGKCB_MULTIPLANEOVERLAYDISABLED     DxgkCbMultiPlaneOverlayDisabled;
	INTERFACE_DXGKCB_DXGKCB_MITIGATEDRANGEUPDATE   DxgkCbMitigatedRangeUpdate;

	INTERFACE_DXGKCB_INVALIDATEHWCONTEXT               DxgkCbInvalidateHwContext;
	INTERFACE_DXGKCB_INDICATE_CONNECTOR_CHANGE         DxgkCbIndicateConnectorChange;
	INTERFACE_DXGKCB_UNBLOCKUEFIFRAMEBUFFERRANGES      DxgkCbUnblockUEFIFrameBufferRanges;
	INTERFACE_DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP2   DxgkCbAcquirePostDisplayOwnership2;

	INTERFACE_DXGKCB_SETPROTECTEDSESSIONSTATUS   DxgkCbSetProtectedSessionStatus;

	INTERFACE_DXGKCB_ALLOCATECONTIGUOUSMEMORY   DxgkCbAllocateContiguousMemory;
	INTERFACE_DXGKCB_FREECONTIGUOUSMEMORY       DxgkCbFreeContiguousMemory;
	INTERFACE_DXGKCB_ALLOCATEPAGESFORMDL        DxgkCbAllocatePagesForMdl;
	INTERFACE_DXGKCB_FREEPAGESFROMMDL           DxgkCbFreePagesFromMdl;
	INTERFACE_DXGKCB_PINFRAMEBUFFERFORSAVE      DxgkCbPinFrameBufferForSave;
	INTERFACE_DXGKCB_UNPINFRAMEBUFFERFORSAVE    DxgkCbUnpinFrameBufferForSave;
	INTERFACE_DXGKCB_MAPFRAMEBUFFERPOINTER      DxgkCbMapFrameBufferPointer;
	INTERFACE_DXGKCB_UNMAPFRAMEBUFFERPOINTER    DxgkCbUnmapFrameBufferPointer;
	INTERFACE_DXGKCB_MAPMDLTOIOMMU              DxgkCbMapMdlToIoMmu;
	INTERFACE_DXGKCB_UNMAPMDLFROMIOMMU          DxgkCbUnmapMdlFromIoMmu;
	INTERFACE_DXGKCB_REPORT_DIAGNOSTIC          DxgkCbReportDiagnostic;

	INTERFACE_DXGKCB_SIGNALEVENT   DxgkCbSignalEvent;

	INTERFACE_DXGKCB_ISFEATUREENABLED         DxgkCbIsFeatureEnabled;
	INTERFACE_DXGKCB_SAVEMEMORYFORHOTUPDATE   DxgkCbSaveMemoryForHotUpdate;

	extern PVOID pBDD;
	
	extern D3DDDI_VIDEO_PRESENT_SOURCE_ID m_SourceId;
	extern BOOLEAN m_SynchExecution;
	extern KEVENT m_hThreadStartupEvent;
	extern KEVENT m_hThreadSuspendEvent;
	
	extern PDEVICE_OBJECT m_PhysicalDevice;
	extern DEVICE_POWER_STATE m_MonitorPowerState;
	extern DEVICE_POWER_STATE m_AdapterPowerState;
	
	extern BDD_FLAGS m_Flags;
	extern DXGKRNL_INTERFACE m_DxgkInterface;
	extern DXGK_START_INFO m_StartInfo;
	extern CURRENT_BDD_MODE m_CurrentMode;
	extern DXGK_DEVICE_INFO m_DeviceInfo;

	extern BYTE m_EDID[128];
}

//Interfaces
extern "C"
{
	INTERFACE_I2C_REFERENCE                                  I2CInterfaceReference;
	INTERFACE_I2C_DEREFERENCE                                I2CInterfaceDereference;
	INTERFACE_I2C_TRANSMIT_DATA_TO_DISPLAY                   I2CTransmitDataToDisplay;
	INTERFACE_I2C_RECEIVE_DATA_FROM_DISPLAY                  I2CReceiveDataFromDisplay;

	INTERFACE_OPM_REFERENCE                                  OPMInterfaceReference;
	INTERFACE_OPM_DEREFERENCE                                OPMInterfaceDereference;
	INTERFACE_OPM_GET_CERTIFICATE_SIZE                       OPMGetCertificateSize;
	INTERFACE_OPM_GET_CERTIFICATE                            OPMGetCertificate;
	INTERFACE_OPM_CREATE_PROTECTED_OUTPUT                    OPMCreateProtectedOutput;
	INTERFACE_OPM_GET_RANDOM_NUMBER                          OPMGetRandomNumber;
	INTERFACE_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS       OPMSetSigningKeyAndSequenceNumbers;
	INTERFACE_OPM_GET_INFORMATION                            OPMGetInformation;
	INTERFACE_OPM_GET_COPP_COMPATIBLE_INFORMATION            OPMGetCOPPCompatibleInformation;
	INTERFACE_OPM_CONFIGURE_PROTECTED_OUTPUT                 OPMConfigureProtectedOutput;
	INTERFACE_OPM_DESTROY_PROTECTED_OUTPUT                   OPMDestroyProtectedOutput;
	INTERFACE_OPM_CREATE_PROTECTED_OUTPUT_NONLOCAL_DISPLAY   OPMCreateProtectedOutputNonLocalDisplay;
	INTERFACE_OPM_SET_SRM_LIST                               OPMSetSrmList;
	INTERFACE_OPM_GET_SRM_LIST_VERSION                       OPMGetSrmListVersion;

	INTERFACE_MIRACAST_REFERENCE                             MiracastInterfaceReference;
	INTERFACE_MIRACAST_DEREFERENCE                           MiracastInterfaceDereference;
	INTERFACE_MIRACAST_QUERY_CAPS                            MiracastQueryCaps;
	INTERFACE_MIRACAST_CREATE_CONTEXT                        MiracastCreateContext;
	INTERFACE_MIRACAST_HANDLE_IO_CONTROL                     MiracastIoControl;
	INTERFACE_MIRACAST_DESTROY_CONTEXT                       MiracastDestroyContext;
}

#endif//_DRIVER_HXX_