//Question-89 : Write a program to find first non repeating character.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found.\n");

    return 0;
}