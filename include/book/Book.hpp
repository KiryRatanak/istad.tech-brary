#pragma once 
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    string country;
    bool borrowed = false;  // track if the book is borrowed
};


