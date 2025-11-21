#include <iostream>
#include <algorithm>

#include "librarian.hpp"

using namespace std;

Librarian::Librarian() {};

void Librarian::importBook(const string& title, const string& author, int year) {
    Book newBook = {nextId++, title, author, year};
    books.push_back(newBook);
    cout << "Book imported successfully!\n";
}

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

int Librarian::amount() {
    return static_cast<int>(books.size());
}

