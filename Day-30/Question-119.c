// Question-119 : Write a program to create mini employee management system.
#include <stdio.h>
struct Employeemanagement
{
    char name[50];
    int id;
    float salary;
};
int main()
{
    struct Employeemanagement e[100];
    int choice = 0, n = 0, i, id, found;
    while (1)
    {
        printf("1.To Add Employee\n");
        printf("2.To Display Employees\n");
        printf("3.To Search Employee\n");
        printf("4.To Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &e[n].id);

            printf("Enter Employee Name: ");
            scanf("%s", e[n].name);

            printf("Enter Salary: ");
            scanf("%f", &e[n].salary);
            n++;
            printf("Employee Record Added Successfully!\n");
            break;
        case 2:
            if (n == 0)
            {
                printf("Record not found.\n");
            }
            else
            {
                printf("\nID\tName\tSalary\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t%f\n", e[i].id, e[i].name, e[i].salary);
                }
            }
            break;
        case 3:
            printf("Enter Employee ID  ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++)
            {
                if (e[i].id == id)
                {
                    printf("\nEmployee Found\n");
                    printf("ID:%d\n", e[i].id);
                    printf("Name:%s\n", e[i].name);
                    printf("Salary:%f\n", e[i].salary);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("Record not found.\n");
            break;
        case 4:
            printf("Terminating the program\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}