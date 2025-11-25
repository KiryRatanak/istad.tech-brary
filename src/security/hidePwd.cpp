#include "security/HidePwd.hpp"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

char getch_cross()
{
#ifdef _WIN32
    return _getch();
#else
    char buf = 0;
    termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    termios newt = old;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &buf, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return buf;
#endif
}

string getPassword()
{
    string password;
    char ch;
    
    while (true)
    {
        ch = getch_cross();

        if (ch == '\r' || ch == '\n')
        {
            cout << endl;
            break;
        }

        if (ch == 8 || ch == 127)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
            continue;
        }

        password.push_back(ch);
        cout << '*';
    }
    return password;
}