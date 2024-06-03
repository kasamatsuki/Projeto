// Created by vasco on 03/06/2024.

#include "registoview.h"
#include <algorithm>

RegistoView::RegistoView(Registo& registo) : registo(registo) {}

void RegistoView::displayUsers() const {
    const auto& users = registo.getUsers(); // Adicionado para evitar cópia desnecessária
    for (const auto& user : users) {
        std::cout << "User: " << user.getName() << ", Email: " << user.getEmail() << ", Number: " << user.getNumber() << std::endl;
    }
}

void RegistoView::addUser(const User& user) {
    registo.addUser(user);
}

void RegistoView::removeUser(int num) {
    registo.removeUser(num);
}
