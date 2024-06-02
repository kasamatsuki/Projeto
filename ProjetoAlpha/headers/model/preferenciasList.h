//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_PREFERENCIASLIST_H
#define PROJETOALPHA_PREFERENCIASLIST_H

#include <string>
#include <iostream>
#include "preferencias.h"
#include <vector>
#include <list>

using namespace std;

class preferenciasList{
private:
    vector<Preferencia> preferencias;
    int search(const string& preferencia_comida);

public:
    list<Preferencia> getAll();
    Preferencia* get(const string& preferencia_comida);
    void add(const Preferencia& obj);
    void remove(const string& preferencia_comida);
    void update(const string& preferencia_comida);
};





#endif //PROJETOALPHA_PREFERENCIASLIST_H
