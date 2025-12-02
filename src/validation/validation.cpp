#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "ui/LabelMenu.hpp"
#include "core/LogIn.hpp"

bool confirmExit(int maxAttempts = 3)
{
    string input;
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        cout << "                                                      Are you sure you want to exit? (y/n): ";
        cin >> input;

        if (input == "y" || input == "Y")
            return true;
        if (input == "n" || input == "N")
            return false;

        attempts++;
        cout << "                                                      Invalid input. Please enter 'y' or 'n'. ";
        cout << "(" << (maxAttempts - attempts) << " attempts left)\n";
    }

    return false;
}

bool confirmExitInLogIn(int maxAttempts = 3)
{
    string input;
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        cout << endl << "Are you sure you want to exit? (y/n): ";
        cin >> input;

        if (input == "y" || input == "Y")
            return true;
        if (input == "n" || input == "N")
            return false;

        attempts++;
        cout << "Invalid input. Please enter 'y' or 'n'. ";
        cout << "(" << (maxAttempts - attempts) << " attempts left)\n";
    }

    return false;
}

int validatedHeader()
{
    int option;
    int attempts;

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
            if (confirmExit(3))
            {
                msgExitProgram();
                break;
            }

            else if (attempts = 3)
            {
                cout << "                                                      Too many invalid attempts. Exit cancelled." << endl;
                msgPressEnter();
                break;
            }

            else
            {
                cout << "                                                      Exit cancelled." << endl;
                msgPressEnter();
                break;
            }
        }

        if (option >= 1 && option <= 3)
            return option;

        else
            msgWrongOptionHeader();
    }
    return -1;
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
        {
            if (confirmExit(3))
            {
                msgExitProgram();
                break;
            }
            else
            {
                cout << "                                                      Exit cancelled." << endl;
                msgPressEnter();
                break;
            }
        }

        if (option >= 1 && option <= 4)
            return option;

        else
            msgWrongOptionLogIn();
    }
    return -1;
}

int validatedAdminLogIn()
{
    int option;

    while (true)
    {
        cout << "\033[2A";
        cout << "\033[22C";
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumberInLogIn();
            continue;
        }

        if (option == 0)
        {
            if (confirmExitInLogIn(3))
            {
                msgExitProgramInLogIn();
                break;
            }
            else
            {
                cout << "Exit cancelled." << endl;
                msgPressEnterInLogIn();
                break;
            }
        }

        if (option >= 1 && option <= 4)
            return option;

        else
            msgWrongOptionInLogIn();
    }
    return -1;
}

int validatedLibrarianLogIn()
{
    int option;

    while (true)
    {
        displayLibrarianLogIn();
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumberInLogIn();
            continue;
        }

        if (option == 0)
        {
            if (confirmExitInLogIn(3))
            {
                msgExitProgramInLogIn();
                break;
            }
            else
            {
                cout << "Exit cancelled." << endl;
                msgPressEnterInLogIn();
                break;
            }
        }

        if (option >= 1 && option <= 7)
            return option;

        else
            msgWrongOptionInLogIn();
    }
    return -1;
}

int validatedManageLibrarian()
{
    int option;

    while (true)
    {
        cout << "\033[2A";
        cout << "\033[22C";
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumberInLogIn();
            continue;
        }

        if (option == 0)
        {
            if (confirmExitInLogIn(3))
            {
                msgExitProgramInLogIn();
                break;
            }
            else
            {
                cout << "Exit cancelled." << endl;
                msgPressEnterInLogIn();
                break;
            }
        }

        if (option >= 1 && option <= 7)
            return option;

        else
            msgWrongOptionInLogIn();
    }
    return -1;
}

int validatedLibrarianMenu()
{
    int option;

    while (true)
    {
        cin>> option;

        if (cin.fail())
        {
            cin.clear();
            msgWithoutNumberInLogIn();
            continue;
        }

        if (option == 0)
        {
            if (confirmExitInLogIn(3))
            {
                msgExitProgramInLogIn();
                break;
            }
            else
            {
                cout << "Exit cancelled." << endl;
                msgPressEnterInLogIn();
                break;
            }
        }

        if (option >= 1 && option <= 6)
            return option;

        else
            msgWrongOptionInLogIn();
    }
    return -1;
}