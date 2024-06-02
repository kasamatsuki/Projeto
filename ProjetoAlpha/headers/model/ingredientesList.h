//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_INGREDIENTESLIST_H
#define PROJETOALPHA_INGREDIENTESLIST_H

#include <string>
#include <iostream>
#include "ingredientes.h"
#include <vector>
#include <list>

using namespace std;

class ingredientesList{
private:
    vector<Ingrediente> ingredientes;
    int search(const string& nomeIngrediente);

public:
    list<Ingrediente> getAll();
    Ingrediente* get(const string& nomeIngrediente,const string& descricao);
    void add(const Ingrediente& obj);
    void remove(const string& nomeIngrediente);
    void update(const string& nomeIngrediente,const string& descricao);
};




#endif //PROJETOALPHA_INGREDIENTESLIST_H
