//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_FAVORITOSLIST_H
#define PROJETOALPHA_FAVORITOSLIST_H

#include <string>
#include <iostream>
#include "favoritos.h"
#include <vector>
#include <list>

using namespace std;

class favoritosList{
private:
    vector<Favorito> favoritos;
    int search(const string& FavComida);

public:
    list<Favorito> getAll();
    Favorito* get(const string& preferencia_comida);
    void add(const Favorito& obj);
    void remove(const string& FavComida);
    void update(const string& FavComida);
};


#endif //PROJETOALPHA_FAVORITOSLIST_H
