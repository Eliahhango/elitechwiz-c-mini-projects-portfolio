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

#define MAX_RECORDS 100

typedef struct {
    char studentName[50];
    int roomNumber;
    float totalFee;
    float paidAmount;
    float dueAmount;
} FeeRecord;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void addRecord(FeeRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Record list is full.\n");
        return;
    }

    FeeRecord *record = &records[*count];

    printf("Enter student name: ");
    if (fgets(record->studentName, sizeof(record->studentName), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    record->studentName[strcspn(record->studentName, "\n")] = '\0';

    printf("Enter room number: ");
    if (scanf("%d", &record->roomNumber) != 1 || record->roomNumber <= 0) {
        printf("Invalid room number.\n");
        clearInput();
        return;
    }

    printf("Enter total fee: ");
    if (scanf("%f", &record->totalFee) != 1 || record->totalFee < 0.0f) {
        printf("Invalid total fee.\n");
        clearInput();
        return;
    }

    printf("Enter paid amount: ");
    if (scanf("%f", &record->paidAmount) != 1 || record->paidAmount < 0.0f || record->paidAmount > record->totalFee) {
        printf("Invalid paid amount.\n");
        clearInput();
        return;
    }
    clearInput();

    record->dueAmount = record->totalFee - record->paidAmount;
    (*count)++;

    printf("Record added successfully.\n");
}

void listRecords(const FeeRecord records[], int count) {
    if (count == 0) {
        printf("No fee records available.\n");
        return;
    }

    float totalDue = 0.0f;
    printf("\n%-4s %-20s %-8s %-10s %-10s %-10s\n", "No.", "Name", "Room", "Total", "Paid", "Due");

    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-8d %-10.2f %-10.2f %-10.2f\n",
               i + 1,
               records[i].studentName,
               records[i].roomNumber,
               records[i].totalFee,
               records[i].paidAmount,
               records[i].dueAmount);
        totalDue += records[i].dueAmount;
    }

    printf("Total Due Amount: %.2f\n", totalDue);
}

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    FeeRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Hostel Fee Manager ===\n");
        printf("1. Add Fee Record\n");
        printf("2. View Fee Report\n");
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
                addRecord(records, &count);
                break;
            case 2:
                listRecords(records, count);
                break;
            case 3:
                printf("Exiting hostel fee manager.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}