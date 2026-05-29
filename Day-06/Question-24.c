//Question-24 : Write a program to Find x^n without pow().
#include <stdio.h>

int main()
{
    int x, n, result = 1;
    printf("Enter the base (x): ");
    scanf("%d", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        result *= x;
    }

    printf("%d^%d = %d\n", x, n, result);

    return 0;
}
