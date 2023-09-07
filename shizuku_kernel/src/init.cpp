
#include "get_set.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_RTOS.hpp"
#include "shizuku_RTOS/shizuku_boot.h"

namespace shizuku_RTOS
{
    
} // namespace shizuku_RTOS

shizuku_RTOS::kernel kernel = shizuku_RTOS::kernel();

void shizuku_kernel_boot(){
    kernel.init();
    return;
}
