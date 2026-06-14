//Question-54 : Write a program to find the frequency of an element.
#include <stdio.h>

int findFrequency(int arr[], int n, int x) 
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == x) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    int arr[] = {10, 20, 30, 20, 40, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 20;
    int frequency = findFrequency(arr, n, x);
    printf("Frequency of %d is %d\n", x, frequency);
    return 0;
}