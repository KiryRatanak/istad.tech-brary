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

    cout << "Enter username: ";
    cin >> lib.username;

    cout << "Enter gender: ";
    cin >> lib.gender;

    cout << "Enter phone number: ";
    cin >> lib.phone;

    cout << "Enter password: ";
    cin >> lib.password;

    cout << "Enter city: ";
    cin >> lib.address;

    librarians.push_back(lib);

    cout << "\nLibrarian created successfully!\n";
}

void Admin::updateLibrarian()
{
    string username;
    cout << "Enter username to update: ";
    cin >> username;

    for (auto &lib : librarians)
    {
        if (lib.username == username)
        {
            cout << "New gender: ";
            cin >> lib.gender;

            cout << "New phone: ";
            cin >> lib.phone;

            cout << "New password: ";
            cin >> lib.password;

            cout << "New city: ";
            cin >> lib.address;

            cout << "Updated successfully!\n";
            return;
        }
    }
    cout << "Librarian not found!\n";
}

void Admin::deleteLibrarian()
{
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    for (size_t i = 0; i < librarians.size(); i++)
    {
        if (librarians[i].username == username)
        {
            librarians.erase(librarians.begin() + i);
            cout << "Deleted successfully!\n";
            return;
        }
    }
    cout << "Librarian not found!\n";
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
        cout << "No librarians found.\n";
        return;
    }
}

int Admin::manageLibrarian()
{
    int option;

    do
    {
        cout << "\n===== Manage Librarians =====\n";
        cout << "1. Create Librarian\n";
        cout << "2. Update Librarian\n";
        cout << "3. Delete Librarian\n";
        cout << "4. Show Librarians\n";
        cout << "5. Return back\n";
        cout << "0. Return\n";
        cout << "Select option: ";

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
            cout << "Invalid option!\n";
        }

    } while (option != 0);

    return -1;
}

int Admin::amount()
{
    cout << "amount successfully" << endl;
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
