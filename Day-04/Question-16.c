//Question-16 : Write a program to Print Armstrong numbers in a range.
#include <stdio.h>
int main() 
{
    int lower, upper, num, originalNum, remainder, result;
    
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);
    
    printf("Armstrong numbers between %d and %d are: ", lower, upper);
    for (num = lower; num <= upper; num++) 
    {
        originalNum = num;
        result = 0;
        
        while (originalNum != 0) 
        {
            remainder = originalNum % 10;
            result += remainder * remainder * remainder;
            originalNum /= 10;
        }
        
        if (result == num) 
        {
            printf("%d ", num);
        }
    }
    
    return 0;
}