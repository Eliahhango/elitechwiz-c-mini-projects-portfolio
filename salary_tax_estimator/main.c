/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    char employeeName[50];
    float baseSalary;
    float allowance;
    float taxRate;
    float grossSalary;
    float taxAmount;
    float netSalary;

    printf("=== Salary Tax Estimator ===\n");
    printf("Enter employee name: ");
    if (fgets(employeeName, sizeof(employeeName), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }
    employeeName[strcspn(employeeName, "\n")] = '\0';

    printf("Enter base salary: ");
    if (scanf("%f", &baseSalary) != 1 || baseSalary < 0.0f) {
        printf("Invalid base salary.\n");
        return 1;
    }

    printf("Enter allowance: ");
    if (scanf("%f", &allowance) != 1 || allowance < 0.0f) {
        printf("Invalid allowance.\n");
        return 1;
    }

    printf("Enter tax rate (%%): ");
    if (scanf("%f", &taxRate) != 1 || taxRate < 0.0f || taxRate > 100.0f) {
        printf("Invalid tax rate.\n");
        return 1;
    }
    clearInput();

    grossSalary = baseSalary + allowance;
    taxAmount = grossSalary * (taxRate / 100.0f);
    netSalary = grossSalary - taxAmount;

    printf("Employee: %s\n", employeeName);
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Tax Amount: %.2f\n", taxAmount);
    printf("Net Salary: %.2f\n", netSalary);

    return 0;
}