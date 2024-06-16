// Created by vasco on 03/06/2024.

#include "../../headers/views/registoView.h"
#include <algorithm>

RegistoView::RegistoView(Registo& registo) : registo(registo) {}

void RegistoView::displayUsers() const {
    const auto& users = registo.getUsers(); // Adicionado para evitar cópia desnecessária
    for (User user : users) {
        std::cout << "User: " << user.getName() << ", Email: " << user.getEmail() << ", Number: " << user.getNumber() << std::endl;
    }
}

void RegistoView::addUser(const User& user) {
    registo.addUser(user);
}

void RegistoView::removeUser(int num) {
    registo.removeUser(num);
}
