#pragma once
#include<iostream>

#include "Colors.h++"

using namespace std;
 
void LogWarning (){
    cout << red << "[WARNING]" << reset << endl;
    
}

void LogSuccess(){ 
    cout<< green << "[SUCCESS]" << reset <<endl;
    
}
void LogError(){
    cout<< red << "[ERROR]" << reset <<endl;
}
void msgWarning(){
    cout  << red << " [WARNING] "<< reset << endl;
}
void msgSuccess(){ 
    cout << green << " [SUCCESS] " << reset << endl;
}  
void msgError(){ 
    cout << red << " [ERROR] " << reset << endl;
}

