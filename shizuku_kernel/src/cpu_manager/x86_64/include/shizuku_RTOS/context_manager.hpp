#ifndef CONTEXT_MANAGER_X86_64
#define CONTEXT_MANAGER_X86_64
namespace shizuku_RTOS {
  namespace types{
    namespace cpu_manager{
    class x86_64
    {
    private:
    public:
      x86_64();
      ~x86_64();
      void context_switch(){};
      void init(){};
      void add_thread(void (*entry_point)()){};
    };
    }
  }// namespace x86_64
} // namespace shizuku_RTOS
#endif