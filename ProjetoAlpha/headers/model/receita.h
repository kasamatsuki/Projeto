#ifndef RECEITA_H
#define RECEITA_H

#include <string>
#include <list>
#include "preferencias.h"
#include "ingrediente.h"

class Receita {
private:
    std::string nomeReceita;
    std::string descricao;
    bool fav;
    std::list<Ingrediente> ingredientes_receita;
    Preferencia preferencia_restricao;

public:
    Receita(const std::string& nomeReceita, const std::string& descricao, const std::list<Ingrediente>& ingredientes_receita, const Preferencia& preferencia_restricao);
    Receita(const Receita& obj); // Construtor de cópia

    ~Receita();

    std::string getNomeReceita() const;
    std::string getDescricao() const;
    bool isFav() const;
    std::list<Ingrediente> getIngredientes() const;
    Preferencia getPreferencia_restricao() const;

    void setNomeReceita(const std::string& nomeReceita);
    void setDescricao(const std::string& descricao);
    void setFav(bool fav);
    void setIngredientes(const std::list<Ingrediente>& ingredientes_receita);
    void setPreferencia_restricao(const Preferencia& preferencia_restricao);

    void addIngrediente(const Ingrediente& ingrediente);
    void removeIngrediente(const Ingrediente& ingrediente);

    bool operator==(const Receita& obj) const;
    bool operator==(const std::string& str) const;
};

#endif // RECEITA_H
