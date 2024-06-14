//
// Created by jppmm on 13/06/2024.
//
#include "receitaView.h"
#include <iostream>

using namespace std;

Receita ReceitaView::getReceita() {
    string nome, descricao;
    bool fav;
    list<Ingrediente> ingredientes;
    string nomeIngrediente, descricaoIngrediente;
    char adicionarMais;

    cout << "Digite o nome da receita: ";
    getline(cin, nome);
    cout << "Digite a descrição da receita: ";
    getline(cin, descricao);
    cout << "A receita é favorita? (1 para sim, 0 para não): ";
    cin >> fav;
    cin.ignore(); // Para ignorar o caractere de nova linha após a leitura de fav

    do {
        cout << "Digite o nome do ingrediente: ";
        getline(cin, nomeIngrediente);
        cout << "Digite a descrição do ingrediente: ";
        getline(cin, descricaoIngrediente);
        ingredientes.push_back(Ingrediente(nomeIngrediente, descricaoIngrediente));

        cout << "Adicionar mais ingredientes? (s/n): ";
        cin >> adicionarMais;
        cin.ignore(); // Para ignorar o caractere de nova linha após a leitura de adicionarMais
    } while (adicionarMais == 's' || adicionarMais == 'S');

    return Receita(nome, descricao, ingredientes);
}

void ReceitaView::printReceita(const Receita& receita) const {
    cout << "Nome: " << receita.getNomeReceita() << endl;
    cout << "Descrição: " << receita.getDescricao() << endl;
    cout << "Favorita: " << (receita.isFav() ? "Sim" : "Não") << endl;
    cout << "Ingredientes: " << endl;
    for (const auto& ingrediente : receita.getIngredientes()) {
        cout << "  - Nome: " << ingrediente.getNomeIngrediente() << endl;
        cout << "    Descrição: " << ingrediente.getDescricao() << endl;
    }
}

void ReceitaView::printReceitas(const std::list<Receita>& receitas) const {
    for (const auto& receita : receitas) {
        printReceita(receita);
    }
}
