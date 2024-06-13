//
// Created by jppmm on 05/06/2024.
//


#ifndef HEADERS_VIEWS_INGREDIENTESVIEW_H_
#define HEADERS_VIEWS_INGREDIENTESVIEW_H_

#include <list>
#include "ingrediente.h"

    Class IngredientesView {public:
    Ingrediente getIngrediente(const std::list<Ingrediente>& ingredientes, const std::string& nome);
    void printIngrediente(const Ingrediente& ingrediente);
    void printIngredientes(const std::list<Ingrediente>& ingredientes);
};

#endif /* HEADERS_VIEWS_INGREDIENTESVIEW_H_ */
