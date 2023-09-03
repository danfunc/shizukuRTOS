#ifndef SHIZUKU_CONFIG
#define SHIZUKU_CONFIG
#include "shizuku_RTOS/cpu_manager.hpp"
namespace shizuku_RTOS {
    using shizuku_system_processor = type::cpu_manager::SHIZUKU_SYSTEM_PROCESSOR;
    using cpu_manager = shizuku_system_processor;
};
#endif