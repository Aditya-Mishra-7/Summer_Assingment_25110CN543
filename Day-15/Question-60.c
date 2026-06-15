//Question-60 : Write a program to move zeroes to end.
#include <stdio.h>

int main() 
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] != 0) 
        {
            arr[count] = arr[i];
            count++;
        }
    }

    while (count < size) 
    {
        arr[count] = 0;
        count++;
    }

    printf("Array after moving zeroes to end:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}