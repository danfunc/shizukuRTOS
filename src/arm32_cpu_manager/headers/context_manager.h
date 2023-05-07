#ifndef SHIZUKU_RTOS_CONTEXT_MANAGER
#define SHIZUKU_RTOS_CONTEXT_MANAGER
#include "stdint.h"
typedef struct
{
    uint32_t r0,r1,r2,r3,r4, r5, r6, r7, r8, r9, r10, r11, r12, returnValue;
    void *sp, *lr;
} shizuku_RTOS_context;

int saveContext(shizuku_RTOS_context *context, int returnValue);
int loadContext(shizuku_RTOS_context *context);

#endif