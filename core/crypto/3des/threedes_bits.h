#ifndef THREEDES_BITS_H
#define THREEDES_BITS_H

#include <cstdint>
#include <QtGlobal>

namespace ThreeDESBits {

uint64_t permute(uint64_t input, const int *table, int inBits, int outBits);
uint64_t bytesToUint64(const uchar *bytes);
void uint64ToBytes(uint64_t val, uchar *bytes);

}

#endif