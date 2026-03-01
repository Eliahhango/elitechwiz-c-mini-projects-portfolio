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

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
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