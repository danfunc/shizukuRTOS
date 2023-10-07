#include "algorithm"
#include "shizuku_RTOS/cpu_manager.hpp"

int shizuku_RTOS::types::cpu_manager::RP2040::add_thread(
    uint32_t crc32_id, uint32_t crc32_salted_id,
    void (*entry_point)(int argc, char *argv[]), int argc, char *argv[]) {
  return 0;
}
