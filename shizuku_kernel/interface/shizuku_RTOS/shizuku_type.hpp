#ifndef SHIZUKU_TYPE_HPP
#define SHIZUKU_TYPE_HPP
#include "crc32.hpp"
#include "shizuku_RTOS/cpu_manager.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "stdint.h"
namespace shizuku_RTOS {
namespace types {

template <typename CPU_MANAGER> class kernel {
private:
  static CPU_MANAGER cpu_manager;
  typedef struct Object {
    uint32_t crc32_id, crc32_salted_id;

  } Object;

public:
  static void init() {
    ::make_crc32_table();
    cpu_manager.init();
  };
  static void create_Object(uint32_t crc32_id, uint32_t crc32_salted_id){};
  static inline void create_Object(char *name, const unsigned int size) {
    char salted[size * 2];
    for (int i = 0; i < size; i++) {
    }

    create_Object(::crc32(name, size), crc32(name, size));
  }
  static inline void add_thread(uint32_t crc32_id, uint32_t crc32_salted_id,
                                void (*entry_point)(int argc, char *argv[])) {
    cpu_manager.add_thread(crc32_id, crc32_salted_id, entry_point);
  };
  kernel(){};
  ~kernel(){};
};
template <typename CPU_MANAGER>
CPU_MANAGER kernel<CPU_MANAGER>::cpu_manager = CPU_MANAGER();
struct Object {
  uint32_t crc32_id;
  uint32_t crc32_salted_id;
} typedef Object;

} // namespace types
} // namespace shizuku_RTOS
#endif
