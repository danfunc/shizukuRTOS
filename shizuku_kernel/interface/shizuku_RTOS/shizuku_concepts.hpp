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
        };
        template <typename T>
        concept kernel_concept = requires(T real){
            cpu_manager_concept<typename T::cpu_manager>;
        };
    } // namespace concepts
} // namespace shizuku_RTOS

#endif