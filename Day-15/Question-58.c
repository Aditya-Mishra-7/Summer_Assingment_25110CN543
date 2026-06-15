//Question-58 : Write a program to rotate array left.
#include <stdio.h>

int main() 
{
    int size, d;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate left: ");
    scanf("%d", &d);

    d = d % size; 
    
    for (int i = 0; i < d; i++) 
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++) 
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }

    printf("Array after left rotation:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
