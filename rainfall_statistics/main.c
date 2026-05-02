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

#define DAYS 7

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    float rainfall[DAYS];
    float total = 0.0f;
    float highest;
    float lowest;

    printf("=== Rainfall Statistics ===\n");

    for (int i = 0; i < DAYS; i++) {
        printf("Enter rainfall for day %d (mm): ", i + 1);
        if (scanf("%f", &rainfall[i]) != 1 || rainfall[i] < 0.0f) {
            printf("Invalid rainfall value.\n");
            return 1;
        }
    }

    highest = rainfall[0];
    lowest = rainfall[0];

    for (int i = 0; i < DAYS; i++) {
        total += rainfall[i];

        if (rainfall[i] > highest) {
            highest = rainfall[i];
        }
        if (rainfall[i] < lowest) {
            lowest = rainfall[i];
        }
    }

    printf("Total Rainfall: %.2f mm\n", total);
    printf("Average Rainfall: %.2f mm\n", total / DAYS);
    printf("Highest Rainfall: %.2f mm\n", highest);
    printf("Lowest Rainfall: %.2f mm\n", lowest);

    return 0;
}