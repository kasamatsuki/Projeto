#include "ingrediente.h"

Ingrediente::Ingrediente(const std::string &name, int stock, bool isAvailable) {
    setIngredienteName(name);
    setStock(stock);
    if(isAvailable) {
        setAvailable();
    }else{
        setUnavailable();
    }
}

bool Ingrediente::operator==(string& name) const {
    if(this->name == name){
        return true;
    }return false;
}

void Ingrediente::setIngredienteName(const string &name)
{
    this->name = name;
}

void Ingrediente::setStock(int stock)
{
    this->stock = stock;
}

void Ingrediente::setAvailable()
{
    if(stock >0){
        this->isAvailable = true;
    }else{
        this->isAvailable = false;
    }

}

void Ingrediente::setUnavailable()
{
    if(stock >0){
        this->isAvailable = true;
    }else{
        this->isAvailable = false;
    }
}

bool Ingrediente::operator==(const Ingrediente &obj) const
{
    if (this->getName() == obj.getName())
        return true;
    return false;
}

const string &Ingrediente::getName() const {
    return this->name;
}

int Ingrediente::getStock() const {
    return this->stock;
}

bool Ingrediente::getIsAvailable() const {
    return this->isAvailable;
}

Ingrediente &Ingrediente::get() {
    return *this;
}
void Ingrediente::addStock(int quantity) {
    if (quantity > 0) {
        this->stock += quantity;
    }
}
