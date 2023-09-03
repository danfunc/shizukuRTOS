#include "shizuku_RTOS/shizuku_boot.h"
#include <stdio.h>
int main(int argc, char const *argv[]) {
  shizuku_kernel_boot();
  return 0;
}
