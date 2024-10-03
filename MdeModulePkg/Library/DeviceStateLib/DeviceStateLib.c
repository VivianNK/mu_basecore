/** @file DeviceStateLib.c
Functions used to support Getting and Setting Device States.
This library uses the PcdDeviceStateBitmask dynamic PCD to store the device state

Copyright (C) Microsoft Corporation.
SPDX-License-Identifier: BSD-2-Clause-Patent

MU_CHANGE: new file
**/

#include <PiPei.h>
#include <Library/PcdLib.h>
#include <Library/DeviceStateLib.h>
#include <Library/DebugLib.h>

/**
Get the platform defined set of insecure device states. This can be used to measure insecure device
states into the TPM or perform other required platform actions when the device enters an insecure state.

@retval The bitmask of insecure device states as defined by the platform.
**/
DEVICE_STATE
EFIAPI
GetInsecureDeviceStateSetting (
  )
{
  return FixedPcdGet32 (PcdInsecureDeviceState);
}

/**
Function to Get current device state
@retval the current DEVICE_STATE
**/
DEVICE_STATE
EFIAPI
GetDeviceState (
  )
{
  return PcdGet32 (PcdDeviceStateBitmask);
}

/**
Function to Add additional bits to the device state

@param AdditionalState - additional state to set active
@retval Status of operation.  EFI_SUCCESS on successful update.
**/
RETURN_STATUS
EFIAPI
AddDeviceState (
  DEVICE_STATE  AdditionalState
  )
{
  DEVICE_STATE  DevState;
  DEVICE_STATE  SetValue;
  EFI_STATUS    Status;

  DevState = PcdGet32 (PcdDeviceStateBitmask);

  DEBUG ((DEBUG_INFO, "Adding Device State.  0x%X\n", AdditionalState));

  DevState |= AdditionalState;
  Status    = PcdSet32S (PcdDeviceStateBitmask, DevState);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "%a - Error setting device state - %r\n", __FUNCTION__, Status));
    return RETURN_DEVICE_ERROR;
  }

  SetValue = PcdGet32 (PcdDeviceStateBitmask);

  return ((SetValue == DevState) ? RETURN_SUCCESS : RETURN_OUT_OF_RESOURCES);
}
