/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>

#define DAYS 7

int main(void) {
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