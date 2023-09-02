add_library(shziuku_libc++ STATIC)
target_link_libraries(shizuku_kernel PUBLIC shziuku_libc++)
target_sources(shziuku_libc++ PRIVATE atexit.cpp)