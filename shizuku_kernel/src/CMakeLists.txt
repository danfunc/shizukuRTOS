add_subdirectory(CPU_controller)
target_sources(shizuku_kernel PRIVATE typecheck.cpp)
target_sources(shizuku_kernel PUBLIC init.cpp)
