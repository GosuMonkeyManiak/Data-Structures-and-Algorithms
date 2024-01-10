#include <stdio.h>
#include <math.h>

int gcd_subtract(int a, int b);
int gcd_division(int a, int b);
static int gcd_division_recursion(int a, int b);

void main()
{
    int a, b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    int gcdSubtract = gcd_subtract(a, b);
    int gcdDivision = gcd_division(a, b);
    int gcdRecursion = gcd_division_recursion(a, b);

    printf("Subtract: gcd(%d, %d) = %d\n", a, b, gcdSubtract);
    printf("Devision: gcd(%d, %d) = %d\n", a, b, gcdDivision);
    printf("Recursion: gcd(%d, %d) = %d\n", a, b, gcdRecursion);

    printf("Fraction %d/%d is reduced to %d/%d\n", a, b, a / gcdDivision, b / gcdDivision);
    printf("lcm(%d, %d) = %d", a, b, a * b / gcdDivision);
}

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
