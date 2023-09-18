/** @file MockReadOnlyVariable2.cpp
  Google Test mock for ReadOnlyVariable2

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <GoogleTest/Ppi/MockReadOnlyVariable2.h>

MOCK_INTERFACE_DEFINITION (MockReadOnlyVariable2);
MOCK_FUNCTION_DEFINITION (MockReadOnlyVariable2, pei_GetVariable, 6, EFIAPI);
MOCK_FUNCTION_DEFINITION (MockReadOnlyVariable2, pei_NextVariableName, 4, EFIAPI);

// Normally PPIVariableServices is "found"
// This will be defined INSIDE the test, with its definition pointing to the mock function getVariable
static EFI_PEI_READ_ONLY_VARIABLE2_PPI  peiReadOnlyVariablePpi = {
  pei_GetVariable,      // EFI_PEI_GET_VARIABLE2
  pei_NextVariableName  // EFI_PEI_GET_NEXT_VARIABLE_NAME2
};

static EFI_PEI_READ_ONLY_VARIABLE2_PPI  *PPIReadOnlyVariableServices = &peiReadOnlyVariablePpi;
