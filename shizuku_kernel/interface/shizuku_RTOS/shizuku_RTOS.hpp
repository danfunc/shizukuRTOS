#ifndef SHIZUKU_RTOS
#define SHIZUKU_RTOS
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
#include "shizuku_RTOS/config.hpp"
#include "get_set.hpp"
static_assert(shizuku_RTOS::concepts::kernel_concept<shizuku_RTOS::kernel>,"shizuku_RTOS::kernel is not much kernel_concept");
#endif