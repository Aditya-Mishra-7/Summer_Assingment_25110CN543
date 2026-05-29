//Question-23 : Write a program to Count set bits in a number.
#include <stdio.h>

int main()
{
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    while(num)
    {
        count += num & 1;
        num >>= 1;
    }

    printf("Number of set bits: %d\n", count);

    return 0;
}
