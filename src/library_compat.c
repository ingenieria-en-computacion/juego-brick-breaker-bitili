#include "library_compat.h"

#ifdef _WIN32

int kbhit_compat() {
    return _kbhit();
}

int getch_compat() {
    return _getch();
}

#else

int kbhit_compat() {
    return kbhit();
}

int getch_compat() {
    return getch_compat();
}

#endif
