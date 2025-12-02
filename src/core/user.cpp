#include "core/User.hpp"
#include "ui/LabelMenu.hpp"
#include "security/HidePwd.hpp"
#include "security/Password.hpp"
#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "core/Librarian.hpp"
#include "book/Book.hpp"

using namespace std;

User::User() {}

// User::User(vector<Book> *libraryBooks)
// {
//     this->books = libraryBooks;
// }

void User::listBooksInlabrary()
{
    system("cls");

    lib.listBooks();
}

void User::findBook()
{
    int option;
    cout << endl << "\n Find book by:\n";
    cout << " 1. Author\n 2. Title\n 3. Year\nChoose: ";
    cin >> option;
    cin.ignore();

    if (option == 1)
        findByAuthor();
    else if (option == 2)
        findByTitle();
    else if (option == 3)
        findByYear();
    else
        cout << " Invalid option!\n";
}

void User::findByAuthor()
{
    string author;
    cout << endl << " Enter author: ";
    getline(cin, author);

    bool found = false;
    for (auto &b : books)
    {
        if (b.author == author)
        {
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
            found = true;
        }
    }
    if (!found)
        cout << " No books found by this author!\n";
}

void User::findByTitle()
{
    string title;
    cout << endl << " Enter title: ";
    getline(cin, title);

    bool found = false;
    for (auto &b : books)
    {
        if (b.title == title)
        {
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
            found = true;
        }
    }
    if (!found)
        cout << " No books found with this title!\n";
}

void User::findByYear()
{
    int year;
    cout << endl << " Enter year: ";
    cin >> year;

    bool found = false;
    for (auto &b : books)
    {
        if (b.year == year)
        {
            cout << b.title << " | " << b.author << " | " << b.year << " | " << b.country << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No books found from this year!\n";
}

void User::borrowBook()
{
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (auto &b : books)
    {
        if (b.id == id)
        {
            if (!b.isBorrowed)
            {
                b.isBorrowed = true;

                borrowHistory.push_back({
                    b.id,
                    b.title,
                    b.author,
                    b.year,
                    b.country,
                    b.isBorrowed
                });
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

void User::viewBorrowHistory()
{
    cout << "\n=== BORROW HISTORY ===\n";

    if (borrowHistory.empty()) {
        cout << "No borrow history.\n";
        return;
    }

    for (auto &h : borrowHistory)
    {
        cout << "ID: " << h.id
             << " | Title: " << h.title
             << " | Author: " << h.author
             << " | Year: " << h.year
             << " | Country: " << h.country
             << " | Borrowed: " << (h.isBorrowed ? "Yes" : "No")
             << endl;
    }
}

void User::deleteBook()
{
    int id;
    cout << "Enter book ID to delete from your borrowed list: ";
    cin >> id;

    for (size_t i = 0; i < borrowHistory.size(); i++)
    {
        if (borrowHistory[i].id == id)
        {

            for (auto &b : books)
            {
                if (b.id == id)
                {
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

int User::userMenu()
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

                option = validatedUserLogIn();

                if (option == 6)
                {
                    msgReturnBackInLogIn();
                    return -1;
                }

                switch (option)
                {
                case 1:
                    lib.listBooks();
                    msgPressEnterInLogIn();
                    break;

                case 2:
                    findBook();
                    msgPressEnterInLogIn();
                    break;

                case 3:
                    lib.listBooks();
                    borrowBook();
                    msgPressEnterInLogIn();
                    break;

                case 4:
                    viewBorrowHistory();
                    msgPressEnterInLogIn();
                    break;

                case 5:
                    viewBorrowHistory();
                    deleteBook();
                    msgPressEnterInLogIn();
                    break;

                default:
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
    return -1;
}
