#include "shizukuRTOS/fatalError.h"
#include "pico/stdio.h"
#include "stdio.h"
void fatalError(char errorMessage[])
{
    stdio_init_all();
    while (1)
    {
        printf("fatalError\nerror Message:%s", errorMessage);
    }
}