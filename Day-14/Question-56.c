//Question-56 : Write a program to find duplicates in an array.
#include <stdio.h>

int findDuplicates(int arr[], int n) 
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() 
{
    int arr[] = {10, 20, 30, 20, 40, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int duplicates = findDuplicates(arr, n);
    printf("Number of duplicates is %d\n", duplicates);
    return 0;
}