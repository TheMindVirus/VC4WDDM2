#include "DRIVER.HXX"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_EVAL_ACPI_METHOD
NTSTATUS APIENTRY DxgkCbEvalAcpiMethod
(
	HANDLE                            DeviceHandle,
	ULONG                             DeviceUid,
	PACPI_EVAL_INPUT_BUFFER_COMPLEX   AcpiInputBuffer,
	ULONG                             AcpiInputSize,
	PACPI_EVAL_OUTPUT_BUFFER          AcpiOutputBuffer,
	ULONG                             AcpiOutputSize
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbEvalAcpiMethod");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DeviceUid);
	UNREFERENCED_PARAMETER(AcpiInputBuffer);
	UNREFERENCED_PARAMETER(AcpiInputSize);
	UNREFERENCED_PARAMETER(AcpiOutputBuffer);
	UNREFERENCED_PARAMETER(AcpiOutputSize);
}

//DXGKCB_GET_DEVICE_INFORMATION
NTSTATUS APIENTRY DxgkCbGetDeviceInformation
(
	HANDLE              DeviceHandle,
	PDXGK_DEVICE_INFO   DeviceInfo
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbGetDeviceInformation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DeviceInfo);
}

//DXGKCB_INDICATE_CHILD_STATUS
NTSTATUS APIENTRY DxgkCbIndicateChildStatus
(
	HANDLE               DeviceHandle,
	PDXGK_CHILD_STATUS   ChildStatus
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbIndicateChildStatus");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(ChildStatus);
}

//DXGKCB_MAP_MEMORY
NTSTATUS APIENTRY DxgkCbMapMemory
(
	HANDLE                DeviceHandle,
	PHYSICAL_ADDRESS      TranslatedAddress,
	ULONG                 Length,
	BOOLEAN               InIoSpace,
	BOOLEAN               MapToUserMode,
	MEMORY_CACHING_TYPE   CacheType,
	PVOID*                VirtualAddress
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbMapMemory");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(TranslatedAddress);
	UNREFERENCED_PARAMETER(Length);
	UNREFERENCED_PARAMETER(InIoSpace);
	UNREFERENCED_PARAMETER(MapToUserMode);
	UNREFERENCED_PARAMETER(CacheType);
	UNREFERENCED_PARAMETER(VirtualAddress);
}

//DXGKCB_QUEUE_DPC
BOOLEAN APIENTRY DxgkCbQueueDpc
(
	HANDLE   DeviceHandle
)
{
	debug("[CALL]: BOOLEAN APIENTRY DxgkCbQueueDpc");
	return FALSE;
	UNREFERENCED_PARAMETER(DeviceHandle);
}

//DXGKCB_QUERY_SERVICES
NTSTATUS APIENTRY DxgkCbQueryServices
(
	HANDLE          DeviceHandle,
	DXGK_SERVICES   ServicesType,
	PINTERFACE      Interface
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbQueryServices");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(ServicesType);
	UNREFERENCED_PARAMETER(Interface);
}

//DXGKCB_READ_DEVICE_SPACE
NTSTATUS APIENTRY DxgkCbReadDeviceSpace
(
	HANDLE   DeviceHandle,
	ULONG    DataType,
	PVOID    Buffer,
	ULONG    Offset,
	ULONG    Length,
	PULONG   BytesRead
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbReadDeviceSpace");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DataType);
	UNREFERENCED_PARAMETER(Buffer);
	UNREFERENCED_PARAMETER(Offset);
	UNREFERENCED_PARAMETER(Length);
	UNREFERENCED_PARAMETER(BytesRead);
}

//DXGKCB_SYNCHRONIZE_EXECUTION
NTSTATUS APIENTRY DxgkCbSynchronizeExecution
(
	HANDLE                  DeviceHandle,
	PKSYNCHRONIZE_ROUTINE   SynchronizeRoutine,
	PVOID                   Context,
	ULONG                   MessageNumber,
	PBOOLEAN                ReturnValue
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbSynchronizeExecution");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(SynchronizeRoutine);
	UNREFERENCED_PARAMETER(Context);
	UNREFERENCED_PARAMETER(MessageNumber);
	UNREFERENCED_PARAMETER(ReturnValue);
}

//DXGKCB_UNMAP_MEMORY
NTSTATUS APIENTRY DxgkCbUnmapMemory
(
	HANDLE   DeviceHandle,
	PVOID    VirtualAddress
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbUnmapMemory");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(VirtualAddress);
}

//DXGKCB_WRITE_DEVICE_SPACE
NTSTATUS APIENTRY DxgkCbWriteDeviceSpace
(
	HANDLE   DeviceHandle,
	ULONG    DataType,
	PVOID    Buffer,
	ULONG    Offset,
	ULONG    Length,
	PULONG   BytesWritten
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbWriteDeviceSpace");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DataType);
	UNREFERENCED_PARAMETER(Buffer);
	UNREFERENCED_PARAMETER(Offset);
	UNREFERENCED_PARAMETER(Length);
	UNREFERENCED_PARAMETER(BytesWritten);
}

//DXGKCB_IS_DEVICE_PRESENT
NTSTATUS APIENTRY DxgkCbIsDevicePresent
(
	HANDLE                            DeviceHandle,
	PPCI_DEVICE_PRESENCE_PARAMETERS   DevicePresenceParameters,
	PBOOLEAN                          DevicePresent
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbIsDevicePresent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DevicePresenceParameters);
	UNREFERENCED_PARAMETER(DevicePresent);
}

//DXGKCB_GETHANDLEDATA 
VOID* APIENTRY CALLBACK DxgkCbGetHandleData
(
	IN_CONST_PDXGKARGCB_GETHANDLEDATA   pArgs
)
{
	debug("[CALL]: VOID* APIENTRY CALLBACK DxgkCbGetHandleData");
	return NULL;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_GETHANDLEPARENT
D3DKMT_HANDLE APIENTRY CALLBACK DxgkCbGetHandleParent
(
	IN_D3DKMT_HANDLE   hAllocation
)
{
	debug("[CALL]: D3DKMT_HANDLE APIENTRY CALLBACK DxgkCbGetHandleParent");
	return 0;
	UNREFERENCED_PARAMETER(hAllocation);
}

//DXGKCB_ENUMHANDLECHILDREN
D3DKMT_HANDLE APIENTRY CALLBACK DxgkCbEnumHandleChildren
(
	IN_CONST_PDXGKARGCB_ENUMHANDLECHILDREN   pArgs
)
{
	debug("[CALL]: D3DKMT_HANDLE APIENTRY CALLBACK DxgkCbEnumHandleChildren");
	return 0;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_NOTIFY_INTERRUPT
VOID APIENTRY CALLBACK DxgkCbNotifyInterrupt
(
	IN_CONST_HANDLE                             hAdapter,
	IN_CONST_PDXGKARGCB_NOTIFY_INTERRUPT_DATA   pArgs
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbNotifyInterrupt");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_NOTIFY_DPC
VOID APIENTRY CALLBACK DxgkCbNotifyDpc
(
	IN_CONST_HANDLE   hAdapter
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbNotifyDpc");
	UNREFERENCED_PARAMETER(hAdapter);
}

//DXGKCB_QUERYVIDPNINTERFACE
NTSTATUS APIENTRY CALLBACK DxgkCbQueryVidPnInterface
(
	IN_CONST_D3DKMDT_HVIDPN                  hVidPn,
	IN_CONST_DXGK_VIDPN_INTERFACE_VERSION    VidPnInterfaceVersion,
	DEREF_OUT_CONST_PPDXGK_VIDPN_INTERFACE   ppVidPnInterface
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbQueryVidPnInterface");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hVidPn);
	UNREFERENCED_PARAMETER(VidPnInterfaceVersion);
	UNREFERENCED_PARAMETER(ppVidPnInterface);
}

//DXGKCB_QUERYMONITORINTERFACE
NTSTATUS APIENTRY CALLBACK DxgkCbQueryMonitorInterface
(
	IN_CONST_HANDLE                            hAdapter,
	IN_CONST_DXGK_MONITOR_INTERFACE_VERSION    MonitorInterfaceVersion,
	DEREF_OUT_CONST_PPDXGK_MONITOR_INTERFACE   ppMonitorInterface
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbQueryMonitorInterface");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(MonitorInterfaceVersion);
	UNREFERENCED_PARAMETER(ppMonitorInterface);
}

//DXGKCB_GETCAPTUREADDRESS
NTSTATUS APIENTRY CALLBACK DxgkCbGetCaptureAddress
(
	INOUT_PDXGKARGCB_GETCAPTUREADDRESS   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbGetCaptureAddress");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_LOG_ETW_EVENT
VOID APIENTRY DxgkCbLogEtwEvent
(
	CONST LPCGUID   EventGuid,
	UCHAR           Type,
	USHORT          EventBufferSize,
	PVOID           EventBuffer
)
{
	debug("[CALL]: VOID APIENTRY DxgkCbLogEtwEvent");
	UNREFERENCED_PARAMETER(EventGuid);
	UNREFERENCED_PARAMETER(Type);
	UNREFERENCED_PARAMETER(EventBufferSize);
	UNREFERENCED_PARAMETER(EventBuffer);
}

//DXGKCB_EXCLUDE_ADAPTER_ACCESS
NTSTATUS APIENTRY DxgkCbExcludeAdapterAccess
(
	HANDLE                       DeviceHandle,
	ULONG                        Attributes,
	DXGKDDI_PROTECTED_CALLBACK   DxgkProtectedCallback,
	PVOID                        ProtectedCallbackContext
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbExcludeAdapterAccess");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(Attributes);
	UNREFERENCED_PARAMETER(DxgkProtectedCallback);
	UNREFERENCED_PARAMETER(ProtectedCallbackContext);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_CREATECONTEXTALLOCATION
NTSTATUS APIENTRY CALLBACK DxgkCbCreateContextAllocation
(
	INOUT_PDXGKARGCB_CREATECONTEXTALLOCATION   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbCreateContextAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_DESTROYCONTEXTALLOCATION
NTSTATUS APIENTRY CALLBACK DxgkCbDestroyContextAllocation
(
	IN_CONST_HANDLE   hAdapter,
	IN_CONST_HANDLE   hAllocation
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbDestroyContextAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(hAllocation);
}

//DXGKCB_SETPOWERCOMPONENTACTIVE
VOID APIENTRY CALLBACK DxgkCbSetPowerComponentActive
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbSetPowerComponentActive");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
}

//DXGKCB_SETPOWERCOMPONENTIDLE
VOID APIENTRY CALLBACK DxgkCbSetPowerComponentIdle
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbSetPowerComponentIdle");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
}

//DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP
NTSTATUS APIENTRY DxgkCbAcquirePostDisplayOwnership
(
	HANDLE                      DeviceHandle,
	PDXGK_DISPLAY_INFORMATION   DisplayInfo
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbAcquirePostDisplayOwnership");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DisplayInfo);
}

//DXGKCB_POWERRUNTIMECONTROLREQUEST
NTSTATUS APIENTRY CALLBACK DxgkCbPowerRuntimeControlRequest
(
	IN_CONST_HANDLE   hAdapter,
	LPCGUID           PowerControlCode,
	PVOID             InBuffer,
	SIZE_T            InBufferSize,
	PVOID             OutBuffer,
	SIZE_T            OutBufferSize,
	PSIZE_T           BytesReturned
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbPowerRuntimeControlRequest");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(PowerControlCode);
	UNREFERENCED_PARAMETER(InBuffer);
	UNREFERENCED_PARAMETER(InBufferSize);
	UNREFERENCED_PARAMETER(OutBuffer);
	UNREFERENCED_PARAMETER(OutBufferSize);
	UNREFERENCED_PARAMETER(BytesReturned);
}

//DXGKCB_SETPOWERCOMPONENTLATENCY
VOID APIENTRY CALLBACK DxgkCbSetPowerComponentLatency
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex,
	ULONGLONG         Latency
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbSetPowerComponentLatency");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
	UNREFERENCED_PARAMETER(Latency);
}

//DXGKCB_SETPOWERCOMPONENTRESIDENCY
VOID APIENTRY CALLBACK DxgkCbSetPowerComponentResidency
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex,
	ULONGLONG         Residency
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbSetPowerComponentResidency");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
	UNREFERENCED_PARAMETER(Residency);
}

//DXGKCB_COMPLETEFSTATETRANSITION
VOID APIENTRY CALLBACK DxgkCbCompleteFStateTransition
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbCompleteFStateTransition");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_COMPLETEPSTATETRANSITION
VOID APIENTRY CALLBACK DxgkCbCompletePStateTransition
(
	IN_CONST_HANDLE   hAdapter,
	UINT              ComponentIndex,
    UINT              CompletedPState
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbCompletePStateTransition");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(ComponentIndex);
	UNREFERENCED_PARAMETER(CompletedPState);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_MAPCONTEXTALLOCATION
D3DGPU_VIRTUAL_ADDRESS APIENTRY CALLBACK DxgkCbMapContextAllocation
(
	IN_CONST_HANDLE                            hAdapter,
	IN_CONST_PDXGKARGCB_MAPCONTEXTALLOCATION   pArgs
)
{
	debug("[CALL]: D3DGPU_VIRTUAL_ADDRESS APIENTRY CALLBACK DxgkCbMapContextAllocation");
	return 0;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_UPDATECONTEXTALLOCATION
NTSTATUS APIENTRY CALLBACK DxgkCbUpdateContextAllocation
(
	IN_CONST_HANDLE                               hAdapter,
	IN_CONST_PDXGKARGCB_UPDATECONTEXTALLOCATION   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbUpdateContextAllocation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE
NTSTATUS APIENTRY CALLBACK DxgkCbReserveGpuVirtualAddressRange
(
	IN_CONST_HANDLE                                  hAdapter,
    INOUT_PDXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbReserveGpuVirtualAddressRange");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_ACQUIREHANDLEDATA
VOID* APIENTRY CALLBACK DxgkCbAcquireHandleData
(
	IN_CONST_PDXGKARGCB_GETHANDLEDATA   pArgs,
	PDXGKARG_RELEASE_HANDLE             ReleaseHandle
)
{
	debug("[CALL]: VOID* APIENTRY CALLBACK DxgkCbAcquireHandleData");
	return NULL;
	UNREFERENCED_PARAMETER(pArgs);
	UNREFERENCED_PARAMETER(ReleaseHandle);
}

//DXGKCB_RELEASEHANDLEDATA
VOID APIENTRY CALLBACK DxgkCbReleaseHandleData
(
	IN_CONST_DXGKARGCB_RELEASEHANDLEDATA   Args
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbReleaseHandleData");
	UNREFERENCED_PARAMETER(Args);
}

//DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN
VOID APIENTRY CALLBACK DxgkCbHardwareContentProtectionTeardown
(
	IN_CONST_HANDLE   hAdapter,
	UINT              Flags
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbHardwareContentProtectionTeardown");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(Flags);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_MULTIPLANEOVERLAYDISABLED
VOID APIENTRY CALLBACK DxgkCbMultiPlaneOverlayDisabled
(
	IN_CONST_HANDLE   hAdapter,
	UINT              VidPnSourceId
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbMultiPlaneOverlayDisabled");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(VidPnSourceId);
}

//DXGKCB_DXGKCB_MITIGATEDRANGEUPDATE
VOID APIENTRY CALLBACK DxgkCbMitigatedRangeUpdate
(
	IN_CONST_HANDLE   hAdapter,
	ULONG             VirtualFunctionIndex
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbMitigatedRangeUpdate");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(VirtualFunctionIndex);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_INVALIDATEHWCONTEXT
NTSTATUS APIENTRY CALLBACK DxgkCbInvalidateHwContext
(
	IN_CONST_PDXGKARGCB_INVALIDATEHWCONTEXT   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbInvalidateHwContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_INDICATE_CONNECTOR_CHANGE
NTSTATUS APIENTRY DxgkCbIndicateConnectorChange
(
	IN_CONST_HANDLE   hAdapter
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbIndicateConnectorChange");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
}

//DXGKCB_UNBLOCKUEFIFRAMEBUFFERRANGES
NTSTATUS APIENTRY CALLBACK DxgkCbUnblockUEFIFrameBufferRanges
(
	IN_CONST_HANDLE                     hAdapter,
	IN_CONST_PDXGK_SEGMENTMEMORYSTATE   pSegmentMemoryState
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbUnblockUEFIFrameBufferRanges");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pSegmentMemoryState);
}

//DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP2
NTSTATUS APIENTRY DxgkCbAcquirePostDisplayOwnership2
(
	HANDLE                          DeviceHandle,
	PDXGK_DISPLAY_INFORMATION       DisplayInfo,
	PDXGK_DISPLAY_OWNERSHIP_FLAGS   Flags
)
{
	debug("[CALL]: NTSTATUS APIENTRY DxgkCbAcquirePostDisplayOwnership2");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(DisplayInfo);
	UNREFERENCED_PARAMETER(Flags);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_SETPROTECTEDSESSIONSTATUS
NTSTATUS APIENTRY CALLBACK DxgkCbSetProtectedSessionStatus
(
	IN_CONST_PDXGKARGCB_PROTECTEDSESSIONSTATUS   pProtectedSessionStatus
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbSetProtectedSessionStatus");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pProtectedSessionStatus);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_ALLOCATECONTIGUOUSMEMORY
NTSTATUS APIENTRY CALLBACK DxgkCbAllocateContiguousMemory
(
	IN_CONST_HANDLE                             hAdapter,
	INOUT_PDXGKARGCB_ALLOCATECONTIGUOUSMEMORY   pAllocateContiguousMemory
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbAllocateContiguousMemory");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pAllocateContiguousMemory);
}

//DXGKCB_FREECONTIGUOUSMEMORY
NTSTATUS APIENTRY CALLBACK DxgkCbFreeContiguousMemory
(
	IN_CONST_HANDLE                            hAdapter,
	IN_CONST_PDXGKARGCB_FREECONTIGUOUSMEMORY   pFreeContiguousMemory
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbFreeContiguousMemory");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pFreeContiguousMemory);
}

//DXGKCB_ALLOCATEPAGESFORMDL
NTSTATUS APIENTRY CALLBACK DxgkCbAllocatePagesForMdl
(
	IN_CONST_HANDLE                        hAdapter,
	INOUT_PDXGKARGCB_ALLOCATEPAGESFORMDL   pAllocatePagesForMdl
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbAllocatePagesForMdl");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pAllocatePagesForMdl);
}

//DXGKCB_FREEPAGESFROMMDL
NTSTATUS APIENTRY CALLBACK DxgkCbFreePagesFromMdl
(
	IN_CONST_HANDLE                        hAdapter,
	IN_CONST_PDXGKARGCB_FREEPAGESFROMMDL   pFreePagesFromMdl
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbFreePagesFromMdl");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pFreePagesFromMdl);
}

//DXGKCB_PINFRAMEBUFFERFORSAVE
NTSTATUS APIENTRY CALLBACK DxgkCbPinFrameBufferForSave
(
	IN_CONST_HANDLE                          hAdapter,
	INOUT_PDXGKARGCB_PINFRAMEBUFFERFORSAVE   pPinFrameBufferForSave
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbPinFrameBufferForSave");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pPinFrameBufferForSave);
}

//DXGKCB_UNPINFRAMEBUFFERFORSAVE
NTSTATUS APIENTRY CALLBACK DxgkCbUnpinFrameBufferForSave
(
	IN_CONST_HANDLE                               hAdapter,
	IN_CONST_PDXGKARGCB_UNPINFRAMEBUFFERFORSAVE   pUnpinFrameBufferForSave
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbUnpinFrameBufferForSave");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUnpinFrameBufferForSave);
}

//DXGKCB_MAPFRAMEBUFFERPOINTER
NTSTATUS APIENTRY CALLBACK DxgkCbMapFrameBufferPointer
(
	IN_CONST_HANDLE                          hAdapter,
	INOUT_PDXGKARGCB_MAPFRAMEBUFFERPOINTER   pMapFrameBufferPointer
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbMapFrameBufferPointer");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pMapFrameBufferPointer);
}

//DXGKCB_UNMAPFRAMEBUFFERPOINTER
NTSTATUS APIENTRY CALLBACK DxgkCbUnmapFrameBufferPointer
(
	IN_CONST_HANDLE                               hAdapter,
	IN_CONST_PDXGKARGCB_UNMAPFRAMEBUFFERPOINTER   pUnmapFrameBufferPointer
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbUnmapFrameBufferPointer");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUnmapFrameBufferPointer);
}

//DXGKCB_MAPMDLTOIOMMU
NTSTATUS APIENTRY CALLBACK DxgkCbMapMdlToIoMmu
(
	IN_CONST_HANDLE                  hAdapter,
	INOUT_PDXGKARGCB_MAPMDLTOIOMMU   pMapMdlToIoMmu
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbMapMdlToIoMmu");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pMapMdlToIoMmu);
}

//DXGKCB_UNMAPMDLFROMIOMMU
VOID APIENTRY CALLBACK DxgkCbUnmapMdlFromIoMmu
(
	IN_CONST_HANDLE                         hAdapter,
	IN_CONST_PDXGKARGCB_UNMAPMDLFROMIOMMU   pUnmapMdlFromIoMmu
)
{
	debug("[CALL]: VOID APIENTRY CALLBACK DxgkCbUnmapMdlFromIoMmu");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pUnmapMdlFromIoMmu);
}

//DXGKCB_REPORT_DIAGNOSTIC
NTSTATUS APIENTRY CALLBACK DxgkCbReportDiagnostic
(
	HANDLE                       DeviceHandle,
	IN_PDXGK_DIAGNOSTIC_HEADER   pDiagnostic
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbReportDiagnostic");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DeviceHandle);
	UNREFERENCED_PARAMETER(pDiagnostic);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_SIGNALEVENT
NTSTATUS APIENTRY CALLBACK DxgkCbSignalEvent
(
	IN_CONST_PDXGKARGCB_SIGNALEVENT   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbSignalEvent");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pArgs);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DXGKCB_ISFEATUREENABLED
NTSTATUS APIENTRY CALLBACK DxgkCbIsFeatureEnabled
(
	INOUT_PDXGKARGCB_ISFEATUREENABLED   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbIsFeatureEnabled");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(pArgs);
}

//DXGKCB_SAVEMEMORYFORHOTUPDATE
NTSTATUS APIENTRY CALLBACK DxgkCbSaveMemoryForHotUpdate
(
	IN_CONST_HANDLE                              hAdapter,
	IN_CONST_PDXGKARGCB_SAVEMEMORYFORHOTUPDATE   pArgs
)
{
	debug("[CALL]: NTSTATUS APIENTRY CALLBACK DxgkCbSaveMemoryForHotUpdate");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pArgs);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////