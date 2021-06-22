#include "DRIVER.HXX"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PINTERFACE_REFERENCE
VOID I2CInterfaceReference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID I2CInterfaceReference");
	UNREFERENCED_PARAMETER(Context);
}

//PINTERFACE_DEREFERENCE
VOID I2CInterfaceDereference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID I2CInterfaceDereference");
	UNREFERENCED_PARAMETER(Context);
}

//DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY
NTSTATUS I2CTransmitDataToDisplay
(
	PVOID                            MiniportDeviceContext,
	D3DDDI_VIDEO_PRESENT_TARGET_ID   VidPnTargetId,
	ULONG                            SevenBitI2CAddress,
	ULONG                            DataLength,
	const void*                      Data
)
{
	debug("[CALL]: NTSTATUS I2CTransmitDataToDisplay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(VidPnTargetId);
	UNREFERENCED_PARAMETER(SevenBitI2CAddress);
	UNREFERENCED_PARAMETER(DataLength);
	UNREFERENCED_PARAMETER(Data);
}

//DXGKDDI_I2C_RECEIVE_DATA_FROM_DISPLAY
NTSTATUS I2CReceiveDataFromDisplay
(
	PVOID                            MiniportDeviceContext,
	D3DDDI_VIDEO_PRESENT_TARGET_ID   VidPnTargetId,
	ULONG                            SevenBitI2CAddress,
	ULONG                            Flags,
	ULONG                            DataLength,
	PVOID                            Data
)
{
	debug("[CALL]: NTSTATUS I2CReceiveDataFromDisplay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(VidPnTargetId);
	UNREFERENCED_PARAMETER(SevenBitI2CAddress);
	UNREFERENCED_PARAMETER(Flags);
	UNREFERENCED_PARAMETER(DataLength);
	UNREFERENCED_PARAMETER(Data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PINTERFACE_REFERENCE
VOID OPMInterfaceReference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID OPMInterfaceReference");
	UNREFERENCED_PARAMETER(Context);
}

//PINTERFACE_DEREFERENCE
VOID OPMInterfaceDereference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID OPMInterfaceDereference");
	UNREFERENCED_PARAMETER(Context);
}

//DXGKDDI_OPM_GET_CERTIFICATE_SIZE
NTSTATUS OPMGetCertificateSize
(
	PVOID                      MiniportDeviceContext,
	DXGKMDT_CERTIFICATE_TYPE   CertificateType,
	PULONG                     CertificateSize
)
{
	debug("[CALL]: NTSTATUS OPMGetCertificateSize");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(CertificateType);
	UNREFERENCED_PARAMETER(CertificateSize);
}

//DXGKDDI_OPM_GET_CERTIFICATE
NTSTATUS OPMGetCertificate
(
	PVOID                      MiniportDeviceContext,
	DXGKMDT_CERTIFICATE_TYPE   CertificateType,
	ULONG                      CertificateSize,
	PVOID                      CertificateBuffer
)
{
	debug("[CALL]: NTSTATUS OPMGetCertificate");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(CertificateType);
	UNREFERENCED_PARAMETER(CertificateSize);
	UNREFERENCED_PARAMETER(CertificateBuffer);
}

//DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT
NTSTATUS OPMCreateProtectedOutput
(
	PVOID                                MiniportDeviceContext,
	D3DDDI_VIDEO_PRESENT_TARGET_ID       VidPnTargetId,
	DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS   NewVideoOutputSemantics,
	PHANDLE                              NewProtectedOutputHandle
)
{
	debug("[CALL]: NTSTATUS OPMCreateProtectedOutput");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(VidPnTargetId);
	UNREFERENCED_PARAMETER(NewVideoOutputSemantics);
	UNREFERENCED_PARAMETER(NewProtectedOutputHandle);
}

//DXGKDDI_OPM_GET_RANDOM_NUMBER
NTSTATUS OPMGetRandomNumber
(
	PVOID                        MiniportDeviceContext,
	HANDLE                       ProtectedOutputHandle,
	PDXGKMDT_OPM_RANDOM_NUMBER   RandomNumber
)
{
	debug("[CALL]: NTSTATUS OPMGetRandomNumber");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
	UNREFERENCED_PARAMETER(RandomNumber);
}

//DXGKDDI_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS
NTSTATUS OPMSetSigningKeyAndSequenceNumbers
(
	PVOID                                     MiniportDeviceContext,
	HANDLE                                    ProtectedOutputHandle,
	const DXGKMDT_OPM_ENCRYPTED_PARAMETERS*   EncryptedParameters
)
{
	debug("[CALL]: NTSTATUS OPMSetSigningKeyAndSequenceNumbers");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
	UNREFERENCED_PARAMETER(EncryptedParameters);
}

//DXGKDDI_OPM_GET_INFORMATION
NTSTATUS OPMGetInformation
(
	PVOID                                    MiniportDeviceContext,
	HANDLE                                   ProtectedOutputHandle,
	const DXGKMDT_OPM_GET_INFO_PARAMETERS*   Parameters,
	PDXGKMDT_OPM_REQUESTED_INFORMATION       RequestedInformation
)
{
	debug("[CALL]: NTSTATUS OPMGetInformation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
	UNREFERENCED_PARAMETER(Parameters);
	UNREFERENCED_PARAMETER(RequestedInformation);
}

//DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION
NTSTATUS OPMGetCOPPCompatibleInformation
(
	PVOID                                                    MiniportDeviceContext,
	HANDLE                                                   ProtectedOutputHandle,
	const DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS*   Parameters,
	PDXGKMDT_OPM_REQUESTED_INFORMATION                       RequestedInformation
)
{
	debug("[CALL]: NTSTATUS OPMGetCOPPCompatibleInformation");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
	UNREFERENCED_PARAMETER(Parameters);
	UNREFERENCED_PARAMETER(RequestedInformation);
}

//DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT
NTSTATUS OPMConfigureProtectedOutput
(
	PVOID                                     MiniportDeviceContext,
	HANDLE                                    ProtectedOutputHandle,
	const DXGKMDT_OPM_CONFIGURE_PARAMETERS*   Parameters,
	ULONG                                     AdditionalParametersSize,
	const void*                               AdditionalParameters
)
{
	debug("[CALL]: NTSTATUS OPMConfigureProtectedOutput");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
	UNREFERENCED_PARAMETER(Parameters);
	UNREFERENCED_PARAMETER(AdditionalParametersSize);
	UNREFERENCED_PARAMETER(AdditionalParameters);
}

//DXGKDDI_OPM_DESTROY_PROTECTED_OUTPUT
NTSTATUS OPMDestroyProtectedOutput
(
    PVOID    MiniportDeviceContext,
	HANDLE   ProtectedOutputHandle
)
{
	debug("[CALL]: NTSTATUS OPMDestroyProtectedOutput");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ProtectedOutputHandle);
}

//DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT_NONLOCAL_DISPLAY
NTSTATUS OPMCreateProtectedOutputNonLocalDisplay
(
	PVOID                                MiniportDeviceContext,
	DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS   NewVideoOutputSemantics,
	UINT64                               OPMEncoderContext,
	DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT*    pActualOutputFormat,
	UINT64                               NonLocalOutputId,
	DXGKMDT_OPM_CONNECTOR_TYPE           NonLocalConnectorType,
	PHANDLE                              NewProtectedOutputHandle
)
{
	debug("[CALL]: NTSTATUS OPMCreateProtectedOutputNonLocalDisplay");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(NewVideoOutputSemantics);
	UNREFERENCED_PARAMETER(OPMEncoderContext);
	UNREFERENCED_PARAMETER(pActualOutputFormat);
	UNREFERENCED_PARAMETER(NonLocalOutputId);
	UNREFERENCED_PARAMETER(NonLocalConnectorType);
	UNREFERENCED_PARAMETER(NewProtectedOutputHandle);
}

//DXGKDDI_OPM_SET_SRM_LIST
NTSTATUS OPMSetSrmList
(
	PVOID   MiniportDeviceContext,
	ULONG   SrmListSize,
	PVOID   SrmListBuffer
)
{
	debug("[CALL]: NTSTATUS OPMSetSrmList")
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(SrmListSize);
	UNREFERENCED_PARAMETER(SrmListBuffer);
}

//DXGKDDI_OPM_GET_SRM_LIST_VERSION
NTSTATUS OPMGetSrmListVersion
(
	PVOID    MiniportDeviceContext,
	PULONG   SrmListVersionSize,
	PVOID    SrmListVersionBuffer
)
{
	debug("[CALL]: NTSTATUS OPMGetSrmListVersion");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(SrmListVersionSize);
	UNREFERENCED_PARAMETER(SrmListVersionBuffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PINTERFACE_REFERENCE
VOID MiracastInterfaceReference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID MiracastInterfaceReference");
	UNREFERENCED_PARAMETER(Context);
}

//PINTERFACE_DEREFERENCE
VOID MiracastInterfaceDereference
(
	PVOID   Context
)
{
	debug("[CALL]: VOID MiracastInterfaceDereference");
	UNREFERENCED_PARAMETER(Context);
}

//DXGKDDI_MIRACAST_QUERY_CAPS
NTSTATUS MiracastQueryCaps
(
	PVOID                 DriverContext,
	ULONG                 MiracastCapsSize,
	PDXGK_MIRACAST_CAPS   MiracastCaps
)
{
	debug("[CALL]: NTSTATUS MiracastQueryCaps");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(MiracastCapsSize);
	UNREFERENCED_PARAMETER(MiracastCaps);
}

//DXGKDDI_MIRACAST_CREATE_CONTEXT
NTSTATUS MiracastCreateContext
(
	PVOID                              DriverContext,
    PDXGK_MIRACAST_DISPLAY_CALLBACKS   MiracastCallbacks,
	PVOID*                             MiracastContext,
	PULONG                             TargetId
)
{
	debug("[CALL]: NTSTATUS MiracastCreateContext");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(MiracastCallbacks);
	UNREFERENCED_PARAMETER(MiracastContext);
	UNREFERENCED_PARAMETER(TargetId);
}

//DXGKDDI_MIRACAST_HANDLE_IO_CONTROL
NTSTATUS MiracastIoControl
(
    PVOID    DriverContext,
	PVOID    MiracastContext,
	ULONG    InputBufferSize,
	PVOID    pInputBuffer,
	ULONG    OutputBufferSize,
	PVOID    pOutputBuffer,
	PULONG   BytesReturned
)
{
	debug("[CALL]: NTSTATUS MiracastIoControl");
	return STATUS_ABANDONED;
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(MiracastContext);
	UNREFERENCED_PARAMETER(InputBufferSize);
	UNREFERENCED_PARAMETER(pInputBuffer);
	UNREFERENCED_PARAMETER(OutputBufferSize);
	UNREFERENCED_PARAMETER(pOutputBuffer);
	UNREFERENCED_PARAMETER(BytesReturned);
}

//DXGKDDI_MIRACAST_DESTROY_CONTEXT
VOID MiracastDestroyContext
(
	PVOID   DriverContext,
	PVOID   MiracastContext
)
{
	debug("[CALL]: VOID MiracastDestroyContext");
	UNREFERENCED_PARAMETER(DriverContext);
	UNREFERENCED_PARAMETER(MiracastContext);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////