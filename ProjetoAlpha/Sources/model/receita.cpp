/*
 * Receita.cpp
 *
 *  Created on: 03/06/2024
 *      Author: diogo
 */

#include "receita.h"
#include "InvalidDataException.h"


// Construtor
Receita::Receita(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes_receita) {
    setNomeReceita(nomeReceita);
    this->descricao = descricao;
    this->ingredientes_receita = ingredientes_receita;
    this->fav = false;
}

// Construtor de cópia
Receita::Receita(const Receita& obj) {
    setNomeReceita(obj.nomeReceita);
    this->descricao = obj.descricao;
    this->fav = obj.fav;
    this->ingredientes_receita = obj.ingredientes_receita;
}

// Destrutor
Receita::~Receita() {
}

// Getters
string Receita::getNomeReceita() const {
    return nomeReceita;
}

string Receita::getDescricao() const {
    return descricao;
}

bool Receita::isFav() const {
    return fav;
}

list<Ingrediente> Receita::getIngredientes() const {
    return ingredientes_receita;
}

// Setters
void Receita::setNomeReceita(const string& nomeReceita) {
        this->nomeReceita = nomeReceita;
}

void Receita::setDescricao(const string& descricao) {
    this->descricao = descricao;
}

void Receita::setFav(bool fav) {
    this->fav = fav;
}

void Receita::setIngredientes(const list<Ingrediente>& ingredientes_receita) {
    this->ingredientes_receita = ingredientes_receita;
}

// Adicionar um ingrediente
void Receita::addIngrediente(const Ingrediente& ingrediente) {
    ingredientes_receita.push_back(ingrediente);
}

// Remover um ingrediente
void Receita::removeIngrediente(const Ingrediente& ingrediente) {
    ingredientes_receita.remove(ingrediente);
}

// Operadores de igualdade
bool Receita::operator==(const Receita& obj) const {
    return this->nomeReceita == obj.nomeReceita;
}

bool Receita::operator==(const string& str) const {
    return this->nomeReceita == str;
}
