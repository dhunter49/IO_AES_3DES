#ifndef IBLOCKCIPHER_H
#define IBLOCKCIPHER_H

#include <QByteArray>
#include <QString>

class IBlockCipher {
public:
    virtual ~IBlockCipher() = default;

    // Algorithm name such as "AES-128", "3DES"
    virtual QString name() const = 0;
    // Implied unsigned value
    virtual int blockSize();
    // Returns false if provided key is incorrect lenght
    // Valid lenghts: AES: 16/24/32 B, 3DES: 16/24 B
    virtual bool setKey(const QByteArray &key) = 0;

    virtual void encryptBlock(const uchar *in, uchar *out) const = 0;
    virtual void decryptBlock(const uchar *in, uchar *out) const = 0;
};

#endif // IBLOCKCIPHER_H
