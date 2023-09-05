#ifndef SHIZUKU_CONCEPTS_HPP
#define SHIZUKU_CONCEPTS_HPP
#include "same_type.hpp"
namespace shizuku_RTOS
{
    namespace concepts
    {
        template <typename T>
        concept cpu_manager_concept =  requires (T real){
        real.context_switch();
        real.init();
        real.add_thread();
        };
        template <typename T>
        concept kernel_concept = requires(T real){
            real.init();
        };

    } // namespace concepts
} // namespace shizuku_RTOS

#endif