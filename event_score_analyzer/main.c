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

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    char participantName[100];
    float score1, score2, score3;
    float total, average;
    char level;

    printf("=== Event Score Analyzer ===\n");
    printf("Enter participant name: ");
    if (fgets(participantName, sizeof(participantName), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    participantName[strcspn(participantName, "\n")] = '\0';

    printf("Enter scores for 3 rounds: ");
    if (scanf("%f %f %f", &score1, &score2, &score3) != 3) {
        printf("Invalid scores.\n");
        return 1;
    }

    total = score1 + score2 + score3;
    average = total / 3.0f;

    if (average >= 70.0f && average <= 100.0f) {
        level = 'A';
    } else if (average >= 60.0f && average <= 69.0f) {
        level = 'B';
    } else if (average >= 50.0f && average <= 59.0f) {
        level = 'C';
    } else if (average >= 40.0f && average <= 49.0f) {
        level = 'D';
    } else if (average >= 0.0f && average < 40.0f) {
        level = 'F';
    } else {
        level = 'X';
    }

    printf("\nParticipant: %s\n", participantName);
    printf("Total Score: %.2f\n", total);
    printf("Average Score: %.2f\n", average);

    if (level == 'X') {
        printf("Level: Invalid score range\n");
    } else {
        printf("Level: %c\n", level);
    }

    return 0;
}
