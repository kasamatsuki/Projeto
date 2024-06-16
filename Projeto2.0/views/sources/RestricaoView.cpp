
//
// Created by diogo on 16/06/2024.
//
#include "RestricoesView.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>

using namespace std;

#define RESTRICAOSPACE 15

Restricao RestricoesView::getRestricao(const string& name) {

    return Utils::getString("Insert resctrition name");


}

void RestricoesView::printRestricao(Restricao* restricao) {
    int w = RESTRICAOSPACE;

    cout << setw(w) << restricao->getName();
}

void RestricoesView::printRestricaoList(list<Restricao>& restricoes, const string& listTitle) {
    int w = RESTRICAOSPACE;

    cout << listTitle << endl;
    cout << "\nResctrition List:" << endl;
    cout << setw(w)<< "\nName";
    cout << endl;
    for (auto it=restricoes.begin(); it != restricoes.end(); ++it){
        printRestricao(&*it);
    }
}

