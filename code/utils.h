#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <string.h>

static inline char* str_duplicate(const char* s) {
    if (!s) return NULL;
    char *d = malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

#endif
