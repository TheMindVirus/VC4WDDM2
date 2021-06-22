#include "DRIVER.HXX"

//--------------------------------------------------------------------------------------------------------
#pragma region //Device Section

//DXGKDDI_CREATEDEVICE
NTSTATUS APIENTRY DxgkDdiCreateDevice
(
	IN_CONST_HANDLE               hAdapter,
	INOUT_PDXGKARG_CREATEDEVICE   pCreateDevice
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCreateDevice);
}

//DXGKDDI_ADD_DEVICE
NTSTATUS DxgkDdiAddDevice
(
	IN_CONST_PDEVICE_OBJECT   PhysicalDeviceObject,
	OUT_PPVOID                MiniportDeviceContext
)
{
	debug("[CALL]: NTSTATUS DxgkDdiAddDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(PhysicalDeviceObject);
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_LINK_DEVICE
NTSTATUS DxgkDdiLinkDevice
(
	IN_CONST_PDEVICE_OBJECT   PhysicalDeviceObject,
	IN_CONST_PVOID            MiniportDeviceContext,
	INOUT_PLINKED_DEVICE      LinkedDevice
)
{
	debug("[CALL]: NTSTATUS DxgkDdiLinkDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(PhysicalDeviceObject);
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(LinkedDevice);
}

//DXGKDDI_START_DEVICE
NTSTATUS DxgkDdiStartDevice
(
	IN_CONST_PVOID          MiniportDeviceContext,
	IN_PDXGK_START_INFO     DxgkStartInfo,
	IN_PDXGKRNL_INTERFACE   DxgkInterface,
	OUT_PULONG              NumberOfVideoPresentSources,
	OUT_PULONG              NumberOfChildren
)
{
	debug("[CALL]: NTSTATUS DxgkDdiStartDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(DxgkStartInfo);
	UNREFERENCED_PARAMETER(DxgkInterface);
	UNREFERENCED_PARAMETER(NumberOfVideoPresentSources);
	UNREFERENCED_PARAMETER(NumberOfChildren);
}

//DXGKDDI_RESET_DEVICE
VOID DxgkDdiResetDevice
(
	IN_CONST_PVOID   MiniportDeviceContext
)
{
	debug("[CALL]: VOID DxgkDdiResetDevice");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_STOP_DEVICE
NTSTATUS DxgkDdiStopDevice
(
	IN_CONST_PVOID   MiniportDeviceContext
)
{
	debug("[CALL]: NTSTATUS DxgkDdiStopDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_REMOVE_DEVICE
NTSTATUS DxgkDdiRemoveDevice
(
	IN_CONST_PVOID   MiniportDeviceContext
)
{
	debug("[CALL]: NTSTATUS DxgkDdiRemoveDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_DESTROYDEVICE
NTSTATUS APIENTRY DxgkDdiDestroyDevice
(
	IN_CONST_HANDLE   hDevice
)
{
	debug("[CALL]: NTSTATUS DxgkDdiDestroyDevice");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
}

//DXGKDDI_UNLOAD
VOID DxgkDdiUnload
(
	VOID
)
{
	debug("[CALL]: VOID DxgkDdiUnloadDevice");
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Present Section

//DXGKDDI_PRESENT
NTSTATUS APIENTRY DxgkDdiPresent
(
	IN_CONST_HANDLE          hContext,
	INOUT_PDXGKARG_PRESENT   pPresent
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPresent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pPresent);
}

//DXGKDDI_RENDER
NTSTATUS APIENTRY DxgkDdiRender
(
	IN_CONST_HANDLE         hContext,
	INOUT_PDXGKARG_RENDER   pRender
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRender");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pRender);
}

//DXGKDDI_RENDER
NTSTATUS APIENTRY DxgkDdiRenderKm
(
	IN_CONST_HANDLE         hContext,
	INOUT_PDXGKARG_RENDER   pRender
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRenderKm");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pRender);
}

//DXGKDDI_RENDERGDI
NTSTATUS APIENTRY DxgkDdiRenderGdi
(
	IN_CONST_HANDLE            hContext,
	INOUT_PDXGKARG_RENDERGDI   pRenderGdi
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRenderGdi");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pRenderGdi);
}

//DXGKDDI_SUBMITRENDER (Reserved)
//PVOID DxgkDdiSubmitRender = NULL;
NTSTATUS DxgkDdiSubmitRender
(
    IN_CONST_HANDLE               hContext,
//	INOUT_PDXGKARG_SUBMITRENDER   pSubmitRender
    PVOID                         pSubmitRender
)
{
	debug("[CALL]: NTSTATUS DxgkDdiSubmitRender");
	return STATUS_ABANDONED;
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pSubmitRender);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Command Section

//DXGKDDI_PATCH
NTSTATUS APIENTRY DxgkDdiPatch
(
	IN_CONST_HANDLE           hAdapter,
	IN_CONST_PDXGKARG_PATCH   pPatch
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPatch");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pPatch);
}

//DXGKDDI_PREEMPTCOMMAND
NTSTATUS APIENTRY DxgkDdiPreemptCommand
(
	IN_CONST_HANDLE                    hAdapter,
	IN_CONST_PDXGKARG_PREEMPTCOMMAND   pPreemptCommand
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPreemptCommand");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pPreemptCommand);
}

//DXGKDDI_SUBMITCOMMAND
NTSTATUS APIENTRY DxgkDdiSubmitCommand
(
	IN_CONST_HANDLE                   hAdapter,
	IN_CONST_PDXGKARG_SUBMITCOMMAND   pSubmitCommand
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSubmitCommand");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSubmitCommand);
}

//DXGKDDI_SUBMITCOMMANDVIRTUAL
NTSTATUS APIENTRY DxgkDdiSubmitCommandVirtual
(
	IN_CONST_HANDLE                          hAdapter,
	IN_CONST_PDXGKARG_SUBMITCOMMANDVIRTUAL   pSubmitCommand
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSubmitCommandVirtual");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSubmitCommand);
}

//DXGKDDI_VALIDATESUBMITCOMMAND
NTSTATUS APIENTRY DxgkDdiValidateSubmitCommand
(
	IN_CONST_HANDLE                        hContext,
	INOUT_PDXGKARG_VALIDATESUBMITCOMMAND   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiValidateSubmitCommand");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_CANCELCOMMAND
NTSTATUS APIENTRY DxgkDdiCancelCommand
(
	IN_CONST_HANDLE                   hAdapter,
	IN_CONST_PDXGKARG_CANCELCOMMAND   pCancelCommand
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCancelCommand");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCancelCommand);
}

//DXGKDDI_BUILDPAGINGBUFFER
NTSTATUS APIENTRY DxgkDdiBuildPagingBuffer
(
	IN_CONST_HANDLE                 hAdapter,
	IN_PDXGKARG_BUILDPAGINGBUFFER   pBuildPagingBuffer
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiBuildPagingBuffer");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pBuildPagingBuffer);
}

//DXGKDDI_RESETFROMTIMEOUT
NTSTATUS APIENTRY CALLBACK DxgkDdiResetFromTimeout
(
	IN_CONST_HANDLE   hAdapter
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkDdiResetFromTimeout");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
}

//DXGKDDI_RESTARTFROMTIMEOUT
NTSTATUS APIENTRY CALLBACK DxgkDdiRestartFromTimeout
(
	IN_CONST_HANDLE   hAdapter
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkDdiRestartFromTimeout");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
}

//DXGKDDI_ESCAPE
NTSTATUS APIENTRY DxgkDdiEscape
(
	IN_CONST_HANDLE            hAdapter,
	IN_CONST_PDXGKARG_ESCAPE   pEscape
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiEscape");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pEscape);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Calibration Section

//DXGKDDI_EXCHANGEPRESTARTINFO
NTSTATUS DxgkDdiExchangePreStartInfo
(
	IN_CONST_HANDLE               hAdapter,
	IN_OUT_PDXGK_PRE_START_INFO   pPreStartInfo
)
{
	debug("[CALL]: NTSTATUS DxgkDdiExchangePreStartInfo");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pPreStartInfo);
}

//DXGKDDI_FORMATHISTORYBUFFER
NTSTATUS APIENTRY DxgkDdiFormatHistoryBuffer
(
	IN_CONST_HANDLE                   hContext,
	IN DXGKARG_FORMATHISTORYBUFFER*   pFormatData
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiFormatHistoryBuffer");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pFormatData);
}

//DXGKDDI_CONTROLDIAGNOSTICREPORTING
NTSTATUS APIENTRY DxgkDdiControlDiagnosticReporting
(
	IN_CONST_PVOID                           MiniportDeviceContext,
	IN_PDXGKARG_CONTROLDIAGNOSTICREPORTING   pArgControlDiagnosticReporting
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiControlDiagnosticReporting");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(pArgControlDiagnosticReporting);
}

//DXGKDDI_COLLECTDIAGNOSTICINFO
NTSTATUS APIENTRY DxgkDdiCollectDiagnosticInfo
(
	IN_CONST_PDEVICE_OBJECT                PhysicalDeviceObject,
	INOUT_PDXGKARG_COLLECTDIAGNOSTICINFO   pCollectDiagnosticInfo
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCollectDiagnosticInfo");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(PhysicalDeviceObject);
	UNREFERENCED_PARAMETER(pCollectDiagnosticInfo);
}

//DXGKDDI_CALIBRATEGPUCLOCK
NTSTATUS APIENTRY DxgkDdiCalibrateGpuClock
(
	IN_CONST_HANDLE                  hAdapter,
	IN UINT32                        NodeOrdinal,
	IN UINT32                        EngineOrdinal,
	OUT_PDXGKARG_CALIBRATEGPUCLOCK   pClockCalibration
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCalibrateGpuClock");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(NodeOrdinal);
	UNREFERENCED_PARAMETER(EngineOrdinal);
	UNREFERENCED_PARAMETER(pClockCalibration);
}

//DXGKDDI_CONTROLMODEBEHAVIOR
NTSTATUS APIENTRY DxgkDdiControlModeBehavior
(
	IN_CONST_HANDLE                      hAdapter,
	INOUT_PDXGKARG_CONTROLMODEBEHAVIOR   pControlModeBehaviorArg
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiControlModeBehavior");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pControlModeBehaviorArg);
}

//DXGKDDI_UPDATEMONITORLINKINFO
NTSTATUS APIENTRY DxgkDdiUpdateMonitorLinkInfo
(
	IN_CONST_HANDLE                        hAdapter,
	INOUT_PDXGKARG_UPDATEMONITORLINKINFO   pUpdateMonitorLinkInfoArg
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiUpdateMonitorLinkInfo");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUpdateMonitorLinkInfoArg);
}

//DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY
NTSTATUS APIENTRY DxgkDdiValidateUpdateAllocationProperty
(
	IN_CONST_HANDLE                                 hAdapter,
	IN_CONST_PDXGKARG_VALIDATEUPDATEALLOCPROPERTY   pValidateUpdateAllocProperty
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiValidateUpdateAllocationProperty");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pValidateUpdateAllocProperty);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Calibration Section

//DXGKDDI_SETUPPRIORITYBANDS
NTSTATUS APIENTRY DxgkDdiSetupPriorityBands
(
	IN_CONST_HANDLE                        hAdapter,
	IN_CONST_PDXGKARG_SETUPPRIORITYBANDS   pSetupPriorityBands
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetupPriorityBands");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetupPriorityBands);
}

//DXGKDDI_SETCONTEXTSCHEDULINGPROPERTIES
NTSTATUS APIENTRY DxgkDdiSetContextSchedulingProperties
(
	IN_CONST_HANDLE                                    hAdapter,
	IN_CONST_PDXGKARG_SETCONTEXTSCHEDULINGPROPERTIES   pSetContextSchedulingProperties
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetContextSchedulingProperties");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetContextSchedulingProperties);
}

//DXGKDDI_SETSCHEDULINGLOGBUFFER
NTSTATUS APIENTRY DxgkDdiSetSchedulingLogBuffer
(
	IN_CONST_HANDLE                            hAdapter,
	IN_CONST_PDXGKARG_SETSCHEDULINGLOGBUFFER   pSetSchedulingLogBuffer
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetSchedulingLogBuffer");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetSchedulingLogBuffer);
}

//DXGKDDI_SETTARGETGAMMA
NTSTATUS APIENTRY DxgkDdiSetTargetGamma
(
	IN_CONST_HANDLE                    hAdapter,
	IN_CONST_PDXGKARG_SETTARGETGAMMA   pSetTargetGammaArg
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTargetGamma");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetTargetGammaArg);
}

//DXGKDDI_SETTARGETCONTENTTYPE
NTSTATUS APIENTRY DxgkDdiSetTargetContentType
(
	IN_CONST_HANDLE                          hAdapter,
	IN_CONST_PDXGKARG_SETTARGETCONTENTTYPE   pSetTargetContentTypeArg
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTargetContentType");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetTargetContentTypeArg);
}

//DXGKDDI_SETTARGETANALOGCOPYPROTECTION
NTSTATUS APIENTRY DxgkDdiSetTargetAnalogCopyProtection
(
	IN_CONST_HANDLE                                   hAdapter,
	IN_CONST_PDXGKARG_SETTARGETANALOGCOPYPROTECTION   pSetTargetAnalogCopyProtectionArg
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTargetAnalogCopyProtection");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetTargetAnalogCopyProtectionArg);
}

//DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY
NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry
(
	IN_CONST_HANDLE                     hAdapter,
	IN D3DDDI_VIDEO_PRESENT_TARGET_ID   TargetId,
	IN DXGK_COLORIMETRY                 AdjustedColorimetry
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(TargetId);
	UNREFERENCED_PARAMETER(AdjustedColorimetry);
}

//DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2
NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry2
(
	IN_CONST_HANDLE                             hAdapter,
	IN_PDXGKARG_SETTARGETADJUSTEDCOLORIMETRY2   pArgSetTargetAdjustedColorimetry
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry2");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgSetTargetAdjustedColorimetry);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Section

//DXGKDDI_SETPALETTE
NTSTATUS APIENTRY DxgkDdiSetPalette
(
	IN_CONST_HANDLE                hAdapter,
	IN_CONST_PDXGKARG_SETPALETTE   pSetPalette
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetPalette");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetPalette);
}

//DXGKDDI_SETPOINTERPOSITION
NTSTATUS APIENTRY DxgkDdiSetPointerPosition
(
	IN_CONST_HANDLE                        hAdapter,
	IN_CONST_PDXGKARG_SETPOINTERPOSITION   pSetPointerPosition
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetPointerPosition");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetPointerPosition);
}

//DXGKDDI_SETPOINTERSHAPE
NTSTATUS APIENTRY DxgkDdiSetPointerShape
(
	IN_CONST_HANDLE                     hAdapter,
	IN_CONST_PDXGKARG_SETPOINTERSHAPE   pSetPointerShape
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetPointerShape");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetPointerShape);
}

//DXGKDDI_SET_POWER_STATE
NTSTATUS DxgkDdiSetPowerState
(
	IN_CONST_PVOID          MiniportDeviceContext,
	IN_ULONG                DeviceUid,
	IN_DEVICE_POWER_STATE   DevicePowerState,
	IN_POWER_ACTION         ActionType
)
{
	debug("[CALL]: NTSTATUS DxgkDdiSetPowerState");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(DeviceUid);
	UNREFERENCED_PARAMETER(DevicePowerState);
	UNREFERENCED_PARAMETER(ActionType);
}

//DXGKDDISETPOWERPSTATE
NTSTATUS APIENTRY DxgkDdiSetPowerPState
(
	IN_CONST_HANDLE   DriverContext,
	UINT              ComponentIndex,
	UINT              RequestedComponentPState
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetPowerPState");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(ComponentIndex);
	UNREFERENCED_PARAMETER(RequestedComponentPState);
}

//DXGKDDISETPOWERCOMPONENTFSTATE
NTSTATUS APIENTRY DxgkDdiSetPowerComponentFState
(
	IN_CONST_HANDLE   DriverContext,
	UINT              ComponentIndex,
	UINT              FState
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetPowerComponentFState");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(ComponentIndex);
	UNREFERENCED_PARAMETER(FState);
}

//DXGKDDI_SETSTABLEPOWERSTATE
VOID APIENTRY DxgkDdiSetStablePowerState
(
	IN_CONST_HANDLE                         hAdapter,
	IN_CONST_PDXGKARG_SETSTABLEPOWERSTATE   pArgs
)
{
	debug("[CALL]: VOID APIENTRY DxgkDdiSetStablePowerState");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL
NTSTATUS APIENTRY DxgkDdiSetTrackedWorkloadPowerLevel
(
	IN_CONST_HANDLE                               hContext,
	INOUT_PDXGKARG_SETTRACKEDWORKLOADPOWERLEVEL   pTrackedWorkloadPowerLevel
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTrackedWorkloadPowerLevel");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pTrackedWorkloadPowerLevel);
}

//DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT
NTSTATUS APIENTRY DxgkDdiSetDisplayPrivateDriverFormat
(
	IN_CONST_HANDLE                                   hAdapter,
	IN_CONST_PDXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT   pSetDisplayPrivateDriverFormat
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetDisplayPrivateDriverFormat");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetDisplayPrivateDriverFormat);
}

//DXGKDDI_SETVIDEOPROTECTEDREGION
NTSTATUS APIENTRY DxgkDdiSetVideoProtectedRegion
(
	IN_CONST_HANDLE                             hAdapter,
	IN_CONST_PDXGKARG_SETVIDEOPROTECTEDREGION   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVideoProtectedRegion");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Get Section

//DXGKDDI_GETSCANLINE
NTSTATUS APIENTRY DxgkDdiGetScanLine
(
	IN_CONST_HANDLE              hAdapter,
	INOUT_PDXGKARG_GETSCANLINE   pGetScanLine
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiGetScanLine");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pGetScanLine);
}

//DXGKDDI_GETNODEMETADATA
NTSTATUS APIENTRY DxgkDdiGetNodeMetadata
(
	IN_CONST_HANDLE                hAdapter,
	UINT                           NodeOrdinalAndAdapterIndex, //WDDMv2: High word is physical adapter index, low word is node ordinal
	OUT_PDXGKARG_GETNODEMETADATA   pGetNodeMetadata
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiGetNodeMetadata");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(NodeOrdinalAndAdapterIndex);
	UNREFERENCED_PARAMETER(pGetNodeMetadata);
}

//DXGKDDI_GET_CHILD_CONTAINER_ID
NTSTATUS DxgkDdiGetChildContainerId
(
	_In_ PVOID                         MiniportDeviceContext,
	_In_ ULONG                         ChildUid,
	_Inout_ PDXGK_CHILD_CONTAINER_ID   ContainerId
)
{
	debug("[CALL]: NTSTATUS DxgkDdiGetChildContainerId");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildUid);
	UNREFERENCED_PARAMETER(ContainerId);
}

//DXGKDDI_GETPOSTCOMPOSITIONCAPS
NTSTATUS APIENTRY DxgkDdiGetPostCompositionCaps
(
	IN_CONST_HANDLE                          hAdapter,
	IN_OUT_PDXGKARG_GETPOSTCOMPOSITIONCAPS   pGetPostCompositionCaps
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiGetPostCompositionCaps");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pGetPostCompositionCaps);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Notify Section

//DXGKDDI_NOTIFY_ACPI_EVENT
NTSTATUS DxgkDdiNotifyAcpiEvent
(
	IN_CONST_PVOID       MiniportDeviceContext,
	IN_DXGK_EVENT_TYPE   EventType,
	IN_ULONG             Event,
	IN_PVOID             Argument,
	OUT_PULONG           AcpiFlags
)
{
	debug("[CALL]: NTSTATUS DxgkDdiNotifyAcpiEvent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(EventType);
	UNREFERENCED_PARAMETER(Event);
	UNREFERENCED_PARAMETER(Argument);
	UNREFERENCED_PARAMETER(AcpiFlags);
}

//DXGKDDI_NOTIFYFOCUSPRESENT
NTSTATUS APIENTRY DxgkDdiNotifyFocusPresent
(
	IN_CONST_HANDLE   hAdapter
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiNotifyFocusParent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
}

//DXGKDDI_NOTIFY_SURPRISE_REMOVAL
NTSTATUS DxgkDdiNotifySurpriseRemoval
(
	_In_ PVOID                        MiniportDeviceContext,
	_In_ DXGK_SURPRISE_REMOVAL_TYPE   RemovalType
)
{
	debug("[CALL]: NTSTATUS DxgkDdiNotifySurpriseRemoval");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(RemovalType);
}

//DXGKDDIPOWERRUNTIMECONTROLREQUEST
NTSTATUS APIENTRY DxgkDdiPowerRuntimeControlRequest
(
	IN_CONST_HANDLE        DriverContext,
	IN LPCGUID             PowerControlCode,
	IN OPTIONAL PVOID      InBuffer,
	IN SIZE_T              InBufferSize,
	OUT OPTIONAL PVOID     OutBuffer,
	IN SIZE_T              OutBufferSize,
	OUT OPTIONAL PSIZE_T   BytesReturned
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPowerRuntimeControlRequest");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(PowerControlCode);
	UNREFERENCED_PARAMETER(InBuffer);
	UNREFERENCED_PARAMETER(InBufferSize);
	UNREFERENCED_PARAMETER(OutBuffer);
	UNREFERENCED_PARAMETER(OutBufferSize);
	UNREFERENCED_PARAMETER(BytesReturned);
}

//DXGKDDI_POWERRUNTIMESETDEVICEHANDLE
NTSTATUS APIENTRY DxgkDdiPowerRuntimeSetDeviceHandle
(
	IN_CONST_HANDLE   DriverContext,
	IN HANDLE         PoDeviceHandle
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPowerRuntimeSetDeviceHandle");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(PoDeviceHandle);
}

//DXGKDDI_CREATEPERIODICFRAMENOTIFICATION
NTSTATUS APIENTRY DxgkDdiCreatePeriodicFrameNotification
(
	INOUT_PDXGKARG_CREATEPERIODICFRAMENOTIFICATION   pCreatePeriodicFrameNotification
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreatePeriodicFrameNotification");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pCreatePeriodicFrameNotification);
}

//DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION
NTSTATUS APIENTRY DxgkDdiDestroyPeriodicFrameNotification
(
	IN_CONST_PDXGKARG_DESTROYPERIODICFRAMENOTIFICATION   pDestroyPeriodicFrameNotification
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyPeriodicFrameNotification");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pDestroyPeriodicFrameNotification);
}

//DXGKDDI_SIGNALMONITOREDFENCE
NTSTATUS APIENTRY DxgkDdiSignalMonitoredFence
(
	IN_CONST_HANDLE                       hContext,
	INOUT_PDXGKARG_SIGNALMONITOREDFENCE   pSignalMonitoredFence
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSignalMonitoredFence");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pSignalMonitoredFence);
}

//DXGKDDI_DISPLAYDETECTCONTROL
NTSTATUS APIENTRY DxgkDdiDisplayDetectControl
(
	IN_CONST_HANDLE                          hAdapter,
	IN_CONST_PDXGKARG_DISPLAYDETECTCONTROL   pDisplayDetectControl
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDisplayDetectControl");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pDisplayDetectControl);
}

//DXGKDDI_RECOMMENDMONITORMODES
NTSTATUS APIENTRY DxgkDdiRecommendMonitorModes
(
	IN_CONST_HANDLE                                 hAdapter,
	IN_CONST_PDXGKARG_RECOMMENDMONITORMODES_CONST   pRecommendMonitorModes
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRecommendMonitorModes");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pRecommendMonitorModes);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Query Section

//DXGKDDI_QUERY_INTERFACE
NTSTATUS DxgkDdiQueryInterface
(
	IN_CONST_PVOID        MiniportDeviceContext,
	IN_PQUERY_INTERFACE   QueryInterface
)
{
	debug("[CALL]: NTSTATUS DxgkDdiQueryInterface");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(QueryInterface);
}

//DXGKDDI_QUERYADAPTERINFO
NTSTATUS APIENTRY DxgkDdiQueryAdapterInfo
(
	IN_CONST_HANDLE                      hAdapter,
	IN_CONST_PDXGKARG_QUERYADAPTERINFO   pQueryAdapterInfo
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryAdapterInfo");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pQueryAdapterInfo);
}

//DXGKDDI_QUERYCURRENTFENCE
NTSTATUS APIENTRY DxgkDdiQueryCurrentFence
(
	IN_CONST_HANDLE                    hAdapter,
	INOUT_PDXGKARG_QUERYCURRENTFENCE   pCurrentFence
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryCurrentFence");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCurrentFence);
}

//DXGKDDI_QUERY_DEVICE_DESCRIPTOR
NTSTATUS DxgkDdiQueryDeviceDescriptor
(
	IN_CONST_PVOID                  MiniportDeviceContext,
	IN_ULONG                        ChildUid,
	INOUT_PDXGK_DEVICE_DESCRIPTOR   DeviceDescriptor
)
{
	debug("[CALL]: NTSTATUS DxgkDdiQueryDeviceDescriptor");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildUid);
	UNREFERENCED_PARAMETER(DeviceDescriptor);
}

//DXGKDDI_QUERYVIDPNHWCAPABILITY
NTSTATUS APIENTRY DxgkDdiQueryVidPnHWCapability
(
	IN_CONST_HANDLE                         i_hAdapter,
	INOUT_PDXGKARG_QUERYVIDPNHWCAPABILITY   io_pVidPnHWCaps
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryVidPnHWCapability");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(i_hAdapter);
	UNREFERENCED_PARAMETER(io_pVidPnHWCaps);
}

//DXGKDDI_QUERY_CHILD_RELATIONS
NTSTATUS DxgkDdiQueryChildRelations
(
	IN_CONST_PVOID                                                     MiniportDeviceContext,
	_Inout_updates_bytes_(ChildRelationsSize) PDXGK_CHILD_DESCRIPTOR   ChildRelations,        //SAL 2.0 Annotation
	_In_ ULONG                                                         ChildRelationsSize
)
{
	debug("[CALL]: NTSTATUS DxgkDdiQueryChildRelations");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildRelations);
	UNREFERENCED_PARAMETER(ChildRelationsSize);
}

//DXGKDDI_QUERY_CHILD_STATUS
NTSTATUS DxgkDdiQueryChildStatus
(
	IN_CONST_PVOID             MiniportDeviceContext,
	INOUT_PDXGK_CHILD_STATUS   ChildStatus,
	IN_BOOLEAN                 NonDestructiveOnly
)
{
	debug("[CALL]: NTSTATUS DxgkDdiQueryChildStatus");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildStatus);
	UNREFERENCED_PARAMETER(NonDestructiveOnly);
}

//DXGKDDI_QUERYCONNECTIONCHANGE
NTSTATUS APIENTRY DxgkDdiQueryConnectionChange
(
	IN_CONST_HANDLE                     hAdapter,
	IN_PDXGKARG_QUERYCONNECTIONCHANGE   pQueryConnectionChange
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryConnectionChange");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pQueryConnectionChange);
}

//DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT
NTSTATUS APIENTRY DxgkDdiQueryDiagnosticTypesSupport
(
	IN_CONST_PVOID                               MiniportDeviceContext,
	INOUT_PDXGKARG_QUERYDIAGNOSTICTYPESSUPPORT   pArgQueryDiagnosticTypesSupport
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryDiagnosticTypesSupport");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(pArgQueryDiagnosticTypesSupport);
}

//DXGKDDI_QUERYDEPENDENTENGINEGROUP
NTSTATUS APIENTRY DxgkDdiQueryDependentEngineGroup
(
	IN_CONST_HANDLE                           hAdapter,
	INOUT_DXGKARG_QUERYDEPENDENTENGINEGROUP   pQueryDependentEngineGroup
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryDependentEngineGroup");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pQueryDependentEngineGroup);
}

//DXGKDDI_QUERYENGINESTATUS
NTSTATUS APIENTRY DxgkDdiQueryEngineStatus
(
	IN_CONST_HANDLE                    hAdapter,
	INOUT_PDXGKARG_QUERYENGINESTATUS   pQueryEngineStatus
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiQueryEngineStatus");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pQueryEngineStatus);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Video Present Network (VidPn) Section

//DXGKDDI_COMMITVIDPN
NTSTATUS APIENTRY DxgkDdiCommitVidPn
(
	IN_CONST_HANDLE                       hAdapter,
	IN_CONST_PDXGKARG_COMMITVIDPN_CONST   pCommitVidPn
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCommitVidPn");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCommitVidPn);
}

//DXGKDDI_ISSUPPORTEDVIDPN
NTSTATUS APIENTRY DxgkDdiIsSupportedVidPn
(
	IN_CONST_HANDLE                   hAdapter,
	INOUT_PDXGKARG_ISSUPPORTEDVIDPN   pIsSupportedVidPn
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiIsSupportedVidPn");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pIsSupportedVidPn);
}

//DXGKDDI_ENUMVIDPNCOFUNCMODALITY
NTSTATUS APIENTRY DxgkDdiEnumVidPnCofuncModality
(
	IN_CONST_HANDLE                                   hAdapter,
	IN_CONST_PDXGKARG_ENUMVIDPNCOFUNCMODALITY_CONST   pEnumCofuncModality
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiEnumVidPnCofuncModality");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pEnumCofuncModality);
}

//DXGKDDI_RECOMMENDFUNCTIONALVIDPN
NTSTATUS APIENTRY DxgkDdiRecommendFunctionalVidPn
(
	IN_CONST_HANDLE                                    hAdapter,
	IN_CONST_PDXGKARG_RECOMMENDFUNCTIONALVIDPN_CONST   pRecommendFunctionalVidPn
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRecommendFunctionalVidPn");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pRecommendFunctionalVidPn);
}

//DXGKDDI_GETMULTIPLANEOVERLAYCAPS
NTSTATUS APIENTRY DxgkDdiGetMultiPlaneOverlayCaps
(
	IN_CONST_HANDLE                            hAdapter,
	IN_OUT_PDXGKARG_GETMULTIPLANEOVERLAYCAPS   pGetMultiPlaneOverlayCaps
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiGetMultiPlaneOverCaps");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pGetMultiPlaneOverlayCaps);
}

//DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT
NTSTATUS APIENTRY DxgkDdiPostMultiPlaneOverlayPresent
(
	IN_CONST_HANDLE                                  hAdapter,
	IN_CONST_PDXGKARG_POSTMULTIPLANEOVERLAYPRESENT   pPostPresent
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPostMultiPlaneOverlayPresent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pPostPresent);
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport
(
	IN_CONST_HANDLE                                 hAdapter,
	IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT   pCheckMultiPlaneOverlaySupport
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport2
(
	IN_CONST_HANDLE                                  hAdapter,
	IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2   pCheckMultiPlaneOverlaySupport
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport2");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport3
(
	IN_CONST_HANDLE                                  hAdapter,
	IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3   pCheckMultiPlaneOverlaySupport
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport3");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay
(
	IN_CONST_HANDLE                                                hAdapter,
	IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2
(
	IN_CONST_HANDLE                                                 hAdapter,
	IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVidPinSourceAddressWithMultiPlaneOverlay2");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3
(
	IN_CONST_HANDLE                                               hAdapter,
	IN_OUT_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
}

//DXGKDDI_SETVIDPNSOURCEADDRESS
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddress
(
	IN_CONST_HANDLE                           hAdapter,
	IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESS   pSetVidPnSourceAddress
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddress");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetVidPnSourceAddress);
}

//DXGKDDI_SETVIDPNSOURCEVISIBILITY
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceVisibility
(
	IN_CONST_HANDLE                              hAdapter,
	IN_CONST_PDXGKARG_SETVIDPNSOURCEVISIBILITY   pSetVidPnSourceVisibility
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVidPnSourceVisibility");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetVidPnSourceVisibility);
}

//DXGKDDI_SETTIMINGSFROMVIDPN
NTSTATUS APIENTRY DxgkDdiSetTimingsFromVidPn
(
	IN_CONST_HANDLE                       hAdapter,
	IN_OUT_PDXGKARG_SETTIMINGSFROMVIDPN   pSetTimings
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetTimingsFromVidPn");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetTimings);
}

//DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH
NTSTATUS APIENTRY DxgkDdiUpdateActiveVidPnPresentPath
(
	IN_CONST_HANDLE                                        hAdapter,
	IN_CONST_PDXGKARG_UPDATEACTIVEVIDPNPRESENTPATH_CONST   pUpdateActiveVidPnPresentPath
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiUpdateActiveVidPnPresentPath");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUpdateActiveVidPnPresentPath);
}

//DXGKDDI_RECOMMENDVIDPNTOPOLOGY
NTSTATUS APIENTRY DxgkDdiRecommendVidPnTopology
(
	IN_CONST_HANDLE                                  hAdapter,
	IN_CONST_PDXGKARG_RECOMMENDVIDPNTOPOLOGY_CONST   pRecommendVidPnTopology
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRecommendedVidPnTopology");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pRecommendVidPnTopology);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Engine Section

//DXGKDDI_RESETENGINE
NTSTATUS APIENTRY DxgkDdiResetEngine
(
	IN_CONST_HANDLE              hAdapter,
	INOUT_PDXGKARG_RESETENGINE   pResetEngine
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiResetEngine");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pResetEngine);
}

//DXGKDDI_RESUMEHWENGINE
NTSTATUS APIENTRY DxgkDdiResumeHwEngine
(
	IN_CONST_HANDLE                 hAdapter,
	INOUT_PDXGKARG_RESUMEHWENGINE   pResumeHwEngine
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiResumeHwEngine");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pResumeHwEngine);
}

//DXGKDDI_RESETHWENGINE
NTSTATUS APIENTRY DxgkDdiResetHwEngine
(
	IN_CONST_HANDLE                hAdapter,
	INOUT_PDXGKARG_RESETHWENGINE   pResetHwEngine
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiResetHwEnigine");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pResetHwEngine);
}

//DXGKDDI_CREATEPROCESS
NTSTATUS APIENTRY DxgkDdiCreateProcess
(
	IN_CONST_HANDLE                hAdapter,
	INOUT_PDXGKARG_CREATEPROCESS   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateProcess");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_DESTROYPROCESS
NTSTATUS APIENTRY DxgkDdiDestroyProcess
(
	IN_CONST_HANDLE   hAdapter,
	IN_CONST_HANDLE   hKmdProcess
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestoryProgram");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(hKmdProcess);
}

//DXGKDDI_STOPCAPTURE
NTSTATUS APIENTRY DxgkDdiStopCapture
(
	IN_CONST_HANDLE                 hAdapter,
	IN_CONST_PDXGKARG_STOPCAPTURE   pStopCapture
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiStopCapture");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pStopCapture);
}

//DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP
NTSTATUS DxgkDdiStopDeviceAndReleasePostDisplayOwnership
(
	_In_ PVOID                            MiniportDeviceContext,
	_In_ D3DDDI_VIDEO_PRESENT_TARGET_ID   TargetId,
	_Out_ PDXGK_DISPLAY_INFORMATION       DisplayInfo
)
{
	debug("[CALL]: NTSTATUS DxgkDdiStopDeviceAndReleasePostDisplayOwnership");
	DisplayInfo->Width = 1280;
	DisplayInfo->Height = 720;
	DisplayInfo->Pitch = DisplayInfo->Width * (8 * 4);
	DisplayInfo->ColorFormat = D3DDDIFMT_A8R8G8B8;
	DisplayInfo->PhysicAddress.QuadPart = 0x0;
	DisplayInfo->TargetId = 0;
	DisplayInfo->AcpiId = 0;
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(TargetId);
}

//DXGKDDI_SYSTEM_DISPLAY_ENABLE
NTSTATUS DxgkDdiSystemDisplayEnable
(
	_In_ PVOID                                  MiniportDeviceContext,
	_In_ D3DDDI_VIDEO_PRESENT_TARGET_ID         TargetId,
	_In_ PDXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS   Flags,
	_Out_ UINT* Width,
	_Out_ UINT* Height,
	_Out_ D3DDDIFORMAT* ColorFormat
)
{
	debug("[CALL]: NTSTATUS DxgkDdiSystemDisplayEnable");
	*Width = 1280;
	*Height = 720;
	*ColorFormat = D3DDDIFMT_A8R8G8B8;
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(TargetId);
	UNREFERENCED_PARAMETER(Flags);
}

//DXGKDDI_SYSTEM_DISPLAY_WRITE
VOID DxgkDdiSystemDisplayWrite
(
	_In_ PVOID                                            MiniportDeviceContext,
	_In_reads_bytes_(SourceHeight* SourceStride) PVOID    Source,                //SAL 2.0 Annotation
	_In_ UINT                                             SourceWidth,
	_In_ UINT                                             SourceHeight,
	_In_ UINT                                             SourceStride,
	_In_ UINT                                             PositionX,
	_In_ UINT                                             PositionY
)
{
	debug("[CALL]: VOID DxgkDdiSystmDisplayWrite");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(Source);
	UNREFERENCED_PARAMETER(SourceWidth);
	UNREFERENCED_PARAMETER(SourceHeight);
	UNREFERENCED_PARAMETER(SourceStride);
	UNREFERENCED_PARAMETER(PositionX);
	UNREFERENCED_PARAMETER(PositionY);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Interrupt Section

//DXGKDDI_DPC_ROUTINE
VOID DxgkDdiDpcRoutine
(
	IN_CONST_PVOID   MiniportDeviceContext
)
{
	debug("[CALL]: VOID DxgkDdiDpcRoutine");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_INTERRUPT_ROUTINE
BOOLEAN DxgkDdiInterruptRoutine
(
	IN_CONST_PVOID   MiniportDeviceContext,
	IN_ULONG         MessageNumber
)
{
	debug("[CALL]: NTSTATUS DxgkDdiInterruptRoutine");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(MessageNumber);
}

//DXGKDDI_DISPATCH_IO_REQUEST
NTSTATUS DxgkDdiDispatchIoRequest
(
	IN_CONST_PVOID             MiniportDeviceContext,
	IN_ULONG                   VidPnSourceId,
	IN_PVIDEO_REQUEST_PACKET   VideoRequestPacket
)
{
	debug("[CALL]: NTSTATUS DxgkDdiDispatchIoRequest");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(VidPnSourceId);
	UNREFERENCED_PARAMETER(VideoRequestPacket);
}

//DXGKDDI_CONTROLINTERRUPT
NTSTATUS APIENTRY DxgkDdiControlInterrupt
(
	IN_CONST_HANDLE                hAdapter,
	IN_CONST_DXGK_INTERRUPT_TYPE   InterruptType,
	IN_BOOLEAN                     EnableInterrupt
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiControlInterrupt");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(InterruptType);
	UNREFERENCED_PARAMETER(EnableInterrupt);
}

//DXGKDDI_CONTROLINTERRUPT2
NTSTATUS APIENTRY DxgkDdiControlInterrupt2
(
	IN_CONST_HANDLE                      hAdapter,
	IN_CONST_DXGKARG_CONTROLINTERRUPT2   InterruptControl
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiControlInterrupt2");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(InterruptControl);
}

//DXGKDDI_CONTROLINTERRUPT3
NTSTATUS APIENTRY DxgkDdiControlInterrupt3
(
	IN_CONST_HANDLE                       hAdapter,
	IN_CONST_PDXGKARG_CONTROLINTERRUPT3   InterruptControl
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiControlInterrupt3");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(InterruptControl);
}

//DXGKDDI_CONTROL_ETW_LOGGING
VOID DxgkDdiControlEtwLogging
(
	IN_BOOLEAN   Enable,
	IN_ULONG     Flags,
	IN_UCHAR     Level
)
{
	debug("[CALL]: VOID DxgkDdiControlEtwLogging");
	UNREFERENCED_PARAMETER(Enable);
	UNREFERENCED_PARAMETER(Flags);
	UNREFERENCED_PARAMETER(Level);
}

//DXGKDDI_COLLECTDBGINFO
NTSTATUS APIENTRY DxgkDdiCollectDbgInfo
(
	IN_CONST_HANDLE                    hAdapter,
	IN_CONST_PDXGKARG_COLLECTDBGINFO   pCollectDbgInfo
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCollectDbgInfo");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCollectDbgInfo);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Allocation Section

//DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA
NTSTATUS APIENTRY DxgkDdiGetStandardAllocationDriverData
(
	IN_CONST_HANDLE                                  hAdapter,
	INOUT_PDXGKARG_GETSTANDARDALLOCATIONDRIVERDATA   pGetStandardAllocationDriverData
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiGetStandardAllocationDriverData");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pGetStandardAllocationDriverData);
}

//DXGKDDI_DESCRIBEALLOCATION
NTSTATUS APIENTRY DxgkDdiDescribeAllocation
(
	IN_CONST_HANDLE                     hAdapter,
	INOUT_PDXGKARG_DESCRIBEALLOCATION   pDescribeAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDescribeAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pDescribeAllocation);
}

//DXGKDDI_CREATEALLOCATION
NTSTATUS APIENTRY DxgkDdiCreateAllocation
(
	IN_CONST_HANDLE                   hAdapter,
	INOUT_PDXGKARG_CREATEALLOCATION   pCreateAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCreateAllocation);
}

//DXGKDDI_CREATEALLOCATION2 (Reserved)
//PVOID DxgkDdiCreateAllocation2 = NULL;
NTSTATUS DxgkDdiCreateAllocation2
(
    IN_CONST_HANDLE                    hAdapter,
//	INOUT_PDXGKARG_CREATEALLOCATION2   pCreateAllocation
    PVOID                              pCreateAllocation
)
{
	debug("[CALL]: NTSTATUS DxgkDdiCreateAllocation2");
	return STATUS_ABANDONED;
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCreateAllocation);
}
 
//DXGKDDI_OPENALLOCATIONINFO
NTSTATUS APIENTRY DxgkDdiOpenAllocation
(
	IN_CONST_HANDLE                    hDevice,
	IN_CONST_PDXGKARG_OPENALLOCATION   pOpenAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiOpenAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
	UNREFERENCED_PARAMETER(pOpenAllocation);
}

//DXGKDDI_CLOSEALLOCATION
NTSTATUS APIENTRY DxgkDdiCloseAllocation
(
	IN_CONST_HANDLE                     hDevice,
	IN_CONST_PDXGKARG_CLOSEALLOCATION   pCloseAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCloseAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
	UNREFERENCED_PARAMETER(pCloseAllocation);
}

//DXGKDDI_DESTROYALLOCATION
NTSTATUS APIENTRY DxgkDdiDestroyAllocation
(
	IN_CONST_HANDLE                       hAdapter,
	IN_CONST_PDXGKARG_DESTROYALLOCATION   pDestroyAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pDestroyAllocation);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Context Section

//DXGKDDI_CREATECONTEXT
NTSTATUS APIENTRY DxgkDdiCreateContext
(
	IN_CONST_HANDLE                hDevice,
	INOUT_PDXGKARG_CREATECONTEXT   pCreateContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
	UNREFERENCED_PARAMETER(pCreateContext);
}

//DXGKDDI_SUSPENDCONTEXT
NTSTATUS APIENTRY DxgkDdiSuspendContext
(
	IN_CONST_HANDLE                    hAdapter,
	IN_CONST_PDXGKARG_SUSPENDCONTEXT   pSuspendContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSuspendContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSuspendContext);
}

//DXGKDDI_RESUMECONTEXT
NTSTATUS APIENTRY DxgkDdiResumeContext
(
	IN_CONST_HANDLE                   hAdapter,
	IN_CONST_PDXGKARG_RESUMECONTEXT   pResumeContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiResumeContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pResumeContext);
}

//DXGKDDI_DESTROYCONTEXT
NTSTATUS APIENTRY DxgkDdiDestroyContext
(
	IN_CONST_HANDLE   hContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
}

//DXGKDDI_CREATEHWCONTEXT
NTSTATUS APIENTRY DxgkDdiCreateHwContext
(
	IN_CONST_HANDLE                  hDevice,
	INOUT_PDXGKARG_CREATEHWCONTEXT   pCreateContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateHwContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
	UNREFERENCED_PARAMETER(pCreateContext);
}

//DXGKDDI_DESTROYHWCONTEXT
NTSTATUS APIENTRY DxgkDdiDestroyHwContext
(
	IN_CONST_HANDLE   hHwContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyHwContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hHwContext);
}

//DXGKDDI_CREATEHWQUEUE
NTSTATUS APIENTRY DxgkDdiCreateHwQueue
(
	IN_CONST_HANDLE                hHwContext,
	INOUT_PDXGKARG_CREATEHWQUEUE   pCreateHwQueue
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateHwQueue");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hHwContext);
	UNREFERENCED_PARAMETER(pCreateHwQueue);
}

//DXGKDDI_PRESENTTOHWQUEUE
NTSTATUS APIENTRY DxgkDdiPresentToHwQueue
(
	IN_CONST_HANDLE          hHwQueue,
	INOUT_PDXGKARG_PRESENT   pPresent
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiPresentToHwQueue");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hHwQueue);
	UNREFERENCED_PARAMETER(pPresent);
}

//DXGKDDI_UPDATEHWCONTEXTSTATE
NTSTATUS APIENTRY DxgkDdiUpdateHwContextState
(
	IN_CONST_HANDLE                          hAdapter,
	IN_CONST_PDXGKARG_UPDATEHWCONTEXTSTATE   pUpdateHwContextState
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiUpdateHwContextState");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUpdateHwContextState);
}

//DXGKDDI_SUBMITCOMMANDTOHWQUEUE
NTSTATUS APIENTRY DxgkDdiSubmitCommandToHwQueue
(
	IN_CONST_HANDLE                            hAdapter,
	IN_CONST_PDXGKARG_SUBMITCOMMANDTOHWQUEUE   pSubmitCommandToHwQueue
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSubmitCommandToHwQueue");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSubmitCommandToHwQueue);
}

//DXGKDDI_SWITCHTOHWCONTEXTLIST
NTSTATUS APIENTRY DxgkDdiSwitchToHwContextList
(
	IN_CONST_HANDLE                           hAdapter,
	IN_CONST_PDXGKARG_SWITCHTOHWCONTEXTLIST   pHwContextList
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSwitchToHwContextList");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pHwContextList);
}

//DXGKDDI_DESTROYHWQUEUE
NTSTATUS APIENTRY DxgkDdiDestroyHwQueue
(
	IN_CONST_HANDLE   hHwQueue
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyHwQueue");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hHwQueue);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Overlay Section

//DXGKDDI_CREATEOVERLAY
NTSTATUS APIENTRY DxgkDdiCreateOverlay
(
	IN_CONST_HANDLE                hAdapter,
	INOUT_PDXGKARG_CREATEOVERLAY   pCreateOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateOverlay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCreateOverlay);
}

//DXGKDDI_UPDATEOVERLAY
NTSTATUS APIENTRY DxgkDdiUpdateOverlay
(
	IN_CONST_HANDLE                   hOverlay,
	IN_CONST_PDXGKARG_UPDATEOVERLAY   pUpdateOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiUpdateOverlay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hOverlay);
	UNREFERENCED_PARAMETER(pUpdateOverlay);
}

//DXGKDDI_FLIPOVERLAY
NTSTATUS APIENTRY DxgkDdiFlipOverlay
(
	IN_CONST_HANDLE                 hOverlay,
	IN_CONST_PDXGKARG_FLIPOVERLAY   pFlipOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiFlipOverlay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hOverlay);
	UNREFERENCED_PARAMETER(pFlipOverlay);
}

//DXGKDDI_DESTROYOVERLAY
NTSTATUS APIENTRY DxgkDdiDestroyOverlay
(
	IN_CONST_HANDLE   hOverlay
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyOverlay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hOverlay);
}

//DXGKDDI_MAPCPUHOSTAPERTURE
NTSTATUS APIENTRY DxgkDdiMapCpuHostAperture
(
	IN_CONST_HANDLE                        hAdapter,
	IN_CONST_PDXGKARG_MAPCPUHOSTAPERTURE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiMapCpuHostAperture");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_UNMAPCPUHOSTAPERTURE
NTSTATUS APIENTRY DxgkDdiUnmapCpuHostAperture
(
	IN_CONST_HANDLE                          hAdapter,
	IN_CONST_PDXGKARG_UNMAPCPUHOSTAPERTURE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiUnmapCpuHostAperture");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_ACQUIRESWIZZLINGRANGE
NTSTATUS APIENTRY DxgkDdiAcquireSwizzlingRange
(
	IN_CONST_HANDLE                        hAdapter,
	INOUT_PDXGKARG_ACQUIRESWIZZLINGRANGE   pAcquireSwizzlingRange
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiAcquireSwizzlingRange");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pAcquireSwizzlingRange);
}

//DXGKDDI_RELEASESWIZZLINGRANGE
NTSTATUS APIENTRY DxgkDdiReleaseSwizzlingRange
(
	IN_CONST_HANDLE                           hAdapter,
	IN_CONST_PDXGKARG_RELEASESWIZZLINGRANGE   pReleaseSwizzlingRange
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiReleaseSwizzlingRange");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pReleaseSwizzlingRange);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Exclusive Section

//DXGKDDI_CREATEPROTECTEDSESSION
NTSTATUS APIENTRY DxgkDdiCreateProtectedSession
(
	IN_CONST_HANDLE                         hAdapter,
	INOUT_PDXGKARG_CREATEPROTECTEDSESSION   pCreateProtectedSession
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiCreateProtectedSession");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pCreateProtectedSession);
}

//DXGKDDI_DESTROYPROTECTEDSESSION
NTSTATUS APIENTRY DxgkDdiDestroyProtectedSession
(
	IN_CONST_HANDLE   hAdapter,
	IN_CONST_HANDLE   hProtectedSession
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiDestroyProtectedSession");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(hProtectedSession);
}

//DXGKDDI_SETVIRTUALMACHINEDATA
NTSTATUS APIENTRY DxgkDdiSetVirtualMachineData
(
	IN_CONST_HANDLE                           hAdapter,
	IN_CONST_PDXGKARG_SETVIRTUALMACHINEDATA   Args
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSetVirtualMachineData");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(Args);
}

//DXGKDDI_BEGINEXCLUSIVEACCESS
NTSTATUS APIENTRY DxgkDdiBeginExclusiveAccess
(
	IN_CONST_HANDLE                    hAdapter,
	IN_PDXGKARG_BEGINEXCLUSIVEACCESS   pBeginExclusiveAccess
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiBeginExclusiveAccess");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pBeginExclusiveAccess);
}

//DXGKDDI_ENDEXCLUSIVEACCESS
NTSTATUS APIENTRY DxgkDdiEndExclusiveAccess
(
	IN_CONST_HANDLE                  hAdapter,
	IN_PDXGKARG_ENDEXCLUSIVEACCESS   pEndExclusiveAccess
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiEndExclusiveAccess");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pEndExclusiveAccess);
}

//DXGKDDI_SAVEMEMORYFORHOTUPDATE
NTSTATUS APIENTRY DxgkDdiSaveMemoryForHotUpdate
(
	IN_CONST_HANDLE                            hContext,
	IN_CONST_PDXGKARG_SAVEMEMORYFORHOTUPDATE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiSaveMemoryForHotUpdate");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_RESTOREMEMORYFORHOTUPDATE
NTSTATUS APIENTRY DxgkDdiRestoreMemoryForHotUpdate
(
	IN_CONST_HANDLE                               hContext,
	IN_CONST_PDXGKARG_RESTOREMEMORYFORHOTUPDATE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkDdiRestoreMemoryForHotUpdate");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hContext);
	UNREFERENCED_PARAMETER(pArgs);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Reserved Section

//DXGKDDI_SETROOTPAGETABLE
VOID APIENTRY DxgkDdiSetRootPageTable
(
	IN_CONST_HANDLE                      hAdapter,
	IN_CONST_PDXGKARG_SETROOTPAGETABLE   pSetPageTable
)
{
	debug("[CALL]: VOID APIENTRY DxgkDdiSetRootPageTable");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSetPageTable);
}

//DXGKDDI_GETROOTPAGETABLESIZE
SIZE_T APIENTRY DxgkDdiGetRootPageTableSize
(
	IN_CONST_HANDLE                       hAdapter,
	INOUT_PDXGKARG_GETROOTPAGETABLESIZE   pArgs
)
{
	debug("[CALL]: SIZE_T APIENTRY DxgkDdiGetRootPageTableSize");
	return 0;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_DESCRIBEPAGETABLE (Reserved)
//PVOID DxgkDdiDescribePageTable = NULL;
NTSTATUS DxgkDdiDescribePageTable
(
    IN_CONST_HANDLE                    hDevice,
//	INOUT_PDXGKARG_DESCRIBEPAGETABLE   pDescribePageTable
	PVOID                              pDescribePageTable
)
{
	debug("[CALL]: NTSTATUS DxgkDdiDescribePageTable");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pDescribePageTable);
}

//DXGKDDI_UPDATEPAGETABLE (Reserved)
//PVOID DxgkDdiUpdatePageTable = NULL;
NTSTATUS DxgkDdiUpdatePageTable
(
    IN_CONST_HANDLE                  hDevice,
//	INOUT_PDXGKARG_UPDATEPAGETABLE   pUpdatePageTable
	PVOID                            pUpdatePageTable
)
{
	debug("[CALL]: NTSTATUS DxgkDdiUpdatePageTable");
	return STATUS_ABANDONED;
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pUpdatePageTable);
}

//DxgkDdiUpdatePageDirectory (Reserved)
//PVOID DxgkDdiUpdatePageDirectory = NULL;
NTSTATUS DxgkDdiUpdatePageDirectory
(
    IN_CONST_HANDLE                      hDevice,
//	INOUT_PDXGKARG_UPDATEPAGEDIRECTORY   pUpdatePageDirectory
	PVOID                                pUpdatePageDirectory
)
{
	debug("[CALL]: NTSTATUS DxgkDdiUpdatePageDirectory");
	return STATUS_ABANDONED;
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pUpdatePageDirectory);
}

//DxgkDdiMovePageDirectory (Reserved)
//PVOID DxgkDdiMovePageDirectory = NULL;
NTSTATUS DxgkDdiMovePageDirectory
(
    IN_CONST_HANDLE                      hContext,
//	_Inout_ DXGKARG_MOVEPAGEDIRECTORY*   pMovePageDirectory
	PVOID                                pMovePageDirectory
)
{
	debug("[CALL]: NTSTATUS DxgkDdiMovePageDirectory");
	return STATUS_ABANDONED;
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pMovePageDirectory);
}

//(Reserved)
//PVOID Reserved = NULL;
NTSTATUS DxgkDdiReserved
(
	VOID
)
{
	debug("[CALL]: NTSTATUS DxgkDdiReserved");
	return STATUS_ABANDONED;
}

//(Reserved)
//PVOID Reserved1 = NULL;
NTSTATUS DxgkDdiReserved1
(
	VOID
)
{
	debug("[CALL]: NTSTATUS DxgkDdiReserved1");
	return STATUS_ABANDONED;
}

//(Reserved)
//PVOID Reserved2 = NULL;
NTSTATUS DxgkDdiReserved2
(
    VOID
)
{
	debug("[CALL]: NTSTATUS DxgkDdiReserved2");
	return STATUS_ABANDONED;
}

//(Reserved)
//PVOID Reserved3 = NULL;
NTSTATUS DxgkDdiReserved3
(
    VOID
)
{
	debug("[CALL]: NTSTATUS DxgkDdiReserved3");
	return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------