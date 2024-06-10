#ifndef PROJETOALPHA_RECEITA_H
#define PROJETOALPHA_RECEITA_H

#include <string>
#include <list>
#include "ingrediente.h"

using namespace std;

class Receita {
private:
    string nomeReceita;
    string descricao;
    bool fav;
    list<Ingrediente> ingredientes_receita;


public:
    // Construtor
    Receita(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes_receita);

    // Construtor de cópia
    Receita(const Receita& obj);

    // Destrutor
    ~Receita();

    // Getters
    string getNomeReceita() const;
    string getDescricao() const;
    bool isFav() const;
    list<Ingrediente> getIngredientes() const;

    // Setters
    void setNomeReceita(const string& nomeReceita);
    void setDescricao(const string& descricao);
    void setFav(bool fav);
    void setIngredientes(const list<Ingrediente>& ingredientes_receita);

    // Adicionar um ingrediente
    void addIngrediente(const Ingrediente& ingrediente);

    // Remover um ingrediente
    void removeIngrediente(const Ingrediente& ingrediente);

    // Operadores de igualdade
    bool operator==(const Receita& obj) const;
    bool operator==(const string& str) const;
};

#endif //PROJETOALPHA_RECEITA_H
