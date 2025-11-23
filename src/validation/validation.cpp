#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "ui/LabelMenu.hpp"
#include "core/LogIn.hpp"

int validatedHeader()
{
    int option;

    while (true)
    {
        displayHeaderMenu();
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumber();
            continue;
        }

        if (option == 0)
        {
            msgExitProgram();
            return 0;
        }

        if (option >= 1 && option <= 3)
            return option;

        else msgWrongOptionHeader();
    }
}

int validatedLogIn()
{
    int option;

    while (true)
    {
        displayLogInMenu();
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumber();
            continue;
        }

        if (option == 0)
            return 0;

        if (option >= 1 && option <= 4)
            return option;

        else msgWrongOptionLogIn();
    }
}