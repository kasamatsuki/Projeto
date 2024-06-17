

#include "ClientList.h"

list<Client>::iterator ClientList::searchByUsername(string &username) {
    auto it = this->clients.begin();
    for (; it != this->clients.end(); ++it){
        if((*it) == username){
            return it;
        }
    }
    return it;
}
list<Client> ClientList::getAll(){
    list<Client> newClientList (this->clients);
    return newClientList;
}

Client* ClientList::getByUsername(string &username) {
    auto it = searchByUsername(username);
    if(it != this->clients.end()){
        return &(*it);
    }
    return nullptr;
}

void ClientList::addClient(Client &client) {
    string username = client.getUsername();
    auto it = searchByUsername(username);
    if(it == this->clients.end()){
        this->clients.push_back(client);
    }else {
        string msg = "Client: " + username;
    }
}
