//Question-06 : Write a program to Reverse a number.
#include <stdio.h>
int main() 
{
    int number, reversed = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number != 0) 
    {
        digit = number % 10; 
        reversed = reversed * 10 + digit; 
        number /= 10;        
    }

    printf("Reversed number: %d\n", reversed);
    return 0;
}