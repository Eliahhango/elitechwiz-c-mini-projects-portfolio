#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[60];
    char author[50];
    int isAvailable;
} Book;

void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int findBookIndex(const Book books[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    Book book;
    printf("Enter book ID: ");
    if (scanf("%d", &book.id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }
    clearInput();

    if (findBookIndex(books, *count, book.id) != -1) {
        printf("Book ID already exists.\n");
        return;
    }

    printf("Enter title: ");
    if (fgets(book.title, sizeof(book.title), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    book.title[strcspn(book.title, "\n")] = '\0';

    printf("Enter author: ");
    if (fgets(book.author, sizeof(book.author), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    book.author[strcspn(book.author, "\n")] = '\0';

    book.isAvailable = 1;
    books[*count] = book;
    (*count)++;

    printf("Book added successfully.\n");
}

void listBooks(const Book books[], int count) {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\n%-6s %-30s %-20s %-12s\n", "ID", "Title", "Author", "Status");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-30s %-20s %-12s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isAvailable ? "Available" : "Borrowed");
    }
}

void borrowBook(Book books[], int count) {
    int id;
    printf("Enter book ID to borrow: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }
    clearInput();

    int index = findBookIndex(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (!books[index].isAvailable) {
        printf("Book is already borrowed.\n");
        return;
    }

    books[index].isAvailable = 0;
    printf("Book borrowed successfully.\n");
}

void returnBook(Book books[], int count) {
    int id;
    printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }
    clearInput();

    int index = findBookIndex(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].isAvailable) {
        printf("Book is already marked available.\n");
        return;
    }

    books[index].isAvailable = 1;
    printf("Book returned successfully.\n");
}

int main(void) {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Library Book Manager ===\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
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
                addBook(books, &count);
                break;
            case 2:
                listBooks(books, count);
                break;
            case 3:
                borrowBook(books, count);
                break;
            case 4:
                returnBook(books, count);
                break;
            case 5:
                printf("Exiting library manager.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
