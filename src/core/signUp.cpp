#include "core/SignUp.hpp"
#include "core/ExcelUtils.hpp"

using namespace std;

Account::Account(const string &username, const string &password)
    : username(username), password(password) {}

string Account::getUsername() const
{
    return username;
}

string Account::getPassword() const
{
    return password;
}

void Account::setUsername(const string &username)
{
    this->username = username;
}

void Account::setPassword(const string &password)
{
    this->password = password;
}

void Account::signUp()
{
    string username, password;

    const string ACCOUNT_FILE = "../../data/accounts.xlsx";
    vector<Account> accounts = readAccountsExcelToVector(ACCOUNT_FILE);

    cout << "===== Sign Up =====\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    accounts.emplace_back(username, password);

    // Save updated list
    writeAccountsExcel(ACCOUNT_FILE, accounts);

    cout << "✔ Account created successfully!\n";

    cout << "\n===== Current Accounts =====\n";

    // readAccountsExcel(ACCOUNT_FILE);

    return;
}
