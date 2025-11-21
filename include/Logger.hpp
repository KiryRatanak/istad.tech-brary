#pragma once
#include<iostream>

#include "Colors.hpp"

using namespace std;
 
void msgWarning(){
    cout  << red << " [WARNING] "<< reset << endl;
}
void msgSuccess(){ 
    cout << green << " [SUCCESS] " << reset << endl;
}  
void msgError(){ 
    cout << red << " [ERROR] " << reset << endl;
}

