#ifndef SHIZUKU_CONFIG_HPP
#define SHIZUKU_CONFIG_HPP
#include "shizuku_RTOS/cpu_managers.hpp"
#include "shizuku_RTOS/memory_managers.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/shizuku_interface.hpp"
#include "shizuku_RTOS/shizuku_type.hpp"
namespace shizuku_RTOS {
    namespace configs
    {
        
using cpu_manager = types::cpu_managers::SHIZUKU_SYSTEM_PROCESSOR;
using memory_manager = types::physical_memory_managers::SHIZUKU_PLATFORM_NAME;
    } // namespace configs
    
/* static_assert(shizuku_RTOS::concepts::cpu_manager_concept<cpu_manager>,"cpu_manager
 is not much cpu_manager_concept");*/
}; // namespace shizuku_RTOS

#endif
