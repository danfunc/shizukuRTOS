#ifndef GET_SET_HPP
#define GET_SET_HPP
#include "getable_getter.hpp"
#include "same_type.hpp"
#include "setable_setter.hpp"

template <typename T> class get_set {
protected:
  T payload = T();

public:
  get_set(){};
  ~get_set(){};
  virtual void getter(T input) { this->payload = input; };
  virtual void setter(T &output) { output = this->payload; };
};
template <typename T, typename U>
concept streamable = requires(T &a, U b) {
  { a.stream(b) } -> shizuku_RTOS::same_type<T &>;
};
template <typename T, typename U>
  requires streamable<T, U>
T &operator<<(T &t, U u)

{
  return t.stream(u);
}

#endif