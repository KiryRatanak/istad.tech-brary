#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "SignUp.hpp"

using namespace std;

void writeAccountsExcel(const string &filename, vector<Account> &accounts);
vector<Account> readAccountsExcelToVector(const string &filename);
void readAccountsExcel(const string &filename);