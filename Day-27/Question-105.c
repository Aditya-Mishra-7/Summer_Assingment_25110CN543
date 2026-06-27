//Question-105 : Write a program to create student record management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNumber;
    char name[50];
    char course[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void displayAll();
void searchStudent();
void updateStudent();
void deleteStudent();
int findIndexByRoll(int roll);

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("System full! Cannot add more records.\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNumber);

    if (findIndexByRoll(s.rollNumber) != -1) {
        printf("Error: A student with Roll Number %d already exists.\n", s.rollNumber);
        return;
    }

    getchar(); 
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    students[studentCount++] = s;
    printf("Student record added successfully!\n");
}

void displayAll() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-20s %-5.2f\n", 
               students[i].rollNumber, students[i].name, students[i].course, students[i].gpa);
    }
}

void searchStudent() {
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Record not found for Roll Number %d.\n", roll);
        return;
    }

    printf("\nRecord Found:\n");
    printf("Roll Number: %d\n", students[idx].rollNumber);
    printf("Name:        %s\n", students[idx].name);
    printf("Course:      %s\n", students[idx].course);
    printf("GPA:         %.2f\n", students[idx].gpa);
}

void updateStudent() {
    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Record not found for Roll Number %d.\n", roll);
        return;
    }

    printf("\nEnter New Details:\n");
    getchar(); 

    printf("Enter Name (Leave empty to keep current: %s): ", students[idx].name);
    char tempName[50];
    fgets(tempName, sizeof(tempName), stdin);
    if (tempName[0] != '\n') {
        tempName[strcspn(tempName, "\n")] = 0;
        strcpy(students[idx].name, tempName);
    }

    printf("Enter Course (Leave empty to keep current: %s): ", students[idx].course);
    char tempCourse[50];
    fgets(tempCourse, sizeof(tempCourse), stdin);
    if (tempCourse[0] != '\n') {
        tempCourse[strcspn(tempCourse, "\n")] = 0;
        strcpy(students[idx].course, tempCourse);
    }

    printf("Enter New GPA: ");
    scanf("%f", &students[idx].gpa);

    printf("Record updated successfully!\n");
}

void deleteStudent() {
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Record not found for Roll Number %d.\n", roll);
        return;
    }

    for (int i = idx; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    printf("Record deleted successfully!\n");
}

int findIndexByRoll(int roll) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            return i;
        }
    }
    return -1;
}
