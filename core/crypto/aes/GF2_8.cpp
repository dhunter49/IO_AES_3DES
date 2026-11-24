#include <iostream>
#include "GF2_8.h"

using namespace std;

uint16_t GF2_8::msb_uint16(uint16_t n) {
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n += 1;
	return (n >> 1);
}

uint8_t GF2_8::add_GF_2_8(uint8_t a, uint8_t b) {
	return a ^ b;
}

uint8_t GF2_8::mult_GF_2_8(uint8_t a, uint8_t b) {
	// 1. mnożenie
	uint16_t ab = 0;
	uint16_t a_uint16 = (uint16_t)a;
	uint16_t b_uint16 = (uint16_t)b;

	while (b_uint16 > 0) {
		if (b_uint16 % 2 == 1) {
			ab = ab ^ a_uint16;
		}
		b_uint16 = b_uint16 >> 1;
		a_uint16 = a_uint16 << 1;
	}

	// 2. dzielenie przez irrpoly -> ab % irrpoly
	uint16_t irrpoly_shift = 0;
	while (msb_uint16(ab) >= msb_uint16(IRRPOLY_GF_2_8)) {
		irrpoly_shift = IRRPOLY_GF_2_8;
		while (msb_uint16(ab) != msb_uint16(irrpoly_shift)) {
			irrpoly_shift = irrpoly_shift << 1;
		}
		ab = ab ^ irrpoly_shift;
	}
	return uint8_t(ab);
}

uint8_t GF2_8::pow_GF_2_8(uint8_t a, uint8_t n) {
	// a^0 = 1
	if (n == 0) {
		return 1;
	}
	// a^n = (a^2)^n/2
	else if (n % 2 == 0) {
		return pow_GF_2_8(mult_GF_2_8(a, a), n >> 1);
	}
	// a^n = a * (a^2)^[(n-1)/2]
	else if (n % 2 == 1) {
		return mult_GF_2_8(a,
			pow_GF_2_8(mult_GF_2_8(a, a), (add_GF_2_8(n, 1) >> 1)));
	}
}

uint8_t GF2_8::inv_GF_2_8(uint8_t a) {
	return pow_GF_2_8(a, 254);
}