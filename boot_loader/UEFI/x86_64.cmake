target_include_directories(shizuku_boot_loader PRIVATE include/UEFI/X64)
add_custom_target(BOOTX64.efi ALL COMMAND cp $<TARGET_FILE:shizuku_boot_loader> ${PROJECT_BINARY_DIR}/BOOTX64.efi)

