set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_C_COMPILER_TARGET x86_64-pc-windows-msvc)
set(CMAKE_CXX_COMPILER_TARGET x86_64-pc-windows-msvc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -mno-red-zone -fno-stack-protector -fshort-wchar -target x86_64-windows-msvc -nostdlib -Wno-microsoft-static-assert")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -mno-red-zone -fno-stack-protector -fshort-wchar -target x86_64-windows-msvc -nostdlib -Wno-microsoft-static-assert")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-subsystem:efi_application -fuse-ld=lld")
set(SHIZUKU_ARCH x86_64 CACHE STRING boot_loader_directory_name FORCE)
set(SHIZUKU_PLATFORM EFI CACHE STRING platform_name FORCE)