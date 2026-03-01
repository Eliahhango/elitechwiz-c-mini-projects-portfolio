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

#define MAX_TICKETS 200

typedef struct {
    int ticketNo;
    char vehicleType;
    float hours;
    float fee;
} Ticket;

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

float calculateFee(char vehicleType, float hours) {
    float rate;
    float minimum;

    if (vehicleType == 'C') {
        rate = 4.0f;
        minimum = 10.0f;
    } else if (vehicleType == 'B') {
        rate = 2.0f;
        minimum = 5.0f;
    } else {
        rate = 6.0f;
        minimum = 15.0f;
    }

    float fee = rate * hours;
    if (fee < minimum) {
        fee = minimum;
    }
    return fee;
}

void addTicket(Ticket tickets[], int *count, int *nextTicketNo) {
    if (*count >= MAX_TICKETS) {
        printf("Ticket capacity reached.\n");
        return;
    }

    Ticket ticket;
    ticket.ticketNo = (*nextTicketNo)++;

    printf("Vehicle type (C=Car, B=Bike, U=Bus): ");
    if (scanf(" %c", &ticket.vehicleType) != 1) {
        printf("Invalid input.\n");
        clearInput();
        return;
    }

    if (ticket.vehicleType == 'c') ticket.vehicleType = 'C';
    if (ticket.vehicleType == 'b') ticket.vehicleType = 'B';
    if (ticket.vehicleType == 'u') ticket.vehicleType = 'U';

    if (ticket.vehicleType != 'C' && ticket.vehicleType != 'B' && ticket.vehicleType != 'U') {
        printf("Invalid vehicle type.\n");
        clearInput();
        return;
    }

    printf("Enter parking hours: ");
    if (scanf("%f", &ticket.hours) != 1 || ticket.hours <= 0.0f) {
        printf("Invalid hours.\n");
        clearInput();
        return;
    }
    clearInput();

    ticket.fee = calculateFee(ticket.vehicleType, ticket.hours);
    tickets[*count] = ticket;
    (*count)++;

    printf("Ticket #%d created. Fee: %.2f\n", ticket.ticketNo, ticket.fee);
}

void listTickets(const Ticket tickets[], int count) {
    if (count == 0) {
        printf("No parking records available.\n");
        return;
    }

    float totalRevenue = 0.0f;
    printf("\n%-8s %-8s %-10s %-10s\n", "Ticket", "Type", "Hours", "Fee");
    for (int i = 0; i < count; i++) {
        totalRevenue += tickets[i].fee;
        printf("%-8d %-8c %-10.2f %-10.2f\n",
               tickets[i].ticketNo,
               tickets[i].vehicleType,
               tickets[i].hours,
               tickets[i].fee);
    }
    printf("Total Revenue: %.2f\n", totalRevenue);
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    Ticket tickets[MAX_TICKETS];
    int count = 0;
    int nextTicketNo = 1001;
    int choice;

    while (1) {
        printf("\n=== Parking Fee Calculator ===\n");
        printf("1. Create Parking Ticket\n");
        printf("2. View Parking Report\n");
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
                addTicket(tickets, &count, &nextTicketNo);
                break;
            case 2:
                listTickets(tickets, count);
                break;
            case 3:
                printf("Exiting parking calculator.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
