#include "heapSort.h"

#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

static void sort(byte *const base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b));
static void buildHeap(byte *const base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b));
static void heapify(byte *const base, const size_t reclen, const size_t n, size_t vertexIndex, int (*cmp)(void *a, void* b));

void heapSort(void *const _base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b))
{
    sort((byte*)_base, reclen, n, cmp);
}

static void sort(byte *const base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b))
{
    if (n == 1)
    {
        return;
    }

    buildHeap(base, reclen, n, cmp);
    
    byte *temp = calloc(1, reclen);

    memcpy(temp, base, reclen);
    memcpy(base, base + (n - 1) * reclen, reclen);
    memcpy(base + (n - 1) * reclen, temp, reclen);

    free(temp);

    sort(base, reclen, n - 1, cmp);
}

static void buildHeap(byte *const base, const size_t reclen, const size_t n, int (*cmp)(void *a, void* b))
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(base, reclen, n, i, cmp);
    }
}

static void heapify(byte *const base, const size_t reclen, const size_t n, size_t vertexIndex, int (*cmp)(void *a, void* b))
{
    int largest = vertexIndex;
    int leftParentIndex = 2 * vertexIndex + 1;
    int rightParentIndex = 2 * vertexIndex + 2;

    if (leftParentIndex < n && cmp(base + leftParentIndex * reclen, base + largest * reclen))
    {
        largest = leftParentIndex;
    }

    if (rightParentIndex < n && cmp(base + rightParentIndex * reclen, base + largest * reclen))
    {
        largest = rightParentIndex;
    }
    
    if (largest != vertexIndex)
    {
        byte *temp = calloc(1, reclen);

        memcpy(temp, base + vertexIndex * reclen, reclen);
        memcpy(base + vertexIndex * reclen, base + largest * reclen, reclen);
        memcpy(base + largest * reclen, temp, reclen);

        free(temp);

        heapify(base, reclen, n, vertexIndex, cmp);
    }
}