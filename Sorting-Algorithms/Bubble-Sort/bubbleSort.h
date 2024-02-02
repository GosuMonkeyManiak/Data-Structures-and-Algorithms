#include <stddef.h>

#ifndef BUBBLESORT

#define BUBBLESORT

extern void * bubleSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *current, void *next));

#endif