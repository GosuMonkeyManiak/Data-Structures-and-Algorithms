#include "quickSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

static void myQSort(byte *base, int start, int end, const size_t reclen, int (*cmp)(void *a, void* b))
{
    int index = (start + end) / 2;
    byte *pivot = base + index * reclen;
    byte *temp = calloc(1, reclen);

    int i = start;
    int j = end;

    while (i <= j)
    {
        while (cmp(base + i * reclen, pivot))
        {
            i++;
        }

        while (cmp(pivot, base + j * reclen))
        {
            j--;
        }

        if (i <= j)
        {
            memcpy(temp, base + i * reclen, reclen);
            memcpy(base + i * reclen, base + j * reclen, reclen);
            memcpy(base + j * reclen, temp, reclen);
            i++;
            j--;
        }
    }
    
    if (start < j)
    {
        myQSort(base, start, j, reclen, cmp);
    }
    
    if (i < end)
    {
        myQSort(base, i, end, reclen, cmp);
    }

    free(temp);
}

void quickSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void *b))
{
    myQSort(_base, 0, n - 1, reclen, cmp);
}