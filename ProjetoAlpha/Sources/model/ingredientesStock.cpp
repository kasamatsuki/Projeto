//
// Created by diogo on 03/06/2024.
//

#include "ingredientesStock.h"

// Construtor
IngredienteStock::IngredienteStock(const Ingrediente& ingrediente, int quantidade)
        : ingrediente(ingrediente), quantidade(quantidade) {}

// Construtor de cópia
IngredienteStock::IngredienteStock(const IngredienteStock& ingredienteStock)
        : ingrediente(ingredienteStock.ingrediente), quantidade(ingredienteStock.quantidade) {}

// Destrutor
IngredienteStock::~IngredienteStock() {}

// Getters
const Ingrediente& IngredienteStock::getIngrediente() const {
    return ingrediente;
}

int IngredienteStock::getQuantidade() const {
    return quantidade;
}

// Setters
void IngredienteStock::setIngrediente(const Ingrediente& ingrediente) {
    this->ingrediente = ingrediente;
}

void IngredienteStock::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

// Operadores de igualdade
bool IngredienteStock::operator==(const IngredienteStock& obj) const {
    return (this->ingrediente == obj.ingrediente) && (this->quantidade == obj.quantidade);
}

bool IngredienteStock::operator==(int nr) const {
    return this->quantidade == nr;
}