//Question-46 : Write a program to write function for Armstrong.
#include <stdio.h>
#include <math.h>

int checkArmstrong(int num)
{
    int original = num;
    int sum = 0;
    int digit;

    while (num > 0)
    {
        digit = num % 10;
        sum += pow(digit, 3);
        num /= 10;
    }

    if (sum == original)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (checkArmstrong(number))
    {
        printf("The given number is an Armstrong number.\n");
    }
    else
    {
        printf("The given number is not an Armstrong number.\n");
    }

    return 0;
}