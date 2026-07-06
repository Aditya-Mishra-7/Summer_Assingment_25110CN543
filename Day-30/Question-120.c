// Question-120 : Write a program to develop complete mini project using arrays, strings and functions.
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

void displayMenu();
void addStudent(int rollNos[], char names[][NAME_LENGTH], float marks[], int *count);
void displayAll(int rollNos[], char names[][NAME_LENGTH], float marks[], int count);
void searchStudent(int rollNos[], char names[][NAME_LENGTH], float marks[], int count);
void calculateStats(float marks[], int count);

int main()
{

    int rollNumbers[MAX_STUDENTS];
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    float studentMarks[MAX_STUDENTS];

    int studentCount = 0;
    int choice;

    printf("=== Welcome to the Student Database Management System ===\n");

    while (1)
    {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        getchar();

        switch (choice)
        {
        case 1:
            addStudent(rollNumbers, studentNames, studentMarks, &studentCount);
            break;
        case 2:
            displayAll(rollNumbers, studentNames, studentMarks, studentCount);
            break;
        case 3:
            searchStudent(rollNumbers, studentNames, studentMarks, studentCount);
            break;
        case 4:
            calculateStats(studentMarks, studentCount);
            break;
        case 5:
            printf("\nExiting the program. Thank you!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu()
{
    printf("\n---------------------------------\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll No\n");
    printf("4. View Class Statistics\n");
    printf("5. Exit\n");
    printf("---------------------------------\n");
}
void addStudent(int rollNos[], char names[][NAME_LENGTH], float marks[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nDatabase full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNos[*count]);
    getchar();

    printf("Enter Student Name: ");

    fgets(names[*count], NAME_LENGTH, stdin);

    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &marks[*count]);

    (*count)++;
    printf("\nStudent added successfully!\n");
}

void displayAll(int rollNos[], char names[][NAME_LENGTH], float marks[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records found. Add some students first!\n");
        return;
    }

    printf("\n==================================================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("==================================================\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-10d %-25s %-10.2f\n", rollNos[i], names[i], marks[i]);
    }
    printf("==================================================\n");
}

void searchStudent(int rollNos[], char names[][NAME_LENGTH], float marks[], int count)
{
    if (count == 0)
    {
        printf("\nDatabase is empty.\n");
        return;
    }

    int searchRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++)
    {
        if (rollNos[i] == searchRoll)
        {
            printf("\nStudent Found!\n");
            printf("-------------------------\n");
            printf("Roll Number: %d\n", rollNos[i]);
            printf("Name:        %s\n", names[i]);
            printf("Marks:       %.2f\n", marks[i]);
            printf("-------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }
}

void calculateStats(float marks[], int count)
{
    if (count == 0)
    {
        printf("\nNo data available to calculate statistics.\n");
        return;
    }

    float sum = 0, average;
    float highest = marks[0];
    float lowest = marks[0];

    for (int i = 0; i < count; i++)
    {
        sum += marks[i];

        if (marks[i] > highest)
        {
            highest = marks[i];
        }
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    average = sum / count;

    printf("\n===== Class Statistics =====\n");
    printf("Total Students : %d\n", count);
    printf("Average Marks  : %.2f\n", average);
    printf("Highest Marks  : %.2f\n", highest);
    printf("Lowest Marks   : %.2f\n", lowest);
    printf("============================\n");
}