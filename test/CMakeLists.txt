add_executable(test test.c)
target_link_libraries(test shizukuRTOS_arm32_cpu_manager pico_stdlib)
pico_enable_stdio_usb(test 1)
pico_add_extra_outputs(test)