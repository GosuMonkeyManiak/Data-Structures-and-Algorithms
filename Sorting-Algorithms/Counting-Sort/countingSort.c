#include "countingSort.h"

#include <stdlib.h>

int * countingSort(int *numbers, int n, int upperBound)
{
    if (upperBound <= 0)
    {
        return NULL;
    }

    int helpLength = upperBound + 1;

    int *help = calloc(helpLength, sizeof(int));

    int i;

    for (i = 0; i < n; i++)
    {
        *(help + *(numbers + i)) += 1;
    }
    
    int k = 0;

    for (i = 0; i < helpLength; i++)
    {
        if (*(help + i) != 0)
        {
            for (int j = 0; j < *(help + i) && k < n; j++, k++)
            {
                *(numbers + k) = i;
            }
        }
    }

    free(help);

    return numbers;
}