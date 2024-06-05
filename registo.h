//
// Created by vasco on 03/06/2024.
//

#ifndef TRABALHO_DE_FSOFT_REGISTO_H
#define TRABALHO_DE_FSOFT_REGISTO_H
// Created by vasco on 03/06/2024.

#include <vector>
#include "User.h"

class Registo {
public:
    void addUser(const User& user);
    void removeUser(int num);
    User* findUserByNumber(int num);
    const std::vector<User>& getUsers() const;

private:
    std::vector<User> users;
};

#endif //TRABALHO_DE_FSOFT_REGISTO_H
