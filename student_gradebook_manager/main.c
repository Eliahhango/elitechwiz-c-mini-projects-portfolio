/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 3

typedef struct {
    char name[50];
    float scores[SUBJECTS];
    float average;
    char grade;
} Student;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

char calculateGrade(float average) {
    if (average >= 70.0f) return 'A';
    if (average >= 60.0f) return 'B';
    if (average >= 50.0f) return 'C';
    if (average >= 40.0f) return 'D';
    return 'F';
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Gradebook is full.\n");
        return;
    }

    Student *s = &students[*count];
    float total = 0.0f;

    printf("Enter student name: ");
    if (fgets(s->name, sizeof(s->name), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    s->name[strcspn(s->name, "\n")] = '\0';

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter score %d (0-100): ", i + 1);
        if (scanf("%f", &s->scores[i]) != 1 || s->scores[i] < 0.0f || s->scores[i] > 100.0f) {
            printf("Invalid score.\n");
            clearInput();
            return;
        }
        total += s->scores[i];
    }
    clearInput();

    s->average = total / SUBJECTS;
    s->grade = calculateGrade(s->average);
    (*count)++;

    printf("Student saved successfully.\n");
}

void listStudents(const Student students[], int count) {
    if (count == 0) {
        printf("No students recorded yet.\n");
        return;
    }

    printf("\n%-4s %-20s %-8s %-8s %-8s %-8s %-6s\n", "No.", "Name", "Score1", "Score2", "Score3", "Average", "Grade");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-8.2f %-8.2f %-8.2f %-8.2f %-6c\n",
               i + 1,
               students[i].name,
               students[i].scores[0],
               students[i].scores[1],
               students[i].scores[2],
               students[i].average,
               students[i].grade);
    }
}

void classSummary(const Student students[], int count) {
    if (count == 0) {
        printf("No data available for summary.\n");
        return;
    }

    float totalAverage = 0.0f;
    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 0; i < count; i++) {
        totalAverage += students[i].average;
        if (students[i].average > students[highestIndex].average) {
            highestIndex = i;
        }
        if (students[i].average < students[lowestIndex].average) {
            lowestIndex = i;
        }
    }

    printf("\nClass Average: %.2f\n", totalAverage / count);
    printf("Top Student: %s (%.2f)\n", students[highestIndex].name, students[highestIndex].average);
    printf("Lowest Student: %s (%.2f)\n", students[lowestIndex].name, students[lowestIndex].average);
}

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Student Gradebook Manager ===\n");
        printf("1. Add Student\n");
        printf("2. View Gradebook\n");
        printf("3. Class Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                listStudents(students, count);
                break;
            case 3:
                classSummary(students, count);
                break;
            case 4:
                printf("Exiting gradebook manager.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
