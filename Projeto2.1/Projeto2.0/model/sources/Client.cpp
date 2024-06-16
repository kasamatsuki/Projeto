//
// Created by diogo on 16/06/2024.
//
//
// Created by ricardo.franca on 24/05/2023.
//

#include "Client.h"

#include <utility>
#include "User.h"
using namespace std;

Client::Client(string &pUsername, string &pPassword) : User(pUsername, pPassword) {
    this->setUsername(pUsername);
    this->setPassword(pPassword);
    this->setName("");
    this->setAddress("");
    this->setNif(0);
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

Client::Client(string &username, string &password,
               string &name) : User(username, password) {
    setUsername(username);
    setPassword(password);
    setAddress(address);
    setNif(nif);
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
