#include "core/User.hpp"
#include "ui/LabelMenu.hpp"
#include "security/HidePwd.hpp"
#include "security/UserPwd.hpp"
#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "core/Librarian.hpp"
#include "book/Book.hpp"

using namespace std;

User::User(vector<Book>* libraryBooks) {
    this->books = libraryBooks;
}

void User::listAllBooks() {
    cout << "\n=====[ ALL BOOKS ]=====\n";
    for (auto &b : *books) {
        cout << b.title << " | " << b.author << " | " << b.year 
             << " | " << b.country 
             << (b.borrowed ? " | Borrowed\n" : " | Available\n");
    }
}

void User::findBook() {
    int option;
    cout << "\nFind book by:\n1. Author\n2. Title\n3. Year\nChoose: ";
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
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
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
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
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
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found from this year!\n";
}

void User::borrowBook() {
    string title;
    cout << "Enter book title to borrow: ";
    cin.ignore();
    getline(cin, title);

    for (auto &b : *books) {
        if (b.title == title) {
            if (!b.borrowed) {
                b.borrowed = true;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void User::addToBorrowHistory(const string& title)
{
    // Add the book title to the borrow history vector
    borrowHistory.push_back(title);

    // Optional: print a message
    cout << "\"" << title << "\" has been added to your borrow history.\n";
}

void User::deleteBook()
{
    string title;
    cout << "Enter book title to return/delete: ";
    cin.ignore();
    getline(cin, title);

    // Check if book is in borrowHistory
    auto it = find(borrowHistory.begin(), borrowHistory.end(), title);
    if (it != borrowHistory.end()) {
        // Mark the book as not borrowed
        for (auto &b : *books) {
            if (b.title == title) {
                b.borrowed = false;
                break;
            }
        }

        // Remove from history
        borrowHistory.erase(it);

        cout << "Book returned and removed from your borrow list.\n";
    }
    else {
        cout << "This book is not in your borrowed list!\n";
    }
}


void User::viewBorrowHistory()
{
    if (borrowHistory.empty()) {
        cout << "No borrowed books yet.\n";
        return;
    }

    cout << "\n=== Borrowed Books ===\n";
    for (size_t i = 0; i < borrowHistory.size(); i++) {
        cout << i + 1 << ". " << borrowHistory[i] << endl;
    }
}


void User::borrowBook()
{
    string title;
    cout << "Enter book title to borrow: ";
    cin.ignore();
    getline(cin, title);

    for (auto &b : *books)
    {
        if (b.title == title)
        {
            if (!b.borrowed)
            {
                b.borrowed = true;
                borrowHistory.push_back(title);  // add to history
                cout << "Book borrowed successfully!\n";
            }
            else
            {
                cout << "Book is already borrowed!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void User::userMenu()
{
    int option;
    string username, password;
    int attempts = 3;

    while (attempts > 0)
    {
        displayUserLogIn();

        cout << "\033[7A";
        cout << "\033[22C";
        cin >> username;

        cout << "\033[3B";
        cout << "\033[22C";
        password = getPassword();

        if (checkUser(username, password))
        {
            do
            {
                displayUserMenu();

                cin >> option;

                option = validatedAdminLogIn();

                switch (option)
                {
                case 1:
                    listAllBooks();
                    break;

                case 2:
                    findBook();
                    break;

                case 3:
                    borrowBook();
                    break;

                case 4:
                    deleteBook();
                    break;

                case 5:
                    viewBorrowHistory();
                    break;

                case 6:
                    msgReturnBack();
                    break;

                case 0:
                    msgExitProgramInLogIn();
                    break;
                }    

            } while (option != 0);
        }
        else
        {
            attempts--;
            cout << endl
                 << endl
                 << endl
                 << b_red
                 << "Invalid credentials. Attempts left: " << attempts << reset << endl;
            if (attempts == 0)
            {
                cout << endl
                     << b_red << "Too many failed attempts. Access denied." << reset << endl;
                msgPressEnterInLogIn();
                continue;
            }
            msgPressEnterInLogIn();
        }
    }
}
