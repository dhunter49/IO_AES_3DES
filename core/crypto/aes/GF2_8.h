#ifndef GF2_8_H
#define GF2_8_H

#include <iostream>
const uint16_t IRRPOLY_GF_2_8 = 0b100011011; // x^8 + x^4 + x^3 + x + 1 = 0x1b = 00011011

class GF2_8 {
public:
	static uint16_t msb_uint16(uint16_t n);
	static uint8_t add_GF_2_8(uint8_t a, uint8_t b);
	static uint8_t mult_GF_2_8(uint8_t a, uint8_t b);
	static uint8_t pow_GF_2_8(uint8_t a, uint8_t n);
	static uint8_t inv_GF_2_8(uint8_t a);
};

#endif