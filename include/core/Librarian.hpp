#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "book/Book.hpp"

using namespace std;

class Librarian
{
public:
    Librarian();

    int getNextId();
    void importBook(const string& title, const string& author, int year, const string& country) ;
    void listBooks();
    void searchBooks(string title);
    void updateBook(int id);
    void deleteBook(int id);
    int amount();

    int librarianMenu();
};

extern Librarian lib;
