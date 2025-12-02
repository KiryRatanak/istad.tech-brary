#include "core/librarian.hpp"
#include "ui/LabelMenu.hpp"
#include "security/HidePwd.hpp"
#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "core/Librarian.hpp"
#include "book/Book.hpp"
#include "security/Password.hpp"

// string filename = "../../studentdata.xlsx";
// vector<Student> students = readExcelToVector(filename);

// vector<string> mainMenu = {
//     "Add New Records",
//     "Delete the Record",
//     "Update the record",
//     "Show all records",
//     "Exit"
// };

using namespace std;

Librarian lib;

Librarian::Librarian() {};

int Librarian::getNextId()
{
    return books.size() + 1; // returns the next available ID
}

void Librarian::importBook(const string &title, const string &author, int year, const string &country)
{
    int id = getNextId();
    books.push_back({id, title, author, year, country});
    cout << b_green << "Book imported successfully!\n"
         << reset;
    msgPressEnterInLogIn();
}

void Librarian::listBooks()
{
    system("cls");

    displayListBooks();

    if (books.empty())
    {
        system("cls");
        cout << b_red << "No books available.\n"
             << reset;
        msgPressEnterInLogIn();
        return;
    }

    for (auto &b : books)
    {
        cout << left << b_blue << " ║ " << reset << setw(7) << b.id
             << b_blue << " ║ " << reset << setw(30) << b.title
             << b_blue << " ║ " << reset << setw(30) << b.author
             << b_blue << " ║ " << reset << setw(7) << b.year
             << b_blue << " ║ " << reset << setw(30) << b.country
             << b_blue << " ║ " << reset << endl;
    }

    cout << b_blue << " ╚═════════╩════════════════════════════════╩════════════════════════════════╩═════════╩════════════════════════════════╝" << reset << endl;
}

void Librarian::searchBooks(string title)
{
    cout << "\n===== Search Result =====\n";
    bool found = false;

    for (auto &b : books)
    {
        if (b.title == title)
        {
            cout << b.title
                 << " | " << b.author
                 << " | " << b.year
                 << " | " << b.country
                 << " | " << (b.isBorrowed ? "Yes" : "No")
                 << endl;

            found = true;
            msgPressEnterInLogIn();
            break; // stop searching
        }
    }

    if (!found)
    {
        cout << b_red << "No matching book found.\n"
             << reset;
        msgPressEnterInLogIn();
    }
}

// void Librarian::searchBooks(string title)
// {
//     cout << "\n===== Search Result =====\n";
//     bool found = false;

//     for (auto &b : books)
//     {
//         if (b.title == title)
//         {
//             cout << b.title
//                  << " | " << b.author
//                  << " | " << b.year
//                  << " | " << b.country
//                  << " | " << (b.isBorrowed ? "Yes" : "No")
//                  << endl;
//             found = true;
//             msgPressEnterInLogIn();
//         } else {
//             cout << b_red << "No matching book found.\n" << reset;
//             msgPressEnterInLogIn();
//         }
//     }

// }

void Librarian::updateBook(int id)
{
    for (auto &b : books)
    {
        if (b.id == id)
        {
            cout << "Enter new title: ";
            cin >> b.title;
            cout << "Enter new author: ";
            cin >> b.author;
            cout << "Enter new year: ";
            cin >> b.year;
            cout << "Enter new country: ";
            cin >> b.country;
            cout << "Book updated successfully!\n";
            msgPressEnterInLogIn();
            return;
        }
    }
    cout << "Book with title " << id << " not found.\n";
    msgPressEnterInLogIn();
}

void Librarian::deleteBook(int id)
{
    auto it = remove_if(books.begin(), books.end(), [&](const Book &b)
                        { return b.id == id; });

    if (it != books.end())
    {
        books.erase(it, books.end());
        cout << "Book deleted successfully!\n";
        msgPressEnterInLogIn();
    }
    else
    {
        cout << "Book with title " << id << " not found.\n";
        msgExitProgramInLogIn();
    }
}

int Librarian::amount()
{
    return static_cast<int>(books.size());
}

int Librarian::librarianMenu()
{
    system("cls");
    int option;
    string username, password;
    int attempts = 3;

    while (attempts > 0)
    {
        displayLibrarianLogIn();

        cout << "\033[7A";
        cout << "\033[22C";
        cin >> username;

        cout << "\033[3B";
        cout << "\033[22C";
        password = getPassword();

        if (checkLibrarian(username, password))
        {
            do
            {
                displayLibrarianMenu();

                option = validatedManageLibrarian();

                if (option == 6)
                {
                    msgReturnBackInLogIn();
                    return -1;
                }

                switch (option)
                {
                case 1:
                {
                    listBooks();
                    msgPressEnterInLogIn();
                    break;
                }

                case 2:
                {
                    system("cls");
                    string title, author, country;
                    int year;
                    listBooks();
                    cout << "Enter book title: ";
                    cin >> title;
                    cout << "Enter book author: ";
                    cin >> author;
                    cout << "Enter publication year: ";
                    cin >> year;
                    cout << "Enter country: ";
                    cin >> country;
                    lib.importBook(title, author, year, country);
                    break;
                }

                case 3:
                {
                    system("cls");
                    string title;
                    cout << "Enter book title: ";
                    cin.ignore();
                    getline(cin, title);
                    lib.searchBooks(title);
                    break;
                }

                case 4:
                {
                    system("cls");
                    int id;
                    listBooks();
                    cout << "Enter book id to update: ";
                    cin >> id;
                    lib.updateBook(id);
                    break;
                }

                case 5:
                {
                    system("cls");
                    int id;
                    listBooks();
                    cout << "Enter book id to delete: ";
                    cin >> id;
                    lib.deleteBook(id);
                    break;
                }

                case 0:
                {
                    break;
                }

                default:
                {
                    cout << "Invalid option. Please try again.\n";
                    break;
                }
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
                     << b_red << "Too many failed attempts. You are not Librarian 🫵." << reset << endl;
                msgPressEnterInLogIn();
                continue;
            }
            msgPressEnterInLogIn();
        }
    }
    return -1;
}
