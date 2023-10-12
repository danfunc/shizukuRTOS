add_subdirectory(cpu_manager)
target_sources(shizuku_kernel PRIVATE init.cpp kernel.cpp)
add_subdirectory(memory_controller)