//
// Created by diogo on 02/06/2024.
//

#include "ingredientesList.h"
#include "DuplicatedDataException.h"

// Método de busca
list<Ingrediente>::iterator ingredientesList::search(const string& nomeIngrediente) {
    list<Ingrediente>::iterator it = this->ingredientes.begin();
    for (; it != this->ingredientes.end(); ++it) {
        if (it->getNomeIngrediente() == nomeIngrediente) {
            return it;
        }
    }
    return it;
}

// Retorna todos os ingredientes
list<Ingrediente> ingredientesList::getAll() {
    list<Ingrediente> newlist(this->ingredientes);
    return newlist;
}

// Obtém um ingrediente pelo nome e descrição
Ingrediente* ingredientesList::get(const string& nomeIngrediente, const string& descricao) {
    list<Ingrediente>::iterator it = search(nomeIngrediente);
    if (it != this->ingredientes.end() && it->getDescricao() == descricao) {
        return &(*it);
    }
    return NULL;
}

// Adiciona um novo ingrediente
void ingredientesList::add(const Ingrediente& obj) {
    list<Ingrediente>::iterator it = search(obj.getNomeIngrediente());
    if (it == this->ingredientes.end()) {
        this->ingredientes.push_back(obj);
    } else {
        string msg = "Ingrediente: " + obj.getNomeIngrediente();
        throw DuplicatedDataException(msg);
    }
}

// Remove um ingrediente pelo nome
void ingredientesList::remove(const string& nomeIngrediente) {
    list<Ingrediente>::iterator it = search(nomeIngrediente);
    if (it != this->ingredientes.end()) {
        this->ingredientes.erase(it);
    }
}

// Atualiza a descrição de um ingrediente pelo nome
void ingredientesList::update(const string& nomeIngrediente, const string& descricao) {
    list<Ingrediente>::iterator it = search(nomeIngrediente);
    if (it != this->ingredientes.end()) {
        it->setDescricao(descricao);
    }
}
