#include "security/Password.hpp"

vector<pair<string,string>> Admin = {
    {"Ratanak", "414141"},
};

vector<pair<string,string>> librarians = {
    {"SovanReach", "424242"},
};

vector<pair<string,string>> user = {
    {"MingYeak", "434343"},
};

bool checkAdmin(string username, string password) {
    for (auto &ad : Admin) {
        if (ad.first == username && ad.second == password) {
            return true;
        }
    }
    return false;
}

bool checkLibrarian(string username, string password) {
    for (auto &lib : librarians) {
        if (lib.first == username && lib.second == password) {
            return true;
        }
    }
    return false;
}

bool checkUser(string username, string password) {
    for (auto &us : user) {
        if (us.first == username && us.second == password) {
            return true;
        }
    }
    return false;
}