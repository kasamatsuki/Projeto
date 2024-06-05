//
// Created by vasco on 05/06/2024.
//

#ifndef HEADERS_VIEWS_VIEW_H_
#define HEADERS_VIEWS_VIEW_H_
#include <string>

using namespace std;

class View{
public:
    View();
    int menuPrincipal();
    int menuUser();
    int pesquisaReceitas();
    int ingredientesUser();
    int rating();
    int receitasFavoritas();
    int historico();


};

#endif //TRABALHO_DE_FSOFT_VIEW_H
