//
// Created by diogo on 15/06/2024.
//




#include <utility>
#include "Client.h"
#include "User.h"
using namespace std;

Client::Client(string &pUsername, string &pPassword) : User(pUsername, pPassword) {
    this->setUsername(pUsername);
    this->setPassword(pPassword);
    this->setName("");
}

bool Client::operator==(const Client &obj) const {
    if(this->getUsername() == obj.getUsername()){
        return true;
    }return false;
}
bool Client::operator==(string &username) const {
    if(this->username == username){
        return true;
    }return false;
}

bool Client::doesPasswordMatch(string &password) {
    if(this->password == password){
        return true;
    }return false;
}

string Client::getUsername() const {
    return User::getUsername();
}

Client::Client(string &username, string &password,string &name) : User(username, password) {
    setUsername(username);
    setPassword(password);
    setName(name);
}

string Client::getPassword() const {
    return password;
}

string Client::getName() const {
    return name;
}


Client &Client::get() {
    return *this;
}
