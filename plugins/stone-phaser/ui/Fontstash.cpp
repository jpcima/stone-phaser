// disable an avalanche of "unused function" warnings
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

#if defined(_WIN32)
#include <windows.h>
#endif

#define FONTSTASH_IMPLEMENTATION
#include <fontstash.h>
