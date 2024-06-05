#include "Preferencias.h"
#include "InvalidDataException.h" // include do InvalidDataException


Preferencia::Preferencia(string preferencia_comida) {
    this->preferencia_comida = preferencia_comida;
}

Preferencia::Preferencia(const Preferencia& obj) {
    this->preferencia_comida = obj.preferencia_comida;
}

Preferencia::~Preferencia() {
    // Não há recursos dinâmicos para liberar, então está vazio
}

const string& Preferencia::getPreferencia_comida() const {
    return preferencia_comida;
}

void Preferencia::setPreferencia_comida(const string &preferencia_comida) {
    this->preferencia_comida = preferencia_comida;
}

bool Preferencia::operator == (const Preferencia& obj) const {
    return this->preferencia_comida == obj.preferencia_comida;
}

bool Preferencia::operator == (const string& str) const {
    return this->preferencia_comida == str;
}
