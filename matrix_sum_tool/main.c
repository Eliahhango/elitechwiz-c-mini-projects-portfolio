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

#define ROWS 2
#define COLS 2

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
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