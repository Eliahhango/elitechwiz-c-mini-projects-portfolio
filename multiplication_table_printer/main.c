/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>

int main(void) {
    int number;
    int limit;

    printf("=== Multiplication Table Printer ===\n");
    printf("Enter number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid number.\n");
        return 1;
    }

    printf("Enter table limit: ");
    if (scanf("%d", &limit) != 1 || limit <= 0) {
        printf("Invalid limit.\n");
        return 1;
    }

    for (int i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}