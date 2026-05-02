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

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void temperatureConverter(void) {
    int choice;
    float value;

    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        clearInput();
        return;
    }

    printf("Enter value: ");
    if (scanf("%f", &value) != 1) {
        printf("Invalid value.\n");
        clearInput();
        return;
    }
    clearInput();

    if (choice == 1) {
        printf("Result: %.2f F\n", (value * 9.0f / 5.0f) + 32.0f);
    } else if (choice == 2) {
        printf("Result: %.2f C\n", (value - 32.0f) * 5.0f / 9.0f);
    } else {
        printf("Invalid option.\n");
    }
}

void lengthConverter(void) {
    int choice;
    float value;

    printf("\nLength Converter\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Centimeters to Inches\n");
    printf("4. Inches to Centimeters\n");
    printf("Choose: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        clearInput();
        return;
    }

    printf("Enter value: ");
    if (scanf("%f", &value) != 1 || value < 0.0f) {
        printf("Invalid value.\n");
        clearInput();
        return;
    }
    clearInput();

    switch (choice) {
        case 1:
            printf("Result: %.2f miles\n", value * 0.621371f);
            break;
        case 2:
            printf("Result: %.2f km\n", value / 0.621371f);
            break;
        case 3:
            printf("Result: %.2f in\n", value / 2.54f);
            break;
        case 4:
            printf("Result: %.2f cm\n", value * 2.54f);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

void weightConverter(void) {
    int choice;
    float value;

    printf("\nWeight Converter\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Choose: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        clearInput();
        return;
    }

    printf("Enter value: ");
    if (scanf("%f", &value) != 1 || value < 0.0f) {
        printf("Invalid value.\n");
        clearInput();
        return;
    }
    clearInput();

    if (choice == 1) {
        printf("Result: %.2f lb\n", value * 2.20462f);
    } else if (choice == 2) {
        printf("Result: %.2f kg\n", value / 2.20462f);
    } else {
        printf("Invalid option.\n");
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    int choice;

    while (1) {
        printf("\n=== Unit Converter Console ===\n");
        printf("1. Temperature Converter\n");
        printf("2. Length Converter\n");
        printf("3. Weight Converter\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                temperatureConverter();
                break;
            case 2:
                lengthConverter();
                break;
            case 3:
                weightConverter();
                break;
            case 4:
                printf("Exiting unit converter.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
