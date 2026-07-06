//Question-114 : Write a program to create menu driven array operations system.
#include <stdio.h>
int main()
{
    int a[100],n,i,choice,sum=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n1. To Display Array\n");
    printf("2.For Minimum Element\n");
    printf("3.For Maximum Element\n");
    printf("4.To find Sum of Elements\n");
    printf("5.To Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Array Elements are : ");
            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
            break;
        case 2:
        {
            int min=a[0];
            for(i=1;i<n;i++)
            {
                if(a[i]<min)
                {
                    min=a[i];
                }
            }
            printf("Minimum=%d",min);
            break;
        }
        case 3:
        {
            int max=a[0];
            for(i=1;i<n;i++)
            {
                if(a[i]>max)
                {
                    max=a[i];
                }
            }
            printf("Maximum=%d",max);
            break;
        }
        case 4:
            for(i=0;i<n;i++)
            {
                sum=sum+a[i];
            }
            printf("Sum=%d",sum);
            break;
        case 5:
            printf("Terminating the program");
            break;
        default:
            printf("Invalid Choice!");
    }
    return 0;
}