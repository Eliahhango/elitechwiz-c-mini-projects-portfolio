/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_COUNT 3

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void castVote(int votes[], const char *candidates[]) {
    int choice;

    printf("\nCandidates:\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
    printf("Choose candidate number: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        clearInput();
        return;
    }
    clearInput();

    if (choice < 1 || choice > CANDIDATE_COUNT) {
        printf("Invalid candidate.\n");
        return;
    }

    votes[choice - 1]++;
    printf("Vote recorded for %s.\n", candidates[choice - 1]);
}

void showResults(const int votes[], const char *candidates[]) {
    int totalVotes = 0;

    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        totalVotes += votes[i];
    }

    printf("\nVoting Results:\n");
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        float percent = 0.0f;
        if (totalVotes > 0) {
            percent = (votes[i] * 100.0f) / totalVotes;
        }
        printf("%s: %d vote(s) (%.2f%%)\n", candidates[i], votes[i], percent);
    }
    printf("Total Votes: %d\n", totalVotes);
}

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    const char *candidates[CANDIDATE_COUNT] = {"Alice", "Brian", "Cathy"};
    int votes[CANDIDATE_COUNT] = {0};
    int choice;

    while (1) {
        printf("\n=== Basic Voting Console ===\n");
        printf("1. Cast Vote\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                castVote(votes, candidates);
                break;
            case 2:
                showResults(votes, candidates);
                break;
            case 3:
                printf("Exiting voting console.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}