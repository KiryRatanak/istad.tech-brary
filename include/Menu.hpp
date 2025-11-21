#pragma once

#include <iostream>

using namespace std;

void displayLibrarianMenu()
{
    cout << "\n===== Library Menu =====\n";
    cout << "  1. Import Book\n";
    cout << "  2. List Books\n";
    cout << "  3. Insert Book\n";
    cout << "  4. Search Book\n";
    cout << "  5. Update Book\n";
    cout << "  6. Delete Book\n";
    cout << "  7. Amount\n";
    cout << "  0. Exit\n";
}

void displayUserMenu()
{
    cout << "\n=====[ USER MENU ]=====\n";
    cout << "1. List all books\n";
    cout << "2. Find a book\n";
    cout << "3. Borrow a book\n";
    cout << "4. View borrow history\n";
    cout << "5. Delete a book\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

void displayAdminMenu()
{
    cout << "\n===== ADMIN MENU =====\n";
    cout << "1. Check Library\n";
    cout << "2. Manage Librarian\n";
    cout << "3. Amount\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}