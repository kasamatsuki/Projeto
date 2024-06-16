#ifndef PROJETOALPHA_USER_H
#define PROJETOALPHA_USER_H

#include <string>
#include "data.h"
#include "receitaList.h"

using namespace std;

class User {
protected:
    string nome;
    string email;
    string password;
    static int num_users;
    int num;
    ReceitaList receitas;

public:
    // Construtor que recebe todos os parâmetros necessários

    User(int num, const string& nome, const string& email, const string& password);
    User(const User& user);
    ~User();

    const string& getName() const;
    void setName(const string& name);

    const string & getEmail();
    void setEmail(const string& email);

    string& getPassword();
    void setPassword(const string& password);

    int getNumber() const;
    void setNumber(int num);

    ReceitaList getReceitas() const;
    void setReceitas(const ReceitaList& receitas);

    bool operator==(const User& obj) const;
    bool operator==(int nr) const;
};

#endif // PROJETOALPHA_USER_H