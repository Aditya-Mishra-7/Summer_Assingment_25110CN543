//Question-95 : Write a program to find longest word.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], longest[100];
    int maxLen = 0;

    fgets(str, sizeof(str), stdin);

    char *word = strtok(str, " \n");

    while (word != NULL) {
        int len = strlen(word);

        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, word);
        }

        word = strtok(NULL, " \n");
    }

    printf("Longest word: %s", longest);

    return 0;
}