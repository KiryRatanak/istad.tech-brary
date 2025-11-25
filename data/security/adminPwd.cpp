#include "security/AdminPwd.hpp"

bool checkAdmin(const string& username, const string& password) {
    const string adminUsername = "Ratanak";
    const string adminPassword = "414141";

    return (username == adminUsername && password == adminPassword);
}