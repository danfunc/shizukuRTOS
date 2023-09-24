#ifndef CPU_MANAGER_HPP
#define CPU_MANAGER_HPP
#include "stdint.h"

namespace shizuku_RTOS {
namespace types {
namespace cpu_manager {
class RP2040 {
  

private:
  struct thread_tree {};

public:
typedef struct context {
    uint32_t  r4, r5, r6, r7, r8, r9, r10, r11, r12,return_value;
    void* sp,*lr;
  } context;
  typedef struct thread {
    context current_context;
    uint32_t thread_id, Object_crc32_id, Object_crc32_salted_id;
  } thread;
  RP2040();
  ~RP2040();
  void context_switch(context next_context);
  void init();
  int load_context(const context &context);
  int save_context(context &context,int return_value);
  int add_thread(uint32_t crc32_id, uint32_t crc32_salted_id,
                 void (*entry_point)(int argc, char *argv[]),int argc,char*argv[]) {
    return 0;
  };
};
} // namespace cpu_manager
} // namespace types
} // namespace shizuku_RTOS

#endif