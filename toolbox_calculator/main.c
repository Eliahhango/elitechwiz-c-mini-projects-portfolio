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
    int choice;
    float num1, num2, result;

    while (1) {
        printf("\n=== Toolbox Calculator ===\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        if (choice == 5) {
            printf("Calculator closed.\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid menu option.\n");
            continue;
        }

        printf("Enter two numbers: ");
        if (scanf("%f %f", &num1, &num2) != 2) {
            printf("Invalid numbers.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (num2 == 0.0f) {
                    printf("Error: division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Unexpected option.\n");
                break;
        }
    }

    return 0;
}
