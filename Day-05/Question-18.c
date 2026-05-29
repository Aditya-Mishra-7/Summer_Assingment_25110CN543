//Question-18 : Write a program to Check strong number.
#include <stdio.h>
int main()
{
    int num, originalNum, remainder, factorial, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    originalNum = num;

    while(num > 0)
    {
        remainder = num % 10;
        factorial = 1;
        for(int i = 1; i <= remainder; i++)
        {
            factorial *= i;
        }
        sum += factorial;
        num /= 10;
    }

    if(sum == originalNum)
    {
        printf("%d is a strong number.\n", originalNum);
    }
    else
    {
        printf("%d is not a strong number.\n", originalNum);
    }

    return 0;
}
