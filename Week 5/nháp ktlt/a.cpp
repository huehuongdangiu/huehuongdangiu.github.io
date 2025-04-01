#include <stdio.h>
#include <string.h>

int main() {

    
    return 0;
}
struct book {
    char author[30];
    char title[30];
    int instockquantity;
    int soldquantity;
};



























void printBooks(struct book books[], int n) {
    printf("\nBooks in Store:\n");
    for (int i = 0; i < n; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Author: %s\n", books[i].author);
        printf("Title: %s\n", books[i].title);
        printf("In Stock Quantity: %d\n", books[i].instockquantity);
        printf("Sold Quantity: %d\n", books[i].soldquantity);
    }
}

void findBook(struct book books[], int n, const char *searchTerm) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].author, searchTerm) != NULL || strstr(books[i].title, searchTerm) != NULL) {
            if (!found) {
                printf("\nFound the following books:\n");
                found = 1;
            }
            printf("\nBook %d\n", i + 1);
            printf("Author: %s\n", books[i].author);
            printf("Title: %s\n", books[i].title);
            printf("In Stock Quantity: %d\n", books[i].instockquantity);
            printf("Sold Quantity: %d\n", books[i].soldquantity);
        }
    }

    if (!found) {
        printf("\nNo book found with the given search term.\n");
    }
}

int main() {
    int N;
    printf("Enter the number of books: ");
    scanf("%d", &N);
    
    struct book books[N];

    // Input books' information
    for (int i = 0; i < N; i++) {
        printf("\nEnter details for book %d:\n", i + 1);
        printf("Author: ");
        getchar();  // To consume the newline character left by the previous scanf
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // Remove the newline character

        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // Remove the newline character

        printf("In Stock Quantity: ");
        scanf("%d", &books[i].instockquantity);

        printf("Sold Quantity: ");
        scanf("%d", &books[i].soldquantity);
    }

    // Print all books
    printBooks(books, N);

    // Search for a book by author or title
    char searchTerm[30];
    printf("\nEnter a search term (author or title): ");
    getchar();  // To consume the newline character left by the previous scanf
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Remove the newline character

    // Find and display books matching the search term
    findBook(books, N, searchTerm);

    return 0;
}
