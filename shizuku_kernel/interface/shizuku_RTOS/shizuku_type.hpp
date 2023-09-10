#ifndef SHIZUKU_TYPE_HPP
#define SHIZUKU_TYPE_HPP
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
namespace shizuku_RTOS
{
    namespace types{
        
        template <concepts::cpu_manager_concept CPU_MANAGER>
        class kernel
        {
        private:
        static CPU_MANAGER cpu_manager;
        public:
            static void init(){
                cpu_manager.init();

            };
            kernel(){
            };
            ~kernel(){};
        };
        template <concepts::cpu_manager_concept CPU_MANAGER>
        CPU_MANAGER kernel<CPU_MANAGER>::cpu_manager = CPU_MANAGER();
        namespace cpu_manager{

        }
    }
} // namespace shizuku_RTOS
#endif
