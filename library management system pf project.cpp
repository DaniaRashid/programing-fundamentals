

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100; // Maximum number of books

struct Book {
    string title;
    int isbn; 
    string author;
    string publisher;
    int copies = 0;
    int edition = 0;
};

Book books[MAX];
int bookCount = 0;

// Save books to file
void saveToFile() {
    ofstream file("books.txt");
    for (int i = 0; i < bookCount; i++) {
        file << books[i].title << "\n";
        file << books[i].isbn << "\n";
        file << books[i].author << "\n";
        file << books[i].publisher << "\n";
        file << books[i].copies << "\n";
        file << books[i].edition << "\n";
    }
    file.close();
}

// Load books from file
void loadFromFile() {
    ifstream file("books.txt");
    if (!file) return;

    while (getline(file, books[bookCount].title)) {
        file >> books[bookCount].isbn;
        file.ignore();
        getline(file, books[bookCount].author);
        getline(file, books[bookCount].publisher);
        file >> books[bookCount].copies;
        file >> books[bookCount].edition;
        file.ignore();
        bookCount++;
    }
    file.close();
}

// Add book
void addBook() {
    if (bookCount >= MAX) {
        cout << "Library full!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, books[bookCount].title);

    cout << "Enter ISBN: ";
    cin >> books[bookCount].isbn;
    cin.ignore();

    cout << "Enter Author: ";
    getline(cin, books[bookCount].author);
    cout << "Enter Publisher: ";
    getline(cin, books[bookCount].publisher);
    cout << "Enter Copies: ";
    cin >> books[bookCount].copies;
    cout << "Enter Edition: ";
    cin >> books[bookCount].edition;
    cin.ignore();

    bookCount++;
    cout << "Book added successfully.\n";
}

// Delete book
void deleteBook() {
    cout << "Enter ISBN to delete: ";
    int isbn;
    cin >> isbn;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            for (int j = i; j < bookCount - 1; j++)
                books[j] = books[j + 1];
            bookCount--;
            cout << "Book deleted.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Modify book
void modifyBook() {
    cout << "Enter ISBN to modify: ";
    int isbn;
    cin >> isbn;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            cout << "Enter New Title: ";
            getline(cin, books[i].title);
            cout << "Enter New Author: ";
            getline(cin, books[i].author);
            cout << "Enter New Publisher: ";
            getline(cin, books[i].publisher);
            cout << "Enter New Copies: ";
            cin >> books[i].copies;
            cout << "Enter New Edition: ";
            cin >> books[i].edition;
            cin.ignore();
            cout << "Book modified.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Search by ISBN
void searchBookByISBN() {
    cout << "Enter ISBN: ";
    int isbn;
    cin >> isbn;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            cout << "\nTitle: " << books[i].title
                << "\nAuthor: " << books[i].author
                << "\nPublisher: " << books[i].publisher
                << "\nCopies: " << books[i].copies
                << "\nEdition: " << books[i].edition << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Search by Title
void searchBookByTitle() {
    cin.ignore();
    string title;
    cout << "Enter Title: ";
    getline(cin, title);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            cout << "\nISBN: " << books[i].isbn
                << "\nAuthor: " << books[i].author
                << "\nPublisher: " << books[i].publisher
                << "\nCopies: " << books[i].copies
                << "\nEdition: " << books[i].edition << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        cout << "Title     : " << books[i].title << endl;
        cout << "ISBN      : " << books[i].isbn << endl;
        cout << "Author    : " << books[i].author << endl;
        cout << "Publisher : " << books[i].publisher << endl;
        cout << "Copies    : " << books[i].copies << endl;
        cout << "Edition   : " << books[i].edition << endl;
    }
}

// Sort and display by Title
void sortByTitle() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].title > books[j].title)
                swap(books[i], books[j]);
        }
    }

    cout << "\n------ Books Sorted by Title ------\n";
    cout << "Title   ISBN   Author   Publisher   Copies   Edition\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << books[i].title << "\t"
             << books[i].isbn << "\t"
             << books[i].author << "\t"
             << books[i].publisher << "\t"
             << books[i].copies << "\t"
             << books[i].edition << "\n";
    }
}

// Sort and display by Edition
void sortByEdition() {
    // First sort by title so same titles are together
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].title > books[j].title)
                swap(books[i], books[j]);
        }
    }

    // Then sort editions for same title
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].title == books[j].title &&
                books[i].edition > books[j].edition)
                swap(books[i], books[j]);
        }
    }

    cout << "\n------ Books Sorted by Edition ------\n";
    cout << "Title   ISBN   Author   Publisher   Copies   Edition\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << books[i].title << "\t"
             << books[i].isbn << "\t"
             << books[i].author << "\t"
             << books[i].publisher << "\t"
             << books[i].copies << "\t"
             << books[i].edition << "\n";
    }
}
// Borrow book
void borrowBook() {
    cout << "Enter ISBN to borrow: ";
    int isbn;
    cin >> isbn;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            if (books[i].copies > 0) {
                books[i].copies--;
                cout << "Book borrowed.\n";
            }
            else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return book
void returnBook() {
    cout << "Enter ISBN to return: ";
    int isbn;
    cin >> isbn;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            books[i].copies++;
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// MAIN
int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n------ Library Management System ------\n";
        cout << "1. Add Book\n2. Delete Book\n3. Modify Book\n4. Search by ISBN\n5. Search by Title\n";
        cout << "6. Sort by Title\n7. Sort by Edition\n8. Borrow Book\n9. Return Book\n10. Display Books\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: deleteBook(); break;
        case 3: modifyBook(); break;
        case 4: searchBookByISBN(); break;
        case 5: searchBookByTitle(); break;
        case 6: sortByTitle(); break;
        case 7: sortByEdition(); break;
        case 8: borrowBook(); break;
        case 9: returnBook(); break;
        case 10: displayBooks(); break;
        case 0: saveToFile(); break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}