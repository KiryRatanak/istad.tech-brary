#include "core/Admin.hpp"
#include "ui/LabelMenu.hpp"
#include "utils/Logger.hpp"
#include "validation/Validation.hpp"
#include "security/HidePwd.hpp"
#include "core/Librarian.hpp"
#include "security/Password.hpp"

using namespace std;

Admin::Admin() {}

void Admin::createLibrarian()
{
    LibrarianManagement lib;

    cout << endl << " Enter username: ";
    cin >> lib.username;

    cout << " Enter password: ";
    cin >> lib.password;

    librarians.push_back(lib);

    cout << b_green << "\n Librarian created successfully.\n" << reset ;
    msgPressEnterInLogIn();
}

void Admin::updateLibrarian()
{
    
    string username;
    cout << " Enter username to update: ";
    cin >> username;

    for (auto &lib : librarians)
    {
        if (lib.username == username)
        {
            cout << " New gender: ";
            cin >> lib.username;

            cout << " New password: ";
            cin >> lib.password;

            cout << b_green << " Updated successfully!\n" << reset ;
            msgPressEnterInLogIn();
            return;
        }
    }
    cout << red << " Librarian not found!\n" << reset ;
    msgPressEnterInLogIn();
}

void Admin::deleteLibrarian()
{
    string username;
    cout << " Enter username to delete: ";
    cin >> username;

    for (size_t i = 0; i < librarians.size(); i++)
    {
        if (librarians[i].username == username)
        {
            librarians.erase(librarians.begin() + i);
            cout << b_green << " Deleted successfully!\n" << reset  ;
            msgPressEnterInLogIn();
            return;
        }
    }
    cout << red << " Librarian not found!\n" << reset ;
    msgPressEnterInLogIn();
}

void Admin::showLibrarians()
{
    cout << "\n===== Librarians =====\n";
    for (auto &lib : librarians)
    {
        cout << lib.username << " | " << lib.password << endl;
    }

    if (librarians.empty())
    {
        cout << b_red << "No librarians found.\n" << reset ;
        msgPressEnterInLogIn();
        return;
    }
}

int Admin::manageLibrarian()
{
    int option;

    do
    {
        displayManageLibrarian();

        option = validatedManageLibrarian();

        if (option == 5)
        {
            msgReturnBackInLogIn();
            return -1;
        }

        switch (option)
        {
        case 1:
            createLibrarian();
            break;
        case 2:
            updateLibrarian();
            break;
        case 3:
            deleteLibrarian();
            break;
        case 4:
            showLibrarians();
            msgPressEnterInLogIn();
            break;
        case 0:

            break;
        default:
            cout << red << "Invalid option!\n" << reset ;
        }

    } while (option != 0);

    return -1;
}

int Admin::amount()
{
    cout << endl << " amount successfully" << endl;
    msgPressEnterInLogIn();
    return -1;
}

int Admin::adminMenu()
{
    system("cls");
    int option;
    string username, password;
    int attempts = 3;

    while (attempts > 0)
    {
        displayAdminLogIn();

        cout << "\033[7A";
        cout << "\033[22C";
        cin >> username;

        cout << "\033[3B";
        cout << "\033[22C";
        password = getPassword();

        if (checkAdmin(username, password))
        {
            do
            {
                displayAdminMenu();

                option = validatedAdminLogIn();

                if (option == 4)
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
                    manageLibrarian();
                    break;

                case 3:
                    amount();
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
                     << b_red << "Too many failed attempts. You are not Admin 🫵. " << reset << endl;
                msgPressEnterInLogIn();
                continue;
            }
            msgPressEnterInLogIn();
        }
    }
    return -1;
}
