#ifndef SHIZUKU_CONCEPTS_HPP
#define SHIZUKU_CONCEPTS_HPP
#include "same_type.hpp"
namespace shizuku_RTOS
{
    namespace concepts
    {
        template <typename object>
        concept object_concept = requires (object real){
            same_type<decltype(real.name),char*>;
        };
        template <typename cpu_manager>
        concept cpu_manager_concept =  requires (cpu_manager real){
        real.context_switch();
        real.init();
        real.add_thread();
        cpu_manager();
        };
        template <typename kernel>
        concept kernel_concept = requires{
            kernel::init();
        };

    } // namespace concepts
} // namespace shizuku_RTOS

#endif