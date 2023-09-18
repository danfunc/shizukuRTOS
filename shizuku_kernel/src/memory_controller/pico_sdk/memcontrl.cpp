#include "shizuku_RTOS/memory_controller.hpp"
#include "stdlib.h"

void *shizuku_RTOS::types::memory_manager::pico_sdk::malloc(unsigned int size) {
  return ::malloc(size);
}
void shizuku_RTOS::types::memory_manager::pico_sdk::free(void *point) {
  ::free(point);
}