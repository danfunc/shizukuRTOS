#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "shizukuRTOS/context.h"
#include "shizukuRTOS/process.h"
#include "stdio.h"
#include "stdlib.h"

void testProcess() {
  void *sp;

  while (1) {

    asm("mov %0, sp" : "=r"(sp));
    printf("sp:%p", sp);
    shizuku_RTOS_contextSwich();
  }
}
int main() {
  stdio_init_all();
  sleep_ms(2000);
  new_process(testProcess, 0, 0);

  while (1) {
    shizuku_RTOS_contextSwich();
  }

  return 0;
}