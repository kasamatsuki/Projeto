//
// Created by vasco on 05/06/2024.
//

#ifndef TRABALHO_DE_FSOFT_CONTROLLER_H
#define TRABALHO_DE_FSOFT_CONTROLLER_H
#include "Views.h"
#include "registoView.h"
#include "favoritosList.h"
#include "ingredientesList.h"
#include "IngredientesStockList.h"
#include "preferenciasList.h"
#include "ReceitaList.h"
#include "utils.h"

class Controller{

private:
    registoView RegistoView;
    View view;
    favoritosList favList;
    ingredientesList ingrList;
    IngredientesStockList ingrStockList;
    preferenciasList prefList;
    ReceitaList recList;


    void runFavoritos();
    void runIngredientes();
    void runIngredientesStock();
    void runPreferencias();
    void runReceitas();



public:
    //Falta criar a App.h que será onde tem os containers todos Controller(App& app);
    void run();
};
#endif //TRABALHO_DE_FSOFT_CONTROLLER_H
