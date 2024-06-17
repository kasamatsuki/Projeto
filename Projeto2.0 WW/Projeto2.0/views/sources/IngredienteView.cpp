//
// Created by diogo on 16/06/2024.
//
#include "IngredienteView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>


#define RESTRICAOSPACE 15

using namespace std;

Ingrediente IngredienteView::getIngrediente() {
    string name;
    int stock;
    bool isAvailable;

    name = Utils::getString("Name");
    stock = Utils::getNumber("Stock");
    isAvailable = Utils::getBool("Is the product available? 1 - yes or 0 - no :  ");

    Ingrediente ingrediente(name, stock, isAvailable);
    return ingrediente;
}

void IngredienteView::printIngredienteList(list <Ingrediente> &ingredientes, const string& listTitle) {

    cout << listTitle << endl;
    cout << setw(30)<<"Name";
    cout << setw(30)<< "Stock" ;
    cout << setw(20)<< "Availability";
    cout << " |";

    cout << endl;
    for (auto it=ingredientes.begin(); it != ingredientes.end(); ++it){
        cout << setw(30) << it->getName();
        cout << setw(30)<< it->getStock();
        cout << setw(20) << ((it->getIsAvailable()) ? "Available" : "Unavailable");;
        cout << " " << it->getName() << endl;
    }

}

void IngredienteView::printIngrediente(Ingrediente* ingrediente, const string& listTitle) {

    cout << listTitle << endl;
    cout << "Name     : " << ingrediente->getName() << endl;
    cout << "Stock    : " <<  ingrediente->getStock() << endl;
    cout << "Available: "<< ingrediente->getIsAvailable()<<endl;

}


string IngredienteView::getName() {
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

void IngredienteView::invalidName() {
    cout << "Invalid Name";
}

