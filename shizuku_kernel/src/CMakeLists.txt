add_subdirectory(CPU_controller)
target_sources(shizuku_kernel PRIVATE init.cpp kernel.cpp)
