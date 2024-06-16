#include "restricoes.h"

Restricao::Restricao(const std::string &name) {
    setName(name);
}

string Restricao::getName() const{
    return name;
}

void Restricao::setName(const string &pName) {
    this->name = pName;
}

bool Restricao::operator==(const Restricao &obj) const {
    if(this->getName() == obj.getName()){
        return true;
    }return false;
}

bool Restricao::operator==(string &name) const {
    if(this->name == name){
        return true;
    }return false;
}