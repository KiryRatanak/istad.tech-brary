#include "security/UserPwd.hpp"

bool checkUser(string username, string password) {
    string userUsername = "MingYeak";
    string userPassword = "434343";

    return (username == userUsername && password == userPassword);
}