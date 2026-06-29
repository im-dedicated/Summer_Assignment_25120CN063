#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Book {
    int id;
    char title[50];
    char author[30];
    int copies;
};

struct Book books[100];
int bookCount = 0;

void addBook() {
    if(bookCount >= 100) {
        printf("Library is full\n");
        return;
    }
    
    printf("Enter book ID: ");
    scanf("%d", &books[bookCount].id);
    printf("Enter book title: ");
    scanf(" %[^\n]", books[bookCount].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", books[bookCount].author);
    printf("Enter number of copies: ");
    scanf("%d", &books[bookCount].copies);
    
    bookCount++;
    printf("Book added successfully\n");
}

void displayBooks() {
    if(bookCount == 0) {
        printf("No books in library\n");
        return;
    }
    
    printf("\n=== Library Books ===\n");
    for(int i = 0; i < bookCount; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Copies: %d\n", books[i].copies);
        printf("\n");
    }
}

void searchBook() {
    char searchTitle[50];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", searchTitle);
    
    int found = 0;
    for(int i = 0; i < bookCount; i++) {
        if(strcmp(books[i].title, searchTitle) == 0) {
            printf("\nBook found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Copies: %d\n", books[i].copies);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Book not found\n");
    }
}

void borrowBook() {
    int id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &id);
    
    for(int i = 0; i < bookCount; i++) {
        if(books[i].id == id) {
            if(books[i].copies > 0) {
                books[i].copies--;
                printf("Book borrowed successfully\n");
                return;
            }
            else {
                printf("Book not available\n");
                return;
            }
        }
    }
    
    printf("Book ID not found\n");
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    
    for(int i = 0; i < bookCount; i++) {
        if(books[i].id == id) {
            books[i].copies++;
            printf("Book returned successfully\n");
            return;
        }
    }
    
    printf("Book ID not found\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
