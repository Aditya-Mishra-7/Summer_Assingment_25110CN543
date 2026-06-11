//Question-42 : Write a program to Write function to find maximum.
#include <stdio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    int x = 5, y = 10;
    printf("Maximum of %d and %d is %d\n", x, y, max(x, y));
    return 0;
}