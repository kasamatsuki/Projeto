//
// Created by jppmm on 13/06/2024.
//
#include "favoritosView.h"
#include <iostream>

using namespace std;

Favorito FavoritoView::getFavorito() {
    string favComida;
    cout << "Digite o nome da comida favorita: ";
    getline(cin, favComida);
    return Favorito(favComida);
}

void FavoritoView::printFavorito(const Favorito& favorito) const {
    cout << "Comida Favorita: " << favorito.getFavComida() << endl;
}

void FavoritoView::printFavoritos(const std::list<Favorito>& favoritos) const {
    for (const auto& favorito : favoritos) {
        printFavorito(favorito);
    }
}
