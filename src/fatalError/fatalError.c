#include "shizukuRTOS/fatalError.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "stdio.h"
void fatalError(char errorMessage[]) {
  stdio_init_all();
  sleep_ms(100);
  while (1) {
    printf("fatalError\nerror Message:%s", errorMessage);
  }
}