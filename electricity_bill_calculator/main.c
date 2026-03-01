#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char customer[50];
    float units;
    char type;
    float bill;
} BillRecord;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

float calculateResidential(float units) {
    float bill = 0.0f;

    if (units <= 100.0f) {
        bill = units * 0.50f;
    } else if (units <= 200.0f) {
        bill = 100.0f * 0.50f + (units - 100.0f) * 0.75f;
    } else {
        bill = 100.0f * 0.50f + 100.0f * 0.75f + (units - 200.0f) * 1.20f;
    }

    bill += 30.0f;
    return bill;
}

float calculateCommercial(float units) {
    float bill = 0.0f;

    if (units <= 100.0f) {
        bill = units * 0.80f;
    } else if (units <= 200.0f) {
        bill = 100.0f * 0.80f + (units - 100.0f) * 1.20f;
    } else {
        bill = 100.0f * 0.80f + 100.0f * 1.20f + (units - 200.0f) * 1.50f;
    }

    bill += 75.0f;
    return bill;
}

void generateBill(BillRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Record capacity reached.\\n");
        return;
    }

    BillRecord *record = &records[*count];

    printf("Enter customer name: ");
    if (fgets(record->customer, sizeof(record->customer), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    record->customer[strcspn(record->customer, "\n")] = '\0';

    printf("Enter units consumed: ");
    if (scanf("%f", &record->units) != 1 || record->units < 0.0f) {
        printf("Invalid units.\\n");
        clearInput();
        return;
    }

    printf("Consumer type (R for Residential, C for Commercial): ");
    if (scanf(" %c", &record->type) != 1) {
        printf("Invalid consumer type.\\n");
        clearInput();
        return;
    }
    clearInput();

    if (record->type == 'R' || record->type == 'r') {
        record->bill = calculateResidential(record->units);
        record->type = 'R';
    } else if (record->type == 'C' || record->type == 'c') {
        record->bill = calculateCommercial(record->units);
        record->type = 'C';
    } else {
        printf("Invalid consumer type.\\n");
        return;
    }

    (*count)++;
    printf("Bill generated successfully. Amount: %.2f\\n", record->bill);
}

void printRecords(const BillRecord records[], int count) {
    if (count == 0) {
        printf("No bill records available.\\n");
        return;
    }

    float total = 0.0f;
    printf("\\n%-4s %-20s %-8s %-10s %-10s\\n", "No.", "Customer", "Type", "Units", "Amount");
    for (int i = 0; i < count; i++) {
        total += records[i].bill;
        printf("%-4d %-20s %-8c %-10.2f %-10.2f\\n",
               i + 1,
               records[i].customer,
               records[i].type,
               records[i].units,
               records[i].bill);
    }
    printf("Total Billed Amount: %.2f\\n", total);
}

int main(void) {
    BillRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        printf("\\n=== Electricity Bill Calculator ===\\n");
        printf("1. Generate New Bill\\n");
        printf("2. View Bill Records\\n");
        printf("3. Exit\\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                generateBill(records, &count);
                break;
            case 2:
                printRecords(records, count);
                break;
            case 3:
                printf("Exiting bill calculator.\\n");
                return 0;
            default:
                printf("Invalid option.\\n");
                break;
        }
    }
}
