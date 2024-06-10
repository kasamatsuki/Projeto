#ifndef PROJETOALPHA_RECEITALIST_H
#define PROJETOALPHA_RECEITALIST_H

#include <string>
#include <list>
#include "receita.h"

using namespace std;

class ReceitaList {
private:
    list<Receita> receitas;
    list<Receita>::iterator search(const string& nomeReceita);

public:
    // Get all receitas
    list<Receita> getAll() const;

    // Get receita by nomeReceita
    Receita* get(const string& nomeReceita);

    // Add a receita
    void add(const Receita& receita);

    // Remove a receita
    void remove(const string& nomeReceita);

    // Update a receita
    void update(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes, bool fav);
};

#endif //PROJETOALPHA_RECEITALIST_H
