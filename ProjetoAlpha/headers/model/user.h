//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_USER_H
#define PROJETOALPHA_USER_H

#include <string>
#include <iostream>
#include "data.h"
#include "Preferencias.h"


using namespace std;

class User{
protected:
    string nome;
    string email;
    string password;
    static int num_users;
    int num;
    Data nasc;

public:
    User(const string& nome, const Data& nasc);
    User(const User& user);
    ~User();
    const string& getName() const;
    void setName(const string &name);
    //
    string& getEmail();
    void setEmail(string &email);
    //
    string& getPassword();
    void setPassword( string &password);
    //
    const Data& getBirthday() const;
    void setBirthday(const Data &birthday);
    //
    int getNumber() const ;
    void setNumber(int num);

    bool operator == (const User& obj) const;
    bool operator == (int nr) const;

};


#endif //PROJETOALPHA_USER_H
