#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
typedef struct {
    char title[100];
    char author[100];
    int year;
    int copies_available;
} Book;

// Function prototypes
void addBook(Book books[], int* num_books);
void displayBooks(const Book books[], int num_books);
void searchBook(const Book books[], int num_books, const char* title);
void borrowBook(Book books[], int num_books, const char* title);
void returnBook(Book books[], int num_books, const char* title);

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;
    int choice;

    printf("Welcome to the Library Management System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &num_books);
                break;
            case 2:
                displayBooks(books, num_books);
                break;
            case 3:
                {
                    char searchTitle[100];
                    printf("Enter the title to search: ");
                    scanf(" %[^\n]", searchTitle);
                    searchBook(books, num_books, searchTitle);
                }
                break;
            case 4:
                {
                    char borrowTitle[100];
                    printf("Enter the title to borrow: ");
                    scanf(" %[^\n]", borrowTitle);
                    borrowBook(books, num_books, borrowTitle);
                }
                break;
            case 5:
                {
                    char returnTitle[100];
                    printf("Enter the title to return: ");
                    scanf(" %[^\n]", returnTitle);
                    returnBook(books, num_books, returnTitle);
                }
                break;
            case 6:
                printf("Thank you for using the Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book books[], int* num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("Maximum book limit reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", books[*num_books].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", books[*num_books].author);
    printf("Enter publication year: ");
    scanf("%d", &books[*num_books].year);
    printf("Enter the number of copies available: ");
    scanf("%d", &books[*num_books].copies_available);

    (*num_books)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book books[], int num_books) {
    if (num_books == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("Books in the library:\n");
    printf("Title\t\tAuthor\t\tYear\tAvailable Copies\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t%s\t%d\t%d\n", books[i].title, books[i].author, books[i].year, books[i].copies_available);
    }
}

void searchBook(const Book books[], int num_books, const char* title) {
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found!\n");
            printf("Title: %s\nAuthor: %s\nYear: %d\nAvailable Copies: %d\n",
                   books[i].title, books[i].author, books[i].year, books[i].copies_available);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found in the library.\n");
    }
}

void borrowBook(Book books[], int num_books, const char* title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            if (books[i].copies_available > 0) {
                books[i].copies_available--;
                printf("You have borrowed the book: %s\n", books[i].title);
                return;
            } else {
                printf("Sorry, the book is currently unavailable for borrowing.\n");
                return;
            }
        }
    }
    printf("Book not found in the library.\n");
}

void returnBook(Book books[], int num_books, const char* title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            books[i].copies_available++;
            printf("You have returned the book: %s\n", books[i].title);
            return;
        }
    }
    printf("Book not found in the library.\n");
}
