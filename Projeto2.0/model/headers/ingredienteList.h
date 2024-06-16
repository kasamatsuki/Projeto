//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_INGREDIENTELIST_H
#define MY_PROJECT_INGREDIENTELIST_H

#include <list>
#include "ingrediente.h"
#include "DuplicateEntryException.h"

//In the future add (or not) code to verify if the product is in a client cart

class IngredienteList{
private:
    list<Ingrediente> ingredientes;
    list<Ingrediente>::iterator search(const string& name);
    list<Ingrediente>::iterator search(const Ingrediente& obj);
public:
    list<Ingrediente> getAll();
    IngredienteList getAvailable();
    Ingrediente* getName(const string& name);
    void add(Ingrediente obj);
    void edit(const string& name,int stock,bool isAvailable);
    void remove(const Ingrediente& obj);

    void reset();
};

#endif //MY_PROJECT_INGREDIENTELIST_H
