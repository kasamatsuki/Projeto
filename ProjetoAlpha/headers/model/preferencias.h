//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_PREFERENCIAS_H
#define PROJETOALPHA_PREFERENCIAS_H


#include <string>
#include <iostream>

using namespace std;


class Preferencia {
private:
    string preferencia_comida;

public:
    Preferencia(string preferencia_comida);
    Preferencia(const Preferencia& obj);

    Preferencia();

    ~Preferencia();

    const string& getPreferencia_comida() const;
    void setPreferencia_comida(const string &preferencia_comida);



    bool operator == (const Preferencia& obj) const;
    bool operator == (const string& str) const;
};
#endif //PROJETOALPHA_PREFERENCIAS_H
