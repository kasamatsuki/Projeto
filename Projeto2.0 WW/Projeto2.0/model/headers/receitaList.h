//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_RECEITALIST_H
#define MY_PROJECT_RECEITALIST_H

#include <list>
#include "receita.h"

class ReceitaList {
private:
    list<Receita> receitas;

    list<Receita>::iterator searchByName(string& name);

public:
    list<Receita> getAll();
    Receita* getByName(string& name);
    void addReceita(Receita& receita);
    void removeReceita(Receita& receita);


};
#endif //MY_PROJECT_RECEITALIST_H
