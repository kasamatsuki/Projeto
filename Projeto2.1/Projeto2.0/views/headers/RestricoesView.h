//
// Created by diogo on 16/06/2024.
//

#ifndef FOODFINDER_RESTRICOESVIEW_H
#define FOODFINDER_RESTRICOESVIEW_H


#include "restricoes.h"
#include "restricoesList.h"
#include "View.h"
#include <list>

class RestricoesView {
public:
    Restricao getRestricao(const string& name);
    void printRestricao(Restricao* restricao);
    void printRestricaoList(list<Restricao>& restricoes, const string& listTitle);


};



#endif //FOODFINDER_RESTRICOESVIEW_H
