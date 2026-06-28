//Question-109 : Write a program to create library management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define STR_LEN 100
#define FILE_NAME "library_data.txt"


typedef struct {
    int id;
    char title[STR_LEN];
    char author[STR_LEN];
    int is_issued;
} Book;


Book library[MAX_BOOKS];
int book_count = 0;


void load_from_file();
void save_to_file();
void add_book();
void display_books();
void search_book();
void issue_book();
void return_book();

int main() {
    int choice;
    load_from_file();

    do {
        printf("\n===== CAMPUS LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Save and Exit\n");
        printf("Enter your selection (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data type entered.\n");
            break;
        }
        getchar(); 

        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_book(); break;
            case 4: issue_book(); break;
            case 5: return_book(); break;
            case 6: save_to_file(); printf("Data saved. Goodbye!\n"); break;
            default: printf("Invalid choice! Please select 1-6.\n");
        }
    } while (choice != 6);

    return 0;
}

void load_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) return; 

    while (fscanf(file, "%d %[^\n] %[^\n] %d", 
           &library[book_count].id, 
           library[book_count].title, 
           library[book_count].author, 
           &library[book_count].is_issued) == 4) {
        book_count++;
        if (book_count >= MAX_BOOKS) break;
    }
    fclose(file);
}


void save_to_file() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error: Could not save data to file.\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%d\n%s\n%s\n%d\n", 
                library[i].id, library[i].title, library[i].author, library[i].is_issued);
    }
    fclose(file);
}


void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library database is full!\n");
        return;
    }

    Book new_book;
    printf("Enter Book ID (Integer): ");
    scanf("%d", &new_book.id);
    getchar();


    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with this ID already exists!\n");
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, STR_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; 

    printf("Enter Author Name: ");
    fgets(new_book.author, STR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; 

    new_book.is_issued = 0; 

    library[book_count] = new_book;
    book_count++;
    printf("Book successfully added to database!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}


void search_book() {
    char search_title[STR_LEN];
    int found = 0;

    printf("Enter Book Title to search: ");
    fgets(search_title, STR_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) printf("No book found matching that title.\n");
}


void issue_book() {
    int target_id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &target_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == target_id) {
            if (library[i].is_issued) {
                printf("Sorry, this book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book successfully issued!\n");
            }
            return;
        }
    }
    printf("Book ID not found.\n");
}


void return_book() {
    int target_id;
    printf("Enter Book ID to return: ");
    scanf("%d", &target_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == target_id) {
            if (!library[i].is_issued) {
                printf("This book is already sitting in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book successfully returned to shelf!\n");
            }
            return;
        }
    }
    printf("Book ID not found.\n");
}
