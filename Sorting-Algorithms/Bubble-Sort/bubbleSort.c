#include "bubbleSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void * bubleSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *current, void *next))
{
    byte *base = _base;
    byte *temp = calloc(1, reclen);
    int flag = 1;

    for (int i = 0; flag; i++)
    {
        flag = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(base + j * reclen, base + (j + 1) * reclen))
            {
                memcpy(temp, base + j * reclen, reclen);
                memcpy(base + j * reclen, base + (j + 1) * reclen, reclen);
                memcpy(base + (j + 1) * reclen, temp, reclen);

                flag = 1;
            }
        }
    }

    free(temp);

    return base;
}