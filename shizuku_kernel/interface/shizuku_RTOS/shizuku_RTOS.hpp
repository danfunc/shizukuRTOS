#ifndef SHIZUKU_RTOS
#define SHIZUKU_RTOS
#include "get_set.hpp"
#include "shizuku_RTOS/config.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
#include "shizuku_RTOS/cpu_managers.hpp"
#include "shizuku_RTOS/memory_managers.hpp"
namespace shizuku_RTOS
{
using kernel = shizuku_RTOS::types::kernel;
using Object = shizuku_RTOS::kernel::Object;
} // namespace shizuku_RTOS

/* static_assert(shizuku_RTOS::concepts::kernel_concept<shizuku_RTOS::kernel>,"shizuku_RTOS::kernel
is not much kernel_concept");*/


#endif