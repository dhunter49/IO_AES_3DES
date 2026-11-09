#ifndef MODECIPHER_H
#define MODECIPHER_H

#include "mode.h"
#include "iblockcipher.h"
#include <QByteArray>
#include <memory>
#include <optional>

// Stream encyption and decryption
// Should be called: setKey -> begin -> update (multiple times) -> finish
class ModeCipher
{
public:
    explicit ModeCipher(std::unique_ptr<IBlockCipher> block);

    // false means wrong key lenght
    bool setKey(const QByteArray &key);
    int  blockSize() const;

    bool begin(Mode mode, bool encrypt, const QByteArray &iv = {});

    // returns data ready for writing. size of output may differ from input size
    QByteArray update(const QByteArray &chunk);
    std::optional<QByteArray> finish();

private:
    std::unique_ptr<IBlockCipher> m_block;
};

#endif // MODECIPHER_H