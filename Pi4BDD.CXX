#include "DRIVER.HXX"

//Use Trace Log to determine which functions need to be overridden here...

//NTSTATUS BddDdiAddDevice
//BDD_HWBLT::BDD_HWBLT
//BASIC_DISPLAY_DRIVER::BASIC_DISPLAY_DRIVER
//NTSTATUS APIENTRY BddDdiQueryAdapterInfo
//NTSTATUS BASIC_DISPLAY_DRIVER::QueryAdapterInfo
//NTSTATUS BddDdiStartDevice
//NTSTATUS BASIC_DISPLAY_DRIVER::StartDevice
//NTSTATUS BddDdiQueryChildRelations
//NTSTATUS BASIC_DISPLAY_DRIVER::QueryChildRelations
//NTSTATUS BddDdiQueryChildStatus
//NTSTATUS BASIC_DISPLAY_DRIVER::QueryChildStatus
//NTSTATUS BddDdiQueryDeviceDescriptor
//NTSTATUS BASIC_DISPLAY_DRIVER::QueryDeviceDescriptor
//NTSTATUS BASIC_DISPLAY_DRIVER::GetEdid
//NTSTATUS APIENTRY BddDdiRecommendMonitorModes
//NTSTATUS BASIC_DISPLAY_DRIVER::RecommendMonitorModes
//NTSTATUS BASIC_DISPLAY_DRIVER::AddSingleMonitorMode
//D3DDDI_VIDEO_PRESENT_SOURCE_ID BASIC_DISPLAY_DRIVER::FindSourceForTarget
//NTSTATUS APIENTRY BddDdiIsSupportedVidPn
//NTSTATUS BASIC_DISPLAY_DRIVER::IsSupportedVidPn
//NTSTATUS APIENTRY BddDdiEnumVidPnCofuncModality
//NTSTATUS BASIC_DISPLAY_DRIVER::EnumVidPnCofuncModality
//NTSTATUS BASIC_DISPLAY_DRIVER::AddSingleSourceMode
//NTSTATUS BASIC_DISPLAY_DRIVER::AddSingleTargetMode
//NTSTATUS APIENTRY BddDdiCommitVidPn
//NTSTATUS BASIC_DISPLAY_DRIVER::CommitVidPn
//NTSTATUS BASIC_DISPLAY_DRIVER::IsVidPnSourceModeFieldsValid
//NTSTATUS BASIC_DISPLAY_DRIVER::IsVidPnPathFieldsValid
//NTSTATUS BASIC_DISPLAY_DRIVER::SetSourceModeAndPath
//NTSTATUS MapFrameBuffer | FrameBuffer : 0x3E3B8000 //<--actual framebuffer location may vary
//VOID BASIC_DISPLAY_DRIVER::BlackOutScreen
//NTSTATUS APIENTRY BddDdiSetVidPnSourceVisibility
//NTSTATUS BASIC_DISPLAY_DRIVER::SetVidPnSourceVisibility
//NTSTATUS APIENTRY BddDdiSetPointerPosition
//NTSTATUS BASIC_DISPLAY_DRIVER::SetPointerPosition
  //NTSTATUS APIENTRY BddDdiPresentDisplayOnly
  //NTSTATUS BASIC_DISPLAY_DRIVER::PresentDisplayOnly
  //NTSTATUS BDD_HWBLT::ExecutePresentDisplayOnly
  //NTSTATUS StartHwBltPresentWorkerThread
  //void HwContextWorkerThread
  //void HwExecutePresentDisplayOnly
  //VOID BltBits
  //VOID CopyBits32_32
  //void ReportPresentProgress
  //VOID BddDdiDpcRoutine
  //VOID BASIC_DISPLAY_DRIVER::DpcRoutine
//NTSTATUS UnmapFrameBuffer
  //NTSTATUS BddDdiStopDevice
  //NTSTATUS BASIC_DISPLAY_DRIVER::StopDevice
  //VOID BASIC_DISPLAY_DRIVER::CleanUp
  //NTSTATUS BddDdiRemoveDevice
  //BASIC_DISPLAY_DRIVER::~BASIC_DISPLAY_DRIVER
  //void BDD_HWBLT::SetPresentWorkerThreadInfo
  //VOID BddDdiUnload

//Experimentally Found:
//NTSTATUS BddDdiAddDevice
  //???DxgkDdiLinkDevice
  //???DxgkDdiQueryInterface
  //???DxgkDdiQueryInterface
  //???DxgkDdiRemoveDevice
  //???DxgkDdiUnloadDevice

NTSTATUS AddSingleSourceMode
(
    _In_ CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*   pVidPnSourceModeSetInterface,
    D3DKMDT_HVIDPNSOURCEMODESET                     hVidPnSourceModeSet
);

NTSTATUS AddSingleTargetMode
(
    _In_ CONST DXGK_VIDPNTARGETMODESET_INTERFACE*   pVidPnTargetModeSetInterface,
    D3DKMDT_HVIDPNTARGETMODESET                     hVidPnTargetModeSet,
    _In_opt_ CONST D3DKMDT_VIDPN_SOURCE_MODE*       pVidPnPinnedSourceModeInfo
);

NTSTATUS MapFrameBuffer
(
    _In_ PHYSICAL_ADDRESS                       PhysicalAddress,
    _In_ ULONG                                  Length,
    _Outptr_result_bytebuffer_(Length) PVOID*   VirtualAddress
);

NTSTATUS UnmapFrameBuffer
(
    _In_reads_bytes_(Length) PVOID   VirtualAddress,
    _In_ ULONG                       Length
);

extern "C"
{
    PVOID pBDD = NULL;
    
    D3DDDI_VIDEO_PRESENT_SOURCE_ID m_SourceId = 0;
    BOOLEAN m_SynchExecution = TRUE;
    KEVENT m_hThreadStartupEvent = { 0 };
    KEVENT m_hThreadSuspendEvent = { 0 };
    
    PDEVICE_OBJECT m_PhysicalDevice = NULL;
    DEVICE_POWER_STATE m_MonitorPowerState = PowerDeviceD0;
    DEVICE_POWER_STATE m_AdapterPowerState = PowerDeviceD0;

    BDD_FLAGS m_Flags = { 0 };
    DXGKRNL_INTERFACE m_DxgkInterface = { 0 };
    DXGK_START_INFO m_StartInfo = { 0 };
    CURRENT_BDD_MODE m_CurrentMode = { 0 };
    DXGK_DEVICE_INFO m_DeviceInfo = { 0 };

    BYTE m_EDID[128] = { 0 };
}

NTSTATUS BddDdiAddDevice
(
    PDEVICE_OBJECT   pPhysicalDeviceObject,
    PVOID*           ppDeviceContext
)
{
    debug("[CALL]: NTSTATUS BddDdiAddDevice");
    if ((!pPhysicalDeviceObject) || (!ppDeviceContext))
    {
        debug("[WARN]: One of pPhysicalDeviceObject (%p), ppDeviceContext (%p) is NULL",
            pPhysicalDeviceObject, ppDeviceContext);
        return STATUS_INVALID_PARAMETER;
    }
    *ppDeviceContext = NULL;
    pBDD = ExAllocatePoolWithTag(NonPagedPool, NonPagedPoolNx, BDDTAG);
    if (!pBDD)
    {
        debug("[WARN]: pBDD failed to be allocated");
        return STATUS_NO_MEMORY;
    }
    *ppDeviceContext = pBDD;
    m_PhysicalDevice = pPhysicalDeviceObject;
    *((UINT32*)&m_Flags) = 0;
    m_Flags._LastFlag = TRUE;
    RtlZeroMemory(&m_DxgkInterface, sizeof(m_DxgkInterface));
    RtlZeroMemory(&m_StartInfo, sizeof(m_StartInfo));
    RtlZeroMemory(&m_CurrentMode, sizeof(m_CurrentMode));
    RtlZeroMemory(&m_DeviceInfo, sizeof(m_DeviceInfo));
    KeInitializeEvent(&m_hThreadStartupEvent, NotificationEvent, FALSE);
    KeInitializeEvent(&m_hThreadSuspendEvent, SynchronizationEvent, FALSE);
    return STATUS_SUCCESS;
}

///???
NTSTATUS BddDdiLinkDevice
(
    IN_CONST_PDEVICE_OBJECT   PhysicalDeviceObject,
    IN_CONST_PVOID            MiniportDeviceContext,
    INOUT_PLINKED_DEVICE      LinkedDevice
)
{
    debug("[CALL]: NTSTATUS BddDdiLinkDevice");
    LinkedDevice->ChainUid = 0;
    LinkedDevice->NumberOfLinksInChain = 0;
    LinkedDevice->LeadLink = FALSE;
    return STATUS_SUCCESS;
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

///???
NTSTATUS BddDdiQueryInterface
(
    IN_CONST_PVOID        MiniportDeviceContext,
    IN_PQUERY_INTERFACE   QueryInterface
)
{
    debug("[CALL]: NTSTATUS BddDdiQueryInterface");
    CONST GUID cGUID = *(QueryInterface->InterfaceType);
    UNICODE_STRING uGUID;
    ANSI_STRING aGUID;
    RtlInitUnicodeString(&uGUID, L"");
    RtlStringFromGUID(cGUID, &uGUID);
    RtlUnicodeStringToAnsiString(&aGUID, &uGUID, TRUE);
    debug("[INFO]: GUID: %s", aGUID.Buffer);
    debug("Size: %d", QueryInterface->Size);
    debug("Version: %d", QueryInterface->Version);
    debug("Interface: %p", QueryInterface->Interface);
    debug("InterfaceSpecificData: %p", QueryInterface->InterfaceSpecificData);
    debug("DeviceUid: %lu", QueryInterface->DeviceUid);

    if (cGUID == GUID_DEVINTERFACE_I2C)
    {
        debug("[INFO]: Detected Known Interface %s", "GUID_DEVINTERFACE_I2C");
        PDXGK_I2C_INTERFACE pInterface = (PDXGK_I2C_INTERFACE)QueryInterface->Interface;
        pInterface->Size = sizeof(DXGK_I2C_INTERFACE);
        pInterface->Version = DXGK_I2C_INTERFACE_VERSION_1;
        pInterface->Context = NULL;
        pInterface->InterfaceReference = I2CInterfaceReference;
        pInterface->InterfaceDereference = I2CInterfaceDereference;
        pInterface->DxgkDdiI2CTransmitDataToDisplay = I2CTransmitDataToDisplay;
        pInterface->DxgkDdiI2CReceiveDataFromDisplay = I2CReceiveDataFromDisplay;
        return STATUS_SUCCESS;
    }
    else if (cGUID == GUID_DEVINTERFACE_OPM)
    {
        debug("[INFO]: Detected Known Interface %s", "GUID_DEVINTERFACE_OPM");
        PDXGK_OPM_INTERFACE_3 pInterface = (PDXGK_OPM_INTERFACE_3)QueryInterface->Interface;
        pInterface->Size = sizeof(DXGK_OPM_INTERFACE_3);
        pInterface->Version = DXGK_OPM_INTERFACE_VERSION_3;
        pInterface->Context = NULL;
        pInterface->InterfaceReference = OPMInterfaceReference;
        pInterface->InterfaceDereference = OPMInterfaceDereference;
        pInterface->DxgkDdiOPMGetCertificateSize = OPMGetCertificateSize;
        pInterface->DxgkDdiOPMGetCertificate = OPMGetCertificate;
        pInterface->DxgkDdiOPMGetRandomNumber = OPMGetRandomNumber;
        pInterface->DxgkDdiOPMSetSigningKeyAndSequenceNumbers = OPMSetSigningKeyAndSequenceNumbers;
        pInterface->DxgkDdiOPMGetInformation = OPMGetInformation;
        pInterface->DxgkDdiOPMGetCOPPCompatibleInformation = OPMGetCOPPCompatibleInformation;
        pInterface->DxgkDdiOPMConfigureProtectedOutput = OPMConfigureProtectedOutput;
        pInterface->DxgkDdiOPMDestroyProtectedOutput = OPMDestroyProtectedOutput;
        pInterface->DxgkDdiOPMCreateProtectedOutputNonLocalDisplay = OPMCreateProtectedOutputNonLocalDisplay;
        pInterface->DxgkDdiOPMSetSrmList = OPMSetSrmList;
        pInterface->DxgkDdiOPMGetSrmListVersion = OPMGetSrmListVersion;
        return STATUS_NOT_SUPPORTED; //STATUS_SUCCESS;
    }
    else if (cGUID == GUID_DEVINTERFACE_MIRACAST_DISPLAY)
    {
        debug("[INFO]: Detected Known Interface %s", "GUID_DEVINTERFACE_MIRACAST_DISPLAY");
        PDXGK_MIRACAST_DISPLAY_INTERFACE pInterface = (PDXGK_MIRACAST_DISPLAY_INTERFACE)QueryInterface->Interface;
        pInterface->Size = sizeof(DXGK_MIRACAST_DISPLAY_INTERFACE);
        pInterface->Version = DXGK_MIRACAST_DISPLAY_INTERFACE_VERSION_1;
        pInterface->Context = NULL;
        pInterface->InterfaceReference = MiracastInterfaceReference;
        pInterface->InterfaceDereference = MiracastInterfaceDereference;
        pInterface->DxgkDdiMiracastQueryCaps = MiracastQueryCaps;
        pInterface->DxgkDdiMiracastCreateContext = MiracastCreateContext;
        pInterface->DxgkDdiMiracastIoControl = MiracastIoControl;
        pInterface->DxgkDdiMiracastDestroyContext = MiracastDestroyContext;
        return STATUS_NOT_SUPPORTED; //STATUS_SUCCESS;
    }
    else
    {
        debug("[INFO]: Unknown Interface GUID Detected");
        return STATUS_NOT_SUPPORTED;
    }
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

NTSTATUS APIENTRY BddDdiQueryAdapterInfo
(
    IN_CONST_HANDLE                      hAdapter,
    IN_CONST_PDXGKARG_QUERYADAPTERINFO   pQueryAdapterInfo
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiQueryAdapterInfo");
    if ((!hAdapter) || (!pQueryAdapterInfo))
    {
        debug("[WARN]: One of hAdapter (%p), pQueryAdapterInfo (%p) is NULL",
            hAdapter, pQueryAdapterInfo);
        return STATUS_INVALID_PARAMETER;
    }
    switch (pQueryAdapterInfo->Type)
    {
        case DXGKQAITYPE_WDDMDEVICECAPS:
        {
            DXGK_WDDMDEVICECAPS* pWDDMDeviceCaps = (DXGK_WDDMDEVICECAPS*)pQueryAdapterInfo->pOutputData;
            RtlZeroMemory(pWDDMDeviceCaps, sizeof(DXGK_WDDMDEVICECAPS));
            pWDDMDeviceCaps->WDDMVersion = DXGKDDI_WDDMv1_2; //more utter nonsense: https://docs.microsoft.com/en-us/windows-hardware/drivers/display/wddm-2-1-features#driver-versioning
            return STATUS_SUCCESS; //Please see StampInf Driver Version Information in Project Settings (9.21.0000.0000)
        }
        break;
        case DXGKQAITYPE_DISPLAYID_DESCRIPTOR:
        {
            //DXGK_QUERYINTEGRATEDDISPLAYOUT* pQueryIntegratedDisplayOut = (DXGK_QUERYINTEGRATEDDISPLAYOUT*)pQueryAdapterInfo->pOutputData;
            //RtlZeroMemory(pQueryIntegratedDisplayOut, sizeof(DXGK_QUERYINTEGRATEDDISPLAYOUT));
            debug("[WARN]: DXGKQAITYPE_DISPLAYID_DESCRIPTOR Not Supported");
            //pQueryIntegratedDisplayOut->Colorimetry = DXGK_COLORIMETRY::;
            return STATUS_ABANDONED;
        }
        break;
        case DXGKQAITYPE_DRIVERCAPS:
        {
            if (pQueryAdapterInfo->OutputDataSize < sizeof(DXGK_DRIVERCAPS))
            {
                debug("[WARN]: pQueryAdapterInfo->OutputDataSize (0x%08lX) is smaller than sizeof(DXGK_DRIVERCAPS) (0x%016llX)",
                    pQueryAdapterInfo->OutputDataSize, sizeof(DXGK_DRIVERCAPS));
                return STATUS_BUFFER_TOO_SMALL;
            }
            DXGK_DRIVERCAPS* pDriverCaps = (DXGK_DRIVERCAPS*)pQueryAdapterInfo->pOutputData;
            // Nearly all fields must be initialized to zero, so zero out to start and then change those that are non-zero.
            // Fields are zero since BDD is Display-Only and therefore does not support any of the render related fields.
            // It also doesn't support hardware interrupts, gamma ramps, etc.
            RtlZeroMemory(pDriverCaps, sizeof(DXGK_DRIVERCAPS));
            pDriverCaps->WDDMVersion = DXGKDDI_WDDMv1_2;
            pDriverCaps->HighestAcceptableAddress.QuadPart = -1;
            pDriverCaps->SupportNonVGA = TRUE;
            pDriverCaps->SupportSmoothRotation = TRUE;
            return STATUS_SUCCESS;
        }
        case DXGKQAITYPE_DISPLAY_DRIVERCAPS_EXTENSION:
        {
            DXGK_DISPLAY_DRIVERCAPS_EXTENSION* pDriverDisplayCaps;
            if (pQueryAdapterInfo->OutputDataSize < sizeof(*pDriverDisplayCaps))
            {
                debug("[WARN]: pQueryAdapterInfo->OutputDataSize (0x%08lX) is smaller than sizeof(DXGK_DISPLAY_DRIVERCAPS_EXTENSION) (0x%016llX)",
                    pQueryAdapterInfo->OutputDataSize, sizeof(DXGK_DISPLAY_DRIVERCAPS_EXTENSION));
                return STATUS_BUFFER_TOO_SMALL;
            }
            pDriverDisplayCaps = (DXGK_DISPLAY_DRIVERCAPS_EXTENSION*)pQueryAdapterInfo->pOutputData;
            // Reset all caps values
            RtlZeroMemory(pDriverDisplayCaps, pQueryAdapterInfo->OutputDataSize);
            // We claim to support virtual display mode.
            pDriverDisplayCaps->VirtualModeSupport = 1;
            return STATUS_SUCCESS;
        }
        default:
        {
            // BDD does not need to support any other adapter information types
            debug("[WARN]: Unknown QueryAdapterInfo Type (0x%08lX) requested", pQueryAdapterInfo->Type);
            return STATUS_NOT_SUPPORTED;
        }
    }
}

NTSTATUS BddDdiStartDevice
(
    IN_CONST_PVOID          pDeviceContext,
    IN_PDXGK_START_INFO     pDxgkStartInfo,
    IN_PDXGKRNL_INTERFACE   pDxgkInterface,
    OUT_PULONG              pNumberOfViews,
    OUT_PULONG              pNumberOfChildren
)
{
    debug("[CALL]: NTSTATUS BddDdiStartDevice");
    if ((!pDeviceContext) || (!pDxgkStartInfo) || (!pDxgkInterface) || (!pNumberOfViews) || (!pNumberOfChildren))
    {
        debug("[WARN]: One of pDeviceContext (%p), DxgkStartInfo (%p), DxgkInterface (%p), pNumberOfViews (%p), pNumberOfChildren (%p) is NULL",
            pDeviceContext, pDxgkStartInfo, pDxgkInterface, pNumberOfViews, pNumberOfChildren);
        return STATUS_INVALID_PARAMETER;
    }
    RtlCopyMemory(&m_StartInfo, pDxgkStartInfo, sizeof(m_StartInfo));
    RtlCopyMemory(&m_DxgkInterface, pDxgkInterface, sizeof(m_DxgkInterface));
    RtlZeroMemory(&m_CurrentMode, sizeof(m_CurrentMode));
    m_CurrentMode.DispInfo.TargetId = D3DDDI_ID_UNINITIALIZED; // <-- ???

    // Get device information from OS.
    //RegisterHWInfo(); // Implementation deliberately left out to avoid reliance on the Registry

    mbox_mmio_setup();
    dev_width2 = 1920; // <-- TEMPORARY SOLUTION
    dev_height2 = 1080; // <-- TEMPORARY SOLUTION
    if (!mbox_get_display_info())
    {
        debug("[WARN]: Mailbox Transaction Error");
        goto failure;
    }
    debug("[MBOX]: dev_framebuffer2 = 0x%016llX", dev_framebuffer2);
    debug("[MBOX]: dev_pitchspace2 = 0x%08lX", dev_pitchspace2);
    if (dev_framebuffer2 == 0x20)
    {
        debug("[WARN]: Malformed Mailbox Data. Start again, Microsoft.");
        goto failure;
    }
    else { debug("[INFO]: (V)"); }
    m_CurrentMode.DispInfo.Width = 1920; // <-- TEMPORARY SOLUTION
    m_CurrentMode.DispInfo.Height = 1080; // <-- TEMPORARY SOLUTION
    m_CurrentMode.DispInfo.PhysicAddress.QuadPart = dev_framebuffer2;
    m_CurrentMode.DispInfo.Pitch = 0x1E00; //dev_pitchspace2; // 0x1E00 reported by the mailbox may cause STATUS_GRAPHICS_INVALID_STRIDE (0xC01E033C)
    m_CurrentMode.DispInfo.ColorFormat = D3DDDIFMT_A8R8G8B8;

    //IMPORTANT: DXGK_INTERFACE

    pDxgkInterface->Size = sizeof(DXGKRNL_INTERFACE);
    pDxgkInterface->Version = DXGKDDI_INTERFACE_VERSION_WDDM2_7; //DXGKDDI_INTERFACE_VERSION_WIN8;
    pDxgkInterface->DeviceHandle = pDeviceContext;

    pDxgkInterface->DxgkCbEvalAcpiMethod = DxgkCbEvalAcpiMethod;
    pDxgkInterface->DxgkCbGetDeviceInformation = DxgkCbGetDeviceInformation;
    pDxgkInterface->DxgkCbIndicateChildStatus = DxgkCbIndicateChildStatus;
    pDxgkInterface->DxgkCbMapMemory = DxgkCbMapMemory;
    pDxgkInterface->DxgkCbQueueDpc = DxgkCbQueueDpc;
    pDxgkInterface->DxgkCbQueryServices = DxgkCbQueryServices;
    pDxgkInterface->DxgkCbReadDeviceSpace = DxgkCbReadDeviceSpace;
    pDxgkInterface->DxgkCbSynchronizeExecution = DxgkCbSynchronizeExecution;
    pDxgkInterface->DxgkCbUnmapMemory = DxgkCbUnmapMemory;
    pDxgkInterface->DxgkCbWriteDeviceSpace = DxgkCbWriteDeviceSpace;
    pDxgkInterface->DxgkCbIsDevicePresent = DxgkCbIsDevicePresent;
    pDxgkInterface->DxgkCbGetHandleData = DxgkCbGetHandleData;
    pDxgkInterface->DxgkCbGetHandleParent = DxgkCbGetHandleParent;
    pDxgkInterface->DxgkCbEnumHandleChildren = DxgkCbEnumHandleChildren;
    pDxgkInterface->DxgkCbNotifyInterrupt = DxgkCbNotifyInterrupt;
    pDxgkInterface->DxgkCbNotifyDpc = DxgkCbNotifyDpc;
    pDxgkInterface->DxgkCbQueryVidPnInterface = DxgkCbQueryVidPnInterface;
    pDxgkInterface->DxgkCbQueryMonitorInterface = DxgkCbQueryMonitorInterface;
    pDxgkInterface->DxgkCbGetCaptureAddress = DxgkCbGetCaptureAddress;
    pDxgkInterface->DxgkCbLogEtwEvent = DxgkCbLogEtwEvent;
    pDxgkInterface->DxgkCbExcludeAdapterAccess = DxgkCbExcludeAdapterAccess;

    pDxgkInterface->DxgkCbCreateContextAllocation = DxgkCbCreateContextAllocation;
    pDxgkInterface->DxgkCbDestroyContextAllocation = DxgkCbDestroyContextAllocation;
    pDxgkInterface->DxgkCbSetPowerComponentActive = DxgkCbSetPowerComponentActive;
    pDxgkInterface->DxgkCbSetPowerComponentIdle = DxgkCbSetPowerComponentIdle;
    pDxgkInterface->DxgkCbAcquirePostDisplayOwnership = DxgkCbAcquirePostDisplayOwnership;
    pDxgkInterface->DxgkCbPowerRuntimeControlRequest = DxgkCbPowerRuntimeControlRequest;
    pDxgkInterface->DxgkCbSetPowerComponentLatency = DxgkCbSetPowerComponentLatency;
    pDxgkInterface->DxgkCbSetPowerComponentResidency = DxgkCbSetPowerComponentResidency;
    pDxgkInterface->DxgkCbCompleteFStateTransition = DxgkCbCompleteFStateTransition;

    pDxgkInterface->DxgkCbCompletePStateTransition = DxgkCbCompletePStateTransition;

    pDxgkInterface->DxgkCbMapContextAllocation = DxgkCbMapContextAllocation;
    pDxgkInterface->DxgkCbUpdateContextAllocation = DxgkCbUpdateContextAllocation;
    pDxgkInterface->DxgkCbReserveGpuVirtualAddressRange = DxgkCbReserveGpuVirtualAddressRange;
    pDxgkInterface->DxgkCbAcquireHandleData = DxgkCbAcquireHandleData;
    pDxgkInterface->DxgkCbReleaseHandleData = DxgkCbReleaseHandleData;
    pDxgkInterface->DxgkCbHardwareContentProtectionTeardown = DxgkCbHardwareContentProtectionTeardown;

    pDxgkInterface->DxgkCbMultiPlaneOverlayDisabled = DxgkCbMultiPlaneOverlayDisabled;
    pDxgkInterface->DxgkCbMitigatedRangeUpdate = DxgkCbMitigatedRangeUpdate;

    pDxgkInterface->DxgkCbInvalidateHwContext = DxgkCbInvalidateHwContext;
    pDxgkInterface->DxgkCbIndicateConnectorChange = DxgkCbIndicateConnectorChange;
    pDxgkInterface->DxgkCbUnblockUEFIFrameBufferRanges = DxgkCbUnblockUEFIFrameBufferRanges;
    pDxgkInterface->DxgkCbAcquirePostDisplayOwnership2 = DxgkCbAcquirePostDisplayOwnership2;

    pDxgkInterface->DxgkCbSetProtectedSessionStatus = DxgkCbSetProtectedSessionStatus;

    pDxgkInterface->DxgkCbAllocateContiguousMemory = DxgkCbAllocateContiguousMemory;
    pDxgkInterface->DxgkCbFreeContiguousMemory = DxgkCbFreeContiguousMemory;
    pDxgkInterface->DxgkCbAllocatePagesForMdl = DxgkCbAllocatePagesForMdl;
    pDxgkInterface->DxgkCbFreePagesFromMdl = DxgkCbFreePagesFromMdl;
    pDxgkInterface->DxgkCbPinFrameBufferForSave = DxgkCbPinFrameBufferForSave;
    pDxgkInterface->DxgkCbUnpinFrameBufferForSave = DxgkCbUnpinFrameBufferForSave;
    pDxgkInterface->DxgkCbMapFrameBufferPointer = DxgkCbMapFrameBufferPointer;
    pDxgkInterface->DxgkCbUnmapFrameBufferPointer = DxgkCbUnmapFrameBufferPointer;
    pDxgkInterface->DxgkCbMapMdlToIoMmu = DxgkCbMapMdlToIoMmu;
    pDxgkInterface->DxgkCbUnmapMdlFromIoMmu = DxgkCbUnmapMdlFromIoMmu;
    pDxgkInterface->DxgkCbReportDiagnostic = DxgkCbReportDiagnostic;

    pDxgkInterface->DxgkCbSignalEvent = DxgkCbSignalEvent;

    pDxgkInterface->DxgkCbIsFeatureEnabled = DxgkCbIsFeatureEnabled;
    pDxgkInterface->DxgkCbSaveMemoryForHotUpdate = DxgkCbSaveMemoryForHotUpdate;

    goto success;

failure:
    m_Flags.DriverStarted = FALSE;
    *pNumberOfViews = 1;
    *pNumberOfChildren = 1;
    return STATUS_ABANDONED;
success:
    m_Flags.DriverStarted = TRUE;
    *pNumberOfViews = 1;
    *pNumberOfChildren = 1;
    return STATUS_SUCCESS;
}

NTSTATUS BddDdiQueryChildRelations
(
    //IN_CONST_PVOID                                                     pDeviceContext,
    //_Inout_updates_bytes_(ChildRelationsSize) PDXGK_CHILD_DESCRIPTOR   pChildRelations,        //SAL 2.0 Annotation
    //_In_ ULONG                                                         ChildRelationsSize
    IN_CONST_PVOID                 pDeviceContext,
    INOUT_PDXGK_CHILD_DESCRIPTOR   pChildRelations,
    IN_ULONG                       ChildRelationsSize
)
{
    debug("[CALL]: NTSTATUS BddDdiQueryChildRelations");
    if ((!pDeviceContext) || (!pChildRelations))
    {
        debug("[WARN]: One of pDeviceContext (%p), pChildRelations (%p) is NULL",
            pDeviceContext, pChildRelations);
        return STATUS_INVALID_PARAMETER;
    }
    ULONG ChildRelationsCount = (ChildRelationsSize / sizeof(DXGK_CHILD_DESCRIPTOR)) - 1;
    if (ChildRelationsCount > 1)
    {
        debug("[ASRT]: ChildRelationsCount (%lu) > 1", ChildRelationsSize);
        return STATUS_INVALID_PARAMETER;
    }
    debug("[INFO]: ChildRelationsCount = %lu", ChildRelationsCount);
    // The last DXGK_CHILD_DESCRIPTOR in the array of pChildRelations must remain zeroed out, so we subtract this from the count
    for (UINT32 ChildIndex = 0; ChildIndex < ChildRelationsCount; ++ChildIndex)
    {
        pChildRelations[ChildIndex].ChildDeviceType = TypeVideoOutput;
        pChildRelations[ChildIndex].ChildCapabilities.HpdAwareness = HpdAwarenessPolled; //HpdAwarenessAlwaysConnected; //HpdAwarenessInterruptible;
        pChildRelations[ChildIndex].ChildCapabilities.Type.VideoOutput.InterfaceTechnology = m_CurrentMode.Flags.IsInternal ? D3DKMDT_VOT_INTERNAL : D3DKMDT_VOT_OTHER;
        pChildRelations[ChildIndex].ChildCapabilities.Type.VideoOutput.MonitorOrientationAwareness = D3DKMDT_MOA_NONE;
        pChildRelations[ChildIndex].ChildCapabilities.Type.VideoOutput.SupportsSdtvModes = FALSE;
        // TODO: Replace 0 with the actual ACPI ID of the child device, if available
        pChildRelations[ChildIndex].AcpiUid = 0;
        pChildRelations[ChildIndex].ChildUid = ChildIndex;
    }

    return STATUS_SUCCESS;
}

NTSTATUS BddDdiQueryChildStatus //NOT BEING CALLED...NOR DxgkDdiQueryChildStatus...
(
    IN_CONST_PVOID             pDeviceContext,
    INOUT_PDXGK_CHILD_STATUS   pChildStatus,
    IN_BOOLEAN                 NonDestructiveOnly
)
{
    debug("[CALL]: NTSTATUS BddDdiQueryChildStatus");
    if ((!pDeviceContext) || (!pChildStatus))
    {
        debug("[WARN]: One of pDeviceContext (%p), pChildStatus (%p) is NULL",
            pDeviceContext, pChildStatus);
        return STATUS_INVALID_PARAMETER;
    }
    if (pChildStatus->ChildUid >= 1)
    {
        debug("[ASRT]: pChildStatus->ChildUid >= 1");
        return STATUS_INVALID_PARAMETER;
    }
    switch (pChildStatus->Type)
    {
        case StatusConnection:
        {
            // HpdAwarenessInterruptible was reported since HpdAwarenessNone is deprecated.
            // However, BDD has no knowledge of HotPlug events, so just always return connected.
            pChildStatus->HotPlug.Connected = m_Flags.DriverStarted;
            return STATUS_SUCCESS;
        }
        case StatusRotation:
        {
            // D3DKMDT_MOA_NONE was reported, so this should never be called
            debug("[WARN]: Child status being queried for StatusRotation even though D3DKMDT_MOA_NONE was reported");
            return STATUS_INVALID_PARAMETER;
        }
        default:
        {
            debug("[WARN]: Unknown pChildStatus->Type (0x%08lX) requested", pChildStatus->Type);
            return STATUS_NOT_SUPPORTED;
        }
    }
    UNREFERENCED_PARAMETER(NonDestructiveOnly);
}

NTSTATUS BddDdiQueryDeviceDescriptor
(
    IN_CONST_PVOID                  pDeviceContext,
    IN_ULONG                        ChildUid,
    INOUT_PDXGK_DEVICE_DESCRIPTOR   pDeviceDescriptor
)
{
    debug("[CALL]: NTSTATUS BddDdiQueryDeviceDescriptor");
    if ((!pDeviceContext) || (!pDeviceDescriptor))
    {
        debug("[ASRT]: One of pDeviceContext (%p), pDeviceDescriptor (%p) is NULL",
            pDeviceContext, pDeviceDescriptor);
        return STATUS_INVALID_PARAMETER;
    }
    if (ChildUid >= 1)
    {
        debug("[ASRT]: ChildUid >= 1");
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        // During stress testing of PnPStop, it is possible for BDD Fallback to get called to start then stop in quick succession.
        // The first call queues a worker thread item indicating that it now has a child device, the second queues a worker thread
        // item that it no longer has any child device. This function gets called based on the first worker thread item, but after
        // the driver has been stopped. Therefore instead of asserting like other functions, we only warn.
        debug("[ASRT]: BddDdiQueryDeviceDescriptor is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    // If we haven't successfully retrieved an EDID yet (invalid ones are ok, so long as it was retrieved)
    if (!m_Flags.EDID_Attempted)
    {
        RtlZeroMemory(&m_EDID, sizeof(m_EDID));
        //mbox_get_edid(&m_EDID); // EDID returns blank on Pi4 hardware anyway, attempting it is a cause of failure
        m_Flags.EDID_Attempted = TRUE;
    }
    if ((!m_Flags.EDID_Retrieved) || (!m_Flags.EDID_ValidHeader) || (!m_Flags.EDID_ValidChecksum))
    {
        // Report no EDID if a valid one wasn't retrieved
        return STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED;
    }
    else if (pDeviceDescriptor->DescriptorOffset == 0)
    {
        // Only the base block is supported
        RtlCopyMemory(pDeviceDescriptor->DescriptorBuffer, &m_EDID,
            min(pDeviceDescriptor->DescriptorLength, sizeof(m_EDID)));
        return STATUS_SUCCESS;
    }
    else { return STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA; }
}

NTSTATUS APIENTRY BddDdiRecommendMonitorModes
(
    IN_CONST_HANDLE                                 hAdapter,
    IN_CONST_PDXGKARG_RECOMMENDMONITORMODES_CONST   pRecommendMonitorModes
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiRecommendMonitorModes");
    if ((!hAdapter) || (!pRecommendMonitorModes))
    {
        debug("[ASRT]: One of hAdapter (%p), pRecommendMonitorModes (%p) is NULL",
            hAdapter, pRecommendMonitorModes);
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiRecommendMonitorModes is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    // This is always called to recommend modes for the monitor. The sample driver doesn't provide EDID for a monitor, so 
    // the OS prefills the list with default monitor modes. Since the required mode might not be in the list, it should 
    // be provided as a recommended mode.
    D3DKMDT_MONITOR_SOURCE_MODE* pMonitorSourceMode = NULL;
    NTSTATUS Status = pRecommendMonitorModes->pMonitorSourceModeSetInterface->pfnCreateNewModeInfo(pRecommendMonitorModes->hMonitorSourceModeSet, &pMonitorSourceMode);
    if (NT_ERROR(Status))
    {
        // If failed to create a new mode info, mode doesn't need to be released since it was never created
        debug("[WARN]: pfnCreateNewModeInfo failed with Status = 0x%08lX, hMonitorSourceModeSet = %p", Status, pRecommendMonitorModes->hMonitorSourceModeSet);
        return Status;
    }
    if (pRecommendMonitorModes->VideoPresentTargetId >= 1)
    {
        debug("[ASRT]: pRecommendMonitorModes->VideoPresentTargetId >= 1");
        return STATUS_INVALID_PARAMETER;
    }

    // Since we don't know the real monitor timing information, just use the current display mode (from the POST device) with unknown frequencies
    pMonitorSourceMode->VideoSignalInfo.VideoStandard = D3DKMDT_VSS_OTHER;
    pMonitorSourceMode->VideoSignalInfo.TotalSize.cx = m_CurrentMode.DispInfo.Width;
    pMonitorSourceMode->VideoSignalInfo.TotalSize.cy = m_CurrentMode.DispInfo.Height;
    pMonitorSourceMode->VideoSignalInfo.ActiveSize = pMonitorSourceMode->VideoSignalInfo.TotalSize;
    pMonitorSourceMode->VideoSignalInfo.VSyncFreq.Numerator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pMonitorSourceMode->VideoSignalInfo.VSyncFreq.Denominator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pMonitorSourceMode->VideoSignalInfo.HSyncFreq.Numerator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pMonitorSourceMode->VideoSignalInfo.HSyncFreq.Denominator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pMonitorSourceMode->VideoSignalInfo.PixelRate = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pMonitorSourceMode->VideoSignalInfo.ScanLineOrdering = D3DDDI_VSSLO_PROGRESSIVE;

    // We set the preference to PREFERRED since this is the only supported mode
    pMonitorSourceMode->Origin = D3DKMDT_MCO_DRIVER;
    pMonitorSourceMode->Preference = D3DKMDT_MP_PREFERRED;
    pMonitorSourceMode->ColorBasis = D3DKMDT_CB_SRGB;
    pMonitorSourceMode->ColorCoeffDynamicRanges.FirstChannel = 8;
    pMonitorSourceMode->ColorCoeffDynamicRanges.SecondChannel = 8;
    pMonitorSourceMode->ColorCoeffDynamicRanges.ThirdChannel = 8;
    pMonitorSourceMode->ColorCoeffDynamicRanges.FourthChannel = 8;

    Status = pRecommendMonitorModes->pMonitorSourceModeSetInterface->pfnAddMode(pRecommendMonitorModes->hMonitorSourceModeSet, pMonitorSourceMode);
    if (NT_ERROR(Status))
    {
        if (Status != STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET)
        {
            debug("[WARN]: pfnAddMode4 failed with Status (0x%08lX), hMonitorSourceModeSet (%p), pMonitorSourceMode (%p)",
                Status, pRecommendMonitorModes->hMonitorSourceModeSet, pMonitorSourceMode);
        }
        else { Status = STATUS_SUCCESS; }
        // If adding the mode failed, release the mode, if this doesn't work there is nothing that can be done, some memory will get leaked
        NTSTATUS TempStatus = pRecommendMonitorModes->pMonitorSourceModeSetInterface->pfnReleaseModeInfo(pRecommendMonitorModes->hMonitorSourceModeSet, pMonitorSourceMode);
        if (NT_ERROR(TempStatus))
        {
            debug("[WARN]: pfnReleaseModeInfo failed with Status (0x%08lX), hMonitorSourceModeSet (%p), pMonitorSourceMode (%p)",
                TempStatus, pRecommendMonitorModes->hMonitorSourceModeSet, pMonitorSourceMode);
        }
        return Status;
    }
    // If AddMode succeeded with something other than STATUS_SUCCESS treat it as such anyway when propagating up
    return STATUS_SUCCESS;
}

NTSTATUS APIENTRY BddDdiIsSupportedVidPn
(
    IN_CONST_HANDLE                   hAdapter,
    INOUT_PDXGKARG_ISSUPPORTEDVIDPN   pIsSupportedVidPn
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiIsSupportedVidPn");
    if (!hAdapter)
    {
        debug("[WARN]: One of hAdapter (%p), pIsSupportedVidPn (%p) is NULL",
            hAdapter, pIsSupportedVidPn);
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiIsSupportedVidPn is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    if (pIsSupportedVidPn->hDesiredVidPn == 0)
    {
        // A null desired VidPn is supported
        pIsSupportedVidPn->IsVidPnSupported = TRUE;
        return STATUS_SUCCESS;
    }

    // Default to not supported, until shown it is supported
    pIsSupportedVidPn->IsVidPnSupported = FALSE;

    CONST DXGK_VIDPN_INTERFACE* pVidPnInterface;
    NTSTATUS Status = m_DxgkInterface.DxgkCbQueryVidPnInterface(pIsSupportedVidPn->hDesiredVidPn, DXGK_VIDPN_INTERFACE_VERSION_V1, &pVidPnInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: DxgkCbQueryVidPnInterface failed with Status (0x%08lX), hDesiredVidPn (%p)",
            Status, pIsSupportedVidPn->hDesiredVidPn);
        return Status;
    }

    D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology;
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface;
    Status = pVidPnInterface->pfnGetTopology(pIsSupportedVidPn->hDesiredVidPn, &hVidPnTopology, &pVidPnTopologyInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnGetTopology failed with Status (0x%08lX), hDesiredVidPn (%p)",
            Status, pIsSupportedVidPn->hDesiredVidPn);
        return Status;
    }

    // Make sure there aren't more paths than there are targets
    SIZE_T NumPathsFromSource = 0;
    Status = pVidPnTopologyInterface->pfnGetNumPathsFromSource(hVidPnTopology, 0, &NumPathsFromSource);
    if (Status != STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY)
    {
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnGetNumPathsFromSource failed with Status (0x%08lX), hVidPnTopology (%p)",
                Status, hVidPnTopology);
            return Status;
        }
        else if (NumPathsFromSource > 1)
        {
            // This VidPn is not supported, which has already been set as the default
            return STATUS_SUCCESS;
        }
    }

    // All sources succeeded so this VidPn is supported
    pIsSupportedVidPn->IsVidPnSupported = TRUE;
    return STATUS_SUCCESS;
}

NTSTATUS APIENTRY BddDdiEnumVidPnCofuncModality
(
    IN_CONST_HANDLE                                   hAdapter,
    IN_CONST_PDXGKARG_ENUMVIDPNCOFUNCMODALITY_CONST   pEnumCofuncModality
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiEnumVidPnCofuncModality");
    if ((!hAdapter) || (!pEnumCofuncModality))
    {
        debug("[ASRT]: One of hAdapter (%p), pEnumCofuncModality(%p) is NULL",
            hAdapter, pEnumCofuncModality);
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiEnumVidPnCofuncModality is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }

    NTSTATUS Status = STATUS_SUCCESS;
    D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology = 0;
    D3DKMDT_HVIDPNSOURCEMODESET hVidPnSourceModeSet = 0;
    D3DKMDT_HVIDPNTARGETMODESET hVidPnTargetModeSet = 0;
    CONST DXGK_VIDPN_INTERFACE* pVidPnInterface = NULL;
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE* pVidPnSourceModeSetInterface = NULL;
    CONST DXGK_VIDPNTARGETMODESET_INTERFACE* pVidPnTargetModeSetInterface = NULL;
    CONST D3DKMDT_VIDPN_PRESENT_PATH* pVidPnPresentPath = NULL;
    CONST D3DKMDT_VIDPN_PRESENT_PATH* pVidPnPresentPathTemp = NULL; // Used for AcquireNextPathInfo
    CONST D3DKMDT_VIDPN_SOURCE_MODE* pVidPnPinnedSourceModeInfo = NULL;
    CONST D3DKMDT_VIDPN_TARGET_MODE* pVidPnPinnedTargetModeInfo = NULL;

    // Get the VidPn Interface so we can get the 'Source Mode Set', 'Target Mode Set' and 'VidPn Topology' interfaces
    Status = m_DxgkInterface.DxgkCbQueryVidPnInterface(pEnumCofuncModality->hConstrainingVidPn, DXGK_VIDPN_INTERFACE_VERSION_V1, &pVidPnInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: DxgkCbQueryVidPnInterface failed with Status (0x%08lX), hFunctionalVidPn (%p)",
            Status, pEnumCofuncModality->hConstrainingVidPn);
        return Status;
    }

    // Get the VidPn Topology interface so we can enumerate all paths
    Status = pVidPnInterface->pfnGetTopology(pEnumCofuncModality->hConstrainingVidPn, &hVidPnTopology, &pVidPnTopologyInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnGetTopology failed with Status (0x%08lX), hFunctionalVidPn (%p)",
            Status, pEnumCofuncModality->hConstrainingVidPn);
        return Status;
    }

    // Get the first path before we start looping through them
    Status = pVidPnTopologyInterface->pfnAcquireFirstPathInfo(hVidPnTopology, &pVidPnPresentPath);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnAcquireFirstPathInfo failed with Status (0x%08lX), hVidPnTopology (%p)",
            Status, hVidPnTopology);
        return Status;
    }

    // Loop through all available paths.
    while (Status != STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET)
    {
        // Get the Source Mode Set interface so the pinned mode can be retrieved
        Status = pVidPnInterface->pfnAcquireSourceModeSet(pEnumCofuncModality->hConstrainingVidPn,
            pVidPnPresentPath->VidPnSourceId, &hVidPnSourceModeSet, &pVidPnSourceModeSetInterface);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquireSourceModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnSourceId = 0x%08lX",
                Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnSourceId);
            break;
        }

        // Get the pinned mode, needed when VidPnSource isn't pivot, and when VidPnTarget isn't pivot
        Status = pVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet, &pVidPnPinnedSourceModeInfo);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquirePinnedModeInfo failed with Status (0x%08lX), hVidPnSourceModeSet (%p)",
                Status, hVidPnSourceModeSet);
            break;
        }

        // SOURCE MODES: If this source mode isn't the pivot point, do work on the source mode set
        if (!((pEnumCofuncModality->EnumPivotType == D3DKMDT_EPT_VIDPNSOURCE) &&
              (pEnumCofuncModality->EnumPivot.VidPnSourceId == pVidPnPresentPath->VidPnSourceId)))
        {
            // If there's no pinned source add possible modes (otherwise they've already been added)
            if (!pVidPnPinnedSourceModeInfo)
            {
                // Release the acquired source mode set, since going to create a new one to put all modes in
                Status = pVidPnInterface->pfnReleaseSourceModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnSourceModeSet);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnReleaseSourceModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p, hVidPnSourceModeSet (%p)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, hVidPnSourceModeSet);
                    break;
                }
                hVidPnSourceModeSet = 0; // Successfully released it

                // Create a new source mode set which will be added to the constraining VidPn with all the possible modes
                Status = pVidPnInterface->pfnCreateNewSourceModeSet(pEnumCofuncModality->hConstrainingVidPn,
                    pVidPnPresentPath->VidPnSourceId, &hVidPnSourceModeSet, &pVidPnSourceModeSetInterface);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnCreateNewSourceModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnSourceId (0x%08lX)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnSourceId);
                    break;
                }

                // Add the appropriate modes to the source mode set
                Status = AddSingleSourceMode(pVidPnSourceModeSetInterface, hVidPnSourceModeSet);
                if (NT_ERROR(Status))
                {
                    break;
                }

                // Give DMM back the source modes just populated
                Status = pVidPnInterface->pfnAssignSourceModeSet(pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnSourceId, hVidPnSourceModeSet);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnAssignSourceModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnSourceId (0x%08lX), hVidPnSourceModeSet (%p)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnSourceId, hVidPnSourceModeSet);
                    break;
                }
                hVidPnSourceModeSet = 0; // Successfully assigned it (equivalent to releasing it)
            }
        } // End: SOURCE MODES

        // TARGET MODES: If this target mode isn't the pivot point, do work on the target mode set
        if (!((pEnumCofuncModality->EnumPivotType == D3DKMDT_EPT_VIDPNTARGET) &&
              (pEnumCofuncModality->EnumPivot.VidPnTargetId == pVidPnPresentPath->VidPnTargetId)))
        {
            // Get the Target Mode Set interface so modes can be added if necessary
            Status = pVidPnInterface->pfnAcquireTargetModeSet(pEnumCofuncModality->hConstrainingVidPn,
                pVidPnPresentPath->VidPnTargetId,
                &hVidPnTargetModeSet,
                &pVidPnTargetModeSetInterface);
            if (NT_ERROR(Status))
            {
                debug("[WARN]: pfnAcquireTargetModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnTargetId (0x%08lX)",
                    Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnTargetId);
                break;
            }

            Status = pVidPnTargetModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnTargetModeSet, &pVidPnPinnedTargetModeInfo);
            if (!NT_SUCCESS(Status))
            {
                debug("[WARN]: pfnAcquirePinnedModeInfo failed with Status (0x%08lX), hVidPnTargetModeSet (%p)",
                    Status, hVidPnTargetModeSet);
                break;
            }

            // If there's no pinned target add possible modes (otherwise they've already been added)
            if (!pVidPnPinnedTargetModeInfo)
            {
                // Release the acquired target mode set, since going to create a new one to put all modes in
                Status = pVidPnInterface->pfnReleaseTargetModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnTargetModeSet);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnReleaseTargetModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), hVidPnTargetModeSet (%p)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, hVidPnTargetModeSet);
                    break;
                }
                hVidPnTargetModeSet = 0; // Successfully released it

                // Create a new target mode set which will be added to the constraining VidPn with all the possible modes
                Status = pVidPnInterface->pfnCreateNewTargetModeSet(pEnumCofuncModality->hConstrainingVidPn,
                    pVidPnPresentPath->VidPnTargetId, &hVidPnTargetModeSet, &pVidPnTargetModeSetInterface);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnCreateNewTargetModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnTargetId (0x%08lX)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnTargetId);
                    break;
                }

                Status = AddSingleTargetMode(pVidPnTargetModeSetInterface, hVidPnTargetModeSet, pVidPnPinnedSourceModeInfo);
                if (NT_ERROR(Status))
                {
                    break;
                }

                // Give BDD back the source modes just populated
                Status = pVidPnInterface->pfnAssignTargetModeSet(pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnTargetId, hVidPnTargetModeSet);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnAssignTargetModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), VidPnTargetId (0x%08lX), hVidPnTargetModeSet (%p)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, pVidPnPresentPath->VidPnTargetId, hVidPnTargetModeSet);
                    break;
                }
                hVidPnTargetModeSet = 0; // Successfully assigned it (equivalent to releasing it)
            }
            else
            {
                // Release the pinned target as there's no other work to do
                Status = pVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet, pVidPnPinnedTargetModeInfo);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnReleaseModeInfo failed with Status (0x%08lX), hVidPnTargetModeSet (%p), pVidPnPinnedTargetModeInfo (%p)",
                        Status, hVidPnTargetModeSet, pVidPnPinnedTargetModeInfo);
                    break;
                }
                pVidPnPinnedTargetModeInfo = NULL; // Successfully released it

                // Release the acquired target mode set, since it is no longer needed
                Status = pVidPnInterface->pfnReleaseTargetModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnTargetModeSet);
                if (NT_ERROR(Status))
                {
                    debug("[WARN]: pfnReleaseTargetModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), hVidPnTargetModeSet (%p)",
                        Status, pEnumCofuncModality->hConstrainingVidPn, hVidPnTargetModeSet);
                    break;
                }
                hVidPnTargetModeSet = 0; // Successfully released it
            }
        } // End: TARGET MODES

        // Nothing else needs the pinned source mode so release it
        if (pVidPnPinnedSourceModeInfo)
        {
            Status = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet, pVidPnPinnedSourceModeInfo);
            if (NT_ERROR(Status))
            {
                debug("[WARN]: pfnReleaseModeInfo failed with Status (0x%08lX), hVidPnSourceModeSet (%p), pVidPnPinnedSourceModeInfo (%p)",
                    Status, hVidPnSourceModeSet, pVidPnPinnedSourceModeInfo);
                break;
            }
            pVidPnPinnedSourceModeInfo = NULL; // Successfully released it
        }

        // With the pinned source mode now released, if the source mode set hasn't been released, release that as well
        if (hVidPnSourceModeSet)
        {
            Status = pVidPnInterface->pfnReleaseSourceModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnSourceModeSet);
            if (NT_ERROR(Status))
            {
                debug("[WARN]: pfnReleaseSourceModeSet failed with Status (0x%08lX), hConstrainingVidPn (%p), hVidPnSourceModeSet (%p)",
                    Status, pEnumCofuncModality->hConstrainingVidPn, hVidPnSourceModeSet);
                break;
            }
            hVidPnSourceModeSet = 0; // Successfully released it
        }

        // If modifying support fields, need to modify a local version of a path structure since the retrieved one is const
        D3DKMDT_VIDPN_PRESENT_PATH LocalVidPnPresentPath = *pVidPnPresentPath;
        BOOLEAN SupportFieldsModified = FALSE;

        // SCALING: If this path's scaling isn't the pivot point, do work on the scaling support
        if (!((pEnumCofuncModality->EnumPivotType == D3DKMDT_EPT_SCALING) &&
              (pEnumCofuncModality->EnumPivot.VidPnSourceId == pVidPnPresentPath->VidPnSourceId) &&
              (pEnumCofuncModality->EnumPivot.VidPnTargetId == pVidPnPresentPath->VidPnTargetId)))
        {
            // If the scaling is unpinned, then modify the scaling support field
            if (pVidPnPresentPath->ContentTransformation.Scaling == D3DKMDT_VPPS_UNPINNED)
            {
                // Identity and centered scaling are supported, but not any stretch modes
                RtlZeroMemory(&(LocalVidPnPresentPath.ContentTransformation.ScalingSupport), sizeof(D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT));
                LocalVidPnPresentPath.ContentTransformation.ScalingSupport.Identity = 1;
                LocalVidPnPresentPath.ContentTransformation.ScalingSupport.Centered = 1;
                SupportFieldsModified = TRUE;
            }
        } // End: SCALING

        // ROTATION: If this path's rotation isn't the pivot point, do work on the rotation support
        if (!((pEnumCofuncModality->EnumPivotType != D3DKMDT_EPT_ROTATION) &&
              (pEnumCofuncModality->EnumPivot.VidPnSourceId == pVidPnPresentPath->VidPnSourceId) &&
              (pEnumCofuncModality->EnumPivot.VidPnTargetId == pVidPnPresentPath->VidPnTargetId)))
        {
            // If the rotation is unpinned, then modify the rotation support field
            if (pVidPnPresentPath->ContentTransformation.Rotation == D3DKMDT_VPPR_UNPINNED)
            {
                LocalVidPnPresentPath.ContentTransformation.RotationSupport.Identity = 1;
                // Sample supports only Rotate90
                LocalVidPnPresentPath.ContentTransformation.RotationSupport.Rotate90 = 1;
                LocalVidPnPresentPath.ContentTransformation.RotationSupport.Rotate180 = 0;
                LocalVidPnPresentPath.ContentTransformation.RotationSupport.Rotate270 = 0;

                // Since clone is not supported, should not support path-independent rotations
                LocalVidPnPresentPath.ContentTransformation.RotationSupport.Offset0 = 1;

                SupportFieldsModified = TRUE;
            }
        } // End: ROTATION

        if (SupportFieldsModified)
        {
            // The correct path will be found by this function and the appropriate fields updated
            Status = pVidPnTopologyInterface->pfnUpdatePathSupportInfo(hVidPnTopology, &LocalVidPnPresentPath);
            if (NT_ERROR(Status))
            {
                debug("[WARN]: pfnUpdatePathSupportInfo failed with Status (0x%08lX), hVidPnTopology (%p)",
                    Status, hVidPnTopology);
                break;
            }
        }

        // Get the next path...
        // (NOTE: This is the value of Status that will return STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET when it's time to quit the loop)
        pVidPnPresentPathTemp = pVidPnPresentPath;
        Status = pVidPnTopologyInterface->pfnAcquireNextPathInfo(hVidPnTopology, pVidPnPresentPathTemp, &pVidPnPresentPath);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquireNextPathInfo failed with Status (0x%08lX), hVidPnTopology (%p), pVidPnPresentPathTemp (%p)",
                Status, hVidPnTopology, pVidPnPresentPathTemp);
            break;
        }

        // ...and release the last path
        NTSTATUS TempStatus = pVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology, pVidPnPresentPathTemp);
        if (NT_ERROR(TempStatus))
        {
            debug("[WARN]: pfnReleasePathInfo failed with Status (0x%08lX, hVidPnTopology (%p), pVidPnPresentPathTemp (%p)",
                TempStatus, hVidPnTopology, pVidPnPresentPathTemp);
            Status = TempStatus;
            break;
        }
        pVidPnPresentPathTemp = NULL; // Successfully released it
    } // End: while loop for paths in topology

    // If quit the while loop normally, set the return value to success
    if (Status == STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET) { Status = STATUS_SUCCESS; }

    // Release any resources hanging around because the loop was quit early.
    // Since in normal execution everything should be released by this point, TempStatus is initialized to a bogus error to be used as an
    // assertion that if anything had to be released now (TempStatus changing) Status isn't successful.
    NTSTATUS TempStatus = STATUS_NOT_FOUND;
    if ((pVidPnSourceModeSetInterface) && (pVidPnPinnedSourceModeInfo))
    {
        TempStatus = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet, pVidPnPinnedSourceModeInfo);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: pVidPnSourceModeSetInterface || pVidPnPinnedSourceModeInfo"); return STATUS_ABANDONED; }
    }
    if ((pVidPnTargetModeSetInterface) && (pVidPnPinnedTargetModeInfo))
    {
        TempStatus = pVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet, pVidPnPinnedTargetModeInfo);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: pVidPnTargetModeSetInterface || pVidPnPinnedTargetModeInfo"); return STATUS_ABANDONED; }
    }
    if (pVidPnPresentPath)
    {
        TempStatus = pVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology, pVidPnPresentPath);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: pVidPnPresentPath"); return STATUS_ABANDONED; }
    }
    if (pVidPnPresentPathTemp)
    {
        TempStatus = pVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology, pVidPnPresentPathTemp);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: pVidPnPresentPathTemp"); return STATUS_ABANDONED; }
    }
    if (hVidPnSourceModeSet)
    {
        TempStatus = pVidPnInterface->pfnReleaseSourceModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnSourceModeSet);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: hVidPnSourceModeSet"); return STATUS_ABANDONED; }
    }
    if (hVidPnTargetModeSet)
    {
        TempStatus = pVidPnInterface->pfnReleaseTargetModeSet(pEnumCofuncModality->hConstrainingVidPn, hVidPnTargetModeSet);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: hVidPnTargetModeSet"); return STATUS_ABANDONED; }
    }
    if (!((TempStatus == STATUS_NOT_FOUND) || (Status != STATUS_SUCCESS)))
    {
        debug("[ASRT]: (TempStatus != STATUS_NOT_FOUND) || (Status != STATUS_SUCCESS)");
        return STATUS_ABANDONED;
    }
    return Status;
}

NTSTATUS AddSingleSourceMode
(
    _In_ CONST DXGK_VIDPNSOURCEMODESET_INTERFACE*   pVidPnSourceModeSetInterface,
    D3DKMDT_HVIDPNSOURCEMODESET                     hVidPnSourceModeSet
)
{
    debug("[CALL]: NTSTATUS AddSingleSourceMode");
    // Create new mode info that will be populated
    D3DKMDT_VIDPN_SOURCE_MODE* pVidPnSourceModeInfo = NULL;
    NTSTATUS Status = pVidPnSourceModeSetInterface->pfnCreateNewModeInfo(hVidPnSourceModeSet, &pVidPnSourceModeInfo);
    if (NT_ERROR(Status))
    {
        // If failed to create a new mode info, mode doesn't need to be released since it was never created
        debug("[WARN]: pfnCreateNewModeInfo failed with Status (0x%08lX), hVidPnSourceModeSet (%p)",
            Status, hVidPnSourceModeSet);
        return Status;
    }

    // Populate mode info with values from current mode and hard-coded values
    // Always report 32 bpp format, this will be color converted during the present if the mode is < 32bpp
    pVidPnSourceModeInfo->Type = D3DKMDT_RMT_GRAPHICS;
    pVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cx = m_CurrentMode.DispInfo.Width;
    pVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cy = m_CurrentMode.DispInfo.Height;
    pVidPnSourceModeInfo->Format.Graphics.VisibleRegionSize = pVidPnSourceModeInfo->Format.Graphics.PrimSurfSize;
    debug("[INFO]: PrimWidth: %u | PrimHeight: %u", pVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cx, pVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cy);
    debug("[INFO]: VisibleWidth: %u | VisibleHeight: %u", pVidPnSourceModeInfo->Format.Graphics.VisibleRegionSize.cx, pVidPnSourceModeInfo->Format.Graphics.VisibleRegionSize.cy);
    pVidPnSourceModeInfo->Format.Graphics.Stride = m_CurrentMode.DispInfo.Pitch;
    //debug("[INFO]: Pitch: %u (0x%04X)", m_CurrentModes[SourceId].DispInfo.Pitch, m_CurrentModes[SourceId].DispInfo.Pitch);
    debug("[INFO]: Stride: %u (0x%04X)", pVidPnSourceModeInfo->Format.Graphics.Stride, pVidPnSourceModeInfo->Format.Graphics.Stride);
    pVidPnSourceModeInfo->Format.Graphics.PixelFormat = m_CurrentMode.DispInfo.ColorFormat; //gBddPixelFormats[PelFmtIdx]; // <-- NONSENSE.
    pVidPnSourceModeInfo->Format.Graphics.ColorBasis = D3DKMDT_CB_SCRGB;
    pVidPnSourceModeInfo->Format.Graphics.PixelValueAccessMode = D3DKMDT_PVAM_DIRECT;

    // Add the mode to the source mode set
    Status = pVidPnSourceModeSetInterface->pfnAddMode(hVidPnSourceModeSet, pVidPnSourceModeInfo);
    if (NT_ERROR(Status))
    {
        // If adding the mode failed, release the mode, if this doesn't work there is nothing that can be done, some memory will get leaked
        NTSTATUS TempStatus = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet, pVidPnSourceModeInfo);
        if (NT_ERROR(TempStatus)) { debug("[ASRT]: pfnReleaseModeInfo failed with Status (0x%08lX", TempStatus); }

        if (Status != STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET)
        {
            debug("[WARN]: pfnAddMode1 failed with Status (0x%08lX), hVidPnSourceModeSet (%p), pVidPnSourceModeInfo (%p)",
                Status, hVidPnSourceModeSet, pVidPnSourceModeInfo);
            return Status;
        }
    }

    D3DKMDT_VIDPN_SOURCE_MODE* pVidPnSourceModeInfo2 = NULL;
    Status = pVidPnSourceModeSetInterface->pfnCreateNewModeInfo(hVidPnSourceModeSet, &pVidPnSourceModeInfo2);
    if (NT_ERROR(Status))
    {
        // If failed to create a new mode info, continuing to the next mode and trying again isn't going to be at all helpful, so return
        // Also, mode doesn't need to be released since it was never created
        debug("[WARN]: pfnCreateNewModeInfo failed with Status (0x%08lX), hVidPnSourceModeSet (%p)",
            Status, hVidPnSourceModeSet);
        return Status;
    }

    // Populate mode info with values from mode at ModeIndex and hard-coded values
    // Always report 32 bpp format, this will be color converted during the present if the mode at ModeIndex was < 32bpp
    pVidPnSourceModeInfo2->Type = D3DKMDT_RMT_GRAPHICS;
    pVidPnSourceModeInfo2->Format.Graphics.PrimSurfSize.cx = m_CurrentMode.DispInfo.Width; //C_SampleSourceMode[ModeIndex].ModeWidth; // <-- GIBBERISH
    pVidPnSourceModeInfo2->Format.Graphics.PrimSurfSize.cy = m_CurrentMode.DispInfo.Height; //C_SampleSourceMode[ModeIndex].ModeHeight; // <-- GIBBERISH
    pVidPnSourceModeInfo2->Format.Graphics.VisibleRegionSize = pVidPnSourceModeInfo2->Format.Graphics.PrimSurfSize;
    pVidPnSourceModeInfo2->Format.Graphics.Stride = m_CurrentMode.DispInfo.Pitch; //4*C_SampleSourceMode[ModeIndex].ModeWidth; // <-- TEMPORARY SOLUTION
    pVidPnSourceModeInfo2->Format.Graphics.PixelFormat = m_CurrentMode.DispInfo.ColorFormat; //gBddPixelFormats[PelFmtIdx]; // <-- TEMPORARY SOLUTION
    pVidPnSourceModeInfo2->Format.Graphics.ColorBasis = D3DKMDT_CB_SCRGB;
    pVidPnSourceModeInfo2->Format.Graphics.PixelValueAccessMode = D3DKMDT_PVAM_DIRECT;

    // Add the mode to the source mode set
    Status = pVidPnSourceModeSetInterface->pfnAddMode(hVidPnSourceModeSet, pVidPnSourceModeInfo2);
    if (NT_ERROR(Status))
    {
        if (Status != STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET)
        {
            debug("[WARN]: pfnAddMode2 failed with Status (0x%08lX), hVidPnSourceModeSet (%p), pVidPnSourceModeInfo2 (%p)",
                Status, hVidPnSourceModeSet, pVidPnSourceModeInfo2);
        }
        // If adding the mode failed, release the mode, if this doesn't work there is nothing that can be done, some memory will get leaked, continue to next mode anyway
        Status = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet, pVidPnSourceModeInfo2);
        if (NT_ERROR(Status))
        {
            debug("[ASRT]: pVidPnSourceModeInfo2 failed with Status (0x%08lX), hVidPnSourceModeSet (%p), pVidPnSourceModeInfo2 (%p)",
                Status, hVidPnSourceModeSet, pVidPnSourceModeInfo2);
            return Status;
        }
    }
    return STATUS_SUCCESS;
}

NTSTATUS AddSingleTargetMode
(
    _In_ CONST DXGK_VIDPNTARGETMODESET_INTERFACE*   pVidPnTargetModeSetInterface,
    D3DKMDT_HVIDPNTARGETMODESET                     hVidPnTargetModeSet,
    _In_opt_ CONST D3DKMDT_VIDPN_SOURCE_MODE*       pVidPnPinnedSourceModeInfo
)
{
    debug("[CALL]: NTSTATUS AddSingleTargetMode");
    D3DKMDT_VIDPN_TARGET_MODE* pVidPnTargetModeInfo = NULL;
    NTSTATUS Status = pVidPnTargetModeSetInterface->pfnCreateNewModeInfo(hVidPnTargetModeSet, &pVidPnTargetModeInfo);
    if (NT_ERROR(Status))
    {
        // If failed to create a new mode info, mode doesn't need to be released since it was never created
        debug("[WARN]: pfnCreateNewModeInfo failed with Status (0x%08lX), hVidPnTargetModeSet(%p)",
            Status, hVidPnTargetModeSet);
        return Status;
    }

    pVidPnTargetModeInfo->VideoSignalInfo.VideoStandard = D3DKMDT_VSS_OTHER;
    UNREFERENCED_PARAMETER(pVidPnPinnedSourceModeInfo);
    pVidPnTargetModeInfo->VideoSignalInfo.TotalSize.cx = m_CurrentMode.DispInfo.Width;
    pVidPnTargetModeInfo->VideoSignalInfo.TotalSize.cy = m_CurrentMode.DispInfo.Height;
    pVidPnTargetModeInfo->VideoSignalInfo.ActiveSize = pVidPnTargetModeInfo->VideoSignalInfo.TotalSize;
    pVidPnTargetModeInfo->VideoSignalInfo.VSyncFreq.Numerator = D3DKMDT_FREQUENCY_NOTSPECIFIED; ///!!!Set to 60???
    pVidPnTargetModeInfo->VideoSignalInfo.VSyncFreq.Denominator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pVidPnTargetModeInfo->VideoSignalInfo.HSyncFreq.Numerator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pVidPnTargetModeInfo->VideoSignalInfo.HSyncFreq.Denominator = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pVidPnTargetModeInfo->VideoSignalInfo.PixelRate = D3DKMDT_FREQUENCY_NOTSPECIFIED;
    pVidPnTargetModeInfo->VideoSignalInfo.ScanLineOrdering = D3DDDI_VSSLO_PROGRESSIVE;
    // We add this as PREFERRED since it is the only supported target
    pVidPnTargetModeInfo->Preference = D3DKMDT_MP_PREFERRED;

    Status = pVidPnTargetModeSetInterface->pfnAddMode(hVidPnTargetModeSet, pVidPnTargetModeInfo);
    if (NT_ERROR(Status))
    {
        if (Status != STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET)
        {
            debug("[WARN]: pfnAddMode3 failed with Status (0x%08lX), hVidPnTargetModeSet (%p), pVidPnTargetModeInfo (%p)",
                Status, hVidPnTargetModeSet, pVidPnTargetModeInfo);
        }
        else { Status = STATUS_SUCCESS; }

        // If adding the mode failed, release the mode, if this doesn't work there is nothing that can be done, some memory will get leaked
        NTSTATUS TempStatus = pVidPnTargetModeSetInterface->pfnReleaseModeInfo(hVidPnTargetModeSet, pVidPnTargetModeInfo);
        if (NT_ERROR(TempStatus))
        {
            debug("[ASRT]: pfnReleaseModeInfo failed with Status (0x%08lX), hVidPnTargetModeSet (%p), pVidPnTargetModeInfo (%p)",
                TempStatus, hVidPnTargetModeSet, pVidPnTargetModeInfo);
            return Status;
        }
    }
    // If AddMode succeeded with something other than STATUS_SUCCESS treat it as such anyway when propagating up
    return STATUS_SUCCESS;
}

NTSTATUS APIENTRY BddDdiCommitVidPn
(
    IN_CONST_HANDLE                       hAdapter,
    IN_CONST_PDXGKARG_COMMITVIDPN_CONST   pCommitVidPn
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiCommitVidPn");
    if (!hAdapter || (!pCommitVidPn))
    {
        debug("[WARN]: One of hAdapter (%p), pCommitVidPn (%p) is NULL",
            hAdapter, pCommitVidPn);
        return STATUS_INVALID_PARAMETER;
    }
    if (pCommitVidPn->AffectedVidPnSourceId >= 1)
    {
        debug("[ASRT]: pCommitVidPn->AffectedVidPnSourceId >= 1");
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiCommitVidPn is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }

    NTSTATUS Status = STATUS_SUCCESS;
    SIZE_T NumPaths = 0;
    D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology = 0;
    D3DKMDT_HVIDPNSOURCEMODESET hVidPnSourceModeSet = 0;
    CONST DXGK_VIDPN_INTERFACE* pVidPnInterface = NULL;
    CONST DXGK_VIDPNTOPOLOGY_INTERFACE* pVidPnTopologyInterface = NULL;
    CONST DXGK_VIDPNSOURCEMODESET_INTERFACE* pVidPnSourceModeSetInterface = NULL;
    CONST D3DKMDT_VIDPN_PRESENT_PATH* pVidPnPresentPath = NULL;
    CONST D3DKMDT_VIDPN_SOURCE_MODE* pPinnedVidPnSourceModeInfo = NULL;

    // Check this CommitVidPn is for the mode change notification when monitor is in power off state.
    if (pCommitVidPn->Flags.PathPoweredOff)
    {
        // Ignore the commitVidPn call for the mode change notification when monitor is in power off state.
        Status = STATUS_SUCCESS;
        goto CommitVidPnExit;
    }

    // Get the VidPn Interface so we can get the 'Source Mode Set' and 'VidPn Topology' interfaces
    Status = m_DxgkInterface.DxgkCbQueryVidPnInterface(pCommitVidPn->hFunctionalVidPn, DXGK_VIDPN_INTERFACE_VERSION_V1, &pVidPnInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: DxgkCbQueryVidPnInterface failed with Status (0x%08lX), hFunctionalVidPn (%p)",
            Status, pCommitVidPn->hFunctionalVidPn);
        goto CommitVidPnExit;
    }

    // Get the VidPn Topology interface so can enumerate paths from source
    Status = pVidPnInterface->pfnGetTopology(pCommitVidPn->hFunctionalVidPn, &hVidPnTopology, &pVidPnTopologyInterface);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnGetTopology failed with Status (0x%08lX), hFunctionalVidPn (%p)",
            Status, pCommitVidPn->hFunctionalVidPn);
        goto CommitVidPnExit;
    }

    // Find out the number of paths now, if it's 0 don't bother with source mode set and pinned mode, just clear current and then quit
    Status = pVidPnTopologyInterface->pfnGetNumPaths(hVidPnTopology, &NumPaths);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnGetNumPaths failed with Status (0x%08lX), hVidPnTopology (%p)",
            Status, hVidPnTopology);
        goto CommitVidPnExit;
    }

    if (NumPaths != 0)
    {
        // Get the Source Mode Set interface so we can get the pinned mode
        Status = pVidPnInterface->pfnAcquireSourceModeSet(pCommitVidPn->hFunctionalVidPn,
            pCommitVidPn->AffectedVidPnSourceId,
            &hVidPnSourceModeSet,
            &pVidPnSourceModeSetInterface);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquireSourceModeSet failed with Status (0x%08lX), hFunctionalVidPn, (%p), AffectedVidPnSourceId (0x%08lX)",
                Status, pCommitVidPn->hFunctionalVidPn, pCommitVidPn->AffectedVidPnSourceId);
            goto CommitVidPnExit;
        }

        // Get the mode that is being pinned
        Status = pVidPnSourceModeSetInterface->pfnAcquirePinnedModeInfo(hVidPnSourceModeSet, &pPinnedVidPnSourceModeInfo);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquirePinnedModeInfo failed with Status (0x%08lX), hFunctionalVidPn (%p)",
                Status, pCommitVidPn->hFunctionalVidPn);
            goto CommitVidPnExit;
        }
    }
    else
    {
        // This will cause the successful quit below
        pPinnedVidPnSourceModeInfo = NULL;
    }

    if ((m_CurrentMode.FrameBuffer.Ptr) && (!m_CurrentMode.Flags.DoNotMapOrUnmap))
    {
        Status = UnmapFrameBuffer(m_CurrentMode.FrameBuffer.Ptr, m_CurrentMode.DispInfo.Pitch * m_CurrentMode.DispInfo.Height);
        m_CurrentMode.FrameBuffer.Ptr = NULL;
        m_CurrentMode.Flags.FrameBufferIsActive = FALSE;

        if (NT_ERROR(Status)) { goto CommitVidPnExit; }
    }

    if (!pPinnedVidPnSourceModeInfo)
    {
        // There is no mode to pin on this source, any old paths here have already been cleared
        Status = STATUS_SUCCESS;
        goto CommitVidPnExit;
    }

    if (pPinnedVidPnSourceModeInfo->Type != D3DKMDT_RMT_GRAPHICS)
    {
        debug("[WARN]: pSourceMode is a non-graphics mode (0x%8lX)",
            pPinnedVidPnSourceModeInfo->Type);
        goto CommitVidPnExit;
    }
    else if ((pPinnedVidPnSourceModeInfo->Format.Graphics.ColorBasis != D3DKMDT_CB_SCRGB) &&
             (pPinnedVidPnSourceModeInfo->Format.Graphics.ColorBasis != D3DKMDT_CB_UNINITIALIZED))
    {
        debug("[WARN]: pSourceMode has a non-linear RGB color basis (0x%08lX)",
            pPinnedVidPnSourceModeInfo->Format.Graphics.ColorBasis);
        goto CommitVidPnExit;
    }
    else if (pPinnedVidPnSourceModeInfo->Format.Graphics.PixelValueAccessMode != D3DKMDT_PVAM_DIRECT)
    {
        debug("[WARN]: pSourceMode has a palettized access mode (0x%08lX)",
            pPinnedVidPnSourceModeInfo->Format.Graphics.PixelValueAccessMode);
        goto CommitVidPnExit;
    }
    else
    {
        if (pPinnedVidPnSourceModeInfo->Format.Graphics.PixelFormat != D3DDDIFMT_A8R8G8B8)
        {
            debug("[WARN]: pSourceMode has an unknown pixel format (0x%08lX)",
                pPinnedVidPnSourceModeInfo->Format.Graphics.PixelFormat);
            goto CommitVidPnExit;
        }
    }

    // Get the number of paths from this source so we can loop through all paths
    SIZE_T NumPathsFromSource = 0;
    Status = pVidPnTopologyInterface->pfnGetNumPathsFromSource(hVidPnTopology, pCommitVidPn->AffectedVidPnSourceId, &NumPathsFromSource);
    if (NT_ERROR(Status))
    {
        debug("[WARN]: pfnGetNumPathsFromSource failed with Status (0x%08lX), hVidPnTopology (%p)",
            Status, hVidPnTopology);
        goto CommitVidPnExit;
    }

    // Loop through all paths to set this mode
    for (SIZE_T PathIndex = 0; PathIndex < NumPathsFromSource; ++PathIndex)
    {
        // Get the target id for this path
        D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId = D3DDDI_ID_UNINITIALIZED;
        Status = pVidPnTopologyInterface->pfnEnumPathTargetsFromSource(hVidPnTopology, pCommitVidPn->AffectedVidPnSourceId, PathIndex, &TargetId);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnEnumPathTargetsFromSource failed with Status (0x%08lX), hVidPnTopology (%p), AffectedVidPnSourceId (0x%08lX), PathIndex (0x%016llX)",
                Status, hVidPnTopology, pCommitVidPn->AffectedVidPnSourceId, PathIndex);
            goto CommitVidPnExit;
        }

        // Get the actual path info
        Status = pVidPnTopologyInterface->pfnAcquirePathInfo(hVidPnTopology, pCommitVidPn->AffectedVidPnSourceId, TargetId, &pVidPnPresentPath);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnAcquirePathInfo failed with Status (0x%08lX), hVidPnTopology (%p), AffectedVidPnSourceId (0x%08lX), TargetId (0x%08lX)",
                Status, hVidPnTopology, pCommitVidPn->AffectedVidPnSourceId, TargetId);
            goto CommitVidPnExit;
        }

        if ((pVidPnPresentPath->VidPnSourceId >= 1) || (pVidPnPresentPath->VidPnTargetId >= 1))
        {
            debug("[WARN]: (VidPnSourceId >= 1) || (VidPnTargetId >= 1)");
            goto CommitVidPnExit;
        }
        else if (pVidPnPresentPath->GammaRamp.Type != D3DDDI_GAMMARAMP_DEFAULT)
        {
            debug("[WARN]: pVidPnPresentPath contains a gamma ramp (0x%08lX)",
                pVidPnPresentPath->GammaRamp.Type);
            goto CommitVidPnExit;
        }
        else if ((pVidPnPresentPath->ContentTransformation.Scaling != D3DKMDT_VPPS_IDENTITY) &&
                 (pVidPnPresentPath->ContentTransformation.Scaling != D3DKMDT_VPPS_CENTERED) &&
                 (pVidPnPresentPath->ContentTransformation.Scaling != D3DKMDT_VPPS_NOTSPECIFIED) &&
                 (pVidPnPresentPath->ContentTransformation.Scaling != D3DKMDT_VPPS_UNINITIALIZED))
        {
            debug("[WARN]: pVidPnPresentPath contains a non-identity scaling (0x%08lX)",
                pVidPnPresentPath->ContentTransformation.Scaling);
            goto CommitVidPnExit;
        }
        else if ((pVidPnPresentPath->ContentTransformation.Rotation != D3DKMDT_VPPR_IDENTITY) &&
                 (pVidPnPresentPath->ContentTransformation.Rotation != D3DKMDT_VPPR_ROTATE90) &&
                 (pVidPnPresentPath->ContentTransformation.Rotation != D3DKMDT_VPPR_NOTSPECIFIED) &&
                 (pVidPnPresentPath->ContentTransformation.Rotation != D3DKMDT_VPPR_UNINITIALIZED))
        {
            debug("[WARN]: pVidPnPresentPath contains a not-supported rotation (0x%08lX)",
                pVidPnPresentPath->ContentTransformation.Rotation);
            goto CommitVidPnExit;
        }
        else if ((pVidPnPresentPath->VidPnTargetColorBasis != D3DKMDT_CB_SCRGB) &&
                 (pVidPnPresentPath->VidPnTargetColorBasis != D3DKMDT_CB_UNINITIALIZED))
        {
            debug("[WARN]: pVidPnPresentPath has a non-linear RGB color basis (0x%08lX)",
                pVidPnPresentPath->VidPnTargetColorBasis);
            goto CommitVidPnExit;
        }

        debug("[CALL]: NTSTATUS BASIC_DISPLAY_DRIVER::SetSourceModeAndPath");
        CURRENT_BDD_MODE* pCurrentBddMode = &m_CurrentMode;

        pCurrentBddMode->Scaling = pVidPnPresentPath->ContentTransformation.Scaling;
        pCurrentBddMode->SrcModeWidth = pPinnedVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cx;
        pCurrentBddMode->SrcModeHeight = pPinnedVidPnSourceModeInfo->Format.Graphics.PrimSurfSize.cy;
        pCurrentBddMode->Rotation = pVidPnPresentPath->ContentTransformation.Rotation;

        if (!pCurrentBddMode->Flags.DoNotMapOrUnmap)
        {
            // Map the new frame buffer
            if (pCurrentBddMode->FrameBuffer.Ptr)
            {
                debug("[ASRT]: pCurrentBddMode->FrameBuffer.Ptr != NULL");
                return STATUS_ABANDONED;
            }
            Status = MapFrameBuffer(pCurrentBddMode->DispInfo.PhysicAddress, pCurrentBddMode->DispInfo.Pitch * pCurrentBddMode->DispInfo.Height, &(pCurrentBddMode->FrameBuffer.Ptr));
        }
        if (NT_SUCCESS(Status))
        {
            pCurrentBddMode->Flags.FrameBufferIsActive = TRUE;

            UINT32 ScreenHeight = m_CurrentMode.DispInfo.Height;
            UINT32 ScreenPitch = m_CurrentMode.DispInfo.Pitch;
            PHYSICAL_ADDRESS NewPhysAddrStart = m_CurrentMode.DispInfo.PhysicAddress;
            PHYSICAL_ADDRESS NewPhysAddrEnd;
            NewPhysAddrEnd.QuadPart = NewPhysAddrStart.QuadPart + ((LONGLONG)ScreenHeight * ScreenPitch);
            if (m_CurrentMode.Flags.FrameBufferIsActive)
            {
                BYTE* MappedAddr = reinterpret_cast<BYTE*>(m_CurrentMode.FrameBuffer.Ptr);
                // Zero any memory at the start that hasn't been zeroed recently
                if (NewPhysAddrStart.QuadPart < m_CurrentMode.ZeroedOutStart.QuadPart)
                {
                    if (NewPhysAddrEnd.QuadPart < m_CurrentMode.ZeroedOutStart.QuadPart)
                    {
                        // No overlap
                        RtlZeroMemory(MappedAddr, ((LONGLONG)ScreenHeight * ScreenPitch));
                    }
                    else { RtlZeroMemory(MappedAddr, (UINT32)(m_CurrentMode.ZeroedOutStart.QuadPart - NewPhysAddrStart.QuadPart)); }
                }
                // Zero any memory at the end that hasn't been zeroed recently
                if (NewPhysAddrEnd.QuadPart > m_CurrentMode.ZeroedOutEnd.QuadPart)
                {
                    if (NewPhysAddrStart.QuadPart > m_CurrentMode.ZeroedOutEnd.QuadPart)
                    {
                        // No overlap
                        // NOTE: When actual pixels were the most recent thing drawn, ZeroedOutStart & ZeroedOutEnd will both be 0
                        // and this is the path that will be used to black out the current screen.
                        RtlZeroMemory(MappedAddr, ((LONGLONG)ScreenHeight * ScreenPitch));
                    }
                    else { RtlZeroMemory(MappedAddr, (UINT32)(NewPhysAddrEnd.QuadPart - m_CurrentMode.ZeroedOutEnd.QuadPart)); }
                }
            }
            m_CurrentMode.ZeroedOutStart.QuadPart = NewPhysAddrStart.QuadPart;
            m_CurrentMode.ZeroedOutEnd.QuadPart = NewPhysAddrEnd.QuadPart;
            // Mark that the next present should be fullscreen so the screen doesn't go from black to actual pixels one dirty rect at a time.

            pCurrentBddMode->Flags.FullscreenPresent = TRUE;
        }

        Status = pVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology, pVidPnPresentPath);
        if (NT_ERROR(Status))
        {
            debug("[WARN]: pfnReleasePathInfo failed with Status (0x%08lX), hVidPnTopology (%p), pVidPnPresentPath (%p)",
                Status, hVidPnTopology, pVidPnPresentPath);
            goto CommitVidPnExit;
        }
        pVidPnPresentPath = NULL; // Successfully released it
    }

CommitVidPnExit:
    NTSTATUS TempStatus = STATUS_SUCCESS;
    if ((pVidPnSourceModeSetInterface) && (hVidPnSourceModeSet) && (pPinnedVidPnSourceModeInfo))
    {
        TempStatus = pVidPnSourceModeSetInterface->pfnReleaseModeInfo(hVidPnSourceModeSet, pPinnedVidPnSourceModeInfo);
        if (NT_ERROR(TempStatus))
        {
            debug("[ASRT]: pfnReleaseModeInfo failed with Status (0x%08lX), hVidPnSourceModeSet (%p), pPinnedVidPnSourceModeInfo (%p)",
                TempStatus, hVidPnSourceModeSet, pPinnedVidPnSourceModeInfo);
        }
    }
    if ((pVidPnInterface) && (pCommitVidPn->hFunctionalVidPn) && (hVidPnSourceModeSet))
    {
        TempStatus = pVidPnInterface->pfnReleaseSourceModeSet(pCommitVidPn->hFunctionalVidPn, hVidPnSourceModeSet);
        if (NT_ERROR(TempStatus))
        {
            debug("[ASRT]: pfnReleaseSourceModeSet failed with Status (0x%08lX), hFunctionalVidPn (%p), hVidPnSourceModeSet (%p)",
                TempStatus, pCommitVidPn->hFunctionalVidPn, hVidPnSourceModeSet);
        }
    }
    if ((pVidPnTopologyInterface) && (hVidPnTopology) && (pVidPnPresentPath))
    {
        TempStatus = pVidPnTopologyInterface->pfnReleasePathInfo(hVidPnTopology, pVidPnPresentPath);
        if (NT_ERROR(TempStatus))
        {
            debug("[ASRT]: pfnReleasePathInfo failed with Status (0x%08lX), hVidPnTopology (%p), pVidPnPresentPath (%p)",
                TempStatus, hVidPnTopology, pVidPnPresentPath);
        }
    }
    return Status;
}

NTSTATUS MapFrameBuffer
(
    _In_ PHYSICAL_ADDRESS                       PhysicalAddress,
    _In_ ULONG                                  Length,
    _Outptr_result_bytebuffer_(Length) PVOID*   VirtualAddress
)
{
    debug("[CALL]: NTSTATUS MapFrameBuffer | FrameBuffer: 0x%016llX", PhysicalAddress.QuadPart);
    if ((!PhysicalAddress.QuadPart) || (!Length) || (!VirtualAddress))
    {
        debug("[WARN]: One of PhysicalAddress.QuadPart (0x%016llX), Length (0x%08lX), VirtualAddress (%p) is NULL",
            PhysicalAddress.QuadPart, Length, VirtualAddress);
        return STATUS_INVALID_PARAMETER;
    }

    *VirtualAddress = MmMapIoSpaceEx(PhysicalAddress, Length, PAGE_READWRITE | PAGE_WRITECOMBINE);
    if (!(*VirtualAddress))
    {
        // The underlying call to MmMapIoSpace failed. This may be because, MmWriteCombined
        // isn't supported, so try again with MmNonCached
        *VirtualAddress = MmMapIoSpaceEx(PhysicalAddress, Length, PAGE_READWRITE | PAGE_NOCACHE);
        if (!(*VirtualAddress))
        {
            debug("[WARN]: MmMapIoSpace returned a NULL buffer when trying to allocate 0x%08lX bytes", Length);
            return STATUS_NO_MEMORY;
        }
    }
    return STATUS_SUCCESS;
}

NTSTATUS APIENTRY BddDdiSetVidPnSourceVisibility
(
    IN_CONST_HANDLE                              hAdapter,
    IN_CONST_PDXGKARG_SETVIDPNSOURCEVISIBILITY   pSetVidPnSourceVisibility
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiSetVidPnSourceVisibility");
    if ((!hAdapter) || (!pSetVidPnSourceVisibility))
    {
        debug("[ASRT]: One of hAdapter (%p), pSetVidPnSourceVisibility (%p) is NULL",
            hAdapter, pSetVidPnSourceVisibility);
        return STATUS_INVALID_PARAMETER;
    }
    if (!((pSetVidPnSourceVisibility->VidPnSourceId < 1) || (pSetVidPnSourceVisibility->VidPnSourceId == D3DDDI_ID_ALL)))
    {
        debug("[ASRT]: (pSetVidPnSourceVisibility->VidPnSourceId < 1) || (pSetVidPnSourceVisibility->VidPnSourceId == D3DDDI_ID_ALL)");
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiSetVidPnSourceVisibility is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    debug("[CALL]: NTSTATUS BASIC_DISPLAY_DRIVER::SetVidPnSourceVisibility");
    
    UINT32 StartVidPnSourceId = (pSetVidPnSourceVisibility->VidPnSourceId == D3DDDI_ID_ALL) ? 0 : pSetVidPnSourceVisibility->VidPnSourceId;
    UINT32 MaxVidPnSourceId = (pSetVidPnSourceVisibility->VidPnSourceId == D3DDDI_ID_ALL) ? 1 : pSetVidPnSourceVisibility->VidPnSourceId + 1;

    for (UINT32 SourceId = StartVidPnSourceId; SourceId < MaxVidPnSourceId; ++SourceId)
    {
        if (pSetVidPnSourceVisibility->Visible) { m_CurrentMode.Flags.FullscreenPresent = TRUE; }
        else
        {
            UINT32 ScreenHeight = m_CurrentMode.DispInfo.Height;
            UINT32 ScreenPitch = m_CurrentMode.DispInfo.Pitch;
            PHYSICAL_ADDRESS NewPhysAddrStart = m_CurrentMode.DispInfo.PhysicAddress;
            PHYSICAL_ADDRESS NewPhysAddrEnd;
            NewPhysAddrEnd.QuadPart = NewPhysAddrStart.QuadPart + ((LONGLONG)ScreenHeight * ScreenPitch);
            if (m_CurrentMode.Flags.FrameBufferIsActive)
            {
                BYTE* MappedAddr = reinterpret_cast<BYTE*>(m_CurrentMode.FrameBuffer.Ptr);
                // Zero any memory at the start that hasn't been zeroed recently
                if (NewPhysAddrStart.QuadPart < m_CurrentMode.ZeroedOutStart.QuadPart)
                {
                    if (NewPhysAddrEnd.QuadPart < m_CurrentMode.ZeroedOutStart.QuadPart)
                    {
                        // No overlap
                        RtlZeroMemory(MappedAddr, ((LONGLONG)ScreenHeight * ScreenPitch));
                    }
                    else { RtlZeroMemory(MappedAddr, (UINT32)(m_CurrentMode.ZeroedOutStart.QuadPart - NewPhysAddrStart.QuadPart)); }
                }
                // Zero any memory at the end that hasn't been zeroed recently
                if (NewPhysAddrEnd.QuadPart > m_CurrentMode.ZeroedOutEnd.QuadPart)
                {
                    if (NewPhysAddrStart.QuadPart > m_CurrentMode.ZeroedOutEnd.QuadPart)
                    {
                        // No overlap
                        // NOTE: When actual pixels were the most recent thing drawn, ZeroedOutStart & ZeroedOutEnd will both be 0
                        // and this is the path that will be used to black out the current screen.
                        RtlZeroMemory(MappedAddr, ((LONGLONG)ScreenHeight * ScreenPitch));
                    }
                    else { RtlZeroMemory(MappedAddr, (UINT32)(NewPhysAddrEnd.QuadPart - m_CurrentMode.ZeroedOutEnd.QuadPart)); }
                }
            }
            m_CurrentMode.ZeroedOutStart.QuadPart = NewPhysAddrStart.QuadPart;
            m_CurrentMode.ZeroedOutEnd.QuadPart = NewPhysAddrEnd.QuadPart;
            // Mark that the next present should be fullscreen so the screen doesn't go from black to actual pixels one dirty rect at a time.
        }

        // Store current visibility so it can be dealt with during Present call
        m_CurrentMode.Flags.SourceNotVisible = !(pSetVidPnSourceVisibility->Visible);
    }
    return STATUS_SUCCESS;
}

NTSTATUS APIENTRY BddDdiSetPointerPosition
(
    IN_CONST_HANDLE                        hAdapter,
    IN_CONST_PDXGKARG_SETPOINTERPOSITION   pSetPointerPosition
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiSetPointerPosition");
    if ((!hAdapter) || (!pSetPointerPosition))
    {
        debug("[ASRT]: One of hAdapter (%p), pSetPointerPosition (%p) is NULL",
            hAdapter, pSetPointerPosition);
        return STATUS_INVALID_PARAMETER;
    }
    if (pSetPointerPosition->VidPnSourceId >= 1)
    {
        debug("[ASRT]: pSetPointerPosition->VidPnSourceId >= 1");
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiSetPointerPosition is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    if (!pSetPointerPosition->Flags.Visible) { return STATUS_SUCCESS; }
    else
    {
        debug("[WARN]: BddDdiSetPointerPosition should never be called to set the pointer to visible since BDD doesn't support hardware cursors.");
        return STATUS_UNSUCCESSFUL;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NTSTATUS APIENTRY BddDdiPresent
(
    IN_CONST_HANDLE               hAdapter,
    INOUT_PDXGKARG_PRESENT        pPresent
)
{
    debug("[CALL]: NTSTATUS APIENTRY BddDdiPresent"); //Not BddDdiPresentDisplayOnly...(mumble, mumble)...
    if ((!hAdapter) || (!pPresent))
    {
        debug("[ASRT]: One of hAdapter (%p), pPresent (%p) is NULL",
            hAdapter, pPresent);
        return STATUS_INVALID_PARAMETER;
    }
    if (!m_Flags.DriverStarted)
    {
        debug("[ASRT]: BddDdiPresent is being called when not active!");
        return STATUS_UNSUCCESSFUL;
    }
    //if (pPresent->BytesPerPixel < MIN_BYTES_PER_PIXEL_REPORTED)
    //{
    //    // Only >=32bpp modes are reported, therefore this Present should never pass anything less than 4 bytes per pixel
    //    //debug("[WARN]: pPresentDisplayOnly->BytesPerPixel is 0x%016llX, which is lower than the allowed.", pPresentDisplayOnly->BytesPerPixel);
    //    return STATUS_INVALID_PARAMETER;
    //}
    //if (pPresent->VidPnSourceId >= 1)
    //{
    //    debug("[ASRT]: pPresent->VidPnSourceId >= 1");
    //    return STATUS_INVALID_PARAMETER;
    //}
    // If it is in monitor off state or source is not supposed to be visible, don't present anything to the screen
    /*
    if ((m_MonitorPowerState > PowerDeviceD0) || (m_CurrentMode.Flags.SourceNotVisible))
    {
        return STATUS_SUCCESS;
    }
    // Present is only valid if the target is actively connected to this source
    if (m_CurrentMode.Flags.FrameBufferIsActive)
    {
        // If actual pixels are coming through, will need to completely zero out physical address next time in BlackOutScreen
        m_CurrentMode.ZeroedOutStart.QuadPart = 0;
        m_CurrentMode.ZeroedOutEnd.QuadPart = 0;

        D3DKMDT_VIDPN_PRESENT_PATH_ROTATION RotationNeededByFb = pPresent->Flags.Rotate ? m_CurrentMode.Rotation : D3DKMDT_VPPR_IDENTITY;
        BYTE* pDst = (BYTE*)m_CurrentMode.FrameBuffer.Ptr;
        UINT32 DstBitPerPixel = BPPFromPixelFormat(m_CurrentMode.DispInfo.ColorFormat);
        if (m_CurrentMode.Scaling == D3DKMDT_VPPS_CENTERED)
        {
            UINT32 CenterShift = (m_CurrentMode.DispInfo.Height - m_CurrentMode.SrcModeHeight) * m_CurrentMode.DispInfo.Pitch;
            CenterShift += (m_CurrentMode.DispInfo.Width - m_CurrentMode.SrcModeWidth) * DstBitPerPixel / 8;
            pDst += (UINT32)CenterShift / 2;
        }
        return m_HardwareBlt.ExecutePresentDisplayOnly(pDst,
            DstBitPerPixel,
            (BYTE*)pPresent->pSource,
            pPresent->BytesPerPixel,
            pPresent->Pitch,
            pPresent->NumMoves,
            pPresent->pMoves,
            pPresent->NumDirtyRects,
            pPresent->pDirtyRect,
            RotationNeededByFb);
    }
    */
    return STATUS_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NTSTATUS UnmapFrameBuffer
(
    _In_reads_bytes_(Length) PVOID   VirtualAddress,
    _In_ ULONG                       Length
)
{
    debug("[CALL]: NTSTATUS UnmapFrameBuffer");
    if ((!VirtualAddress) && (!Length))
    {
        // Allow this function to be called when there's no work to do, and treat as successful
        return STATUS_SUCCESS;
    }
    else if ((!VirtualAddress) || (!Length))
    {
        debug("[WARN]: Only one of Length (0x%08lX), VirtualAddress (%p) is NULL",
            Length, VirtualAddress);
        return STATUS_INVALID_PARAMETER;
    }
    MmUnmapIoSpace(VirtualAddress, Length);
    return STATUS_SUCCESS;
}