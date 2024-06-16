//
// Created by diogo on 16/06/2024.
//

#ifndef MY_PROJECT_CONTROLLER_H
#define MY_PROJECT_CONTROLLER_H

#include "View.h"
#include "FoodFinder.h"
#include "ReceitaView.h"
#include "IngredienteView.h"
#include "RestricoesView.h"
#include "utils.h"
#include "ClientView.h"

using namespace std;

class Controller{
private:
    FoodFinder             model;
    View                view;
    ReceitaView     receitaView;
    ClientView          clientView;
    IngredienteView         ingredienteView;
    RestricoesView   restricoesView;


    User*               loggedUser{};




    void runLogin();
    void runCreateAccount();

    void runGeral();
    void runUser();
    void runReceitas();
    void runIngredientes();
    void runRestricoes();


    void runCreateReceita();



    void login(User* pUser);
    void logout();

    //Others
    bool isManagerLoggedIn();


public:
    explicit Controller(FoodFinder& foodFinder);
    void run();

};


#endif //MY_PROJECT_CONTROLLER_H
