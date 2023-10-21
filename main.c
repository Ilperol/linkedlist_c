#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[50];
    float weight;
    int publicationYear;
    struct Book* next;
};

struct Book* createBook(const char title[], float price, int pages, const char language[], float weight, int publicationYear) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->publicationYear = publicationYear;
    newBook->next = NULL;

    return newBook;
}

void insertBook(struct Book** head, struct Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        struct Book* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}

void displayBooks(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        printf("Book name: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Wight: %.2f\n", current->weight);
        printf("Year of publication: %d\n", current->publicationYear);
        printf("\n");
        current = current->next;
    }
}

void freeBooks(struct Book* head) {
    while (head != NULL) {
        struct Book* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Book* bookList = NULL;

    insertBook(&bookList, createBook("Philosopher's Stone", 14.99, 223, "English", 0.4, 1997));
    insertBook(&bookList, createBook("Chamber of Secrets", 15.99, 251, "English", 0.45, 1998));
    insertBook(&bookList, createBook("Prisoner of Azkaban", 16.99, 317, "English", 0.5, 1999));
    insertBook(&bookList, createBook("Goblet of Fire", 17.99, 439, "English", 0.55, 2000));
    insertBook(&bookList, createBook("Order of the Phoenix", 18.99, 317, "English", 0.6, 2003));
    insertBook(&bookList, createBook("Half-Blood Prince", 19.99, 317, "English", 0.65, 2005));
    insertBook(&bookList, createBook("Deathly Hallows", 20.99, 607, "English", 0.7, 2007));

    displayBooks(bookList);

    freeBooks(bookList);

    return 0;
}
