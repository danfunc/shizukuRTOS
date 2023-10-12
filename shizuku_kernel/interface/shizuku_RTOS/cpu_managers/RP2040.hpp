#ifndef CPU_MANAGER_RP2040_HPP
#define CPU_MANAGER_RP2040_HPP
#include "stdint.h"

namespace shizuku_RTOS {
namespace types {
namespace cpu_manager {
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
  void context_switch();
  void init();
  int load_context(const context &context);
  int save_context(context &context, int return_value);
  int add_thread(uint32_t crc32_id, uint32_t crc32_salted_id,
                 void (*entry_point)(int argc, char *argv[]), int argc,
                 char *argv[]);
  using thread_list = struct thread_list {
    thread_list *next, *before;
    thread current_thread;
  };
};
} // namespace cpu_manager
} // namespace types
} // namespace shizuku_RTOS

#endif