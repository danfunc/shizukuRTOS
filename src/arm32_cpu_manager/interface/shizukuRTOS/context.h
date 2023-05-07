#ifndef SHIZUKU_RTOS_CONTEXT
#define SHIZUKU_RTOS_CONTEXT
#include "stdint.h"
#include "stdnoreturn.h"
typedef struct {
  uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12;
  void *sp, *lr;
} shizuku_RTOS_context;
int saveContext(shizuku_RTOS_context *context, int returnValue);
void loadContext(shizuku_RTOS_context *context);
#endif
