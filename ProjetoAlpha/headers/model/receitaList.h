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
    Receita* get(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes);

    // Add a receita
    void add(const Receita& receita);

    // Remove a receita
    void remove(const Receita& receita);

    // Update a receita
    void update(const Receita& receita);
};

#endif //PROJETOALPHA_RECEITALIST_H
