#include "core/LogIn.hpp"
#include "validation/Validation.hpp"
#include "ui/LabelMenu.hpp"
#include "utils/Logger.hpp"

void header()
{
    int option;

    do
    {
        option = validatedHeader();

        if (option == 0)
        {
            msgExitProgram();
            return;
        }

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

    do
    {
        option = validatedLogIn();

        if (option == 0)
        {
            msgExitProgram();
            return;
        }

        if (option == 4)
        {
            msgReturnBack();
            return;
        }

        switch (option)
        {
        case 1:
            cout << "admin\n";
            msgUnsuccess();
            msgPressEnter();
            break;

        case 2:
            cout << "librarian\n";
            msgUnsuccess();
            msgPressEnter();
            break;

        case 3:
            cout << "user\n";
            msgUnsuccess();
            msgPressEnter();
            break;
        }

    } while (option != 0);
}
