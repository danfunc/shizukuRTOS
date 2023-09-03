#ifndef CPU_MANAGER_HPP
#define CPU_MANAGER_HPP
namespace shizuku_RTOS{
    namespace type{
        namespace cpu_manager{
            class RP2040
            {
            private:
                /* data */
            public:
                RP2040();
                ~RP2040();
                context_switch();
            };
            
            RP2040::RP2040(/* args */)
            {
            }
            
            RP2040::~RP2040()
            {
            }
            RP2040::context_switch(){

            }
            
        }
    }
}
#endif