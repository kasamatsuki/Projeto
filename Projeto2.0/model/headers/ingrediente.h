//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_INGREDIENTE_H
#define MY_PROJECT_INGREDIENTE_H
#include <string>

using namespace std;

class Ingrediente{
private:
    string name;
    int stock;
    bool isAvailable{};
public:
    Ingrediente(const string& name,int stock,bool isAvailable);

    void setIngredienteName(const string& name);
    void setStock(int stock);
    void setAvailable();
    void setUnavailable();
    void toggleAvailability();

    Ingrediente& get();
    const string& getName() const;
    int getStock() const;
    bool getIsAvailable() const;

    bool operator == (string& ean) const;
    bool operator == (const Ingrediente &obj) const;

};
#endif //MY_PROJECT_INGREDIENTE_H
