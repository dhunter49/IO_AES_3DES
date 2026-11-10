#ifndef MODE_H
#define MODE_H

#include <QString>
#include <optional>

enum class Mode {
    ECB,
    CBC,
    CTR
};

std::optional<Mode> modeFromString(const QString &s);
QString modeToString(Mode m);

#endif // MODE_H
