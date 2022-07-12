/** @file -- EventAudit.h

This protocol provides debug access to a list of events to allow
validation of the events.

Copyright (c) Microsoft Corporation. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EVENT_AUDIT_PROTOCOL__
#define __EVENT_AUDIT_PROTOCOL__

#include <Uefi.h>

#include <Library/PrintLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Guid/EventGroup.h>
#include <Protocol/SimpleFileSystem.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>

#define MAX_STR_LEN  256

#define EVENT_AUDIT_PROTOCOL_GUID \
  { \
    0x40e54833, 0x6bf7, 0x4177, { 0x94, 0x92, 0x51, 0xd1, 0xa2, 0xbc, 0xcb, 0x70 } \
  }

#define EVENT_INFO_SIGNATURE  SIGNATURE_32 ('E','V','I','N')

// TODO: consolidate with struct definition from Event.h

///
/// Event Info
///
typedef struct {
  UINT32        Signature;
  LIST_ENTRY    Link;
  CHAR8         ImagePath[MAX_STR_LEN];
  CHAR8         FunctionAddress[16];
  UINT64        TimeInNanoSeconds;
  EFI_TPL       Tpl;              // UINTN
} EVENT_INFO;

typedef struct {
  LIST_ENTRY    gEventInfoList;
  UINTN         NumberOfEntries;
} _EVENT_AUDIT_PROTOCOL;

typedef _EVENT_AUDIT_PROTOCOL EVENT_AUDIT_PROTOCOL;

extern EFI_GUID  gEventAuditProtocolGuid;

#endif
