
#include "crc32.hpp"
#include "stdint.h"

uint32_t crc32_table[256];

void make_crc32_table(void) {
  for (uint32_t i = 0; i < 256; i++) {
    uint32_t c = i;
    for (int j = 0; j < 8; j++) {
      c = (c & 1) ? (0xEDB88320 ^ (c >> 1)) : (c >> 1);
    }
    crc32_table[i] = c;
  }
}

uint32_t crc32(uint8_t *buf, unsigned int len) {
  uint32_t c = 0xFFFFFFFF;
  for (unsigned int i = 0; i < len; i++) {
    c = crc32_table[(c ^ buf[i]) & 0xFF] ^ (c >> 8);
  }
  return c ^ 0xFFFFFFFF;
}