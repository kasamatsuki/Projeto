//
// Created by diogo on 16/06/2024.
//
#include <iostream>
#include "Controller.h"
#include "Utils.h"
#include "InvalidDataException.h"

Controller::Controller(FoodFinder& foodFinder) {
    this->model = foodFinder;
}
void Controller::run() {
    int op = -1;
    if(this->loggedUser == nullptr){
        do{
            op = this->view.menuPrincipal();
            switch(op){
                case 1:runLogin(); //2 - Login
                    break;
                case 2:runCreateAccount(); //3 - Sign up
                    break;
                default:
                    break;
            }
        }while(op != 0);
    }else{

        menuGeral();
    }
}

void Controller::runLogin(){


    string username = this->clientView.getUsername();
    string password = this->clientView.getPassword();

    // Obter cliente pelo nome de usuário
    ClientList& clientList = model.getClientList();
    Client* tempClient = clientList.getByUsername(username);

    // Verificar se o cliente existe
    if (tempClient == nullptr) {
        this-> clientView.invalidUsername();
        return;
    }

    // Verificar se a senha corresponde
    if(tempClient->doesPasswordMatch(password)){
        this->login((User*)tempClient);
        cout<<"Login Successful";
        menuGeral();
    }else{
        this->clientView.incorrectPassword();
    }
}
void Controller::runCreateAccount() {
    ClientList& clientList = this->model.getClientList();
    string username = this->clientView.getUsername();

    if(clientList.getByUsername(username) != nullptr){
        cout << "Username already taken.";
        return;
    }
    string password = this->clientView.getPassword();
    Client newClient(username, password);
    clientList.addClient(newClient);
}

void Controller::login(User* pUser) {
    this->loggedUser = pUser;
}

void Controller::logout() {
    if(this->loggedUser == nullptr){
        cout<<"No account is logged in";
        return;
    }
    this->loggedUser = nullptr;
}

void Controller::runGeral() {
    int op = -1;
    auto* loggedClient = (Client*)this->loggedUser;
    do{
        op = this->view.menuPrincipal();
        switch(op){
            case 1:
                runReceitas();     //1 - Recipes
                break;
            case 2:
                runIngredientes();                  //2 - Ingredients
                break;
            case 3:
                runRestricoes();      //3 - Restrictions
                break;
            case 4:                         //4 - User
                runUser();
                break;
            default:
                break;
        }
    }while(op != 0);
    logout();
}

void Controller::runReceitas() {
    int op = -1;
    ReceitaList& receitaList = this->model.getReceitaList();
    do {
        // Obtém todas as receitas atualizadas da lista
        list<Receita> allReceitas = receitaList.getAll();



        // Menu de receitas
        op = this->view.receitasMenu();
        switch (op) {
            case 1: // 1 - View Receitas
                this->receitaView.printReceitaList(allReceitas, "Recipes List:");
                op = -1;
                break;
            case 2: // 2 - Create Receita
                runCreateReceita();
                allReceitas = receitaList.getAll();
                op = -1;
                break;

            case 3:runEditReceita();          // 3 - Edit Receita
                allReceitas = receitaList.getAll();
                op = -1;
                break;

            case 4:runEditReceita();          // 4 - Delete Receita
                allReceitas = receitaList.getAll();
                op = -1;
                break;
            default:
                break;
        }
    }while(op != 0);
}
void Controller::runCreateReceita(){
    ReceitaList& receitaList = this->model.getReceitaList();
    string name = this->receitaView.getName();
    if(receitaList.getByName(name) != nullptr){
        cout << "Recipe already in the store.";
        return;
    }
    Receita receita = this->receitaView.getReceita();
    receitaList.addReceita(receita);
}
void Controller::runEditReceita(){

    ReceitaList& receitaList = this->model.getReceitaList();

    // Passo 2: Obter o nome da receita que deseja atualizar
    string name = this->receitaView.getName();

    // Passo 3: Verificar se a receita existe
    Receita* existingReceita = receitaList.getByName(name);
    if(existingReceita == nullptr){
        this->receitaView.invalidName();
        return;
    }

    // Passo 4: Obter os novos valores da receita do usuário
    Receita updatedReceita = this->receitaView.getReceita();

    // Criar variáveis temporárias para armazenar os valores
    string updatedName = updatedReceita.getNomeReceita();
    string updatedDescricao = updatedReceita.getDescricao();
    Restricao updatedRestricao = updatedReceita.GetRestricao();
    IngredienteList updatedIngredientes = updatedReceita.GetIngredientes();
    bool updatedFav = updatedReceita.getFav();

    // Atualizar os valores da receita existente usando referências
    existingReceita->SetNomeReceita(updatedName);
    existingReceita->SetDescricao(updatedDescricao);
    existingReceita->SetRestricao(updatedRestricao);
    existingReceita->SetIngredientes(updatedIngredientes);
    existingReceita->SetFav(updatedFav);


    cout << "Recipe updated successfully!\n";
}