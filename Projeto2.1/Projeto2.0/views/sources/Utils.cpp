//
// Created by diogo on 16/06/2024.
//
#include "Utils.h"
#include <iostream>
#include <limits>

using namespace std;

int Utils::getNumber(const string&  label){
    int number;
    bool flag;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "Not a number, please enter a number" << endl;
            cin.clear(); //corrects stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag);
    cin.clear(); //corrects stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

bool Utils::getBool(const string& label){
    string s;
    int n;
    do{
        n = stoi(getString(label));
    }while(n < 0 || n > 1);
    return n;
}

string Utils::getString(const string&  label){
    string input;
    cout<<label<<": ";
    getline (cin, input);
    return input;
}

unsigned int Utils::getUInt(const string& label) {
    unsigned int number;
    bool flag;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "Not a number, please enter a number" << endl;
            cin.clear(); //corrects stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag);
    cin.clear(); //corrects stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;}

bool Utils::stringIsNumber(string &s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return (!s.empty() && it == s.end());
}

float Utils::getFloat(const string &label) {
    float number;
    bool flag;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "Not a number, please enter a number" << endl;
            cin.clear(); //corrects stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag);
    cin.clear(); //corrects stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

