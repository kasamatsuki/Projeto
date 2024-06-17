//
// Created by diogo on 16/06/2024.
//

#ifndef FOODFINDER_INGREDIENTEVIEW_H
#define FOODFINDER_INGREDIENTEVIEW_H


#include "ingrediente.h"
#include "ingredienteList.h"
#include "View.h"

class IngredienteView {
public:
    Ingrediente getIngrediente();
    void printIngrediente(Ingrediente* ingrediente, const string& listTitle);
    void printIngredienteList(list<Ingrediente>& ingredientes, const string& listTitle);
    string getName();
    void invalidName();

};



#endif //FOODFINDER_INGREDIENTEVIEW_H
