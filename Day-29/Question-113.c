//Question-113 : Write a program to create menu driven calculator.
#include <stdio.h>
int main()
{
    int operation;
    float a,b,res;
    printf("Enter the first number: ");
    scanf("%f",&a);
    printf("Enter the second number: ");
    scanf("%f",&b);
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("Enter your choice: ");
    scanf("%d",&operation);
    switch(operation)
    {
        case 1:
            res=a+b;
            printf("Result=%f",res);
            break;
        case 2:
            res=a-b;
            printf("Result=%.f",res);
            break;
        case 3:
            res=a*b;
            printf("Result=%f",res);
            break;
        case 4:
            if(b==0)
            {
                printf("Division not possible.");
            }
            else
            {
                res=a/b;
                printf("Result=%f",res);
            }
            break;
        default:
            printf("Invalid Choice!");
    }
    return 0;
}