//Question-57 : Write a program to reverse array.
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

    int left = 0;
    int right = size - 1;

    while (left < right) 
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    printf("Array after reversing:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
