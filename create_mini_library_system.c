#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define TITLE_LEN 100
#define AUTHOR_LEN 50

struct Book {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int copies;
};

void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book *book = &library[*count];
    printf("Enter book ID: ");
    scanf("%d", &book->id);
    getchar();

    printf("Enter book title: ");
    fgets(book->title, TITLE_LEN, stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(book->author, AUTHOR_LEN, stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter number of copies: ");
    scanf("%d", &book->copies);
    getchar();

    (*count)++;
    printf("Book added successfully.\n\n");
}

void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("No books in the library yet.\n\n");
        return;
    }

    printf("\nLibrary catalog:\n");
    printf("%-6s %-30s %-20s %-8s\n", "ID", "Title", "Author", "Copies");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-30s %-20s %-8d\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].copies);
    }
    printf("\n");
}

void searchBook(struct Book library[], int count) {
    if (count == 0) {
        printf("No books available to search.\n\n");
        return;
    }

    int choice;
    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Title\n");
    printf("Choose option: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        int id;
        printf("Enter book ID: ");
        scanf("%d", &id);
        getchar();

        for (int i = 0; i < count; i++) {
            if (library[i].id == id) {
                printf("Book found:\n");
                printf("ID: %d\nTitle: %s\nAuthor: %s\nCopies: %d\n\n",
                       library[i].id,
                       library[i].title,
                       library[i].author,
                       library[i].copies);
                return;
            }
        }
        printf("No book found with ID %d.\n\n", id);
    } else if (choice == 2) {
        char search[TITLE_LEN];
        printf("Enter book title: ");
        fgets(search, TITLE_LEN, stdin);
        search[strcspn(search, "\n")] = '\0';

        for (int i = 0; i < count; i++) {
            if (strcmp(library[i].title, search) == 0) {
                printf("Book found:\n");
                printf("ID: %d\nTitle: %s\nAuthor: %s\nCopies: %d\n\n",
                       library[i].id,
                       library[i].title,
                       library[i].author,
                       library[i].copies);
                return;
            }
        }
        printf("No book found with title '%s'.\n\n", search);
    } else {
        printf("Invalid choice.\n\n");
    }
}

int main() {
    struct Book library[MAX_BOOKS];
    int count = 0;
    int option;

    while (1) {
        printf("Mini Library System\n");
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. Search book\n");
        printf("4. Exit\n");
        printf("Choose option: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Please choose a valid option.\n\n");
        }
    }
}
