//
// Created by vasco on 16/06/2024.
//
#include "MockData.h"

std::vector<User> MockData::getusers() {
    std::vector<User> users;
    users.push_back(User(1,"João Silva", "joao@example.com", "vasco123"));
    users.push_back(User(2,"Maria Oliveira", "maria@example.com", "vasco123"));
    return users;
}

std::vector<Receita> MockData::getReceitas() {
    std::vector<Receita> receitas;
    receitas.push_back(Receita("Pasta Carbonara", "Deliciosa pasta italiana com molho cremoso", 4.5));
    receitas.push_back(Receita("Frango ao Curry", "Frango al curry picante e saboroso", 4.7));
    return receitas;
}

std::vector<Ingrediente> MockData::getIngredientes() {
    std::vector<Ingrediente> ingredientes;
    ingredientes.push_back(Ingrediente("Tomate", "Tomates vermelhos frescos"));
    ingredientes.push_back(Ingrediente("Frango", "Peito de frango de criação livre"));
    return ingredientes;
}

std::vector<IngredienteStock> MockData::getIngredienteStock() {
    std::vector<IngredienteStock> ingredienteStock;
    ingredienteStock.push_back(Ingrediente("Alho", "Dentes de alho frescos"));
    ingredienteStock.push_back(Ingrediente("Cebola", "Cebolas amarelas"));
    return ingredienteStock;
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