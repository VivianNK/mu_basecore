/** @file MockPeiServicesLib.cpp
  Google Test mocks for PeiServicesLib

  Copyright (c) 2022, Microsoft Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <GoogleTest/Library/MockPeiServicesLib.h>

MOCK_INTERFACE_DEFINITION(MockPeiServicesLib);
MOCK_FUNCTION_DEFINITION(MockPeiServicesLib, PeiServicesLocatePpi, 4, EFIAPI);