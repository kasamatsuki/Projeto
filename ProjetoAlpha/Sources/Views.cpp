#include <iostream>
#include "View.h"
#include "Utils.h"


using namespace std;

View::View(){
int Views:menuPrincipal(){
    int op = -1;
    do{
        cout << "\n\n Menu Login\n";
        cout << "1 - Entrar\n";
        cout << "2 - Registos\n";
        cout << "0 - Sair\n";
        op = Utils :: getNumber(label:"Option");
    }while(op <0 || op > 2);
    return op;
}
}
int View:menuUser(){
    int op = -1;
    do{
        cout << "\n\nMenu do User\n";
        cout << "1 - Pesquisar receitas\n";
        cout << "2 - Rating\n";
        cout << "3 - Ingredientes do utilizador\n";
        cout << "4 - Receitas favoritas\n";
        cout << "5 - Historico\n";
        cout << "0 - Sair\n";
        op = Utils :: getNumber(label:"Option");
    }while(op <0 || op > 5);
    return op;
}

int View:pesquisaReceitas(){
    int op = -1;
    do{
        cout << "\n\nPesquisar receitas\n";
        cout << "1 - Pesquisa por rating\n";
        cout << "2 - Pesquisa por referencias\n";
        cout << "3 - Pesquisa por restricoes\n";
        cout << "4 - Historico\n";
        cout << "5 - Voltar\n";
        cout << "0 - Sair\n";
        op = Utils :: getNumber(label:"Option");
    }while(op <0 || op > 5);
    return op;
}
int View:ingredientesUser(){
    int op = -1;
    do{
        cout << "\n\nIngredientes do Utilizador\n";
        cout << "1 - Adicionar ingredientes\n";
        cout << "0 - Voltar\n";
        op = Utils :: getNumber(label:"Option");
    }while(op <0 || op > 1);
    return op;
}
int View:rating(){
    int op = -1;
    do{
        cout << "\n\nRating\n";
        cout << "1 - Avaliar uma receita\n";
        cout << "0 - Voltar\n";
        op = Utils :: getNumber(label:"Option");
    }while(op <0 || op > 1);
    return op;
}
int View::receitasFavoritas() {
    int op = -1;
    do {
        cout << "\n\nReceitas Favoritas\n";
        cout << "Lista de receitas favoritas \n";
        cout << "0 - Voltar\n";
        op = Utils::getNumber(label: "Option");
    } while (op < 0 || op > 1);
    return op;
}
int View::historico() {
    int op = -1;
    do {
        cout << "\n\nHistorico\n";
        cout << "1 - Lista do historico \n";
        cout << "0 - Voltar\n";
        op = Utils::getNumber(label: "Option");
    } while (op < 0 || op > 1);
    return op;
}

