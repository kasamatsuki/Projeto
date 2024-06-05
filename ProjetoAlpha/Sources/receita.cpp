#include "receita.h"
#include "InvalidDataException.h"

// Construtor que inicializa os membros da classe
Receita::Receita(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes_receita) {
    this->nomeReceita = nomeReceita;
    this->descricao = descricao;
    this->ingredientes_receita = ingredientes_receita;
}

// Construtor de cópia
Receita::Receita(const Receita& obj) {
    this->nomeReceita = obj.nomeReceita;
    this->descricao = obj.descricao;
    this->ingredientes_receita = obj.ingredientes_receita;
}

// Destrutor
Receita::~Receita() {
}

// Getter para o nome da receita
string Receita::getNomeReceita() const {
    return nomeReceita;
}

// Getter para a descrição da receita
string Receita::getDescricao() const {
    return descricao;
}

// Getter para a lista de ingredientes da receita
list<Ingrediente> Receita::getIngredientes() const {
    return ingredientes_receita;
}

// Setter para o nome da receita
void Receita::setNomeReceita(const string& nomeReceita) {
    this->nomeReceita = nomeReceita;
}

// Setter para a descrição da receita
void Receita::setDescricao(const string& descricao) {
    this->descricao = descricao;
}

// Setter para a lista de ingredientes da receita
void Receita::setIngredientes(const list<Ingrediente>& ingredientes_receita) {
    this->ingredientes_receita = ingredientes_receita;
}

// Adicionar um ingrediente à lista de ingredientes da receita
void Receita::addIngrediente(const Ingrediente& ingrediente) {
    ingredientes_receita.push_back(ingrediente);
}

// Remover um ingrediente da lista de ingredientes da receita
void Receita::removeIngrediente(const Ingrediente& ingrediente) {
    ingredientes_receita.remove(ingrediente);
}

// Operador de igualdade para comparar duas receitas
bool Receita::operator == (const Receita& obj) const {
    return this->nomeReceita == obj.nomeReceita &&
           this->descricao == obj.descricao &&
           this->ingredientes_receita == obj.ingredientes_receita;
}

// Operador de igualdade para comparar a receita com um nome de receita
bool Receita::operator == (const string& nomeReceita) const {
    return this->nomeReceita == nomeReceita;
}

