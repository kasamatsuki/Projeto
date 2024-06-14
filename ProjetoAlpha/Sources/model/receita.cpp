#include "receita.h"

// Construtor
Receita::Receita(const std::string& nomeReceita, const std::string& descricao, const std::list<Ingrediente>& ingredientes_receita, const Preferencia& preferencia_restricao) {
    setNomeReceita(nomeReceita);
    this->descricao = descricao;
    this->ingredientes_receita = ingredientes_receita;
    this->fav = false;
    this->preferencia_restricao = preferencia_restricao;
}

// Construtor de cópia
Receita::Receita(const Receita& obj) {
    setNomeReceita(obj.nomeReceita);
    this->descricao = obj.descricao;
    this->fav = obj.fav;
    this->ingredientes_receita = obj.ingredientes_receita;
    this->preferencia_restricao = obj.preferencia_restricao;
}

// Destrutor
Receita::~Receita() {
    // Aqui normalmente não teríamos nada específico para destruir, pois não há recursos alocados dinamicamente diretamente nesta classe
}

// Getters
std::string Receita::getNomeReceita() const {
    return nomeReceita;
}

std::string Receita::getDescricao() const {
    return descricao;
}

bool Receita::isFav() const {
    return fav;
}

std::list<Ingrediente> Receita::getIngredientes() const {
    return ingredientes_receita;
}

Preferencia Receita::getPreferencia_restricao() const {
    return preferencia_restricao;
}

// Setters
void Receita::setNomeReceita(const std::string& nomeReceita) {
    this->nomeReceita = nomeReceita;
}

void Receita::setDescricao(const std::string& descricao) {
    this->descricao = descricao;
}

void Receita::setFav(bool fav) {
    this->fav = fav;
}

void Receita::setIngredientes(const std::list<Ingrediente>& ingredientes_receita) {
    this->ingredientes_receita = ingredientes_receita;
}

void Receita::setPreferencia_restricao(const Preferencia& preferencia_restricao) {
    this->preferencia_restricao = preferencia_restricao;
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

bool Receita::operator==(const std::string& str) const {
    return this->nomeReceita == str;
}
