#include "quickSort.h"

#include <stdio.h>
#include <stdlib.h>

int cmp(void *a, void *b)
{
    int first = *((int*) a);
    int second = *((int*) b);

    if (first < second)
    {
        return 1;
    }
    
    if (first > second)
    {
        return 0;
    }
    
    return 0;
}

void main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    int *numbers = calloc(n, sizeof(int));

    puts("Enter elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", numbers + i);
    }

    quickSort(numbers, sizeof(int), n, cmp);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    

    free(numbers);
}