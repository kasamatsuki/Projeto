
#include "Ingredientes.h"
#include "InvalidDataException.h"


// Construtor que inicializa as propriedades do ingrediente
Ingrediente::Ingrediente(const string& nomeIngrediente, const string descricao) {
    this->nomeIngrediente = nomeIngrediente;
    this->descricao = descricao;
}

// Construtor de cópia
Ingrediente::Ingrediente(const Ingrediente& ingredientes) {
    this->nomeIngrediente = ingredientes.nomeIngrediente;
    this->descricao = ingredientes.descricao;
}

// Destrutor
Ingrediente::~Ingrediente() {

}

// Método que retorna o nome do ingrediente
const string& Ingrediente::getNomeIngrediente() const {
    return nomeIngrediente;
}

// Método que define o nome do ingrediente
void Ingrediente::setNomeIngrediente(const string &nomeIngrediente) {
    this->nomeIngrediente = nomeIngrediente;
}

// Método que retorna a descrição do ingrediente
const string& Ingrediente::getDescricao() const {
    return descricao;
}

// Método que define a descrição do ingrediente
void Ingrediente::setDescricao(const string &descricao) {
    this->descricao = descricao;
}

// Operador de igualdade para comparar dois ingredientes
bool Ingrediente::operator == (const Ingrediente& obj) const {
    return this->nomeIngrediente == obj.nomeIngrediente;
}

bool Ingrediente::operator == (int nr) const {
    return false;
}
