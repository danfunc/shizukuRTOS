#include "shizuku_RTOS/shizuku_RTOS.hpp"
#include "stdlib.h"

void *shizuku_RTOS::types::physical_memory_managers::pico_sdk::malloc(std::size_t size) {
  return ::malloc(size);
}
void shizuku_RTOS::types::physical_memory_managers::pico_sdk::free(void *point) {
  ::free(point);
}