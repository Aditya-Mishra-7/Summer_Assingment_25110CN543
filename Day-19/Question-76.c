//Question-76 : Write a program to find diagonal sum of a matrix.
#include <stdio.h>

int main() 
{
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int diagonalSum = 0;

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (i == j) 
            {
                diagonalSum += matrix[i][j];
            }
        }
    }

    printf("Sum of the diagonal elements: %d\n", diagonalSum);

    return 0;
}