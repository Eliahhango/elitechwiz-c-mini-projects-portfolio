/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    int a[ROWS][COLS];
    int b[ROWS][COLS];
    int sum[ROWS][COLS];

    printf("=== Matrix Sum Tool (2x2) ===\n");

    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("A[%d][%d]: ", i, j);
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
        }
    }

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("B[%d][%d]: ", i, j);
            if (scanf("%d", &b[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Sum Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}