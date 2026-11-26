#include "threedes_bits.h"

namespace ThreeDESBits {

uint64_t permute(uint64_t input, const int *table, int inBits, int outBits) {
    uint64_t output = 0;
    for (int i = 0; i < outBits; ++i) {
        uint64_t bit = (input >> (inBits - table[i])) & 1ULL;
        output = (output << 1) | bit;
    }
    return output;
}

uint64_t bytesToUint64(const uchar *bytes) {
    uint64_t val = 0;
    for (int i = 0; i < 8; ++i) {
        val = (val << 8) | bytes[i];
    }
    return val;
}

void uint64ToBytes(uint64_t val, uchar *bytes) {
    for (int i = 7; i >= 0; --i) {
        bytes[i] = static_cast<uchar>(val & 0xFF);
        val >>= 8;
    }
}

}