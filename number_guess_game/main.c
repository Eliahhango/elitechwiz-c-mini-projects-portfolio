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
#include <time.h>

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
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