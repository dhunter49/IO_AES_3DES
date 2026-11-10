#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QString>
#include <optional>

enum class Algorithm {
    Aes,
    Aes128,
    Aes192,
    Aes256,
    TripleDes
};

std::optional<Algorithm> algorithmFromString(const QString &s);
QString algorithmToString(Algorithm a);

#endif // ALGORITHM_H
