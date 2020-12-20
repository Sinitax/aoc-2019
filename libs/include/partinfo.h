#ifndef AOC_PARTINFO_H
#define AOC_PARTINFO_H

#include <stdlib.h>

struct PartInfo {
    int debug;
    int part;

    const char *inputfile;
    char *input;
    size_t input_size;

    const char **args;
};

#endif // AOC_PARTINFO_H
