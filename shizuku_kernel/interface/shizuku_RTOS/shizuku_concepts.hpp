#ifndef SHIZUKU_CONCEPTS_HPP
#define SHIZUKU_CONCEPTS_HPP
#include "same_type.hpp"
#include "stdint.h"
namespace shizuku_RTOS
{
    namespace concepts
    {
        template <typename cpu_manager>
        concept cpu_manager_concept =  requires (cpu_manager real,void (*entry_point)(int argc,char *argv[]),uint32_t crc32_id, uint32_t crc32_salted_id){
        real.context_switch();
        real.init();
        {real.add_thread(crc32_id,crc32_salted_id,entry_point)} -> shizuku_RTOS::same_type<int>;
        cpu_manager();
        };
        template <typename kernel>
        concept kernel_concept = requires(void (*entry_point)(int argc,char *argv[]),uint32_t crc32_id, uint32_t crc32_salted_id){
            kernel::init();
            kernel::create_Object(crc32_id,crc32_salted_id);
            kernel::add_thread(crc32_id,crc32_salted_id,entry_point);
        };
    } // namespace concepts
} // namespace shizuku_RTOS

#endif