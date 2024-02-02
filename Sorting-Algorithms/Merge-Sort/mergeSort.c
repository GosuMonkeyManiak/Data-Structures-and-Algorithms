#include "mergeSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

static void sort(void *const _base, const size_t reclen, const size_t start, const size_t end, int (*cmp)(void *a, void *b));
static void merge(byte *const base, const size_t start, const size_t end, const size_t m, const size_t reclen, int (*cmp)(void *a, void *b));

void mergeSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void *b))
{
    sort(_base, reclen, 0, n - 1, cmp);
}

static void sort(void *const _base, const size_t reclen, const size_t start, const size_t end, int (*cmp)(void *a, void *b))
{
    if (start == end)
    {
        return;
    }

    int m = (start + end) / 2;

    sort(_base, reclen, start, m, cmp);
    sort(_base, reclen, m + 1, end, cmp);

    merge(_base, start, end, m, reclen, cmp);
}

static void merge(byte *const base, const size_t start, const size_t end, const size_t m, const size_t reclen, int (*cmp)(void *a, void *b))
{
    size_t helpLength = end - start + 1;
    byte *help = calloc(helpLength, reclen);
    int i = 0;

    int left = start;
    int right = m + 1;

    while (left <= m && right <= end)
    {
        int resultOfCmp = cmp(base + left * reclen, base + right * reclen);

        if (resultOfCmp < 0)
        {
            memcpy(help + i * reclen, base + left * reclen, reclen);
            left++;
        }
        else
        {
            memcpy(help + i * reclen, base + right * reclen, reclen);
            right++;
        }
        
        i++;
    }
    
    for (left; left <= m; left++)
    {
        memcpy(help + i * reclen, base + left * reclen, reclen);
        i++;
    }
    
    for (right; right <= end; right++)
    {
        memcpy(help + i * reclen, base + right * reclen, reclen);
        i++;
    }
    
    i = 0;

    for (int j = start; j <= end; j++, i++)
    {
        memcpy(base + j * reclen, help + i * reclen, reclen);
    }
    
    free(help);
}