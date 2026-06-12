//Question-45 : Write a program to write function for palindrome.
#include <stdio.h>
#include <string.h>

int checkPalindrome(char text[])
{
    int left = 0;
    int right = strlen(text) - 1;

    while (left < right)
    {
        if (text[left] != text[right])
        {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

int main()
{
    char word[100];

    printf("Enter a word: ");
    scanf("%99s", word);

    if (checkPalindrome(word))
    {
        printf("The given word is a palindrome.\n");
    }
    else
    {
        printf("The given word is not a palindrome.\n");
    }

    return 0;
}