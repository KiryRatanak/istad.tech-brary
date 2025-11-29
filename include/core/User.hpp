#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "book/Book.hpp"
using namespace std;

class User {
private:
    vector<Book>* books;

public:
    User(vector<Book>* libraryBooks);

    void listAllBooks();
    void findBook();
    void findByAuthor();
    void findByTitle();
    void findByYear();
    void borrowBook();
    void User::addToBorrowHistory(const string& title);
    void userMenu();
    void viewBorrowHistory();     // new
    void deleteBook();  
};
