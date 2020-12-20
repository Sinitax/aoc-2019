#include "util.h"

int
main(int argc, const char **argv)
{
    struct PartInfo info;
    const char *envvar;
    FILE *f;

    if (argc <= 1) die("Supply the part number to solve\n");
    info.args = &argv[2];

    info.inputfile = getenv("AOCINPUT");
    if (!info.inputfile) info.inputfile = "input";
    else debug("Using input file: '%s'\n", info.inputfile);

    envvar = getenv("AOCDEBUG");
    info.debug = envvar ? atoi(envvar) : 0;

    if (!(f = fopen("input", "r"))) die("Failed to open input file\n");
    if (readall(fileno(f), (void**) &info.input, &info.input_size) == FAILURE)
        die("Failed to read from input file\n");
    fclose(f);

    info.part = atoi(argv[1]);
    if (info.part == 1) part1(&info);
    else if (info.part == 2) part2(&info);
    else die("Invalid part number\n");
}
