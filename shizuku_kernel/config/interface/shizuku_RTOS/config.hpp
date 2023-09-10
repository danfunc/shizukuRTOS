#ifndef SHIZUKU_CONFIG_HPP
#define SHIZUKU_CONFIG_HPP
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
namespace shizuku_RTOS {
    using cpu_manager = types::cpu_manager::SHIZUKU_SYSTEM_PROCESSOR;
};
namespace shizuku_RTOS {
    using kernel = types::kernel<cpu_manager>;
};
#endif