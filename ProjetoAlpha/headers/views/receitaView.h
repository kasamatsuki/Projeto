//
// Created by jppmm on 13/06/2024.
//

#ifndef HEADERS_VIEWS_RECEITAVIEW_H_
#define HEADERS_VIEWS_RECEITAVIEW_H_

#include <list>
#include "receita.h"

class ReceitaView {
public:
    Receita getReceita();
    void printReceita(const Receita& receita) const;
    void printReceitas(const std::list<Receita>& receitas) const;
};

#endif /* HEADERS_VIEWS_RECEITAVIEW_H_ */
