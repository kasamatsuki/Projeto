// Created by vasco on 03/06/2024.

#ifndef CREATEUSER_H_REGISTOVIEW_H
#define CREATEUSER_H_REGISTOVIEW_H

#include "registo.h"
#include <iostream>

class RegistoView {
public:
    RegistoView(Registo& registo);
    void displayUsers() const;
    void addUser(const User& user);
    void removeUser(int num);

private:
    Registo& registo;
};

#endif // CREATEUSER_H_REGISTOVIEW_H
