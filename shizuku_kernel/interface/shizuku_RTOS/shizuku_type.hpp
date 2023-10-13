#ifndef SHIZUKU_TYPE_HPP
#define SHIZUKU_TYPE_HPP
#include "crc32.hpp"
#include "shizuku_RTOS/cpu_managers.hpp"
#include "shizuku_RTOS/memory_managers.hpp"
#include "shizuku_RTOS/shizuku_concepts.hpp"
#include "shizuku_RTOS/config.hpp"
#include "stdint.h"
namespace shizuku_RTOS {
namespace types {
class kernel {
private:

public:
  using Object = struct Object { 
    
    uint32_t crc32_id, crc32_salted_id; };
  static void init() {
    ::make_crc32_table();
  };
  static void create_Object(uint32_t crc32_id, uint32_t crc32_salted_id){};
  static inline void create_Object(char *name, const unsigned int size) {
  }
  static inline void add_thread(uint32_t crc32_id, uint32_t crc32_salted_id,
                                void (*entry_point)(int argc, char *argv[])) {
  };
  kernel(){};
  ~kernel(){};
};


} // namespace types
} // namespace shizuku_RTOS
#endif
