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

#define SEAT_COUNT 10

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void viewSeats(const int seats[]) {
    printf("\nSeat Status:\n");
    for (int i = 0; i < SEAT_COUNT; i++) {
        printf("Seat %2d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

void bookSeat(int seats[]) {
    int seatNo;

    printf("Enter seat number to book (1-%d): ", SEAT_COUNT);
    if (scanf("%d", &seatNo) != 1) {
        printf("Invalid seat number.\n");
        clearInput();
        return;
    }
    clearInput();

    if (seatNo < 1 || seatNo > SEAT_COUNT) {
        printf("Seat number out of range.\n");
        return;
    }

    if (seats[seatNo - 1]) {
        printf("Seat already booked.\n");
    } else {
        seats[seatNo - 1] = 1;
        printf("Seat booked successfully.\n");
    }
}

void cancelSeat(int seats[]) {
    int seatNo;

    printf("Enter seat number to cancel (1-%d): ", SEAT_COUNT);
    if (scanf("%d", &seatNo) != 1) {
        printf("Invalid seat number.\n");
        clearInput();
        return;
    }
    clearInput();

    if (seatNo < 1 || seatNo > SEAT_COUNT) {
        printf("Seat number out of range.\n");
        return;
    }

    if (!seats[seatNo - 1]) {
        printf("Seat is not booked.\n");
    } else {
        seats[seatNo - 1] = 0;
        printf("Seat cancellation successful.\n");
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    int seats[SEAT_COUNT] = {0};
    int choice;

    while (1) {
        printf("\n=== Ticket Booking Console ===\n");
        printf("1. View Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Seat\n");
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
                viewSeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                cancelSeat(seats);
                break;
            case 4:
                printf("Exiting ticket booking console.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}