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

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    float goalAmount;
    float monthlySaving;
    float savedAmount = 0.0f;
    int months = 0;

    printf("=== Savings Goal Planner ===\n");
    printf("Enter savings goal amount: ");
    if (scanf("%f", &goalAmount) != 1 || goalAmount <= 0.0f) {
        printf("Invalid goal amount.\n");
        return 1;
    }

    printf("Enter monthly saving amount: ");
    if (scanf("%f", &monthlySaving) != 1 || monthlySaving <= 0.0f) {
        printf("Invalid monthly saving amount.\n");
        return 1;
    }

    printf("\nProgress:\n");
    while (savedAmount < goalAmount) {
        months++;
        savedAmount += monthlySaving;
        if (savedAmount > goalAmount) {
            savedAmount = goalAmount;
        }
        printf("Month %d: %.2f / %.2f\n", months, savedAmount, goalAmount);
    }

    printf("Goal reached in %d month(s).\n", months);
    return 0;
}