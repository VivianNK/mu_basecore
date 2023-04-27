/** @file MockPeiServicesLib.cpp
  Google Test mocks for PeiServicesLib

  Copyright (c) 2022, Microsoft Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <GoogleTest/Library/MockPeiServicesLib.h>

MOCK_INTERFACE_DEFINITION(MockPeiServicesLib);
MOCK_FUNCTION_DEFINITION(MockPeiServicesLib, PeiServicesLocatePpi, 4, EFIAPI);
MOCK_FUNCTION_DEFINITION(MockPeiServicesLib, pei_GetVariable, 6, EFIAPI);

  // todo why "variable2"?

// no this can't exist yet... or it can?
// normally variableservices is "found"
// this will be defined INSIDE the test, with its definition pointing to the mock function pei_GetVariable
static EFI_PEI_READ_ONLY_VARIABLE2_PPI peiReadOnlyVariablePpi = {
  pei_GetVariable, // EFI_PEI_GET_VARIABLE2
  NULL, // EFI_PEI_GET_NEXT_VARIABLE_NAME2
};


extern "C" {
  EFI_PEI_READ_ONLY_VARIABLE2_PPI* PPIVariableServices = &peiReadOnlyVariablePpi;
}