#include "utils/Logger.hpp"
#include "validation/Validation.hpp"

#include <iostream>
#include <string>

int msgReturnBack()
{
    cout << GREEN
         << "                                                      ✅ Returning to header menu..."
         << RESET << endl;
    msgPressEnter();
    return -1;
}

void msgPressEnter()
{
    cout << YELLOW
         << "                                                      👉 press enter to continue... "
         << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void msgTryAgain()
{
    cout << RED
         << "                                                      ⚠️  please try again... "
         << RESET << endl;
}

void msgSuccess()
{
    cout << GREEN
         << "                                                      ✅ successfully. "
         << RESET << endl;
}

void msgUnsuccess()
{
    cout << RED
         << "                                                      ❌ unsuccessfully..! "
         << RESET << endl;
}

void msgWrongOptionHeader()
{
    cout << RED
         << "                                                      ⚠️  please put 0 to 3... "
         << RESET << endl;
    msgPressEnter();
}

void msgWrongOptionLogIn()
{
    cout << RED
         << "                                                      ⚠️  please put 0 to 4... "
         << RESET << endl;
    msgPressEnter();
}

void msgExitProgram()
{
    cout << GREEN
         << "                                                      👋 exit program successfully."
         << endl
         << "                                                      🙏 thank you....."
         << RESET << endl;
    msgPressEnter();
    exit(0);
}

void msgWithoutNumber()
{
    cout << RED
         << "                                                      ⚠️  invalid input..! please enter a number... "
         << RESET << endl;
    msgPressEnter();
}

void msgNotAdmin()
{
    cout << RED
         << "                                                      ⚠️  invalid input..! please enter a number... "
         << RESET << endl;
    msgPressEnter();
}

void msgPressEnterInLogIn()
{
    cout << endl
         << YELLOW
         << "👉 press enter to continue... "
         << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void msgWithoutNumberInLogIn()
{
    cout << endl << RED
         << "⚠️  invalid input..! please enter a number... "
         << RESET << endl;
    msgPressEnterInLogIn();
}

void msgExitProgramInLogIn()
{
    cout << endl << GREEN
         << "👋 exit program successfully."
         << endl
         << "🙏 thank you....."
         << RESET << endl;
    msgPressEnterInLogIn();
    exit(0);
}

void msgWrongOptionInLogIn()
{
    cout << endl << RED
         << "⚠️  please put 0 to 4... "
         << RESET << endl;
    msgPressEnterInLogIn();
}

void msgSuccessInLogIn()
{
    cout << GREEN
         << "✅ successfully. "
         << RESET << endl;
}

int msgReturnBackInLogIn()
{
    cout << endl << GREEN
         << "✅ Returning to header menu..."
         << RESET << endl;
    msgPressEnterInLogIn();
    return -1;
}
