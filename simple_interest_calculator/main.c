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
    float principal;
    float rate;
    float timeYears;
    float interest;
    float totalAmount;

    printf("=== Simple Interest Calculator ===\n");

    printf("Enter principal amount: ");
    if (scanf("%f", &principal) != 1 || principal <= 0.0f) {
        printf("Invalid principal amount.\n");
        return 1;
    }

    printf("Enter annual interest rate (%%): ");
    if (scanf("%f", &rate) != 1 || rate < 0.0f) {
        printf("Invalid interest rate.\n");
        return 1;
    }

    printf("Enter time in years: ");
    if (scanf("%f", &timeYears) != 1 || timeYears < 0.0f) {
        printf("Invalid time value.\n");
        return 1;
    }

    interest = (principal * rate * timeYears) / 100.0f;
    totalAmount = principal + interest;

    printf("Interest: %.2f\n", interest);
    printf("Total Amount: %.2f\n", totalAmount);

    return 0;
}