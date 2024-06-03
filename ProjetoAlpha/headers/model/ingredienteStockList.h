#ifndef PROJETOALPHA_INGREDIENTESLIST_H
#define PROJETOALPHA_INGREDIENTESLIST_H

#include <string>
#include <iostream>
#include "ingredientesStock.h"
#include <vector>
#include <list>

using namespace std;

class IngredientesStockList {
private:
    list<IngredienteStock> ingredientesStockList;
    list<IngredienteStock>::iterator search(const string& nomeIngrediente);

public:
    list<IngredienteStock> getAll();
    IngredienteStock* get(const string& nomeIngrediente, const int& quantidade);
    void add(const IngredienteStock& ingrediente_stock);
    void remove(const IngredienteStock& ingrediente_stock);
    void update(const IngredienteStock& ingrediente_stock);
};

#endif //PROJETOALPHA_INGREDIENTESLIST_H