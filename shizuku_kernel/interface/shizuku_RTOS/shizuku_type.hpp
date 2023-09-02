#ifndef SHIZUKU_TYPE_HPP
#define SHIZUKU_TYPE_HPP
#include "shizuku_RTOS/shizuku_concepts.hpp"
namespace shizuku_RTOS
{
    namespace type{
        template <concepts::cpu_manager_concept T>
        class kernel
        {
        private:
        public:
            T cpu_manager = T();
            kernel() {};
            ~kernel(){};
        };
    }
} // namespace shizuku_RTOS

#endif
