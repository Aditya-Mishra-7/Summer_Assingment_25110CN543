//Question-51 : Write a program to find largest and smallest element.
#include <stdio.h>

int main() 
{
    int arr[10], i, n;
    int largest, smallest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];

    for (i = 1; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            largest = arr[i];
        }
        if (arr[i] < smallest) 
        {
            smallest = arr[i];
        }
    }

    printf("The largest element in the array is: %d\n", largest);
    printf("The smallest element in the array is: %d\n", smallest);

    return 0;
}