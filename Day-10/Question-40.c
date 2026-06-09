//Question-40 : Write a program to Print character pyramid.
#include <stdio.h>

int main() 
{
    int n, i, j;
    char ch = 'A';
    printf("Enter the number of rows for the character pyramid: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n - i; j++) 
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) 
        {
            printf("%c", ch);
        }
        ch++;
        printf("\n");
    }
    return 0;
}
