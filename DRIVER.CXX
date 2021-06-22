#include "DRIVER.HXX"

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
    debug("[CALL]: NTSTATUS DriverEntry");
    NTSTATUS status = STATUS_SUCCESS;
    DRIVER_INITIALIZATION_DATA config = { 0 };

    if (!ARGUMENT_PRESENT(DriverObject)
        || !ARGUMENT_PRESENT(RegistryPath))
    {
        debug("[WARN]: The Specified DriverObject or RegistryPath is Invalid");
        return STATUS_INVALID_PARAMETER;
    }

    DriverObject->DriverUnload = DriverUnload;

    config.Version = DXGKDDI_INTERFACE_VERSION;

//-------------------------------------------------------------------------
#pragma region //Device Section

    config.DxgkDdiCreateDevice = DxgkDdiCreateDevice;
    config.DxgkDdiAddDevice = BddDdiAddDevice; //DxgkDdiAddDevice;
    config.DxgkDdiLinkDevice = BddDdiLinkDevice; ////DxgkDdiLinkDevice;
    config.DxgkDdiStartDevice = BddDdiStartDevice; //DxgkDdiStartDevice;
    config.DxgkDdiResetDevice = DxgkDdiResetDevice;
    config.DxgkDdiStopDevice = DxgkDdiStopDevice;
    config.DxgkDdiRemoveDevice = DxgkDdiRemoveDevice;
    config.DxgkDdiDestroyDevice = DxgkDdiDestroyDevice;
    config.DxgkDdiUnload = DxgkDdiUnload;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Present Section

    config.DxgkDdiPresent = BddDdiPresent; //DxgkDdiPresent;
    config.DxgkDdiRender = DxgkDdiRender;
    config.DxgkDdiRenderKm = DxgkDdiRenderKm;
    config.DxgkDdiRenderGdi = DxgkDdiRenderGdi;
    config.DxgkDdiSubmitRender = DxgkDdiSubmitRender;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Command Section

    config.DxgkDdiPatch = DxgkDdiPatch;
    config.DxgkDdiPreemptCommand = DxgkDdiPreemptCommand;
    config.DxgkDdiSubmitCommand = DxgkDdiSubmitCommand;
    config.DxgkDdiSubmitCommandVirtual = DxgkDdiSubmitCommandVirtual;
    config.DxgkDdiValidateSubmitCommand = DxgkDdiValidateSubmitCommand;
    config.DxgkDdiCancelCommand = DxgkDdiCancelCommand;
    config.DxgkDdiBuildPagingBuffer = DxgkDdiBuildPagingBuffer;
    config.DxgkDdiResetFromTimeout = DxgkDdiResetFromTimeout;
    config.DxgkDdiRestartFromTimeout = DxgkDdiRestartFromTimeout;
    config.DxgkDdiEscape = DxgkDdiEscape;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Calibration Section

    config.DxgkDdiExchangePreStartInfo = DxgkDdiExchangePreStartInfo;
    config.DxgkDdiFormatHistoryBuffer = DxgkDdiFormatHistoryBuffer;
    config.DxgkDdiControlDiagnosticReporting = DxgkDdiControlDiagnosticReporting;
    config.DxgkDdiCollectDiagnosticInfo = DxgkDdiCollectDiagnosticInfo;
    config.DxgkDdiCalibrateGpuClock = DxgkDdiCalibrateGpuClock;
    config.DxgkDdiControlModeBehavior = DxgkDdiControlModeBehavior;
    config.DxgkDdiUpdateMonitorLinkInfo = DxgkDdiUpdateMonitorLinkInfo;
    config.DxgkDdiValidateUpdateAllocationProperty = DxgkDdiValidateUpdateAllocationProperty;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Set Calibration Section

    config.DxgkDdiSetupPriorityBands = DxgkDdiSetupPriorityBands;
    config.DxgkDdiSetContextSchedulingProperties = DxgkDdiSetContextSchedulingProperties;
    config.DxgkDdiSetSchedulingLogBuffer = DxgkDdiSetSchedulingLogBuffer;
    config.DxgkDdiSetTargetGamma = DxgkDdiSetTargetGamma;
    config.DxgkDdiSetTargetContentType = DxgkDdiSetTargetContentType;
    config.DxgkDdiSetTargetAnalogCopyProtection = DxgkDdiSetTargetAnalogCopyProtection;
    config.DxgkDdiSetTargetAdjustedColorimetry = DxgkDdiSetTargetAdjustedColorimetry;
    config.DxgkDdiSetTargetAdjustedColorimetry2 = DxgkDdiSetTargetAdjustedColorimetry2;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Set Section

    config.DxgkDdiSetPalette = DxgkDdiSetPalette;
    config.DxgkDdiSetPointerPosition = BddDdiSetPointerPosition; //DxgkDdiSetPointerPosition;
    config.DxgkDdiSetPointerShape = DxgkDdiSetPointerShape;
    config.DxgkDdiSetPowerState = DxgkDdiSetPowerState;
    config.DxgkDdiSetPowerPState = DxgkDdiSetPowerPState;
    config.DxgkDdiSetPowerComponentFState = DxgkDdiSetPowerComponentFState;
    config.DxgkDdiSetStablePowerState = DxgkDdiSetStablePowerState;
    config.DxgkDdiSetTrackedWorkloadPowerLevel = DxgkDdiSetTrackedWorkloadPowerLevel;
    config.DxgkDdiSetDisplayPrivateDriverFormat = DxgkDdiSetDisplayPrivateDriverFormat;
    config.DxgkDdiSetVideoProtectedRegion = DxgkDdiSetVideoProtectedRegion;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Get Section

    config.DxgkDdiGetScanLine = DxgkDdiGetScanLine;
    config.DxgkDdiGetNodeMetadata = DxgkDdiGetNodeMetadata;
    config.DxgkDdiGetChildContainerId = DxgkDdiGetChildContainerId;
    config.DxgkDdiGetPostCompositionCaps = DxgkDdiGetPostCompositionCaps;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Notify Section

    config.DxgkDdiNotifyAcpiEvent = DxgkDdiNotifyAcpiEvent;
    config.DxgkDdiNotifyFocusPresent = DxgkDdiNotifyFocusPresent;
    config.DxgkDdiNotifySurpriseRemoval = DxgkDdiNotifySurpriseRemoval;
    config.DxgkDdiPowerRuntimeControlRequest = DxgkDdiPowerRuntimeControlRequest;
    config.DxgkDdiPowerRuntimeSetDeviceHandle = DxgkDdiPowerRuntimeSetDeviceHandle;
    config.DxgkDdiCreatePeriodicFrameNotification = DxgkDdiCreatePeriodicFrameNotification;
    config.DxgkDdiDestroyPeriodicFrameNotification = DxgkDdiDestroyPeriodicFrameNotification;
    config.DxgkDdiSignalMonitoredFence = DxgkDdiSignalMonitoredFence;
    config.DxgkDdiDisplayDetectControl = DxgkDdiDisplayDetectControl;
    config.DxgkDdiRecommendMonitorModes = BddDdiRecommendMonitorModes; //DxgkDdiRecommendMonitorModes;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Query Section

    config.DxgkDdiQueryInterface = BddDdiQueryInterface; ////DxgkDdiQueryInterface;
    config.DxgkDdiQueryAdapterInfo = BddDdiQueryAdapterInfo; //DxgkDdiQueryAdapterInfo;
    config.DxgkDdiQueryCurrentFence = DxgkDdiQueryCurrentFence;
    config.DxgkDdiQueryDeviceDescriptor = BddDdiQueryDeviceDescriptor; //DxgkDdiQueryDeviceDescriptor;
    config.DxgkDdiQueryVidPnHWCapability = DxgkDdiQueryVidPnHWCapability;
    config.DxgkDdiQueryChildRelations = BddDdiQueryChildRelations; //DxgkDdiQueryChildRelations;
    config.DxgkDdiQueryChildStatus = BddDdiQueryChildStatus; //DxgkDdiQueryChildStatus; //Not Being Called...
    config.DxgkDdiQueryConnectionChange = DxgkDdiQueryConnectionChange;
    config.DxgkDdiQueryDiagnosticTypesSupport = DxgkDdiQueryDiagnosticTypesSupport;
    config.DxgkDdiQueryDependentEngineGroup = DxgkDdiQueryDependentEngineGroup;
    config.DxgkDdiQueryEngineStatus = DxgkDdiQueryEngineStatus;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Video Present Network (VidPn) Section

    config.DxgkDdiCommitVidPn = BddDdiCommitVidPn; //DxgkDdiCommitVidPn;
    config.DxgkDdiIsSupportedVidPn = BddDdiIsSupportedVidPn; //DxgkDdiIsSupportedVidPn;
    config.DxgkDdiEnumVidPnCofuncModality = BddDdiEnumVidPnCofuncModality; //DxgkDdiEnumVidPnCofuncModality;
    config.DxgkDdiRecommendFunctionalVidPn = DxgkDdiRecommendFunctionalVidPn;
    config.DxgkDdiGetMultiPlaneOverlayCaps = DxgkDdiGetMultiPlaneOverlayCaps;
    config.DxgkDdiPostMultiPlaneOverlayPresent = DxgkDdiPostMultiPlaneOverlayPresent;
    config.DxgkDdiCheckMultiPlaneOverlaySupport = DxgkDdiCheckMultiPlaneOverlaySupport;
    config.DxgkDdiCheckMultiPlaneOverlaySupport2 = DxgkDdiCheckMultiPlaneOverlaySupport2;
    config.DxgkDdiCheckMultiPlaneOverlaySupport3 = DxgkDdiCheckMultiPlaneOverlaySupport3;
    config.DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay;
    config.DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2 = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2;
    config.DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3 = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3;
    config.DxgkDdiSetVidPnSourceAddress = DxgkDdiSetVidPnSourceAddress;
    config.DxgkDdiSetVidPnSourceVisibility = BddDdiSetVidPnSourceVisibility; //DxgkDdiSetVidPnSourceVisibility;
    config.DxgkDdiSetTimingsFromVidPn = DxgkDdiSetTimingsFromVidPn;
    config.DxgkDdiUpdateActiveVidPnPresentPath = DxgkDdiUpdateActiveVidPnPresentPath;
    config.DxgkDdiRecommendVidPnTopology = DxgkDdiRecommendVidPnTopology;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Engine Section

    config.DxgkDdiResetEngine = DxgkDdiResetEngine;
    config.DxgkDdiResumeHwEngine = DxgkDdiResumeHwEngine;
    config.DxgkDdiResetHwEngine = DxgkDdiResetHwEngine;
    config.DxgkDdiCreateProcess = DxgkDdiCreateProcess;
    config.DxgkDdiDestroyProcess = DxgkDdiDestroyProcess;
    config.DxgkDdiStopCapture = DxgkDdiStopCapture;
    config.DxgkDdiStopDeviceAndReleasePostDisplayOwnership = DxgkDdiStopDeviceAndReleasePostDisplayOwnership;
    config.DxgkDdiSystemDisplayEnable = DxgkDdiSystemDisplayEnable;
    config.DxgkDdiSystemDisplayWrite = DxgkDdiSystemDisplayWrite;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Interrupt Section

    config.DxgkDdiDpcRoutine = DxgkDdiDpcRoutine;
    config.DxgkDdiInterruptRoutine = DxgkDdiInterruptRoutine;
    config.DxgkDdiDispatchIoRequest = DxgkDdiDispatchIoRequest;
    config.DxgkDdiControlInterrupt = DxgkDdiControlInterrupt;
    config.DxgkDdiControlInterrupt2 = DxgkDdiControlInterrupt2;
    config.DxgkDdiControlInterrupt3 = DxgkDdiControlInterrupt3;
    config.DxgkDdiControlEtwLogging = DxgkDdiControlEtwLogging;
    config.DxgkDdiCollectDbgInfo = DxgkDdiCollectDbgInfo;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Allocation Section

    config.DxgkDdiGetStandardAllocationDriverData = DxgkDdiGetStandardAllocationDriverData;
    config.DxgkDdiDescribeAllocation = DxgkDdiDescribeAllocation;
    config.DxgkDdiCreateAllocation = DxgkDdiCreateAllocation;
    config.DxgkDdiCreateAllocation2 = DxgkDdiCreateAllocation2;
    config.DxgkDdiOpenAllocation = DxgkDdiOpenAllocation;
    config.DxgkDdiCloseAllocation = DxgkDdiCloseAllocation;
    config.DxgkDdiDestroyAllocation = DxgkDdiDestroyAllocation;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Context Section

    config.DxgkDdiCreateContext = DxgkDdiCreateContext;
    config.DxgkDdiSuspendContext = DxgkDdiSuspendContext;
    config.DxgkDdiResumeContext = DxgkDdiResumeContext;
    config.DxgkDdiDestroyContext = DxgkDdiDestroyContext;
    config.DxgkDdiCreateHwContext = DxgkDdiCreateHwContext;
    config.DxgkDdiDestroyHwContext = DxgkDdiDestroyHwContext;
    config.DxgkDdiCreateHwQueue = DxgkDdiCreateHwQueue;
    config.DxgkDdiPresentToHwQueue = DxgkDdiPresentToHwQueue;
    config.DxgkDdiUpdateHwContextState = DxgkDdiUpdateHwContextState;
    config.DxgkDdiSubmitCommandToHwQueue = DxgkDdiSubmitCommandToHwQueue;
    config.DxgkDdiSwitchToHwContextList = DxgkDdiSwitchToHwContextList;
    config.DxgkDdiDestroyHwQueue = DxgkDdiDestroyHwQueue;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Overlay Section

    config.DxgkDdiCreateOverlay = DxgkDdiCreateOverlay;
    config.DxgkDdiUpdateOverlay = DxgkDdiUpdateOverlay;
    config.DxgkDdiFlipOverlay = DxgkDdiFlipOverlay;
    config.DxgkDdiDestroyOverlay = DxgkDdiDestroyOverlay;
    config.DxgkDdiMapCpuHostAperture = DxgkDdiMapCpuHostAperture;
    config.DxgkDdiUnmapCpuHostAperture = DxgkDdiUnmapCpuHostAperture;
    config.DxgkDdiAcquireSwizzlingRange = DxgkDdiAcquireSwizzlingRange;
    config.DxgkDdiReleaseSwizzlingRange = DxgkDdiReleaseSwizzlingRange;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Exclusive Section

    config.DxgkDdiCreateProtectedSession = DxgkDdiCreateProtectedSession;
    config.DxgkDdiDestroyProtectedSession = DxgkDdiDestroyProtectedSession;
    config.DxgkDdiSetVirtualMachineData = DxgkDdiSetVirtualMachineData;
    config.DxgkDdiBeginExclusiveAccess = DxgkDdiBeginExclusiveAccess;
    config.DxgkDdiEndExclusiveAccess = DxgkDdiEndExclusiveAccess;
    config.DxgkDdiSaveMemoryForHotUpdate = DxgkDdiSaveMemoryForHotUpdate;
    config.DxgkDdiRestoreMemoryForHotUpdate = DxgkDdiRestoreMemoryForHotUpdate;

#pragma endregion
//-------------------------------------------------------------------------
#pragma region //Reserved Section

    config.DxgkDdiSetRootPageTable = DxgkDdiSetRootPageTable;
    config.DxgkDdiGetRootPageTableSize = DxgkDdiGetRootPageTableSize;
    config.DxgkDdiDescribePageTable = DxgkDdiDescribePageTable;
    config.DxgkDdiUpdatePageTable = DxgkDdiUpdatePageTable;
    config.DxgkDdiUpdatePageDirectory = DxgkDdiUpdatePageDirectory;
    config.DxgkDdiMovePageDirectory = DxgkDdiMovePageDirectory;
    config.Reserved = DxgkDdiReserved;
    config.Reserved1 = DxgkDdiReserved1;
    config.Reserved2 = DxgkDdiReserved2;
    config.Reserved3 = DxgkDdiReserved3;

#pragma endregion
//-------------------------------------------------------------------------

    status = DxgkInitialize(DriverObject, RegistryPath, &config);
    if (NT_ERROR(status))
    {
        debug("[WARN]: DxgkInitialize Failed");
        return status;
    }

    debug("[INFO]: DriverEntry Complete");
    return STATUS_SUCCESS;
}

VOID DriverUnload(PDRIVER_OBJECT DriverObject)
{
    debug("[CALL]: VOID DriverUnload");
    DxgkUnInitialize(DriverObject);
    debug("[INFO]: DriverUnload Complete");
}

#pragma endregion
//-------------------------------------------------------------------------