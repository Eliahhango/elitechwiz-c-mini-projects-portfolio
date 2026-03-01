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
#include <string.h>
#include <stdlib.h>

#define MAX_EXPENSES 200

typedef struct {
    char category[30];
    char note[60];
    float amount;
} Expense;

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full.\n");
        return;
    }

    Expense *expense = &expenses[*count];

    printf("Enter category (Food/Transport/Utilities/Other): ");
    if (fgets(expense->category, sizeof(expense->category), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    expense->category[strcspn(expense->category, "\n")] = '\0';

    printf("Enter note: ");
    if (fgets(expense->note, sizeof(expense->note), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    expense->note[strcspn(expense->note, "\n")] = '\0';

    printf("Enter amount: ");
    if (scanf("%f", &expense->amount) != 1 || expense->amount <= 0.0f) {
        printf("Invalid amount.\n");
        clearInput();
        return;
    }
    clearInput();

    (*count)++;
    printf("Expense saved.\n");
}

void listExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n%-4s %-15s %-30s %-10s\n", "No.", "Category", "Note", "Amount");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-15s %-30s %-10.2f\n",
               i + 1,
               expenses[i].category,
               expenses[i].note,
               expenses[i].amount);
    }
}

void summary(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expense data for summary.\n");
        return;
    }

    float total = 0.0f;
    int maxIndex = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
        if (expenses[i].amount > expenses[maxIndex].amount) {
            maxIndex = i;
        }
    }

    printf("Total Spending: %.2f\n", total);
    printf("Highest Expense: %s - %.2f (%s)\n",
           expenses[maxIndex].category,
           expenses[maxIndex].amount,
           expenses[maxIndex].note);
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Daily Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                listExpenses(expenses, count);
                break;
            case 3:
                summary(expenses, count);
                break;
            case 4:
                printf("Exiting expense tracker.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
