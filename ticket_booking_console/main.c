/*
Group Number: 11
Class: OD24CE
Assignment Type: Group
Module Name: Programming Fundamentals for Technicians
Submission Date: March 1, 2026
*/

#include <stdio.h>
#include <stdlib.h>

#define SEAT_COUNT 10

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

void pauseBeforeExit(void) {
    system("pause");
}
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