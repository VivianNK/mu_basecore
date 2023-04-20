/** @file -- VariablePolicyGoogleTest.cpp
  Unit tests for the implementation of VariablePolicyLib.

  Copyright (c) 2023, Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <Library/GoogleTestLib.h>
#include <GoogleTest/Library/MockUefiLib.h>
#include <GoogleTest/Library/MockUefiRuntimeServicesTableLib.h>

extern "C" {
  #include <Uefi.h>
  #include <Library/VariablePolicyLib.h>
  #include <Library/SortLib.h>
}

using namespace testing;

/////////////////////////////////////////////////////////////
class InitVariablePolicyLibTest : public Test {
  protected:
    MockUefiRuntimeServicesTableLib RtServicesMock;
    EFI_STATUS  Status;

    void SetUp() override {
      
    }
};



INTN
EFIAPI
CompareUint32 (
  IN CONST VOID  *Left,
  IN CONST VOID  *Right
  )
{
  if (*(UINT32*)Right > *(UINT32*)Left) {
    return 1;
  } else if (*(UINT32*)Right < *(UINT32*)Left) {
    return -1;
  }

  return 0;
}



// Test StringCompare() API from UefiSortLib to verify the comparison
// succeeds when the same buffer is compared with itself.
TEST(StringCompareTest, CompareSameBuffer) {
  INTN           RetVal;
  CONST CHAR16  *Buffer = (CHAR16*)L"abcdefg";

  RetVal = StringCompare (&Buffer, &Buffer);
  EXPECT_EQ(RetVal, 0);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}