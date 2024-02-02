#include <stddef.h>

#ifndef QUICKSORT

#define QUICKSORT

extern void quickSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void *b));

#endif