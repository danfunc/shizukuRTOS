
#include "get_set.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_RTOS.hpp"
#include "shizuku_RTOS/shizuku_boot.h"

namespace shizuku_RTOS
{
    
} // namespace shizuku_RTOS


void shizuku_kernel_boot(){
    shizuku_RTOS::kernel::init();
    return;
}
struct Object
{
    
    unsigned int id;
    const char *name;
    Object(char *name):name(name){}
    };

static_assert(shizuku_RTOS::concepts::object_concept<Object>);