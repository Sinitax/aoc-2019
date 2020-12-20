#ifndef AOC_UTIL_H
#define AOC_UTIL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum { SUCCESS, FAILURE };

#define die(...)  exitmsg(FAILURE, __VA_ARGS__)
#define quit(...) exitmsg(SUCCESS, __VA_ARGS__)

void exitmsg(int rv, const char *fmtstr, ...);
void debug(const char *fmtstr, ...);

int min(int a, int b);
int max(int a, int b);

void* assertp(void *alloc);

int readall(int fd, void **data, size_t *read);

#endif // AOC_UTIL_H
