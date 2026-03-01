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
    int year;
    int isLeap;

    printf("=== Leap Year Checker ===\n");
    printf("Enter year: ");

    if (scanf("%d", &year) != 1 || year <= 0) {
        printf("Invalid year.\n");
        return 1;
    }

    isLeap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

    if (isLeap) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}