//Question-10 : Write a program to Print prime numbers in a range.
#include <stdio.h>
int main()
{
    int lower, upper, i, j, flag;

    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (i = lower; i <= upper; i++) 
    {
        if (i <= 1)
            continue;

        flag = 0;
        for (j = 2; j <= i / 2; ++j) 
        {
            if (i % j == 0) 
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}