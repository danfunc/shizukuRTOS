#ifndef PICO_SDK_MEMORY_CONTROLLER
#define PICO_SDK_MEMORY_CONTROLLER
#include "shizuku_RTOS/shizuku_RTOS.hpp"
#include "stdint.h"
namespace shizuku_RTOS {
namespace types {
namespace memory_manager {
class pico_sdk {
  static void *malloc(unsigned int size);
  static void free(void *point);
};
} // namespace memory_manager

} // namespace types

} // namespace shizuku_RTOS

#endif
