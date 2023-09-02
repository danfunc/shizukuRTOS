#ifndef CONTEXT_MANAGER_X86_64
#define CONTEXT_MANAGER_X86_64
namespace shizuku_RTOS {
  namespace type{
    namespace cpu_manager{
    class x86_64
    {
    private:
      /* data */
    public:
      x86_64();
      ~x86_64();
      void context_switch(){};
    };

    }
    
  }
 // namespace x86_64
} // namespace shizuku_RTOS
#endif