//
// Created by ricardo.franca on 24/05/2023.
//

#include <iostream>
#include "ingredienteList.h"

list<Ingrediente>::iterator IngredienteList::search(const string& name) {
    auto it = this->ingredientes.begin();
    for (; it != this->ingredientes.end(); ++it){
        if((it->getName()) == name){
            return it;
        }
    }
    return it;
}

list<Ingrediente>::iterator IngredienteList::search(const Ingrediente &obj) {
    auto it = this->ingredientes.begin();
    for (; it != this->ingredientes.end(); ++it){
        if((it->getName()) == obj.getName()){
            return it;
        }
    }
    return it;}

list<Ingrediente> IngredienteList::getAll() {
    list<Ingrediente> newIngredientesList (this->ingredientes);
    return newIngredientesList;
}

Ingrediente* IngredienteList::getName(const std::string &name){
    auto it = search(name);
    if(it != this->ingredientes.end()){
        return &(*it);
    }
    return nullptr;
}

void IngredienteList::add(Ingrediente obj) {
    auto it = search(obj);
    if(it == this->ingredientes.end()){
        this->ingredientes.push_back(obj);
    }else{
        string msg = "Ingrediente: " + obj.getName();
    }
}

void IngredienteList::edit(const std::string &name, int stock, bool isAvailable) {
    list<Ingrediente>::iterator it = search(name);
    if(it != this->ingredientes.end()) {
        it->setIngredienteName(name);
        it->setStock(stock);
        if(isAvailable){
            it->setAvailable();
        }else{
            it->setUnavailable();
        }
    }
}


IngredienteList IngredienteList::getAvailable(){
    IngredienteList returnIngredienteList;
    auto it = this->ingredientes.begin();
    for (; it != this->ingredientes.end(); ++it){
        if(it->getIsAvailable() && it->getStock() > 0){
            Ingrediente tempIngrediente = it->get();
            returnIngredienteList.add(tempIngrediente);
        }
    }
    return returnIngredienteList;
}

void IngredienteList::remove(const Ingrediente &obj) {
    auto it = search(obj);
    if(it != this->ingredientes.end()){
        this->ingredientes.erase(it);
        return;
    }

    cout << "Ingrediente not found in list.\n";
}

void IngredienteList::reset() {
    this->ingredientes.clear();
}

void IngredienteList::addStock(const std::string& name, int quantity) {
    auto it = search(name);
    if (it != ingredientes.end()) {
        it->addStock(quantity);
    } else {
        std::cout << "Ingredient not found." << std::endl;
    }
}
void IngredienteList::removeStock(const std::string& name, int quantity) {
    auto it = search(name);
    if (it != ingredientes.end()) {
        if (it->getStock() >= quantity) {
            it->setStock(it->getStock() - quantity);
        } else {
            std::cout << "Insufficient stock. Stock not updated." << std::endl;
        }
    } else {
        std::cout << "Ingredient not found." << std::endl;
    }
}
