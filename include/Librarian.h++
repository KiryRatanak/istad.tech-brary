#pragma once
#include <vector>
#include <string>

// Book struct to represent a book's information
struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

class Librarian {
private:
    std::vector<Book> books;
    int nextId = 1; // Used for auto-incrementing the book ID

public:
    Librarian();  // Constructor to initialize the librarian (doesn't need any input)
    
    void importBook(const std::string& title, const std::string& author, int year);
    void listBooks();
    //void insertBook(const std::string& title, const std::string& author, int year);
    void searchBooks(const std::string& title, const std::string& author, int year);
    void updateBook(int id);
    void deleteBook(int id);
    int amount();
};

// Menu and Welcome message function declarations
void displayMenu();
void showWelcomeMessage();
