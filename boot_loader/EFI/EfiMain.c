#include "shizuku_kernel/kernel_entry.h"
#include <Uefi.h>

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  start_kernel();
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello,World");
  while (1) {
  }
  return 1;
}
