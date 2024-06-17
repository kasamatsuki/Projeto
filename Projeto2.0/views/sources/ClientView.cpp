//
// Created by diogo on 16/06/2024.
//
#include <iostream>
#include "ClientView.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "View.h"
#include <iomanip>

using namespace std;


string ClientView::getUsername() {
    return Utils::getString("Please enter your username");
}

string ClientView::getPassword() {
    return Utils::getString("Please enter your password - UNSECURE");
}

void ClientView::invalidUsername() {
    cout << "Invalid Username";
}

void ClientView::incorrectPassword() {
    cout << "Incorrect Password";
}

string ClientView::getName() {
    string name;
    int spaceCount;
    do{
        spaceCount = 0;
        name = Utils::getString("Please enter your first and last names");
        for(int i = 0; name[i] != '\0'; i++){
            if(name[i] == ' ')
                spaceCount++;
        }
        if(spaceCount == 0)
            cout << "Too few words" << endl;
        if(spaceCount > 1)
            cout << "Too many words" << endl;
    }while(spaceCount !=1);
    return  name;
}
void ClientView::printClient(Client* client) {

    cout << "Client Information:" << endl;
    cout << "Username: " << getUsername() << endl;
    cout << "Password: " << getPassword() << endl;
}

void ClientView::clientNotFound() {
    cout << "Client not found";
}
