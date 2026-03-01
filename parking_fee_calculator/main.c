#include <stdio.h>

#define MAX_TICKETS 200

typedef struct {
    int ticketNo;
    char vehicleType;
    float hours;
    float fee;
} Ticket;

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

int main(void) {
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
