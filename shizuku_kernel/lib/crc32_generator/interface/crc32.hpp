
#ifndef CRC32_HPP
#define CRC32_HPP
#include "stdint.h"
void make_crc32_table(void);
uint32_t crc32(uint8_t *buf, unsigned int len);
#endif