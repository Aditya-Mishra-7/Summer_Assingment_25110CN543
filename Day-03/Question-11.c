//Question-11 : Write a program to Find GCD of two numbers.
#include <stdio.h>
int main()
{
    int num1, num2, gcd;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    for (gcd = (num1 < num2) ? num1 : num2; gcd > 0; gcd--) 
    {
        if (num1 % gcd == 0 && num2 % gcd == 0) 
        {
            printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
            break;
        }
    }

    return 0;
}