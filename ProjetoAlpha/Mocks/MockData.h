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
#include "../headers/model/ingredientesStock.h"
#include "../headers/model/favoritosList.h"

class MockData {
public:
    static std::vector<User> getusers();
    static std::vector<Receita> getReceitas();
    static std::vector<Ingrediente> getIngredientes();
    static std::vector<IngredienteStock> getIngredienteStock();
    static std::vector<Favorito> getFavoriteRecipes();
    static Preferencia getpreferencias();
};

#endif // MOCKDATA_H

#endif //MY_PROJECT_MOCKDATA_H