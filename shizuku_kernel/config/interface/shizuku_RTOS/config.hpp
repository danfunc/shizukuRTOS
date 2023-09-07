#ifndef SHIZUKU_CONFIG_HPP
#define SHIZUKU_CONFIG_HPP
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
namespace shizuku_RTOS {
    using shizuku_system_processor = types::cpu_manager::SHIZUKU_SYSTEM_PROCESSOR;
    using cpu_manager = shizuku_system_processor;
};
namespace shizuku_RTOS {
    using kernel = types::shizuku_kernel<types::kernel<cpu_manager>>;
};
#endif