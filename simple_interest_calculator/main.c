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