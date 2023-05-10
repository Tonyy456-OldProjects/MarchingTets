
#ifndef MY_LOGGER_H
#define MY_LOGGER_H

#include <cstdio>
#include <cstring>
#include <libgen.h> // for basename()
#define LOG(msg) printf("%s:%d - %s\n", basename(__FILE__), __LINE__, msg)

#endif