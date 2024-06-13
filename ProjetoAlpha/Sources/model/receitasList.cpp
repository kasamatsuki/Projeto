#include "receitaList.h"
#include "InvalidDataException.h"

// Função privada para buscar uma receita pelo nome
list<Receita>::iterator ReceitaList::search(const string& nomeReceita) {
    list<Receita>::iterator it = this->receitas.begin();
    for (; it != this->receitas.end(); ++it) {
        if (it->getNomeReceita() == nomeReceita) {
            return it;
        }
    }
    return it;
}

// Retorna todas as receitas
list<Receita> ReceitaList::getAll() const {
    return this->receitas;
}

// Obtém uma receita específica pelo nome
Receita* ReceitaList::get(const string& nomeReceita) {
    list<Receita>::iterator it = search(nomeReceita);
    if (it != this->receitas.end()) {
        return &(*it);
    }
    return nullptr;
}

// Adiciona uma nova receita
void ReceitaList::add(const Receita& receita) {
    list<Receita>::iterator it = search(receita.getNomeReceita());
    if (it == this->receitas.end()) {
        this->receitas.push_back(receita);
    } else {
        throw std::runtime_error("Receita já existe");
    }
}

// Remove uma receita pelo nome
void ReceitaList::remove(const string& nomeReceita) {
    list<Receita>::iterator it = search(nomeReceita);
    if (it != this->receitas.end()) {
        this->receitas.erase(it);
    }
}

// Atualiza uma receita existente
void ReceitaList::update(const string& nomeReceita, const string& descricao, const list<Ingrediente>& ingredientes, bool fav) {
    list<Receita>::iterator it = search(nomeReceita);
    if (it != this->receitas.end()) {
        it->setDescricao(descricao);
        it->setIngredientes(ingredientes);
        it->setFav(fav);  //
    }
}
