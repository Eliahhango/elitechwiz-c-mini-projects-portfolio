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

#define MAX_VALUES 20

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    int count;
    int value;
    int evenCount = 0;
    int oddCount = 0;
    int evenSum = 0;
    int oddSum = 0;

    printf("=== Even/Odd Analyzer ===\n");
    printf("How many integers (1-%d): ", MAX_VALUES);

    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_VALUES) {
        printf("Invalid count.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid number.\n");
            return 1;
        }

        if (value % 2 == 0) {
            evenCount++;
            evenSum += value;
        } else {
            oddCount++;
            oddSum += value;
        }
    }

    printf("Even count: %d\n", evenCount);
    printf("Odd count: %d\n", oddCount);
    printf("Even sum: %d\n", evenSum);
    printf("Odd sum: %d\n", oddSum);

    return 0;
}