//Question-07 : Write a program to Find product of digits.
#include <stdio.h>
int main() 
{
    int number, product = 1, digit;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number != 0) 
    {
        digit = number % 10; 
        product *= digit;       
        number /= 10;        
    }

    printf("Product of digits: %d\n", product);
    return 0;
}