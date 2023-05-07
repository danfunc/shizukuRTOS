#ifndef SHIZUKU_RTOS_PROCESS_MANAGER
#define SHIZUKU_RTOS_PROCESS_MANAGER
#define SHIZUKU_RTOS_SYSTEM_STACK_SIZE 1024

#include "context_manager.h"

typedef struct shizuku_RTOS_process {
  struct shizuku_RTOS_process *before;
  struct shizuku_RTOS_process *after;
  shizuku_RTOS_context context;
} shizuku_RTOS_process;

static char shizuku_RTOS_System_Stack[SHIZUKU_RTOS_SYSTEM_STACK_SIZE];
static char *shizuku_RTOS_System_Stack_Address = shizuku_RTOS_System_Stack;

void new_process(void (*entrypoint)(int, char **), int argc, char *argv[]);
void shizuku_RTOS_System();
void shizuku_RTOS_contextSwich();
void add_process(shizuku_RTOS_context context);

#endif