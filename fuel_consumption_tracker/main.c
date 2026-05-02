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

#define MAX_TRIPS 100

typedef struct {
    float distance;
    float fuel;
    float efficiency;
} Trip;

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void addTrip(Trip trips[], int *count) {
    if (*count >= MAX_TRIPS) {
        printf("Trip limit reached.\n");
        return;
    }

    Trip *trip = &trips[*count];

    printf("Enter trip distance (km): ");
    if (scanf("%f", &trip->distance) != 1 || trip->distance <= 0.0f) {
        printf("Invalid distance.\n");
        clearInput();
        return;
    }

    printf("Enter fuel used (liters): ");
    if (scanf("%f", &trip->fuel) != 1 || trip->fuel <= 0.0f) {
        printf("Invalid fuel value.\n");
        clearInput();
        return;
    }
    clearInput();

    trip->efficiency = trip->distance / trip->fuel;
    (*count)++;

    printf("Trip saved. Efficiency: %.2f km/L\n", trip->efficiency);
}

void showSummary(const Trip trips[], int count) {
    if (count == 0) {
        printf("No trips recorded.\n");
        return;
    }

    float totalDistance = 0.0f;
    float totalFuel = 0.0f;

    printf("\n%-4s %-12s %-12s %-12s\n", "No.", "Distance", "Fuel", "Efficiency");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-12.2f %-12.2f %-12.2f\n",
               i + 1,
               trips[i].distance,
               trips[i].fuel,
               trips[i].efficiency);
        totalDistance += trips[i].distance;
        totalFuel += trips[i].fuel;
    }

    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Fuel: %.2f liters\n", totalFuel);
    printf("Overall Efficiency: %.2f km/L\n", totalDistance / totalFuel);
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    Trip trips[MAX_TRIPS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Fuel Consumption Tracker ===\n");
        printf("1. Add Trip\n");
        printf("2. View Summary\n");
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
                addTrip(trips, &count);
                break;
            case 2:
                showSummary(trips, count);
                break;
            case 3:
                printf("Exiting fuel tracker.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}