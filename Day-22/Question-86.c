//Question-86 : Write a program to count words in a sentence.
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, words = 1;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
            words++;
    }

    printf("Number of words = %d\n", words);

    return 0;
}