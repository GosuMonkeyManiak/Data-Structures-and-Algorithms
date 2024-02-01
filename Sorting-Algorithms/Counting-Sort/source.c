#include "countingSort.h"

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int upperBound, n;

    printf("Enter upper bound: ");
    scanf("%d", &upperBound);

    printf("n = ");
    scanf("%d", &n);

    int *numbers = calloc(n, sizeof(int));

    puts("Enter elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", numbers + i);
    }

    int *result = countingSort(numbers, n, upperBound);

    if (result == NULL)
    {
        puts("Incorrect upper bound!");
        free(numbers);
        return;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(numbers + i));
    }

    free(numbers);
}