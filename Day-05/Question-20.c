//Question-20 : Write a program to Find largest prime factor.
#include <stdio.h>
int main()
{
    int num, largestPrimeFactor = 1;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    for(int i = 2; i <= num; i++)
    {
        if(num % i == 0)
        {
            int isPrime = 1;
            for(int j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime)
            {
                largestPrimeFactor = i;
            }
        }
    }

    printf("Largest prime factor of %d is %d.\n", num, largestPrimeFactor);

    return 0;
}
