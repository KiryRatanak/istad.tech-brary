#include "core/Admin.hpp"
#include "ui/LabelMenu.hpp"
#include "security/AdminPwd.hpp"
#include "utils/Logger.hpp"
#include "validation/Validation.hpp"
#include "security/HidePwd.hpp"

using namespace std;
void checkLibrary()
{
    cout << "checkLibrary successfully" << endl;
}

void manageLibrarian()
{
    cout << "manageLibrarian successfully" << endl;
}

void amount()
{
    cout << "amount successfully" << endl;
}

void adminMenu()
{
    // int option;
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
            cout << endl << endl << endl;
            msgSuccessInLogIn();
            msgPressEnterInLogIn();
            cout << endl ;
            msgReturnBackInLogIn();
            // do
            // {
            //     displayAdminMenu();

            //     cin >> option;

            //     option = validatedAdminLogIn();

            //     switch (option)
            //     {
            //     case 1:
            //         checkLibrary();
            //         break;

            //     case 2:
            //         manageLibrarian();
            //         break;

            //     case 3:
            //         amount();
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
                     << b_red << "Too many failed attempts. You are not Admin 🫵. " << reset << endl;
                msgPressEnterInLogIn();
                continue;
            }
            msgPressEnterInLogIn();
        }
    }
}
