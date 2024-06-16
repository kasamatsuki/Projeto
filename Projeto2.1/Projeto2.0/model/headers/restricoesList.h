//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_RESTRICOESLIST_H
#define MY_PROJECT_RESTRICOESLIST_H
#include <list>
#include "restricoes.h"

class restricoesList{
private:
    list<Restricao> restricoes;
    list<Restricao>::iterator searchByName(string &name);
public:
    Restricao* getByName(string& name);
    list<Restricao> getAll();
    void addRestricoes(const Restricao& restricao);
    void removeRestricoes(const Restricao& restricao);
};
#endif //MY_PROJECT_RESTRICOESLIST_H
