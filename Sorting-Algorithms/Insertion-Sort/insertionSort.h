#include <stddef.h>

#ifndef INSETIONSORT

#define INSETIONSORT

extern void * insetionSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *current, void *toBeInsert));

#endif