#ifndef TYPES_H
#define TYPES_H

#include <functional>
#include <QString>

using ContextCallback = std::function<void(QString)>;
using PosCallback = std::function<void(int)>;

#endif // TYPES_H
