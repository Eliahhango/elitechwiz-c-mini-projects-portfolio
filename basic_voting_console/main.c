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

#define CANDIDATE_COUNT 3

/* Utility: clears leftover input from stdin buffer. */
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

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
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