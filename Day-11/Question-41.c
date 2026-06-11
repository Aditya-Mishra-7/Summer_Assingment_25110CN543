//Question-41 : Write a program to Write function to find sum of two numbers.
#include <stdio.h> 

int sum(int a, int b) 
{
    return a + b;
}

int main() 
{
    int x = 5, y = 10;
    printf("Sum of %d and %d is %d\n", x, y, sum(x, y));
    return 0;
}