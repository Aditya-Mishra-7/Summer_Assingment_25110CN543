// Question-110 : Write a program to create bank account system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct
{
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

void createAccount(Account acc[], int *count);
void deposit(Account acc[], int count);
void withdraw(Account acc[], int count);
void checkBalance(Account acc[], int count);
int findAccount(Account acc[], int count, int accNum);

int main()
{
    Account database[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    while (1)
    {
        printf("\n=================================");
        printf("\n   BANK ACCOUNT MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting system.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            createAccount(database, &totalAccounts);
            break;
        case 2:
            deposit(database, totalAccounts);
            break;
        case 3:
            withdraw(database, totalAccounts);
            break;
        case 4:
            checkBalance(database, totalAccounts);
            break;
        case 5:
            printf("\nThank you for using our banking system!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void createAccount(Account acc[], int *count)
{
    if (*count >= MAX_ACCOUNTS)
    {
        printf("\nBank database is full! Cannot add more accounts.\n");
        return;
    }

    int newAccNum;
    printf("\nEnter a unique Account Number: ");
    scanf("%d", &newAccNum);

    if (findAccount(acc, *count, newAccNum) != -1)
    {
        printf("\nError: Account number already exists!\n");
        return;
    }

    acc[*count].accountNumber = newAccNum;

    while (getchar() != '\n')
        ;

    printf("Enter Account Holder Full Name: ");
    fgets(acc[*count].name, NAME_LENGTH, stdin);
    acc[*count].name[strcspn(acc[*count].name, "\n")] = '\0';

    printf("Enter Initial Deposit Amount: $");
    scanf("%f", &acc[*count].balance);

    if (acc[*count].balance < 0)
    {
        printf("\nError: Initial deposit cannot be negative. Account created with $0 balance.\n");
        acc[*count].balance = 0.0;
    }

    printf("\nAccount created successfully for %s!\n", acc[*count].name);
    (*count)++;
}

void deposit(Account acc[], int count)
{
    int accNum, index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(acc, count, accNum);
    if (index == -1)
    {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter Amount to Deposit: $");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount! Deposit must be greater than 0.\n");
    }
    else
    {
        acc[index].balance += amount;
        printf("\nSuccessfully deposited $%.2f. New Balance: $%.2f\n", amount, acc[index].balance);
    }
}

void withdraw(Account acc[], int count)
{
    int accNum, index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(acc, count, accNum);
    if (index == -1)
    {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter Amount to Withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount! Withdrawal must be greater than 0.\n");
    }
    else if (amount > acc[index].balance)
    {
        printf("\nInsufficient funds! Current Balance: $%.2f\n", acc[index].balance);
    }
    else
    {
        acc[index].balance -= amount;
        printf("\nSuccessfully withdrew $%.2f. Remaining Balance: $%.2f\n", amount, acc[index].balance);
    }
}

void checkBalance(Account acc[], int count)
{
    int accNum, index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(acc, count, accNum);
    if (index == -1)
    {
        printf("\nAccount not found!\n");
        return;
    }

    printf("\n=== Account Details ===");
    printf("\nAccount Number : %d", acc[index].accountNumber);
    printf("\nAccount Holder : %s", acc[index].name);
    printf("\nCurrent Balance: $%.2f\n", acc[index].balance);
}

int findAccount(Account acc[], int count, int accNum)
{
    for (int i = 0; i < count; i++)
    {
        if (acc[i].accountNumber == accNum)
        {
            return i;
        }
    }
    return -1;
}
