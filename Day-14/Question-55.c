//Question-55 : Write a program to second largest element.
#include <stdio.h>

int secondLargest(int arr[], int n) 
{
    int largest = arr[0];
    int secondLargest = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            secondLargest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > secondLargest && arr[i] != largest) 
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() 
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = secondLargest(arr, n);
    printf("Second largest element is %d\n", result);
    return 0;
}