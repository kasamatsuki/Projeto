//
// Created by vasco on 16/06/2024.
//
#include "MockData.h"
#include "user.h"
#include "receita.h"
#include "ingrediente.h"
#include "preferencias.h"

std::vector<user> MockData::getUsers() {
    std::vector<user> users;
    users.push_back(user("joao_silva", "João Silva", "joao@example.com"));
    users.push_back(user("maria_oliveira", "Maria Oliveira", "maria@example.com"));
    return users;
}

std::vector<receita> MockData::getReceitas() {
    std::vector<receita> receitas;
    receitas.push_back(receita("Pasta Carbonara", "Deliciosa pasta italiana com molho cremoso", 4.5));
    receitas.push_back(receita("Frango ao Curry", "Frango ao curry picante e saboroso", 4.7));
    return receitas;
}

std::vector<ingrediente> MockData::getIngredientes() {
    std::vector<ingrediente> ingredientes;
    ingredientes.push_back(ingrediente("Tomate", "Tomates vermelhos frescos", 2));
    ingredientes.push_back(ingrediente("Frango", "Peito de frango de criação livre", 5));
    return ingredientes;
}

std::vector<ingrediente> MockData::getIngredientesStock() {
    std::vector<ingrediente> ingredientesStock;
    ingredientesStock.push_back(ingrediente("Alho", "Dentes de alho frescos", 1));
    ingredientesStock.push_back(ingrediente("Cebola", "Cebolas amarelas", 3));
    return ingredientesStock;
}

std::vector<receita> MockData::getReceitasFavoritas() {
    std::vector<receita> receitasFavoritas;
    receitasFavoritas.push_back(receita("Bolo de Chocolate", "Bolo de chocolate rico e úmido", 4.8));
    return receitasFavoritas;
}

preferencias MockData::getPreferencias() {
    preferencias prefs;
    prefs.setDieta("Vegetariana");
    prefs.setCulinaria("Italiana");
    return prefs;
}