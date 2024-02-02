#include <stddef.h>

#ifndef MERGESORT

#define MERGESORT

extern void mergeSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void *b));

#endif