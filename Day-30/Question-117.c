// Question-117 : Write a program to create student record system using arrays and strings.
#include <stdio.h>
int main()
{
    int rollno[100], n, i, searchroll, found;
    char name[100][50];
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Roll Number: ");
        scanf("%d", &rollno[i]);
        printf("Enter Name: ");
        scanf("%s", name[i]);
    }
    printf("\nStudent Record\n");
    printf("Roll Name\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  %s\n", rollno[i], name[i]);
    }
    printf("Enter Roll Number to Search: ");
    scanf("%d", &searchroll);
    found = 0;
    for (i = 0; i < n; i++)
    {
        if (rollno[i] == searchroll)
        {
            printf("Student Found\n");
            printf("Roll Number:%d\n", rollno[i]);
            printf("Name:%s", name[i]);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Record not found.");
    }
    return 0;
}