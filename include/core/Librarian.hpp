#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

class Librarian {
private:
    std::vector<Book> books;
    int nextId = 1;

public:
    Librarian();
    
    void importBook(const std::string& title, const std::string& author, int year);
    void listBooks();
    //void insertBook(const std::string& title, const std::string& author, int year);
    void searchBooks(const std::string& title, const std::string& author, int year);
    void updateBook(int id);
    void deleteBook(int id);
    int amount();
};
