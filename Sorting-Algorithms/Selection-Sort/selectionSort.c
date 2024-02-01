#include "selectionSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void * selectionSort(void *const _base, const size_t recLen, const size_t n, int (*cmp)(void *current, void *min))
{
    byte *base = _base;
    int min;
    byte *temp = calloc(1, recLen);

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (cmp(base + j * recLen, base + min * recLen))
            {
                min = j;
            }
        }

        if (min != i)
        {
            memcpy(temp, base + i * recLen, recLen);
            memcpy(base + i * recLen, base + min * recLen, recLen);
            memcpy(base + min * recLen, temp, recLen);
        }
    }

    free(temp);

    return base;
}