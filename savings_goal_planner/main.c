/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <stdlib.h>

void pauseBeforeExit(void) {
    system("pause");
}
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