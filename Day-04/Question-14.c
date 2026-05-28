//Question-14 : Write a program to Find nth Fibonacci term.
#include <stdio.h>
int main() 
{
    int n, first = 0, second = 1, next;
    
    printf("Enter the term number: ");
    scanf("%d", &n);
    
    if (n <= 0) 
    {
        printf("Please enter a positive integer.\n");
    } 
    else if (n == 1) 
    {
        printf("The %dth Fibonacci term is: %d\n", n, first);
    } 
    else if (n == 2) 
    {
        printf("The %dth Fibonacci term is: %d\n", n, second);
    } 
    else 
    {
        for (int i = 3; i <= n; i++) 
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("The %dth Fibonacci term is: %d\n", n, next);
    }
    
    return 0;
}