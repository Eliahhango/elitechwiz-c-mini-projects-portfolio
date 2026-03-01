/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define QUESTION_COUNT 5
#define MAX_ATTEMPTS 100

typedef struct {
    const char *prompt;
    const char *options[4];
    int correct;
} Question;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int playQuiz(const Question questions[]) {
    int score = 0;

    for (int i = 0; i < QUESTION_COUNT; i++) {
        int answer;

        printf("\nQ%d: %s\n", i + 1, questions[i].prompt);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Your answer: ");

        if (scanf("%d", &answer) != 1 || answer < 1 || answer > 4) {
            printf("Invalid answer. Question marked incorrect.\n");
            clearInput();
        } else {
            clearInput();
            if (answer == questions[i].correct) {
                score++;
            }
        }
    }

    return score;
}

void showStats(const int scores[], int attempts) {
    if (attempts == 0) {
        printf("No attempts yet.\n");
        return;
    }

    int best = scores[0];
    int total = 0;

    for (int i = 0; i < attempts; i++) {
        total += scores[i];
        if (scores[i] > best) {
            best = scores[i];
        }
    }

    printf("Attempts: %d\n", attempts);
    printf("Best Score: %d/%d\n", best, QUESTION_COUNT);
    printf("Average Score: %.2f/%d\n", (float) total / attempts, QUESTION_COUNT);
}

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    Question questions[QUESTION_COUNT] = {
        {"Which language is primarily used for system programming?", {"HTML", "C", "SQL", "CSS"}, 2},
        {"What is the output type of sizeof operator?", {"int", "float", "size_t", "char"}, 3},
        {"Which symbol is used for pointer declaration in C?", {"&", "*", "%", "#"}, 2},
        {"Which loop checks condition first?", {"do-while", "for", "while", "Both for and while"}, 4},
        {"Which header is needed for printf?", {"stdlib.h", "string.h", "stdio.h", "math.h"}, 3}
    };

    int scores[MAX_ATTEMPTS];
    int attempts = 0;
    int choice;

    while (1) {
        printf("\n=== Quiz Master Game ===\n");
        printf("1. Play Quiz\n");
        printf("2. View Score Statistics\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: {
                if (attempts >= MAX_ATTEMPTS) {
                    printf("Attempt limit reached.\n");
                    break;
                }
                int score = playQuiz(questions);
                scores[attempts++] = score;
                printf("Quiz complete. You scored %d/%d.\n", score, QUESTION_COUNT);
                break;
            }
            case 2:
                showStats(scores, attempts);
                break;
            case 3:
                printf("Exiting quiz game.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
