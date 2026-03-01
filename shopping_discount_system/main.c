/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>

int main(void) {
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