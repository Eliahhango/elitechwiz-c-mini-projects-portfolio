/*
DAR ES SALAAM INSTITUTE OF TECHNOLOGY
CIVIL ENGINEERING DEPARTMENT

Module Name: Programming Fundamentals for Technicians
Module Code: GST 05117
Class: OD24CE-2
Assignment Type: Group
Assignment No: 3
Group Number: 11
Submission Date: March 1, 2026

Group Members:
1. ABDULAZIZ MAHYORO - 240121429579
2. LAWRENCE MMATAMBWE - 220121417491
3. ELIAH HANGO - 240121476067
4. HUSSEIN OMARY - 240121449049
5. ROBERT JAMES - 240121479897
6. GIDEON OLANG'U - 240121429421
7. MOSES MFUSE - 24012317533
8. GLORIA DAUDI - 240121453512
*/
#include <stdio.h>
#include <stdlib.h>

float balance = 0.0f;

void deposit(void) {
    float amount;
    printf("Enter amount to deposit: ");

    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount.\n");
        return;
    }

    if (amount <= 0.0f) {
        printf("Deposit must be greater than zero.\n");
        return;
    }

    balance += amount;
    printf("Deposit successful.\n");
}

void withdraw(void) {
    float amount;
    printf("Enter amount to withdraw: ");

    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount.\n");
        return;
    }

    if (amount <= 0.0f) {
        printf("Withdrawal must be greater than zero.\n");
        return;
    }

    if (amount > balance) {
        printf("Insufficient balance.\n");
        return;
    }

    balance -= amount;
    printf("Withdrawal successful.\n");
}

void checkBalance(void) {
    printf("Current balance: %.2f\n", balance);
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    int choice;

    while (1) {
        printf("\n=== Wallet Service Console ===\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                printf("System closed.\n");
                return 0;
            default:
                printf("Invalid menu option.\n");
                break;
        }
    }
}
