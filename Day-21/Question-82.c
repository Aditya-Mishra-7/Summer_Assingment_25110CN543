//Question-82 : Write a program to reverse a string.
#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100], temp;
    int i, length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);

    if (str[length - 1] == '\n') 
    {
        str[length - 1] = '\0';
        length--;
    }

    for (i = 0; i < length / 2; i++) 
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}