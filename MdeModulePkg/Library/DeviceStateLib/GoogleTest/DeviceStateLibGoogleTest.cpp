/** @file DeviceStateLibGoogleTest.cpp

**/

#include <Library/GoogleTestLib.h>

extern "C" {
  #include <Uefi.h>
  #include <Library/BaseLib.h>
  #include <Library/DebugLib.h>
  #include <Library/DeviceStateLib.h>
}

using namespace testing;

/**
  Sample unit test that verifies a global BOOLEAN is updatable
**/
class DeviceStateBitmaskIsSetTest : public Test {
protected:
  DEVICE_STATE CurrentDeviceState; // mocking the variable instead of mocking pcd lib
  DEVICE_STATE InsecureDeviceStateSetting;

  void
  SetUp (
    ) override
  {
    CurrentDeviceState         = 0x000000000;
    InsecureDeviceStateSetting = 0x000000000;
  }
};

TEST_F (DeviceStateBitmaskIsSetTest, BitmaskCheckAllBits) {
  CurrentDeviceState |= DEVICE_STATE_SOURCE_DEBUG_ENABLED;
  CurrentDeviceState |= DEVICE_STATE_SOURCE_DEBUG_ENABLED;
  CurrentDeviceState |= DEVICE_STATE_UNIT_TEST_MODE;

  BOOLEAN  Result = DeviceStateBitmaskIsSet (CurrentDeviceState, InsecureDeviceStateSetting);

  EXPECT_FALSE (Result);

  InsecureDeviceStateSetting |= DEVICE_STATE_SOURCE_DEBUG_ENABLED;

  //
  // Only one of the current device's bits that is set is considered insecure
  // Return true
  Result = DeviceStateBitmaskIsSet (CurrentDeviceState, InsecureDeviceStateSetting);
  EXPECT_TRUE (Result);

  InsecureDeviceStateSetting |= DEVICE_STATE_UNIT_TEST_MODE;

  //
  // All of the current device's bits that are set are considered insecure
  //
  Result = DeviceStateBitmaskIsSet (CurrentDeviceState, InsecureDeviceStateSetting);
  EXPECT_TRUE (Result);
}

int
main (
  int   argc,
  char  *argv[]
  )
{
  InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
