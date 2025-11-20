#include <iostream>
#include <string>
#include"Admin.h++"
using namespace std;

// Function to check admin credentials
bool checkAdmin(const string& username, const string& password) {
    const string adminUsername = "admin";
    const string adminPassword = "admin123"; // You can change this

    return (username == adminUsername && password == adminPassword);
}

// Placeholder functions
void checkLibrary() {
    // You will add code here later
    cout<<"Function runs successfully!"<<endl;
}

void manageLibrarian() {
    // You will add code here later
    cout<<"Function runs successfully!"<<endl;
}

void amount() {
    // You will add code here later
    cout<<"Function runs successfully!"<<endl;
}

// Function to display admin menu
void adminMenu() {
    int choice;

    do {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Check Library\n";
        cout << "2. Manage Librarian\n";
        cout << "3. Amount\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkLibrary();
                break;
            case 2:
                manageLibrarian();
                break;
            case 3:
                amount();
                break;
            case 0:
                cout << "Exiting menu...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);
}

// Function to handle login process
void login() {
    string username, password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (checkAdmin(username, password)) {
            cout << "Login successful. Welcome, Admin!" << endl;
            adminMenu();  // Show menu after successful login
            return;
        } else {
            attempts--;
            cout << "Invalid credentials. Attempts left: " << attempts << endl;
        }
    }

    cout << "Too many failed attempts. Access denied." << endl;
}

// Main function
int main() {
    system("cls");

    login();
    
    return 0;
}
