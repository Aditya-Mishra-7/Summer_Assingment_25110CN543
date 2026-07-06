//Question-116 : Write a program to create inventory management system.
#include <stdio.h>
struct Inventory
{
    int prodid;
    char prodname[50];
    int quantity;
};
int main()
{
    struct Inventory i[100];
    int choice=0,n=0,j,id,found;
    while(1)
    {
        printf("1.To Add Product\n");
        printf("2.To Display Products\n");
        printf("3.To Search Product\n");
        printf("4.To Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d",&i[n].prodid);
                printf("Enter Product Name: ");
                scanf("%s",i[n].prodname);
                printf("Enter Quantity: ");
                scanf("%d",&i[n].quantity);
                n++;
                printf("Product Added Successfully!");
                break;
            case 2:
                if(n==0)
                {
                    printf("Record not found.");
                }
                else
                {
                    printf("\nID\tName\tQuantity");
                    for(j=0;j<n;j++)
                    {
                        printf("%d\t%s\t%d\n",i[j].prodid,i[j].prodname,i[j].quantity);
                    }
                }
                break;
            case 3:
                printf("Enter Product ID: ");
                scanf("%d",&id);
                found=0;
                for(j=0;j<n;j++)
                {
                    if(i[j].prodid==id)
                    {
                        printf("\nProduct Found");
                        printf("ID:%d\n",i[j].prodid);
                        printf("Name:%s\n",i[j].prodname);
                        printf("Quantity:%d\n",i[j].quantity);

                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    printf("Record not found");
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