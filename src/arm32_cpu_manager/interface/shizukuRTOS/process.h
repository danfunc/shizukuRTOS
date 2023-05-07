#ifndef SHIZUKU_RTOS_PROCESS
#define SHIZUKU_RTOS_PROCESS
#include "shizukuRTOS/context.h"
void new_process(void (*entrypoint)(void), int argc, char *argv[]);
void shizuku_RTOS_contextSwich();
void add_process(shizuku_RTOS_context context);
#endif