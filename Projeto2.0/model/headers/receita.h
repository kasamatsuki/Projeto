#ifndef MY_PROJECT_RECEITA_H
#define MY_PROJECT_RECEITA_H

#include "ingrediente.h"
#include "restricoes.h"
#include "ingredienteList.h"
#include <string>

class Receita {
private:
    std::string name;
    std::string descricao;
    Restricao restricao;
    bool fav;
    IngredienteList ingredientes;


public:
    Receita(std::string &name,
            std::string &descricao,
            IngredienteList &ingredientes,
            Restricao &restricao,
            bool &fav
            );

    void SetNomeReceita(std::string &name);
    void SetDescricao(std::string &descricao);
    void SetFav(bool &fav);
    void SetRestricao(Restricao &restricao);
    void SetIngredientes(IngredienteList &ingredientes);

    IngredienteList GetIngredientes() const;

    Restricao GetRestricao() const;
    bool getFav();
    string getNomeReceita();
    string getDescricao() const;

    void addIngrediente(const Ingrediente &ingrediente);
    void removeIngrediente(const Ingrediente &ingrediente);

    bool operator==(const Receita &obj) const;
    bool operator==(std::string &name) const;
};

#endif // MY_PROJECT_RECEITA_H
