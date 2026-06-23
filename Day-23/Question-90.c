//Question-90 : Write a program to find first repeating character.
#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0};

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;

        if (freq[(unsigned char)str[i]] == 2) {
            printf("First repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No repeating character found.\n");

    return 0;
}