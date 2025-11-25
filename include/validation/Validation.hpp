#pragma once

#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool confirmExit(int maxAttempts);
bool confirmExitInLogIn(int maxAttempts);
int validatedHeader();
int validatedLogIn();
int validatedAdminLogIn();
int validatedLibrarianLogIn();