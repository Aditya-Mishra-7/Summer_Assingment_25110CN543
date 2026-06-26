//Question-102 : Write a program to create voting eligibility system.
#include <stdio.h>

int main() {
    int age;

    printf("=== Voting Eligibility System ===\n");
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
    }

    return 0;
}