#ifndef SHIZUKU_CONCEPTS_HPP
#define SHIZUKU_CONCEPTS_HPP
#include "same_type.hpp"
#include "stdint.h"
namespace shizuku_RTOS {
namespace concepts {
template <typename cpu_manager>
concept cpu_manager_concept =
    requires(cpu_manager real, void (*entry_point)(int argc, char *argv[]),
             uint32_t crc32_id, uint32_t crc32_salted_id) {
  real.context_switch(); // コンテキストスイッチ機能
  real.init();           // 初期化機能
  {
    real.add_thread(crc32_id, crc32_salted_id, entry_point)
    } -> shizuku_RTOS::same_type<
        int>; // スレッド追加機能(オブジェクトIDとエントリポイントを渡したらスレッドIDが返ってくる)
  cpu_manager();
};
template <typename kernel>
concept object_system_available = requires(uint32_t crc32_id,
                                           uint32_t crc32_salted_id, char *name,
                                           unsigned int size) {
  kernel::create_Object(
      crc32_id,
      crc32_salted_id); // オブジェクトを作成する(オブジェクト名をcrc32してソルトした上でもう一度crc32して入れる)
  {
    kernel::search_Object(crc32_id, crc32_salted_id)
    } -> shizuku_RTOS::same_type<int>; // オブジェクト検索
  kernel::create_Object(name, size);
  { kernel::search_Object(name, size) } -> shizuku_RTOS::same_type<int>;
};
template <typename kernel>
concept kernel_concept = requires(void (*entry_point)(int argc, char *argv[]),
                                  uint32_t crc32_id, uint32_t crc32_salted_id) {
  kernel::init(); // 初期化機能(ブートローダは最終的にこれを呼び出す)
  kernel::create_Object(
      crc32_id,
      crc32_salted_id); // オブジェクトを作成する(オブジェクト名をcrc32してソルトした上でもう一度crc32して入れる)
  kernel::add_thread(crc32_id, crc32_salted_id, entry_point);
  {
    kernel::search_Object(crc32_id, crc32_salted_id)
    } -> shizuku_RTOS::same_type<int>; // オブジェクト検索
  object_system_available<kernel>;
};
} // namespace concepts
} // namespace shizuku_RTOS

#endif