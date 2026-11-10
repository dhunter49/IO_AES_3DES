#ifndef CIPHERFACTORY_H
#define CIPHERFACTORY_H

#include "iblockcipher.h"
#include "algorithm.h"
#include <QString>
#include <memory>

std::unique_ptr<IBlockCipher> makeBlockCipher(Algorithm algo);

#endif // CIPHERFACTORY_H
