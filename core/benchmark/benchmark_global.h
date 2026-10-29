#ifndef BENCHMARK_GLOBAL_H
#define BENCHMARK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BENCHMARK_LIBRARY)
#define BENCHMARK_EXPORT Q_DECL_EXPORT
#else
#define BENCHMARK_EXPORT Q_DECL_IMPORT
#endif

#endif // BENCHMARK_GLOBAL_H
