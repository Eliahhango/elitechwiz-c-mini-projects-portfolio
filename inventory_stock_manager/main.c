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

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[40];
    int quantity;
    float unitPrice;
} Item;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int findItemIndex(const Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full.\n");
        return;
    }

    Item item;
    printf("Enter item ID: ");
    if (scanf("%d", &item.id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }
    clearInput();

    if (findItemIndex(items, *count, item.id) != -1) {
        printf("Item ID already exists.\n");
        return;
    }

    printf("Enter item name: ");
    if (fgets(item.name, sizeof(item.name), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    item.name[strcspn(item.name, "\n")] = '\0';

    printf("Enter quantity: ");
    if (scanf("%d", &item.quantity) != 1 || item.quantity < 0) {
        printf("Invalid quantity.\n");
        clearInput();
        return;
    }

    printf("Enter unit price: ");
    if (scanf("%f", &item.unitPrice) != 1 || item.unitPrice < 0.0f) {
        printf("Invalid price.\n");
        clearInput();
        return;
    }
    clearInput();

    items[*count] = item;
    (*count)++;
    printf("Item added successfully.\n");
}

void restockItem(Item items[], int count) {
    int id, quantity;
    printf("Enter item ID to restock: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }

    int index = findItemIndex(items, count, id);
    if (index == -1) {
        printf("Item not found.\n");
        clearInput();
        return;
    }

    printf("Enter quantity to add: ");
    if (scanf("%d", &quantity) != 1 || quantity <= 0) {
        printf("Invalid quantity.\n");
        clearInput();
        return;
    }
    clearInput();

    items[index].quantity += quantity;
    printf("Stock updated. New quantity: %d\n", items[index].quantity);
}

void sellItem(Item items[], int count) {
    int id, quantity;
    printf("Enter item ID to sell: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }

    int index = findItemIndex(items, count, id);
    if (index == -1) {
        printf("Item not found.\n");
        clearInput();
        return;
    }

    printf("Enter quantity to sell: ");
    if (scanf("%d", &quantity) != 1 || quantity <= 0) {
        printf("Invalid quantity.\n");
        clearInput();
        return;
    }
    clearInput();

    if (quantity > items[index].quantity) {
        printf("Not enough stock available.\n");
        return;
    }

    items[index].quantity -= quantity;
    printf("Sale complete. Remaining quantity: %d\n", items[index].quantity);
}

void showInventory(const Item items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    float totalValue = 0.0f;
    printf("\n%-6s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Quantity", "Price", "Value");
    for (int i = 0; i < count; i++) {
        float value = items[i].quantity * items[i].unitPrice;
        totalValue += value;
        printf("%-6d %-20s %-10d %-10.2f %-10.2f\n",
               items[i].id,
               items[i].name,
               items[i].quantity,
               items[i].unitPrice,
               value);
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
}

void pauseBeforeExit(void) {
    system("pause");
}
int main(void) {
    atexit(pauseBeforeExit);
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Inventory Stock Manager ===\n");
        printf("1. Add New Item\n");
        printf("2. Restock Item\n");
        printf("3. Sell Item\n");
        printf("4. Show Inventory Report\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                restockItem(items, count);
                break;
            case 3:
                sellItem(items, count);
                break;
            case 4:
                showInventory(items, count);
                break;
            case 5:
                printf("Exiting inventory manager.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
