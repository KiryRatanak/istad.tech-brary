#include "core/Admin.hpp"
#include "ui/LabelMenu.hpp"
#include "security/AdminPwd.hpp"
#include "utils/Logger.hpp"
#include "validation/Validation.hpp"
#include "security/HidePwd.hpp"

using namespace std;
Admin::Admin() {
    // Constructor implementation (if needed)
}

void Admin::checkLibrary() {
    cout << "checkLibrary successfully" << endl;
}



void Admin::createLibrarian() {
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

void Admin::updateLibrarian() {
    string username;
    cout << "Enter username to update: ";
    cin >> username;

    for (auto &lib : librarians) {
        if (lib.username == username) {
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

void Admin::deleteLibrarian() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    for (size_t i = 0; i < librarians.size(); i++) {
        if (librarians[i].username == username) {
            librarians.erase(librarians.begin() + i);
            cout << "Deleted successfully!\n";
            return;
        }
    }
    cout << "Librarian not found!\n";
}

void Admin::showLibrarians() {
    if (librarians.empty()) {
        cout << "No librarians found.\n";
        return;
    }

    cout << "\n===== Librarians =====\n";
    for (const auto &lib : librarians) {
        cout << "Username: " << lib.username << "\n";
        cout << "Gender: " << lib.gender << "\n";
        cout << "Phone: " << lib.phone << "\n";
        cout << "City: " << lib.address << "\n";
        cout << "------------------------\n";
    }
}

void Admin::manageLibrarian() {
    system("cls");
    int option;

    do {
        cout << "\n===== Manage Librarians =====\n";
        cout << "1. Create Librarian\n";
        cout << "2. Update Librarian\n";
        cout << "3. Delete Librarian\n";
        cout << "4. Show Librarians\n";
        cout << "0. Return\n";
        cout << "Select option: ";
        cin >> option;

        switch (option) {
            case 1: createLibrarian(); break;
            case 2: updateLibrarian(); break;
            case 3: deleteLibrarian(); break;
            case 4: showLibrarians(); break;
            case 0: break;
            default: cout << "Invalid option!\n";
        }

    } while (option != 0);
}



void Admin::amount() {
    cout << "amount successfully" << endl;
}

void Admin::adminMenu()
{
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

                cin >> option;

                option = validatedAdminLogIn();

                switch (option)
                {
            //     case 1:
            //         checkLibrary();
            //         break;

                case 2:
                    manageLibrarian();
                    break;

            //     case 3:
            //         amount();
            //         break;
                default:
                    break;
                } // end switch

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
}
