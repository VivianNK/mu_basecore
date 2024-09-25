/** @file NvmeExpressDxeGoogleTest.cpp

**/

#include <Library/GoogleTestLib.h>
#include <Library/FunctionMockLib.h>
#include <GoogleTest/Protocol/MockPciIoProtocol.h>

extern "C" {
  #include <Uefi.h>
  #include <Library/BaseLib.h>
  #include <Library/DebugLib.h>
  #include "../NvmExpress.h"
  #include "../NvmExpressHci.h"
}

using namespace testing;

/**
  Sample unit test that verifies a global BOOLEAN is updatable
**/
class NvmExpressHciTest : public Test {
protected:
  StrictMock<MockPciIoProtocol> PciIoProtocolMock;
  EFI_STATUS Status;
  NVME_CONTROLLER_PRIVATE_DATA *Private;

  void
  SetUp (
    ) override
  {
    Status  = EFI_SUCCESS;
    Private = (NVME_CONTROLLER_PRIVATE_DATA *)AllocateZeroPool (sizeof (NVME_CONTROLLER_PRIVATE_DATA));
    if (Private == NULL) {
      Status = EFI_OUT_OF_RESOURCES;
    }
  }

  void
  TearDown (
    ) override
  {
    if (Private != NULL) {
      FreePool (Private);
    }
  }
};

TEST_F (NvmExpressHciTest, ReadNvmeControllerCapabilitiesTest) {
  EXPECT_CALL (
    PciIoProtocolMock,
    PciIoRead
    ).WillOnce (
        Return (EFI_SUCCESS)
        );

  Status = ReadNvmeControllerCapabilities ();
}

TEST_F (NvmExpressHciTest, NvmeControllerInitTest) {
  Status = NvmeControllerInit ();
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
