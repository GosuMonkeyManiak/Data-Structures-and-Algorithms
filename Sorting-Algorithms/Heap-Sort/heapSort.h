#include <stddef.h>

#ifndef HEAPSORT

#define HEAPSORT

extern void heapSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b));

#endif