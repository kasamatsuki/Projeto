//
// Created by diogo on 03/06/2024.
//

#ifndef PROJETOALPHA_INGREDIENTESTOCK_H
#define PROJETOALPHA_INGREDIENTESTOCK_H

#include <string>
#include <iostream>
#include "ingrediente.h"

using namespace std;

class IngredienteStock {
private:
    Ingrediente ingrediente;
    int quantidade;

public:
    // Construtor
    IngredienteStock(const Ingrediente& ingrediente, int quantidade);

    // Construtor de cópia
    IngredienteStock(const IngredienteStock& ingrediente);

    // Destrutor
    ~IngredienteStock();

    // Getters
    const Ingrediente& getIngrediente() const;
    int getQuantidade() const;

    // Setters
    void setIngrediente(const Ingrediente& ingrediente);
    void setQuantidade(int quantidade);

    // Operadores de igualdade
    bool operator==(const IngredienteStock& obj) const;
    bool operator==(int nr) const;
};

#endif //PROJETOALPHA_INGREDIENTESTOCK_H
