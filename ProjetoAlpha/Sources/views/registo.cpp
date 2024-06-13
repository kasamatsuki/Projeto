//
// Created by vasco on 03/06/2024.
//
#include "../../headers/model/registo.h"

void Registo::addUser(const User& user) {
    users.push_back(user);
}

void Registo::removeUser(int num) {
    users.erase(std::remove_if(users.begin(), users.end(), [num](const User& user) {
        return user.getNumber() == num;
    }), users.end());
}

User* Registo::findUserByNumber(int num) {
    for (auto& user : users) {
        if (user.getNumber() == num) {
            return &user;
        }
    }
    return nullptr;
}

const std::vector<User>& Registo::getUsers() const {
    return users;
}
