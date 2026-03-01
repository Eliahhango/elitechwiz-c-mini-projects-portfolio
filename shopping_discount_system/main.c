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
    int customerType;
    float purchaseAmount;
    float discountRate;
    float discountAmount;
    float finalAmount;

    printf("=== Shopping Discount System ===\n");
    printf("1. Student Customer (10%%)\n");
    printf("2. Regular Customer (5%%)\n");
    printf("3. Wholesale Customer (15%%)\n");
    printf("Choose customer type: ");

    if (scanf("%d", &customerType) != 1) {
        printf("Invalid customer type.\n");
        return 1;
    }

    printf("Enter purchase amount: ");
    if (scanf("%f", &purchaseAmount) != 1 || purchaseAmount <= 0.0f) {
        printf("Invalid amount.\n");
        return 1;
    }

    switch (customerType) {
        case 1:
            discountRate = 0.10f;
            break;
        case 2:
            discountRate = 0.05f;
            break;
        case 3:
            discountRate = 0.15f;
            break;
        default:
            printf("Invalid customer type.\n");
            return 1;
    }

    discountAmount = purchaseAmount * discountRate;
    finalAmount = purchaseAmount - discountAmount;

    printf("Discount: %.2f\n", discountAmount);
    printf("Final Amount: %.2f\n", finalAmount);

    return 0;
}