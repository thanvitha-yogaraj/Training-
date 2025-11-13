#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[100];
    int choice, count = 0, i, id, found;

    while (1) {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter Book ID: ");
            scanf("%d", &library[count].id);
            printf("Enter Book Title: ");
            scanf(" %[^\n]", library[count].title);
            printf("Enter Author Name: ");
            scanf(" %[^\n]", library[count].author);
            count++;
            printf("Book added successfully!\n");
            break;

        case 2:
            if (count == 0)
                printf("No books in the library!\n");
            else {
                printf("\n%-10s %-30s %-20s\n", "Book ID", "Title", "Author");
                printf("-----------------------------------------------------\n");
                for (i = 0; i < count; i++)
                    printf("%-10d %-30s %-20s\n", library[i].id, library[i].title, library[i].author);
            }
            break;

        case 3:
            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < count; i++) {
                if (library[i].id == id) {
                    printf("Book Found!\n");
                    printf("ID: %d\nTitle: %s\nAuthor: %s\n", library[i].id, library[i].title, library[i].author);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found!\n");
            break;

        case 4:
            printf("Exiting program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
