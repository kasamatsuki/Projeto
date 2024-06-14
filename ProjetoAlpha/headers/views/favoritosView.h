//
// Created by jppmm on 13/06/2024.
//
#ifndef HEADERS_VIEWS_FAVORITOVIEW_H_
#define HEADERS_VIEWS_FAVORITOVIEW_H_

#include <list>
#include "favoritos.h"

class FavoritoView {
public:
    Favorito getFavorito();
    void printFavorito(const Favorito& favorito) const;
    void printFavoritos(const std::list<Favorito>& favoritos) const;
};

#endif /* HEADERS_VIEWS_FAVORITOVIEW_H_ */

