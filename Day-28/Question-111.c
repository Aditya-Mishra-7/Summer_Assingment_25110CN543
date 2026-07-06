//Question-111 : Write a program to create ticket booking system.
#include <stdio.h>
struct Ticketbooking
{
    int ticketnumber;
    char name[50];
    float price;
};
int main()
{
    struct Ticketbooking t[100];
    int choice=0,n=0,i,ticketnumber,found;
    while(1)
    {
        printf("1.To Book Ticket\n");
        printf("2.To Display Tickets\n");
        printf("3.To Search Ticket\n");
        printf("4.To Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Ticket Number: ");
                scanf("%d",&t[n].ticketnumber);
                printf("Enter Passenger Name: ");
                scanf("%s",t[n].name);
                printf("Enter Ticket Price: ");
                scanf("%f",&t[n].price);
                n++;
                printf("Ticket Booked.");
                break;
            case 2:
                if(n==0)
                {
                    printf("No records found.");
                }
                else
                {
                    printf("\nTicketNo\tName\tPrice\n");
                    for(i=0;i<n;i++)
                    {
                        printf("%d\t\t%s\t%.2f\n",t[i].ticketnumber,t[i].name,t[i].price);
                    }
                }
                break;
            case 3:
                printf("Enter Ticket Number: ");
                scanf("%d",&ticketnumber);
                found=0;
                for(i=0;i<n;i++)
                {
                    if(t[i].ticketnumber==ticketnumber)
                    {
                        printf("\nTicket Found\n");
                        printf("Ticket Number:%d\n",t[i].ticketnumber);
                        printf("Passenger Name:%s\n",t[i].name);
                        printf("Ticket Price:%.2f\n",t[i].price);

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