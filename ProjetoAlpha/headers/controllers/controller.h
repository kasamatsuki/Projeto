//
// Created by vasco on 05/06/2024.
//

#ifndef TRABALHO_DE_FSOFT_CONTROLLER_H
#define TRABALHO_DE_FSOFT_CONTROLLER_H

#include "../../headers/views/View.h"
#include "registoView.h"
#include "favoritosList.h"
#include "ingredientesList.h"
#include "../../headers/model/ingredienteStockList.h"
#include "preferenciasList.h"
#include "receitaList.h"
#include "utils.h"
#include "FoodFinder.h"

class Controller {
private:
    RegistoView RegistoView;
    View view;
    favoritosList favList;
    ingredientesList ingrList;
    ingredientesList ingrStockList;
    preferenciasList prefList;
    ReceitaList recList;
    FoodFinder app;

    void runUsers();
    void runFavoritos();
    void runIngredientes();
    void runIngredientesStock();
    void runPreferencias();
    void runReceitas();

public:
    Controller(FoodFinder& app);
    void run();
};

#endif //TRABALHO_DE_FSOFT_CONTROLLER_H
