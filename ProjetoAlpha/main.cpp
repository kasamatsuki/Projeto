//============================================================================
// Name        : main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "Mocks/MockData.h"


int main() {
    FoodFinder app;
    app.setUsers(MockData::getUsers());
    app.setReceitas(MockData::getReceitas());
    app.setIngredientes(MockData::getIngredientes());
    app.setIngredientesStock(MockData::getIngredientesStock());
    app.setReceitasFavoritas(MockData::getReceitasFavoritas());
    app.setPreferencias(MockData::getPreferencias());

    Controller controller(app);
    controller.run();

    return 0;
}

