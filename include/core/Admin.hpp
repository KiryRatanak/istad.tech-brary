#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LibrarianManagement {
    string username;
    string password;
};

class Admin {
private:
    vector<LibrarianManagement> librarians;
public:
    Admin();
    int adminMenu();
    int manageLibrarian();
    int amount();

private:

    void createLibrarian();
    void updateLibrarian();
    void deleteLibrarian();
    void showLibrarians();
};