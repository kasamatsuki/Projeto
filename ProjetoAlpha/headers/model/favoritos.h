//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_FAVORITOS_H
#define PROJETOALPHA_FAVORITOS_H

#include <string>
#include <iostream>

using namespace std;

class Favorito {
private:
    string FavComida;

public:
    Favorito(string FavComida);
    Favorito(const Favorito& obj);
    ~Favorito();

    const string& getFavComida() const;
    void setFavComida(const string &FavComida);



    bool operator == (const Favorito& obj) const;
    bool operator == (const string& str) const;
};


#endif //PROJETOALPHA_FAVORITOS_H
