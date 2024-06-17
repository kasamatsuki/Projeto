

#include "FoodFinder.h"


using namespace std;

FoodFinder::FoodFinder() {
}

FoodFinder::FoodFinder(const std::string &name) {
    this->name = name;
}

string &FoodFinder::getName() {
    return name;
}

ClientList &FoodFinder::getClientList() {
    return this->clients;
}

IngredienteList &FoodFinder::getIngredienteList() {
    return this->ingredientes;
}

ReceitaList &FoodFinder::getReceitaList() {
    return this->receitas;
}

restricoesList &FoodFinder::getRestricoesList() {
    return this->restricoes;
}

