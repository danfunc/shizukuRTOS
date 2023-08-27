template <typename T>
concept contextable = requires { typename T::resiters; };
template <typename T, typename U>
concept context_switcher = requires(T context_switcher, U context) {
  requires contextable<U>;
  context_switcher.change_context(context);
};