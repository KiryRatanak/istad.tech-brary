#include <iostream>
#include <string>

using namespace std;

// Function prototypes for role-specific actions
void adminFunction();
void librarianFunction();
void userFunction();

int main() {
    system("cls");
    
    string username, password;
    int roleChoice;

    // Hardcoded credentials for simplicity
    string adminUsername = "admin";
    string adminPassword = "admin123";

    string librarianUsername = "librarian";
    string librarianPassword = "lib123";

    string userUsername = "user";
    string userPassword = "user123";

    // Ask for user credentials
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check the credentials and assign the role
    if (username == adminUsername && password == adminPassword) {
        roleChoice = 1; // Admin role
    } 
    else if (username == librarianUsername && password == librarianPassword) {
        roleChoice = 2; // Librarian role
    }
    else if (username == userUsername && password == userPassword) {
        roleChoice = 3; // User role
    }
    else {
        cout << "Invalid username or password!" << endl;
        return 1; // Exit if login fails
    }

    // After successful login, switch based on the role
    switch (roleChoice) {
        case 1:
            cout << "Login successful! Welcome, Admin!" << endl;
            adminFunction(); // Call admin-specific function
            break;

        case 2:
            cout << "Login successful! Welcome, Librarian!" << endl;
            librarianFunction(); // Call librarian-specific function
            break;

        case 3:
            cout << "Login successful! Welcome, User!" << endl;
            userFunction(); // Call user-specific function
            break;

        default:
            cout << "Error: Invalid role!" << endl;
            break;
    }

    return 0;
}

// Admin function (you can add functionality later)
void adminFunction() {
    cout << "Admin-specific functions will go here!" << endl;
    // Add your admin-related functions here
}

// Librarian function (you can add functionality later)
void librarianFunction() {
    cout << "Librarian-specific functions will go here!" << endl;
    // Add your librarian-related functions here
}

// User function (you can add functionality later)
void userFunction() {
    cout << "User-specific functions will go here!" << endl;
    // Add your user-related functions here
}
