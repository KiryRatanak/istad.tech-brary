#include "core/librarian.hpp"
#include "ui/LabelMenu.hpp"
#include "security/HidePwd.hpp"
#include "security/LibrarianPwd.hpp"
#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "core/Librarian.hpp"

using namespace std;

Librarian::Librarian() {};

// void Librarian::importBook(const string &title, const string &author, int year)
// {
//     Book newBook = {nextId++, title, author, year};
//     books.push_back(newBook);
//     cout << "Book imported successfully!\n";
// }

// void Librarian::listBooks()
// {
//     cout << "\n===== Book List =====\n";
//     if (books.empty())
//     {
//         cout << "No books available.\n";
//         return;
//     }

//     for (const auto &b : books)
//     {
//         cout << "ID: " << b.id << " | " << b.title
//              << " | " << b.author
//              << " | " << b.year << endl;
//     }
// }

// // Insert a new book
// // void Librarian::insertBook(const string& title, const string& author, int year) {
// //     Book newBook = {nextId++, title, author, year};  // Automatically generate an ID
// //     books.push_back(newBook);
// //     cout << "Book inserted!\n";
// // }

// void Librarian::searchBooks(const string &title, const string &author, int year)
// {
//     cout << "\n===== Search Result =====\n";
//     bool found = false;

//     for (const auto &b : books)
//     {
//         if (b.title == title || b.author == author || b.year == year)
//         {
//             cout << "ID: " << b.id << " | " << b.title
//                  << " | " << b.author
//                  << " | " << b.year << endl;
//             found = true;
//         }
//     }

//     if (!found)
//     {
//         cout << "No matching book found.\n";
//     }
// }

// void Librarian::updateBook(int id)
// {
//     for (auto &b : books)
//     {
//         if (b.id == id)
//         {
//             cout << "Enter new title: ";
//             cin >> b.title;
//             cout << "Enter new author: ";
//             cin >> b.author;
//             cout << "Enter new year: ";
//             cin >> b.year;
//             cout << "Book updated successfully!\n";
//             return;
//         }
//     }
//     cout << "Book with ID " << id << " not found.\n";
// }

// void Librarian::deleteBook(int id)
// {
//     auto it = remove_if(books.begin(), books.end(), [&](const Book &b)
//                         { return b.id == id; });

//     if (it != books.end())
//     {
//         books.erase(it, books.end());
//         cout << "Book deleted successfully!\n";
//     }
//     else
//     {
//         cout << "Book with ID " << id << " not found.\n";
//     }
// }

// int Librarian::amount()
// {
//     return static_cast<int>(books.size());
// }

void Librarian::librarianMenu()
{
    // int option;
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
            cout << endl << endl << endl ;
            msgSuccessInLogIn();
            msgPressEnterInLogIn();
            cout << endl ;
            msgReturnBackInLogIn();
            // do
            // {
            //     displayLibrarianMenu();

            //     cin >> option;

            //     option = validatedAdminLogIn();

            //     switch (option)
            //     {
            //     case 1:
            //         break;

            //     case 2:
            //         break;

            //     case 3:
            //         break;
            //     case 4:
            //         break;

            //     case 5:
            //         break;

            //     case 6:
            //         break;

            //     case 7:
            //         break;
            //     }

            // } while (option != 0);
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
}
