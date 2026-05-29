//Question-22 : Write a program to Convert binary to decimal.
#include <stdio.h>
#include <math.h>

int main()
{
    long long binary, decimal = 0, base = 1;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while(binary > 0)
    {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal equivalent: %lld\n", decimal);

    return 0;
}
