#include "util.h"

void
exitmsg(int rv, const char *fmtstr, ...)
{
    va_list ap;

    va_start(ap, fmtstr);
    vprintf(fmtstr, ap);
    va_end(ap);

    exit(rv);
}

void
debug(const char *fmtstr, ...)
{
    va_list ap;

    va_start(ap, fmtstr);
    vfprintf(stderr, fmtstr, ap);
    va_end(ap);
}

int
min(int a, int b)
{
	return a < b ? a : b;
}

int
max(int a, int b)
{
	return a > b ? a : b;
}

void*
assertp(void *alloc)
{
	if (!alloc) die("Out of Memory\n");
	return alloc;
}

int
readall(int fileno, void **data, size_t *totalread) {
	size_t allocsize = 10, want = allocsize, got;

	*data = assertp(malloc(allocsize));

	*totalread = 0;
	while ((got = read(fileno, *data + *totalread, want)) > 0) {
		if (got == want) {
			allocsize *= 2;
			*totalread += got;
			*data = assertp(realloc(*data, allocsize));
		} else {
			*totalread += got;
		}
		want = allocsize - *totalread;
	}

    return (got < 0) ? FAILURE : SUCCESS;
}
