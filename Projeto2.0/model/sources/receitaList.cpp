

#include "receitaList.h"

list<Receita>::iterator ReceitaList::searchByName(string &name) {
    auto it = this->receitas.begin();
    for (; it != this->receitas.end(); ++it){
        if((*it) == name){
            return it;
        }
    }
    return it;
}
list<Receita> ReceitaList::getAll(){
    list<Receita> newReceitaList (this->receitas);
    return newReceitaList;
}

Receita* ReceitaList::getByName(string &name) {
    auto it = searchByName(name);
    if(it != this->receitas.end()){
        return &(*it);
    }
    return nullptr;
}

void ReceitaList::addReceita(Receita& receita) {
    string nomeReceita = receita.getNomeReceita();
    auto it = searchByName(nomeReceita);
    if(it == this->receitas.end()){
        this->receitas.push_back(receita);
    } else {
        std::string msg = "Receita: " + nomeReceita + " já existe.";
        throw DuplicateEntryException(msg);
    }
}

void ReceitaList::removeReceita(Receita& receita) {
    string nomeReceita = receita.getNomeReceita();
    auto it = searchByName(nomeReceita);
    if(it != this->receitas.end()){
        this->receitas.erase(it);
    }
}