#ifndef SHIZUKU_TYPE_HPP
#define SHIZUKU_TYPE_HPP
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
namespace shizuku_RTOS
{
    namespace types{
        
        template <concepts::cpu_manager_concept T>
        class kernel
        {
        private:
        public:
            T cpu_manager = T();
            void init() {cpu_manager.init();};
            kernel(){};
            ~kernel(){};
        };
        namespace cpu_manager{

        }
        template <concepts::kernel_concept T>
        class shizuku_kernel
        {
        private:
            /* data */
        public:
        void init();
            shizuku_kernel(/* args */);
            ~shizuku_kernel();
        };
        template <concepts::kernel_concept T>
        shizuku_kernel<T>::shizuku_kernel()
        {
        };
        template <concepts::kernel_concept T>
        shizuku_kernel<T>::~shizuku_kernel()
        {
        };
        template <concepts::kernel_concept T>
        void shizuku_kernel<T>::init(){
        };
    }
} // namespace shizuku_RTOS

#endif
