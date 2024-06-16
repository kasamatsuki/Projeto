//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_CLIENTLIST_H
#define MY_PROJECT_CLIENTLIST_H

#include <list>
#include "Client.h"

class ClientList {
private:
    list<Client> clients;

    list<Client>::iterator searchByUsername(string& username);

public:
    list<Client> getAll();
    Client* getByUsername(string& username);
    void addClient(Client& client);


};

#endif //MY_PROJECT_CLIENTLIST_H
