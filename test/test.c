#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "shizukuRTOS/context.h"
#include "shizukuRTOS/process.h"
#include "stdio.h"
#include "stdlib.h"

shizuku_RTOS_context test;
int main() {
  stdio_init_all();
  sleep_ms(2000);

  while (1) {
    if (saveContext(&test, 1) == 0) {
      sleep_ms(100);
      printf("changing\n");
      loadContext(&test);
    } else {
      sleep_ms(100);
      printf("failed\n");
    }
  }

  return 0;
}