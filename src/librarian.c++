#include <iostream>
#include <algorithm>
#include "librarian.h++"

using namespace std;

// Constructor to initialize the librarian (no parameters needed)
Librarian::Librarian() {}

// Import Book
void Librarian::importBook(const string& title, const string& author, int year) {
    Book newBook = {nextId++, title, author, year};  // Create a new book with an auto-incremented ID
    books.push_back(newBook);
    cout << "Book imported successfully!\n";
}

// List all Books
void Librarian::listBooks() {
    cout << "\n===== Book List =====\n";
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    for (const auto& b : books) {
        cout << "ID: " << b.id << " | " << b.title
             << " | " << b.author
             << " | " << b.year << endl;
    }
}

// Insert a new book
// void Librarian::insertBook(const string& title, const string& author, int year) {
//     Book newBook = {nextId++, title, author, year};  // Automatically generate an ID
//     books.push_back(newBook);
//     cout << "Book inserted!\n";
// }

// Search for books by title, author, or year
void Librarian::searchBooks(const string& title, const string& author, int year) {
    cout << "\n===== Search Result =====\n";
    bool found = false;

    for (const auto& b : books) {
        if (b.title == title || b.author == author || b.year == year) {
            cout << "ID: " << b.id << " | " << b.title
                 << " | " << b.author
                 << " | " << b.year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching book found.\n";
    }
}

// Update book details
void Librarian::updateBook(int id) {
    for (auto& b : books) {
        if (b.id == id) {
            cout << "Enter new title: ";
            cin >> b.title;
            cout << "Enter new author: ";
            cin >> b.author;
            cout << "Enter new year: ";
            cin >> b.year;
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

// Delete a book by ID
void Librarian::deleteBook(int id) {
    auto it = remove_if(books.begin(), books.end(), [&](const Book& b) {
        return b.id == id;
    });

    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book deleted successfully!\n";
    } else {
        cout << "Book with ID " << id << " not found.\n";
    }
}

// Get the total number of books
int Librarian::amount() {
    return books.size();
}

// Menu Functions
void displayMenu() {
    cout << "\n===== Library Menu =====\n";
    cout << "  1. Import Book\n";
    cout << "  2. List Books\n";
    // cout << "  3. Insert Book\n";
    cout << "  3. Search Book\n";
    cout << "  4. Update Book\n";
    cout << "  5. Delete Book\n";
    cout << "  6. Amount\n";
    cout << "  0. Exit\n";
}

void showWelcomeMessage() {
    cout << "------| Welcome to Library System |------" << endl;
}
