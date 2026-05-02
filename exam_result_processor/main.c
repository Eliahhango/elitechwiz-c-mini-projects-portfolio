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

#define STUDENT_COUNT 5

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
    char names[STUDENT_COUNT][40];
    float marks[STUDENT_COUNT];
    float total = 0.0f;
    float highest = 0.0f;
    float lowest = 100.0f;
    int passCount = 0;
    int failCount = 0;

    printf("=== Exam Result Processor ===\n");

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter name for student %d: ", i + 1);
        if (fgets(names[i], sizeof(names[i]), stdin) == NULL) {
            printf("Input error.\n");
            return 1;
        }
        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Enter mark for %s (0-100): ", names[i]);
        if (scanf("%f", &marks[i]) != 1 || marks[i] < 0.0f || marks[i] > 100.0f) {
            printf("Invalid mark.\n");
            clearInput();
            return 1;
        }
        clearInput();

        total += marks[i];
        if (marks[i] > highest) {
            highest = marks[i];
        }
        if (marks[i] < lowest) {
            lowest = marks[i];
        }

        if (marks[i] >= 50.0f) {
            passCount++;
        } else {
            failCount++;
        }
    }

    printf("\n%-4s %-20s %-8s %-10s\n", "No.", "Name", "Mark", "Status");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%-4d %-20s %-8.2f %-10s\n",
               i + 1,
               names[i],
               marks[i],
               (marks[i] >= 50.0f) ? "Pass" : "Fail");
    }

    printf("Average Mark: %.2f\n", total / STUDENT_COUNT);
    printf("Highest Mark: %.2f\n", highest);
    printf("Lowest Mark: %.2f\n", lowest);
    printf("Pass Count: %d\n", passCount);
    printf("Fail Count: %d\n", failCount);

    return 0;
}