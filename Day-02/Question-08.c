//Question-08 : Write a program to Check if a number is palindrome.
#include <stdio.h>
int main() 
{
    int number, original, reversed = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &number);

    original = number; 

    while (number != 0) 
    {
        digit = number % 10; 
        reversed = reversed * 10 + digit; 
        number /= 10;        
    }

    if (original == reversed) 
        printf("The number is a palindrome.\n");
    else
        printf("The number is not a palindrome.\n");

    return 0;
}