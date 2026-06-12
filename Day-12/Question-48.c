//Question-48 : Write a program to write function for perfect number.
#include <stdio.h>

int checkPerfect(int num)
{
    int sum = 0;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    if (sum == num)
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

    if (checkPerfect(number))
    {
        printf("The given number is a perfect number.\n");
    }
    else
    {
        printf("The given number is not a perfect number.\n");
    }

    return 0;
}