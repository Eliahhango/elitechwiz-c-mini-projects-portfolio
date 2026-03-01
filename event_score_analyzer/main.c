/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pauseBeforeExit(void) {
    system("pause");
}
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
