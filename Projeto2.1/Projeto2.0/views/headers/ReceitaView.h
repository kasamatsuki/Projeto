//
// Created by diogo on 16/06/2024.
//

#ifndef FOODFINDER_RECEITASVIEW_H
#define FOODFINDER_RECEITASVIEW_H


#include "receita.h"
#include "receitaList.h"
#include "View.h"

class ReceitaView {
public:
    Receita getReceita();
    void printReceita(Receita* receita);
    void printReceitaList(list<Receita>& receitas, const string& listTitle);
    string getName();
    void invalidName();
    IngredienteList getIngredientesFromUser();
};


#endif //FOODFINDER_RECEITASVIEW_H
