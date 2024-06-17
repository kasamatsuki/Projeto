#include "restricoesList.h"

list<Restricao> restricoesList::getAll() {
    list<Restricao> newSupplierList (this->restricoes);
    return newSupplierList;
}

list<Restricao>::iterator restricoesList::searchByName(string &name) {
    auto it = this->restricoes.begin();
    for (; it != this->restricoes.end(); ++it){
        if((*it) == name){
            return it;
        }
    }
    return it;
}

Restricao *restricoesList::getByName(string& name) {
    auto it = searchByName(name);
    if(it != this->restricoes.end()){
        return &(*it);
    }
    return nullptr;
}

void restricoesList::addRestricoes(const Restricao &restricao) {
    string name = restricao.getName();
    auto it = searchByName(name);
    if(it == this->restricoes.end()){
        this->restricoes.push_back(restricao);
    }else {
        string msg = "Restricion: " + name;
    }
}

void restricoesList::removeRestricoes(const Restricao &restricao) {
    string name = restricao.getName();
    auto it = searchByName(name);
    if (it != restricoes.end()) {
        restricoes.erase(it);
    }
}



