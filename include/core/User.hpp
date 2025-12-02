#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "book/Book.hpp"
#include "core/History.hpp"

class User {
private:
    std::vector<Book>* books;            // points to main library list
    std::vector<History> borrowHistory;  // list of borrowed books

public:
    User();  // if you need default constructor

    int userMenu();

    void listBooksInlabrary();
    void findBook();
    void findByAuthor();
    void findByTitle();
    void findByYear();

    void borrowBook();
    void viewBorrowHistory();
    void deleteBook();
};
