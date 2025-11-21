#include "core/Admin.hpp"
#include "ui/Menu.hpp"

using namespace std;

bool checkAdmin(const string& username, const string& password) {
    const string adminUsername = "admin";
    const string adminPassword = "admin123";

    return (username == adminUsername && password == adminPassword);
}

void checkLibrary() {
    cout<<"Function runs successfully!"<<endl;
}

void manageLibrarian() {
    cout<<"Function runs successfully!"<<endl;
}

void amount() {
    cout<<"Function runs successfully!"<<endl;
}

void adminMenu() {
    int choice;

    do {

        displayAdminMenu();
        
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

void loginAs() {
    string username, password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (checkAdmin(username, password)) {
            cout << "Login successful. Welcome, Admin!" << endl;
            adminMenu();
            return;
        } else {
            attempts--;
            cout << "Invalid credentials. Attempts left: " << attempts << endl;
        }
    }

    cout << "Too many failed attempts. Access denied." << endl;
}
