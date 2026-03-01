/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>

#define MAX_VALUES 20

int main(void) {
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