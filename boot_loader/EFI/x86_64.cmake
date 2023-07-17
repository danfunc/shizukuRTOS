add_executable(BOOTX64.efi EfiMain.c)
target_link_options(BOOTX64.efi PRIVATE -Wl,-entry:EfiMain)
target_include_directories(BOOTX64.efi PRIVATE include/UEFI include/UEFI/X64 include/UEFI/Uefi)
target_link_libraries(BOOTX64.efi shizuku_kernel)