//
// Created by jppmm on 13/06/2024.
//
#include "IngredientesView.h"
#include <iostream>

using namespace std;

Ingrediente IngredientesView::getIngrediente() {
    string nome, descricao;
    cout << "Digite o nome do ingrediente: ";
    getline(cin, nome);
    cout << "Digite a descrição do ingrediente: ";
    getline(cin, descricao);
    return Ingrediente(nome, descricao);
}

void IngredientesView::printIngrediente(const Ingrediente& ingrediente) const {
    cout << "Nome: " << ingrediente.getNomeIngrediente() << endl;
    cout << "Descrição: " << ingrediente.getDescricao() << endl;
}

void IngredientesView::printIngredientes(const std::list<Ingrediente>& ingredientes) const {
    for (const auto& ingrediente : ingredientes) {
        printIngrediente(ingrediente);
    }
}
