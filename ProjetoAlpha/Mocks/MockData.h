//
// Created by vasco on 16/06/2024.
//

#ifndef MY_PROJECT_MOCKDATA_H
#define MY_PROJECT_MOCKDATA_H
#ifndef MOCKDATA_H
#define MOCKDATA_H

#include <vector>
#include "../headers/model/user.h"
#include "../headers/model/receita.h"
#include "../headers/model/ingrediente.h"
#include "../headers/model/preferencias.h"

class MockData {
public:
    static std::vector<User> getusers();
    static std::vector<receita> getrecitas();
    static std::vector<ingrediente> getingredients();
    static std::vector<ingredientesStock> getIngredientsStock();
    static std::vector<favoritos> getFavoriteRecipes();
    static preferencias getpreferencias();
};

#endif // MOCKDATA_H

#endif //MY_PROJECT_MOCKDATA_H