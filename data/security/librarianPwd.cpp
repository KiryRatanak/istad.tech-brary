#include "security/LibrarianPwd.hpp"

bool checkLibrarian(string username, string password) {
    string librarianUsername = "SovanReach";
    string librarianPassword = "424242";

    return (username == librarianUsername && password == librarianPassword);
}