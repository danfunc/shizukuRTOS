#ifndef CPU_MANAGER_RP2040_HPP
#define CPU_MANAGER_RP2040_HPP
#include "stdint.h"

namespace shizuku_RTOS {
namespace types {
namespace cpu_managers {
class RP2040 {
public:
  using context = struct {
    uint32_t r4, r5, r6, r7, r8, r9, r10, r11, r12, return_value;
    void *sp, *lr;
  };
  using thread = struct {
    context current_context;
    uint32_t thread_id, Object_crc32_id, Object_crc32_salted_id;
  };
  RP2040();
  ~RP2040();
  void context_switch(context &current_context, context &next_context);
  void init();
  int load_context(const context &context);
  int save_context(context &context, int return_value);
};
} // namespace cpu_manager
} // namespace types
} // namespace shizuku_RTOS

#endif