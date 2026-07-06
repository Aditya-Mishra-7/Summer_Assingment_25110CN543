// Question-118 : Write a program to create mini library system.
#include <stdio.h>
#include <string.h>
struct library
{
    int id;
    char name[50];
    char author[50];
};
int main()
{
    struct library b[100];
    int choice = 0, n = 0, i, id, found;
    while (1)
    {
        printf("1. To Add Book\n");
        printf("2. To Display Books\n");
        printf("3. To Search Book\n");
        printf("4. To Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &b[n].id);
            printf("Enter Book Name: ");
            scanf("%s", b[n].name);
            printf("Enter Author Name: ");
            scanf("%s", b[n].author);
            n++;
            printf("Book Record Added .\n");
            break;
        case 2:
            if (n == 0)
            {
                printf("Record not found.\n");
            }
            else
            {
                printf("\nID\tBook Name\tAuthor\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t\t%s\n",
                           b[i].id,
                           b[i].name,
                           b[i].author);
                }
            }
            break;
        case 3:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    printf("\nBook Found\n");
                    printf("ID: %d\n", b[i].id);
                    printf("Book Name: %s\n", b[i].name);
                    printf("Author: %s\n", b[i].author);

                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("Record not found.\n");
            }
            break;
        case 4:
            printf("Terminating the program\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}