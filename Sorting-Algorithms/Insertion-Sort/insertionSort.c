#include "insertionSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void * insetionSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *current, void *toBeInsert))
{
    byte *base = _base;
    byte *temp = calloc(1, reclen);
    int j;

    for (int i = 1; i < n; i++)
    {
        memcpy(temp, base + i * reclen, reclen);
        j = i - 1;

        while (j >= 0 && cmp(base + j * reclen, temp))
        {
            memcpy(base + (j + 1) * reclen, base + j * reclen, reclen);
            j--;
        }
        
        memcpy(base + (j + 1) * reclen, temp, reclen);
    }

    free(temp);

    return base;
}