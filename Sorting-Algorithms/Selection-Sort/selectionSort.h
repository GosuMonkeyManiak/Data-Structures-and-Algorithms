#include <stddef.h>

#ifndef SELECTIONSORT

#define SELECTIONSORT

extern void * selectionSort(void *const _base, const size_t recLen, const size_t n, int (*cmp)(void *current, void *min));

#endif