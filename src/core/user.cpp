#include "core/User.hpp"
#include "ui/Menu.hpp"

using namespace std;

vector<Book> libraryBooks = {
    {1, "Math", "Minh", 2013, false},
    {2, "English", "Ratana", 2008, false},
    {3, "Chinese", "Chea", 1999, false},
    {4, "Biology", "Reach", 2011, false},
    {5, "Taiwan", "Nana", 2000, false},
    {6, "Physics", "Sreypov", 2016, false},
    {7, "Chemistry", "Kanha", 2020, false}
};

User::User(vector<Book>* libraryBooks) {
    this->books = libraryBooks;
}

void User::userMenu() {
    int choice;
    do {
        displayUserMenu();
        cin >> choice;

        switch (choice) {
        case 1: listAllBooks(); break;
        case 2: findBook(); break;
        case 3: borrowBook(); break;
        case 4: viewBorrowHistory(); break;
        case 5: deleteBook(); break;
        case 0: exitMenu(); break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

void User::listAllBooks() {
    cout << "\n=====[ ALL BOOKS ]=====\n";
    for (auto &b : *books) {
        cout << b.id << " | " << b.title << " | " << b.author 
             << " | " << b.year 
             << (b.isBorrowed ? " | Borrowed\n" : " | Available\n");
    }
}

void User::findBook() {
    int option;
    cout << "\nFind book by:\n";
    cout << "1. Author\n2. Title\n3. Year\nChoose: ";
    cin >> option;
    cin.ignore();

    if (option == 1) findByAuthor();
    else if (option == 2) findByTitle();
    else if (option == 3) findByYear();
    else cout << "Invalid option!\n";
}
void User::findByAuthor() {
    string author;
    cout << "Enter author: ";
    getline(cin, author);

    bool found = false;
    for (auto &b : *books) {
        if (b.author == author) {
            cout << b.id << " | " << b.title << " | " << b.year << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found by this author!\n";
}

void User::findByTitle() {
    string title;
    cout << "Enter title: ";
    getline(cin, title);

    bool found = false;
    for (auto &b : *books) {
        if (b.title == title) {
            cout << b.id << " | " << b.author << " | " << b.year << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found with this title!\n";
}

void User::findByYear() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    bool found = false;
    for (auto &b : *books) {
        if (b.year == year) {
            cout << b.id << " | " << b.title << " | " << b.author << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found from this year!\n";
}

void User::borrowBook() {
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (auto &b : *books) {
        if (b.id == id) {
            if (!b.isBorrowed) {
                b.isBorrowed = true;

                borrowHistory.push_back({ b.id, b.title });
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void User::viewBorrowHistory() {
    cout << "\n=== BORROW HISTORY ===\n";
    for (auto &h : borrowHistory) {
        cout << h.bookId << " | " << h.title << endl;
    }
}

void User::deleteBook() {
    int id;
    cout << "Enter book ID to delete from your borrowed list: ";
    cin >> id;

    for (size_t i = 0; i < borrowHistory.size(); i++) {
        if (borrowHistory[i].bookId == id) {

            for (auto& b : *books) {
                if (b.id == id) {
                    b.isBorrowed = false;
                    break;
                }
            }

            borrowHistory.erase(borrowHistory.begin() + i);

            cout << "Book removed from your borrow list.\n";
            return;
        }
    }

    cout << "This book is not in your borrow list!\n";
}

void User::exitMenu() {
    cout << "Exiting user menu...\n";
}
