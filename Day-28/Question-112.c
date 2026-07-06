//Question-112 : Write a program to create contact management system.
#include <stdio.h>
struct Contactdetails
{
    int id;
    char name[50];
    int mobilenum;
};
int main()
{
    struct Contactdetails c[100];
    int choice=0,n=0,i,id,found;
    while(1)
    {
        printf("1.To Add Contact\n");
        printf("2.To Display Contacts\n");
        printf("3.To Search Contact\n");
        printf("4.To Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Contact ID: ");
                scanf("%d",&c[n].id);
                printf("Enter Contact Name: ");
                scanf("%s",c[n].name);
                printf("Enter Mobile Number: ");
                scanf("%d",&c[n].mobilenum);
                n++;
                printf("Contact Added ");
                break;
            case 2:
                if(n==0)
                {
                    printf("No records found.");
                }
                else
                {
                    printf("\nID\tName\tMobile Number\n");
                    for(i=0;i<n;i++)
                    {
                        printf("%d\t%s\t%d\n",c[i].id,c[i].name,c[i].mobilenum);
                    }
                }
                break;
            case 3:
                printf("Enter Contact ID: ");
                scanf("%d",&id);
                found=0;
                for(i=0;i<n;i++)
                {
                    if(c[i].id==id)
                    {
                        printf("\nContact Found\n");
                        printf("Contact ID:%d\n",c[i].id);
                        printf("Name:%s\n",c[i].name);
                        printf("Mobile Number:%d\n",c[i].mobilenum);
                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    printf("Record not found.");
                }
                break;
            case 4:
                printf("Terminating the program");
                return 0;
            default:
                printf("Invalid Choice!");
        }
    }
    return 0;
}