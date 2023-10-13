
#include "shizuku_RTOS/shizuku_RTOS.hpp"

int shizuku_RTOS::types::cpu_managers::RP2040::save_context(context &context,int return_value){
  if (return_value == 0) {
    return_value = 1;
  }
  context.return_value = return_value;
  void *sp, *lr, *pc;
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11, r12;
  asm("mov %0, r4" : "=r"(r4));
  context.r4 = r4;
  asm("mov %0, r5" : "=r"(r5));
  context.r5 = r5;
  asm("mov %0, r6" : "=r"(r6));
  context.r6 = r6;
  asm("mov %0, r7" : "=r"(r7));
  context.r7 = r7;
  asm("mov %0, r8" : "=r"(r8));
  context.r8 = r8;
  asm("mov %0, r9" : "=r"(r9));
  context.r9 = r9;
  asm("mov %0, r10" : "=r"(r10));
  context.r10 = r10;
  asm("mov %0, r11" : "=r"(r11));
  context.r11 = r11;
  asm("mov %0, r12" : "=r"(r12));
  context.r12 = r12;
  asm("mov %0, sp" : "=r"(sp) :);
  context.sp = sp;
  asm("mov %0, lr" : "=r"(lr));
  context.lr = lr;
  return 0;
}

void shizuku_RTOS::types::cpu_managers::RP2040::context_switch(context &current_context, context &next_context){
  if (!save_context(current_context,1)){
    load_context(next_context);
  }
  return;
};


int shizuku_RTOS::types::cpu_managers::RP2040::load_context(const context &context){
    void *sp, *lr;
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11, r12;
  r4 = context.r4;
  asm("mov r4, %0" : : "r"(r4));
  r5 = context.r5;
  asm("mov r5, %0" : : "r"(r5));
  r6 = context.r6;
  asm("mov r6, %0" : : "r"(r6));
  r7 = context.r7;
  asm("mov r7, %0" : : "r"(r7));
  r8 = context.r8;
  asm("mov r8, %0" : : "r"(r8));
  r9 = context.r9;
  asm("mov r9, %0" : : "r"(r9));
  r10 = context.r10;
  asm("mov r10, %0" : : "r"(r10));
  r11 = context.r11;
  asm("mov r11, %0" : : "r"(r11));
  r12 = context.r12;
  asm("mov r12, %0" : : "r"(r12));
  sp = context.sp;
  asm("mov sp, %0" : : "r"(sp));
  lr = context.lr;
  asm("mov lr, %0" : : "r"(lr));
  return context.return_value;
}
