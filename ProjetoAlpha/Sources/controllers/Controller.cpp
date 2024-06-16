#include <iostream>
#include <string>
#include "../../headers/controllers/controller.h"
#include "Utils.h"
#include "DataConsistencyException.h"
#include "User.h"
#include "../../headers/model/receita.h"
#include "../../headers/model/ingrediente.h"
#include "FoodFinder.h"
using namespace std;

Controller::Controller(FoodFinder& app) {
    this->app = app;
}

void Controller::run() {
    int op = -1;
    do {
        op = this->view.menuPrincipal();
        switch(op) {
            case 1: runUsers();
                break;
            case 2: runReceitas();
                break;
            case 3: runIngredientes();
                break;
            case 4: runIngredientesStock();
                break;
            case 5: runFavoritos();
                break;
            case 6: runPreferencias();
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runUsers() {
    int op = -1;
    do {
        op = this->view.menuUser();
        switch(op) {
            case 1: {
                User user = this->RegistoView.getUser();
                this->app.addUser(user);
            }
                break;
            case 2: {
                string username = Utils::getString("Introduza o username");
                User* user = this->app.getUser(username);
                if(user != NULL) {
                    this->RegistoView.printUser(user);
                } else {
                    cout << "O utilizador [" << username << "] nao existe." << endl;
                }
            }
                break;
            case 3: {
                string username = Utils::getString("Introduza o username");
                this->app.removeUser(username);
            }
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runReceitas() {
    int op = -1;
    do {
        op = this->view.pesquisaReceitas();
        switch(op) {
            case 1: {
                Recipe recipe = this->recList.getRecipe();
                this->app.addRecipe(recipe);
            }
                break;
            case 2: {
                string name = Utils::getString("Introduza o nome da receita");
                Recipe* recipe = this->app.getRecipe(name);
                if(recipe != NULL) {
                    this->recList.printRecipe(recipe);
                } else {
                    cout << "A receita [" << name << "] nao existe." << endl;
                }
            }
                break;
            case 3: {
                string name = Utils::getString("Introduza o nome da receita");
                this->app.removeRecipe(name);
            }
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runIngredientes() {
    int op = -1;
    do {
        op = this->view.ingredientesUser();
        switch(op) {
            case 1: {
                Ingredient ingredient = this->ingrList.getIngredient();
                this->app.addIngredient(ingredient);
            }
                break;
            case 2: {
                string name = Utils::getString("Introduza o nome do ingrediente");
                Ingredient* ingredient = this->app.getIngredient(name);
                if(ingredient != NULL) {
                    this->ingrList.printIngredient(ingredient);
                } else {
                    cout << "O ingrediente [" << name << "] nao existe." << endl;
                }
            }
                break;
            case 3: {
                string name = Utils::getString("Introduza o nome do ingrediente");
                this->app.removeIngredient(name);
            }
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runIngredientesStock() {
    int op = -1;
    do {
        op = this->view.menuIngredientesStock();
        switch(op) {
            case 1: {
                Ingredient ingredient = this->ingrStockList.getIngredient();
                this->app.addIngredientToStock(ingredient);
            }
                break;
            case 2: {
                string name = Utils::getString("Introduza o nome do ingrediente no stock");
                Ingredient* ingredient = this->app.getIngredientFromStock(name);
                if(ingredient != NULL) {
                    this->ingrStockList.printIngredient(ingredient);
                } else {
                    cout << "O ingrediente [" << name << "] nao existe no stock." << endl;
                }
            }
                break;
            case 3: {
                string name = Utils::getString("Introduza o nome do ingrediente");
                this->app.removeIngredientFromStock(name);
            }
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runFavoritos() {
    int op = -1;
    do {
        op = this->view.receitasFavoritas();
        switch(op) {
            case 1: {
                Recipe recipe = this->favList.getRecipe();
                this->app.addRecipeToFavorites(recipe);
            }
                break;
            case 2: {
                string name = Utils::getString("Introduza o nome da receita favorita");
                Recipe* recipe = this->app.getFavoriteRecipe(name);
                if(recipe != NULL) {
                    this->favList.printRecipe(recipe);
                } else {
                    cout << "A receita favorita [" << name << "] nao existe." << endl;
                }
            }
                break;
            case 3: {
                string name = Utils::getString("Introduza o nome da receita favorita");
                this->app.removeRecipeFromFavorites(name);
            }
                break;
            default:
                break;
        }
    } while(op != 0);
}

void Controller::runPreferencias() {
    int op = -1;
    do {
        op = this->view.h
