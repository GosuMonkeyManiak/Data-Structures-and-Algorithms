#include <math.h>
#include "euclidean.h"


int gcd_subtract(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    a = abs(a);
    b = abs(b);
    
    while (b != 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    
    return a;
}

int gcd_division(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

static int gcd_division_recursion(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    if (b == 0)
    {
        return a;
    }

    return gcd_division_recursion(b, a % b);
}