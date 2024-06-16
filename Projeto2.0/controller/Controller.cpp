//
// Created by diogo on 16/06/2024.
//
//
// Created by diogo on 16/06/2024.
//
#include <iostream>
#include "Controller.h"
#include "View.h"
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
            runGeral();
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
        runGeral();
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

            case 4:runDeleteReceita();          // 4 - Delete Receita
                allReceitas = receitaList.getAll();
                op = -1;
                break;
            case 5:runSearchReceita();          // 5 - Delete Receita
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

void Controller::runDeleteReceita(){

    string name = this->receitaView.getName();

    // Verifica se a receita existe
    Receita* existingReceita = this->model.getReceitaList().getByName(name);
    if(existingReceita == nullptr) {
        this->receitaView.invalidName();
        return;
    }
    // Remove a receita
    this->model.getReceitaList().removeReceita(*existingReceita);
    cout << "Recipe " << name << " removed with success." << endl;
}

void Controller::runSearchReceita(){
    cout << "Search Recipe: "<< endl;
    string name = this->receitaView.getName();

    // Verifica se a receita existe
    Receita* foundReceita = this->model.getReceitaList().getByName(name);
    if(foundReceita == nullptr) {
        cout << "Receita not found." << endl;
    } else {
        this->receitaView.printReceita(foundReceita);
    }

}

void Controller::runIngredientes() {
    int op = -1;
    IngredienteList& ingredienteList = this->model.getIngredienteList();
    do {
        // Obtém todas os ingredientes atualizadas da lista
        list<Ingrediente> allIngredientes = ingredienteList.getAll();



        // Menu de receitas
        op = this->view.ingredientesMenu();
        switch (op) {
            case 1: // 1 - View Ingredients
                this->ingredienteView.printIngredienteList(allIngredientes, "Ingredient List");
                op = -1;
                break;
            case 2: // 2 - Ver Ingredientes em Stock
                runSeeIngredientesInStock();
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;

            case 3:runAddStock();          // 3 - Edit Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;

            case 4:runDeleteStock();          // 4 - Delete Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;
            case 5:runSearchReceitaWithStock();          // 5 - Delete Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;
            default:
                break;
        }
    }while(op != 0);
}

void Controller::runSeeIngredientesInStock(){
    // Obtém a lista de ingredientes disponíveis
    IngredienteList& ingredienteList = this->model.getIngredienteList();
    list<Ingrediente> availableIngredientes = ingredienteList.getAvailable().getAll();

    // Verifica se há ingredientes disponíveis para exibir
    if (availableIngredientes.empty()) {
        cout << "No ingredients available in stock." << endl;
    } else {
        // Exibe a lista de ingredientes disponíveis
        this->ingredienteView.printIngredienteList(availableIngredientes, "Available Ingredients:");
    }
}
void Controller::runAddStock() {
    // Obtém a lista de ingredientes
    IngredienteList& ingredienteList = this->model.getIngredienteList();
    string name = this->ingredienteView.getName();

    // Verifica se o ingrediente existe na lista
    Ingrediente* ingrediente = ingredienteList.getName(name);
    if (ingrediente == nullptr) {
        cout << "Ingredient not found." << endl;
        return;
    }

    // Pede ao usuário a quantidade de estoque a adicionar
    int quantity = Utils::getNumber("Enter the quantity to add to stock:");

    // Adiciona o estoque ao ingrediente
    ingredienteList.addStock(name, quantity);

    // Exibe o ingrediente atualizado
    this->ingredienteView.printIngrediente(ingrediente, "Updated Ingredient:");
}

void Controller::runDeleteStock() {
    // Obtém a lista de ingredientes
    IngredienteList& ingredienteList = this->model.getIngredienteList();
    string name = this->ingredienteView.getName();

    Ingrediente* ingrediente = ingredienteList.getName(name);
    if (ingrediente == nullptr) {
        cout << "Ingredient not found." << endl;
        return;
    }

    int quantity = Utils::getNumber("Enter the quantity to remove from stock:");
    ingredienteList.removeStock(name, quantity);
    this->ingredienteView.printIngrediente(ingrediente, "Updated Ingredient:");
}

void Controller::runSearchReceitaWithStock(){

    // Obtém a lista de receitas e ingredientes
    ReceitaList& receitaList = this->model.getReceitaList();
    IngredienteList& ingredienteList = this->model.getIngredienteList();

    // Obtém a lista de ingredientes com stock positivo ou maior que 0
    IngredienteList availableIngredientesList = ingredienteList.getAvailable();

    // Obtém todas as receitas
    list<Receita> allReceitas = receitaList.getAll();

    // Lista para armazenar as receitas possíveis de serem feitas
    list<Receita> receitasPossiveis;


    for (auto& receita : allReceitas) {
        bool todosIngredientesDisponiveis = true;
        auto ingredientesReceita = receita.GetIngredientes().getAll();

        for (auto& ingredienteReceita : ingredientesReceita) {
            // Verifica se o ingrediente necessário está disponível
            Ingrediente* ingredienteEmStock = availableIngredientesList.getName(ingredienteReceita.getName());

            if (ingredienteEmStock == nullptr || ingredienteEmStock->getStock() <= 0) {
                todosIngredientesDisponiveis = false;
                break;
            }
        }

        // Se todos os ingredientes estiverem disponíveis, adiciona a receita à lista de receitas possíveis
        if (todosIngredientesDisponiveis) {
            receitasPossiveis.push_back(receita);
        }
    }

    // Exibe a lista de receitas possíveis
    this->receitaView.printReceitaList(receitasPossiveis, "Possible Recipes:");

    // Se não houver receitas possíveis, informa o usuário
    if (receitasPossiveis.empty()) {
        cout << "No recipes can be made with the available ingredients." << endl;
    }
}
void Controller::runRestricoes() {
    int op = -1;
    restricoesList& restricoesListVarivel = this->model.getRestricoesList();
    do {
        // Obtém todas os ingredientes atualizadas da lista
        list<Restricao> allRestricoes = restricoesListVarivel.getAll();


        // Menu de receitas
        op = this->view.ingredientesMenu();
        switch (op) {
            case 1: // 1 - View restricoes
                this->restricoesView.printRestricaoList(allRestricoes, "Ingredient List");
                op = -1;
                break;
            case 2: // 2 - Add Restricao
                runAddRestricao();
                allRestricoes = restricoesListVarivel.getAll();
                op = -1;
                break;

            case 3:runAddStock();          // 3 - Edit Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;

            case 4:runDeleteStock();          // 4 - Delete Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;
            case 5:runSearchReceitaWithStock();          // 5 - Delete Receita
                allIngredientes = ingredienteList.getAll();
                op = -1;
                break;
            default:
                break;
        }
    }while(op != 0);
}

void Controller::runAddRestricao(){

}