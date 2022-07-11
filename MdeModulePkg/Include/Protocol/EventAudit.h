/** @file -- EventAudit.h

This protocol provides debug access to a list of events to allow
validation of the events.

Copyright (c) Microsoft Corporation. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EVENT_AUDIT_PROTOCOL__
#define __EVENT_AUDIT_PROTOCOL__

#define EVENT_AUDIT_PROTOCOL_GUID \
  { \
    0x40e54833, 0x6bf7, 0x4177, { 0x94, 0x92, 0x51, 0xd1, 0xa2, 0xbc, 0xcb, 0x70 } \
  }

typedef struct {
  LIST_ENTRY    gEventInfoList;
} _EVENT_AUDIT_PROTOCOL;

typedef _EVENT_AUDIT_PROTOCOL EVENT_AUDIT_PROTOCOL;

extern EFI_GUID  gEventAuditProtocolGuid;

#endif
