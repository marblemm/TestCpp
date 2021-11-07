#ifndef UTILSBOX_H
#define UTILSBOX_H

#include <string>

#define UTILSBOX_VERSION "v0.1.1"

namespace UtilsBox
{
    extern "C" __declspec(dllimport) std::string GetVersion(void);
    std::string format(const char *fmt, ...);
}

#endif
