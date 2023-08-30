<<<<<<< Updated upstream
template <typename T>
concept contextable = requires { typename T::resiters; };
template <typename T, typename U>
concept context_switcher = requires(T context_switcher, U context) {
  requires contextable<U>;
  context_switcher.change_context(context);
};
=======
#include "same_type.hpp"
namespace shizuku_RTOS
{
    namespace concepts
    {
        template <typename T>
        concept context_switch_concept =  requires (T real){
        
        };
        template <typename T>
        concept kernel_concept = requires(T real){
        typename T::context_switch;
        };
    } // namespace concepts
    
    
} // namespace shizuku_RTOS
>>>>>>> Stashed changes
