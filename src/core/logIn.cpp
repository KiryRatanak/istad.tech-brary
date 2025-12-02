#include "core/LogIn.hpp"
#include "validation/Validation.hpp"
#include "ui/LabelMenu.hpp"
#include "utils/Logger.hpp"
#include "core/Admin.hpp"
#include "core/Librarian.hpp"
#include "core/User.hpp"

void header()
{
    system ("cls");
    int option;

    do
    {
        option = validatedHeader();

        switch (option)
        {
        case 1:
        {
            logInMenu();
            break;
        }

        case 2:
        {
            displayRequestAccount();
            msgPressEnter();
            break;
        }

        case 3:
        {
            displayAboutUs();
            msgPressEnter();
            break;
        }
        }

    } while (option != 0);
}

void logInMenu()
{
    int option;

    User user;

    Admin admin;

    do
    {
        option = validatedLogIn();

        if (option == 4)
        {
            msgReturnBack();
            return;
        }

        switch (option)
        {
        case 1:
            admin.adminMenu();
            break;

        case 2:
            lib.librarianMenu();
            break;

        case 3:
            user.userMenu();
            break;
        }

    } while (option != 0);
}


