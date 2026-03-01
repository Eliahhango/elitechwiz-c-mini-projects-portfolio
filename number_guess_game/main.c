/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int main(void) {
    int secret;
    int guess;
    int attempts = 0;
    const int maxAttempts = 7;

    srand((unsigned int) time(NULL));
    secret = (rand() % 100) + 1;

    printf("=== Number Guess Game ===\n");
    printf("Guess a number between 1 and 100. You have %d attempts.\n", maxAttempts);

    while (attempts < maxAttempts) {
        printf("Attempt %d: ", attempts + 1);

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Try again.\n");
            clearInput();
            continue;
        }
        clearInput();

        attempts++;

        if (guess == secret) {
            printf("Correct! You guessed in %d attempt(s).\n", attempts);
            return 0;
        }

        if (guess < secret) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
    }

    printf("Game over. The number was %d.\n", secret);
    return 0;
}