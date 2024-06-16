//
// Created by diogo on 15/06/2024.
//

#ifndef MY_PROJECT_RESTRICOES_H
#define MY_PROJECT_RESTRICOES_H
#include <string>

using namespace std;

class Restricao{
private:
    string name;

public:

    Restricao(const string& name);

    string getName() const;
    void setName(const string& pName);

    bool operator == (const Restricao& obj) const;
    bool operator == (string& name) const;
};
#endif //MY_PROJECT_RESTRICOES_H
