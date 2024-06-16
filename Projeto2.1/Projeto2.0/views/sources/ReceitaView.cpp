//
// Created by diogo on 16/06/2024.
//
#include "ReceitaView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

#define RESTRICAOSPACE 15

using namespace std;

Receita ReceitaView::getReceita() {
    string name;
    string descricao;
    IngredienteList ingredientes;

    bool fav;

    name = Utils::getString("Name");
    descricao = Utils::getString("Description");
    ingredientes = getIngredientesFromUser();
    Restricao restricao(Utils::getString("Restricao Name"));
    fav = Utils::getBool("Add to favorites? 1 - yes or 0 - no? ");

    Receita receita(name, descricao, ingredientes, restricao, fav);
    return receita;
}

void ReceitaView::printReceitaList(list<Receita> &receitas, const string& listTitle) {

    cout << listTitle << endl;
    cout << setw(20) << "Name";
    cout << setw(30) << "Description";
    cout << setw(20) << "Restriction";
    cout << setw(10) << "Favorite";
    cout << endl;

    for (auto it = receitas.begin(); it != receitas.end(); ++it) {
        cout << setw(20) << it->getNomeReceita();
        cout << setw(30) << it->getDescricao();
        cout << setw(20) << it->GetRestricao().getName();
        cout << setw(10) << (it->getFav() ? "Yes" : "No");
        cout << endl;
    }
}

void ReceitaView::printReceita(Receita *receita) {

        cout << "Name       : " << receita->getNomeReceita() << endl;
        cout << "Description: " << receita->getDescricao() << endl;
        cout << "Restriction: " << receita->GetRestricao().getName() << endl;
        cout << "Favorite   : " << (receita->getFav() ? "Yes" : "No") << endl;

        cout << "Ingredients:" << endl;
        auto ingredientes = receita->GetIngredientes().getAll();
        for (auto& ingrediente : ingredientes) {
            cout << " - " << ingrediente.getName() << endl;
        }
}




string ReceitaView::getName() {
    string name;
    bool flag;
    do {
        name = Utils::getString("Insert ingredient name"); // Solicita ao usuário o nome do ingrediente
        flag = false;
        if (name.empty()) { // Verifica se a string está vazia
            flag = true;
            invalidName(); // Chama a função para informar que o nome é inválido
        }
    } while (flag);
    return name; // Retorna o nome válido inserido pelo usuário
}

void ReceitaView::invalidName() {
    cout << "Invalid EAN";
}

IngredienteList ReceitaView::getIngredientesFromUser() {
    IngredienteList ingredientes;
    int numIngredientes = Utils::getUInt("Enter the number of ingredients: ");

    for (int i = 0; i < numIngredientes; ++i) {
        string nomeIngrediente = Utils::getString("Enter the ingredient name: ");
        int stock = Utils::getUInt("Enter the stock for the ingredient: ");
        bool isAvailable = Utils::getBool("Is the ingredient available? (1 for yes, 0 for no): ");

        Ingrediente ingrediente(nomeIngrediente, stock, isAvailable);
        ingredientes.add(ingrediente);
    }

    return ingredientes;
}
