//
// Created by vasco on 05/06/2024.
//

#ifndef TRABALHO_DE_FSOFT_CONTROLLER_H
#define TRABALHO_DE_FSOFT_CONTROLLER_H

#include "../../headers/views/View.h"
#include "../../headers/views/registoView.h"
#include "../../headers/model/favoritosList.h"
#include "../../headers/model/ingredientesList.h"
#include "../../headers/model/ingredienteStockList.h"
#include "../../headers/model/preferenciasList.h"
#include "../../headers/model/receita.h"
#include "../../headers/views/utils.h"

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
