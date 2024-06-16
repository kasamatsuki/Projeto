//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_INGREDIENTES_H
#define PROJETOALPHA_INGREDIENTES_H

#include <string>
#include <iostream>

using namespace std;

class Ingrediente {
private:

    string nomeIngrediente;
    string descricao;

public:
    Ingrediente(const string& nomeIngrediente,const string& descricao);
    Ingrediente(const Ingrediente& ingredientes);
    ~Ingrediente();

    const string& getNomeIngrediente() const;
    void setNomeIngrediente(const string &nomeIngrediente);
    //
    const string& getDescricao() const;
    void setDescricao(const string &descricao);

    bool operator == (const Ingrediente& obj) const;
    bool operator == (int nr) const;
};



#endif //PROJETOALPHA_INGREDIENTES_H
