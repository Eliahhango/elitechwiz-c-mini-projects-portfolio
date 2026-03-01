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

#define MAX_STUDENTS 50

typedef struct {
    char name[50];
    int presentDays;
    int totalDays;
} Student;

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student capacity reached.\n");
        return;
    }

    printf("Enter student name: ");
    if (fgets(students[*count].name, sizeof(students[*count].name), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    students[*count].presentDays = 0;
    students[*count].totalDays = 0;
    (*count)++;

    printf("Student added successfully.\n");
}

void markAttendance(Student students[], int count) {
    if (count == 0) {
        printf("No students found. Add students first.\n");
        return;
    }

    printf("Mark attendance for the day (P=Present, A=Absent).\n");
    for (int i = 0; i < count; i++) {
        char status;

        while (1) {
            printf("%s: ", students[i].name);
            if (scanf(" %c", &status) != 1) {
                printf("Invalid input.\n");
                clearInput();
                continue;
            }

            if (status == 'P' || status == 'p' || status == 'A' || status == 'a') {
                break;
            }
            printf("Please enter only P or A.\n");
        }

        students[i].totalDays++;
        if (status == 'P' || status == 'p') {
            students[i].presentDays++;
        }
    }
    clearInput();
    printf("Attendance marked successfully.\n");
}

void viewReport(const Student students[], int count) {
    if (count == 0) {
        printf("No students recorded.\n");
        return;
    }

    printf("\n%-4s %-20s %-10s %-10s %-12s\n", "No.", "Name", "Present", "Total", "Percent");
    for (int i = 0; i < count; i++) {
        float percent = 0.0f;
        if (students[i].totalDays > 0) {
            percent = (students[i].presentDays * 100.0f) / students[i].totalDays;
        }

        printf("%-4d %-20s %-10d %-10d %.2f%%\n",
               i + 1,
               students[i].name,
               students[i].presentDays,
               students[i].totalDays,
               percent);
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Attendance Tracker Console ===\n");
        printf("1. Add Student\n");
        printf("2. Mark Daily Attendance\n");
        printf("3. View Attendance Report\n");
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
                markAttendance(students, count);
                break;
            case 3:
                viewReport(students, count);
                break;
            case 4:
                printf("Exiting attendance tracker.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
