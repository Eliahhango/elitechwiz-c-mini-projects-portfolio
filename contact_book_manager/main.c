#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 200

typedef struct {
    char name[50];
    char phone[20];
    char email[60];
} Contact;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void toLowerString(const char *src, char *dst, size_t size) {
    size_t i;
    for (i = 0; i + 1 < size && src[i] != '\0'; i++) {
        dst[i] = (char) tolower((unsigned char) src[i]);
    }
    dst[i] = '\0';
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact limit reached.\\n");
        return;
    }

    Contact *contact = &contacts[*count];

    printf("Enter name: ");
    if (fgets(contact->name, sizeof(contact->name), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    contact->name[strcspn(contact->name, "\n")] = '\0';

    printf("Enter phone: ");
    if (fgets(contact->phone, sizeof(contact->phone), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    contact->phone[strcspn(contact->phone, "\n")] = '\0';

    printf("Enter email: ");
    if (fgets(contact->email, sizeof(contact->email), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    contact->email[strcspn(contact->email, "\n")] = '\0';

    (*count)++;
    printf("Contact added successfully.\\n");
}

void listContacts(const Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\\n");
        return;
    }

    printf("\\n%-4s %-20s %-18s %-30s\\n", "No.", "Name", "Phone", "Email");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-18s %-30s\\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void searchContact(const Contact contacts[], int count) {
    char query[50];
    char queryLower[50];

    if (count == 0) {
        printf("No contacts to search.\\n");
        return;
    }

    printf("Enter name to search: ");
    if (fgets(query, sizeof(query), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    query[strcspn(query, "\n")] = '\0';
    toLowerString(query, queryLower, sizeof(queryLower));

    int found = 0;
    for (int i = 0; i < count; i++) {
        char nameLower[50];
        toLowerString(contacts[i].name, nameLower, sizeof(nameLower));

        if (strstr(nameLower, queryLower) != NULL) {
            printf("Found: %s | %s | %s\\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contact found.\\n");
    }
}

void deleteContact(Contact contacts[], int *count) {
    char target[50];
    char targetLower[50];

    if (*count == 0) {
        printf("No contacts to delete.\\n");
        return;
    }

    printf("Enter exact name to delete: ");
    if (fgets(target, sizeof(target), stdin) == NULL) {
        printf("Input error.\\n");
        return;
    }
    target[strcspn(target, "\n")] = '\0';
    toLowerString(target, targetLower, sizeof(targetLower));

    for (int i = 0; i < *count; i++) {
        char nameLower[50];
        toLowerString(contacts[i].name, nameLower, sizeof(nameLower));

        if (strcmp(nameLower, targetLower) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully.\\n");
            return;
        }
    }

    printf("Contact not found.\\n");
}

int main(void) {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\\n=== Contact Book Manager ===\\n");
        printf("1. Add Contact\\n");
        printf("2. List Contacts\\n");
        printf("3. Search Contact\\n");
        printf("4. Delete Contact\\n");
        printf("5. Exit\\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                listContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting contact manager.\\n");
                return 0;
            default:
                printf("Invalid option.\\n");
                break;
        }
    }
}
