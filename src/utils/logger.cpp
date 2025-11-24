#include "utils/Logger.hpp"
#include "validation/Validation.hpp"

int msgReturnBack()
{
    cout << green
         << "                                                      ✅ Returning to previous menu... 🔙"
         << reset << endl;
    msgPressEnter();
    return -1;
}


void msgPressEnter()
{
    cout << yellow
         << "                                                      👍 press enter to continue... "
         << reset;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void msgTryAgain()
{
    cout << red
         << "                                                      ⚠️  please try again... "
         << reset << endl;
}

void msgSuccess()
{
    cout << green
         << "                                                      ✅ successfully. "
         << reset << endl;
}

void msgUnsuccess()
{
    cout << red
         << "                                                      ❌ unsuccessfully..! "
         << reset << endl;
}

void msgWrongOptionHeader()
{
    cout << red
         << "                                                      ⚠️  please put 0 to 3... "
         << reset << endl;
    msgPressEnter();
}

void msgWrongOptionLogIn()
{
    cout << red
         << "                                                      ⚠️  please put 0 to 4... "
         << reset << endl;
    msgPressEnter();
}


void msgExitProgram()
{
    cout << green
         << "                                                      ✅ exit program successfully. 👋"
         << reset << endl;
    msgPressEnter();
    exit(0);
}

void msgWithoutNumber()
{
    cout << red
         << "                                                      ⚠️  invalid input..! please enter a number... "
         << reset << endl;
    msgPressEnter();
}
