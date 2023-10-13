#ifndef MEMORY_MANAGER_PICO_SDK
#define MEMORY_MANAGER_PICO_SDK
#include "cstdint"

namespace shizuku_RTOS {
namespace types {
namespace physical_memory_managers {
class pico_sdk {
  static void *malloc(std::size_t size);
  static void free(void *point);
};
} // namespace memory_manager

} // namespace types

} // namespace shizuku_RTOS

#endif