#pragma once

#define _USBBUSIF_

#ifndef USB_BUSIFFN
#define USB_BUSIFFN __stdcall
#endif

#if (NTDDI_VERSION >= NTDDI_WINXP)

#if !defined(_HUBBUSIF_)
typedef PVOID PUSB_DEVICE_HANDLE;
#endif

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB) (
  IN PVOID,
  IN PURB);

#define USB_HCD_CAPS_SUPPORTS_RT_THREADS    0x00000001

typedef VOID
(USB_BUSIFFN *PUSB_BUSIFFN_GETUSBDI_VERSION) (
  IN PVOID,
  OUT PUSBD_VERSION_INFORMATION OPTIONAL,
  OUT PULONG OPTIONAL);

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_TIME) (
  IN PVOID,
  OUT PULONG OPTIONAL);

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_ENUM_LOG_ENTRY) (
  IN PVOID,
  IN ULONG,
  IN ULONG,
  IN ULONG,
  IN ULONG);

typedef struct _USB_BUS_INFORMATION_LEVEL_0 {
  ULONG TotalBandwidth;
  ULONG ConsumedBandwidth;
} USB_BUS_INFORMATION_LEVEL_0, *PUSB_BUS_INFORMATION_LEVEL_0;

typedef struct _USB_BUS_INFORMATION_LEVEL_1 {
  ULONG TotalBandwidth;
  ULONG ConsumedBandwidth;
  ULONG ControllerNameLength;
  WCHAR ControllerNameUnicodeString[1];
} USB_BUS_INFORMATION_LEVEL_1, *PUSB_BUS_INFORMATION_LEVEL_1;

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_INFORMATION) (
  IN PVOID,
  IN ULONG,
  IN OUT PVOID,
  OUT PULONG,
  OUT PULONG OPTIONAL);

typedef BOOLEAN
(USB_BUSIFFN *PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED) (
  IN PVOID OPTIONAL);

#define USB_BUSIF_USBDI_VERSION_0         0x0000
#define USB_BUSIF_USBDI_VERSION_1         0x0001
#define USB_BUSIF_USBDI_VERSION_2         0x0002
#define USB_BUSIF_USBDI_VERSION_3         0x0003

DEFINE_GUID(USB_BUS_INTERFACE_USBDI_GUID,
  0xb1a96a13, 0x3de0, 0x4574, 0x9b, 0x1, 0xc0, 0x8f, 0xea, 0xb3, 0x18, 0xd6);

typedef struct _USB_BUS_INTERFACE_USBDI_V0 {
  USHORT Size;
  USHORT Version;
  PVOID BusContext;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PUSB_BUSIFFN_GETUSBDI_VERSION GetUSBDIVersion;
  PUSB_BUSIFFN_QUERY_BUS_TIME QueryBusTime;
  PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB SubmitIsoOutUrb;
  PUSB_BUSIFFN_QUERY_BUS_INFORMATION QueryBusInformation;
} USB_BUS_INTERFACE_USBDI_V0, *PUSB_BUS_INTERFACE_USBDI_V0;

typedef struct _USB_BUS_INTERFACE_USBDI_V1 {
  USHORT Size;
  USHORT Version;
  PVOID BusContext;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PUSB_BUSIFFN_GETUSBDI_VERSION GetUSBDIVersion;
  PUSB_BUSIFFN_QUERY_BUS_TIME QueryBusTime;
  PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB SubmitIsoOutUrb;
  PUSB_BUSIFFN_QUERY_BUS_INFORMATION QueryBusInformation;
  PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED IsDeviceHighSpeed;
} USB_BUS_INTERFACE_USBDI_V1, *PUSB_BUS_INTERFACE_USBDI_V1;

typedef struct _USB_BUS_INTERFACE_USBDI_V2 {
  USHORT Size;
  USHORT Version;
  PVOID BusContext;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PUSB_BUSIFFN_GETUSBDI_VERSION GetUSBDIVersion;
  PUSB_BUSIFFN_QUERY_BUS_TIME QueryBusTime;
  PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB SubmitIsoOutUrb;
  PUSB_BUSIFFN_QUERY_BUS_INFORMATION QueryBusInformation;
  PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED IsDeviceHighSpeed;
  PUSB_BUSIFFN_ENUM_LOG_ENTRY EnumLogEntry;
} USB_BUS_INTERFACE_USBDI_V2, *PUSB_BUS_INTERFACE_USBDI_V2;

#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */

#if (NTDDI_VERSION >= NTDDI_VISTA)

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_QUERY_BUS_TIME_EX) (
  IN PVOID OPTIONAL,
  OUT PULONG OPTIONAL);

typedef NTSTATUS
(USB_BUSIFFN *PUSB_BUSIFFN_QUERY_CONTROLLER_TYPE) (
  IN PVOID OPTIONAL,
  OUT PULONG OPTIONAL,
  OUT PUSHORT OPTIONAL,
  OUT PUSHORT OPTIONAL,
  OUT PUCHAR OPTIONAL,
  OUT PUCHAR OPTIONAL,
  OUT PUCHAR OPTIONAL,
  OUT PUCHAR OPTIONAL);

typedef struct _USB_BUS_INTERFACE_USBDI_V3 {
  USHORT Size;
  USHORT Version;
  PVOID BusContext;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PUSB_BUSIFFN_GETUSBDI_VERSION GetUSBDIVersion;
  PUSB_BUSIFFN_QUERY_BUS_TIME QueryBusTime;
  PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB SubmitIsoOutUrb;
  PUSB_BUSIFFN_QUERY_BUS_INFORMATION QueryBusInformation;
  PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED IsDeviceHighSpeed;
  PUSB_BUSIFFN_ENUM_LOG_ENTRY EnumLogEntry;
  PUSB_BUSIFFN_QUERY_BUS_TIME_EX QueryBusTimeEx;
  PUSB_BUSIFFN_QUERY_CONTROLLER_TYPE QueryControllerType;
} USB_BUS_INTERFACE_USBDI_V3, *PUSB_BUS_INTERFACE_USBDI_V3;

DEFINE_GUID(USB_BUS_INTERFACE_USBC_CONFIGURATION_GUID,
  0x893b6a96, 0xb7f, 0x4d4d, 0xbd, 0xb4, 0xbb, 0xd4, 0xce, 0xeb, 0xb3, 0x1c);

#define USBC_FUNCTION_FLAG_APPEND_ID 0x1

typedef struct _USBC_FUNCTION_DESCRIPTOR{
  UCHAR FunctionNumber;
  UCHAR NumberOfInterfaces;
  PUSB_INTERFACE_DESCRIPTOR *InterfaceDescriptorList;
  UNICODE_STRING HardwareId;
  UNICODE_STRING CompatibleId;
  UNICODE_STRING FunctionDescription;
  ULONG FunctionFlags;
  PVOID Reserved;
} USBC_FUNCTION_DESCRIPTOR, *PUSBC_FUNCTION_DESCRIPTOR;

typedef
NTSTATUS
(USB_BUSIFFN *USBC_START_DEVICE_CALLBACK)(
  IN PUSB_DEVICE_DESCRIPTOR DeviceDescriptor,
  IN PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  OUT PUSBC_FUNCTION_DESCRIPTOR *FunctionDescriptorBuffer,
  OUT PULONG FunctionDescriptorBufferLength,
  IN PDEVICE_OBJECT FdoDeviceObject,
  IN PDEVICE_OBJECT PdoDeviceObject);

typedef
BOOLEAN
(USB_BUSIFFN *USBC_PDO_ENABLE_CALLBACK)(
  IN PVOID  Context,
  IN USHORT FirstInterfaceNumber,
  IN USHORT NumberOfInterfaces,
  IN UCHAR  FunctionClass,
  IN UCHAR  FunctionSubClass,
  IN UCHAR  FunctionProtocol);

#define USBC_DEVICE_CONFIGURATION_INTERFACE_VERSION_1         0x0001

typedef struct _USBC_DEVICE_CONFIGURATION_INTERFACE_V1 {
  USHORT Size;
  USHORT Version;
  PVOID Context;
  PINTERFACE_REFERENCE InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  USBC_START_DEVICE_CALLBACK StartDeviceCallback;
  USBC_PDO_ENABLE_CALLBACK   PdoEnableCallback;
  PVOID Reserved[7];
} USBC_DEVICE_CONFIGURATION_INTERFACE_V1, *PUSBC_DEVICE_CONFIGURATION_INTERFACE_V1;

#endif /* (NTDDI_VERSION >= NTDDI_VISTA) */
