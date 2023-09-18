
#include "get_set.hpp"
#include "shizuku_RTOS/shizuku_RTOS.hpp"
#include "shizuku_RTOS/shizuku_boot.h"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"

namespace shizuku_RTOS {
namespace types {}
} // namespace shizuku_RTOS

void shizuku_kernel_boot() {
  shizuku_RTOS::kernel::create_Object(32, 32);
  shizuku_RTOS::kernel::init();
  return;
}
