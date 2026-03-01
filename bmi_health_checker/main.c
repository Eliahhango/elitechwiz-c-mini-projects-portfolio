/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    float weightKg;
    float heightM;
    float bmi;
    char category[20];
} BmiRecord;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void bmiCategory(float bmi, char output[]) {
    if (bmi < 18.5f) {
        strcpy(output, "Underweight");
    } else if (bmi < 25.0f) {
        strcpy(output, "Normal");
    } else if (bmi < 30.0f) {
        strcpy(output, "Overweight");
    } else {
        strcpy(output, "Obese");
    }
}

void addRecord(BmiRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Record limit reached.\n");
        return;
    }

    BmiRecord *record = &records[*count];

    printf("Enter name: ");
    if (fgets(record->name, sizeof(record->name), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    record->name[strcspn(record->name, "\n")] = '\0';

    printf("Enter weight in kg: ");
    if (scanf("%f", &record->weightKg) != 1 || record->weightKg <= 0.0f) {
        printf("Invalid weight.\n");
        clearInput();
        return;
    }

    printf("Enter height in meters: ");
    if (scanf("%f", &record->heightM) != 1 || record->heightM <= 0.0f) {
        printf("Invalid height.\n");
        clearInput();
        return;
    }
    clearInput();

    record->bmi = record->weightKg / (record->heightM * record->heightM);
    bmiCategory(record->bmi, record->category);
    (*count)++;

    printf("BMI: %.2f (%s)\n", record->bmi, record->category);
}

void listRecords(const BmiRecord records[], int count) {
    if (count == 0) {
        printf("No BMI records found.\n");
        return;
    }

    printf("\n%-4s %-20s %-10s %-10s %-8s %-12s\n", "No.", "Name", "Weight", "Height", "BMI", "Category");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-10.2f %-10.2f %-8.2f %-12s\n",
               i + 1,
               records[i].name,
               records[i].weightKg,
               records[i].heightM,
               records[i].bmi,
               records[i].category);
    }
}

void showStats(const BmiRecord records[], int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    float total = 0.0f;
    float highest = records[0].bmi;
    float lowest = records[0].bmi;

    for (int i = 0; i < count; i++) {
        total += records[i].bmi;
        if (records[i].bmi > highest) highest = records[i].bmi;
        if (records[i].bmi < lowest) lowest = records[i].bmi;
    }

    printf("Average BMI: %.2f\n", total / count);
    printf("Highest BMI: %.2f\n", highest);
    printf("Lowest BMI: %.2f\n", lowest);
}

int main(void) {
    BmiRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== BMI Health Checker ===\n");
        printf("1. Add BMI Record\n");
        printf("2. View All Records\n");
        printf("3. View BMI Statistics\n");
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
                addRecord(records, &count);
                break;
            case 2:
                listRecords(records, count);
                break;
            case 3:
                showStats(records, count);
                break;
            case 4:
                printf("Exiting BMI checker.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
