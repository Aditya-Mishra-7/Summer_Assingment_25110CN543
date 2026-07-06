//Question-115 : Write a program to create menu driven string operations system.
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100],str2[100];
    int choice;
    printf("Enter first string: ");
    scanf("%s",str1);
    printf("Enter second string: ");
    scanf("%s",str2);
    printf("\n1.To find String Length\n");
    printf("2.To copy String\n");
    printf("3.For String Concatenation\n");
    printf("4.To String Compare\n");
    printf("5.To Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("The Length of first string=%d\n",strlen(str1));
            printf("The Length of second string=%d",strlen(str2));
            break;
        case 2:
            strcpy(str2,str1);
            printf("Copied String=%s",str2);
            break;
        case 3:
            strcat(str1,str2);
            printf("Concatenated String=%s",str1);
            break;
        case 4:
            if(strcmp(str1,str2)==0)
            {
                printf("The Strings are equal");
            }
            else
            {
                printf("The Strings are not equal");
            }
            break;
        case 5:
            printf("Terminating the program");
            break;
        default:
            printf("Invalid Choice!");
    }
    return 0;
}