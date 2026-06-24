//Question-96 : Write a program to remove duplicate characters.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        int duplicate = 0;

        for (int j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
            printf("%c", str[i]);
    }

    return 0;
}