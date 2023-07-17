file(GLOB_RECURSE SHIZUKU_BOOT_LOADER ${SHIZUKU_PLATFORM}/CMakeLists.txt)
if(SHIZUKU_BOOT_LOADER)
message("BOOT_LOADER : ${SHIZUKU_BOOT_LOADER}")
add_subdirectory(${SHIZUKU_PLATFORM})
else()
message(SEND_ERROR "BOOT_LOADER NOT FOUND plese check boot_loader for your SHIZUKU_PLATFORM")
endif()



