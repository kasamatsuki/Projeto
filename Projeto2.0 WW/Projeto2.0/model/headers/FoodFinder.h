//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_FOODFINDER_H
#define MY_PROJECT_FOODFINDER_H

#include "ClientList.h"
#include "ingredienteList.h"
#include "receitaList.h"
#include "restricoesList.h"


using namespace std;

class FoodFinder{
private:
    string name;
    ClientList clients;
    IngredienteList ingredientes;
    ReceitaList receitas;
    restricoesList restricoes;
public:

    FoodFinder();
    FoodFinder(const string& name);
    string& getName();

    ClientList& getClientList();
    IngredienteList& getIngredienteList();
    ReceitaList& getReceitaList();
    restricoesList& getRestricoesList();



};
#endif //MY_PROJECT_FOODFINDER_H
