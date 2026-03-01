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
