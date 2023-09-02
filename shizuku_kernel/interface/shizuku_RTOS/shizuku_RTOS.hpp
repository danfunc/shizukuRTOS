#ifndef SHIZUKU_RTOS
#define SHIZUKU_RTOS
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
#include "shizuku_RTOS/config.hpp"
namespace shizuku_RTOS {
    using kernel = type::kernel<type::cpu_manager::x86_64>;
}
#endif