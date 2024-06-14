//
// Created by jppmm on 13/06/2024.
//
#include "preferenciasView.h"
#include <iostream>

using namespace std;

Preferencia PreferenciaView::getPreferencia() {
    string preferenciaComida;
    cout << "Digite o nome da preferência de comida: ";
    getline(cin, preferenciaComida);
    return Preferencia(preferenciaComida);
}

void PreferenciaView::printPreferencia(const Preferencia& preferencia) const {
    cout << "Preferência de Comida: " << preferencia.getPreferencia_comida() << endl;
}

void PreferenciaView::printPreferencias(const std::list<Preferencia>& preferencias) const {
    for (const auto& preferencia : preferencias) {
        printPreferencia(preferencia);
    }
}
