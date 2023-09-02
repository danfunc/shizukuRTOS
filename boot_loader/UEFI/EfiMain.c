#include <Uefi.h>

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
char a[10000];
int b = 0;
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello,World");
  while (1) {
    a[b] = 1;
    ++b;
  }

  return 1;
}
