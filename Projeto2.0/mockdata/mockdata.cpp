//
// Created by diogo on 16/06/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Client.h"
#include "ingrediente.h"
#include "receita.h"
#include "restricoes.h"
#include "ClientList.h"
#include "ingredienteList.h"
#include "receitaList.h"
#include "restricoesList.h"

using namespace std;

class MockData {
public:
    void loadMockClientes(ClientList& clientList);
    void loadMockIngrediente(IngredienteList& ingredienteList);
    void loadMockReceitas(ReceitaList& receitaList);
    void loadMockRestricoes(restricoesList& restricoesList1);
    void generateData(ClientList& clientList, IngredienteList& ingredienteList, ReceitaList& receitaList, restricoesList& restricoesList1);
};

void MockData::loadMockClientes(ClientList &clientList) {
    ifstream file("../Data/MockClientes.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    string line;
    getline(file, line);  // Skip header

    while (getline(file, line)) {
        stringstream iss(line);
        string name, password;


        getline(iss, name, ',');
        getline(iss, password, ',');

        Client client( name, password);
        clientList.addClient(client);
    }

    file.close();  // Always close the file when done
}


void MockData::loadMockIngrediente(IngredienteList &ingredienteList) {
    ifstream file("../Data/MockIngrediente.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    string line;
    getline(file, line);  // Skip header

    while (getline(file, line)) {
        stringstream iss(line);
        string name, stockStr, isAvailableStr;

        getline(iss, name, ',');
        getline(iss, stockStr, ',');
        getline(iss, isAvailableStr, ',');

        // Convert stock and isAvailable from string to appropriate types
        float stock = stof(stockStr);
        bool isAvailable = (isAvailableStr == "true"); // Assuming "true" or "false" strings in CSV

        Ingrediente ingrediente(name, stock, isAvailable);
        ingredienteList.add(ingrediente);
    }
}


void MockData::loadMockReceitas(ReceitaList &receitaList) {
    ifstream file("../Data/MockReceitas.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    string line;
    getline(file, line);  // Skip header

    while (getline(file, line)) {
        stringstream iss(line);
        string name, descricao, restricao, ingredientes_str, fav;

        getline(iss, name, ',');
        getline(iss, descricao, ',');
        getline(iss, restricao, ',');
        getline(iss, fav, ',');
        getline(iss, ingredientes_str, ',');


        // Processar lista de ingredientes
        stringstream ingrediente_ss(ingredientes_str);
        vector<string> ingredientes;
        string ingrediente;

        while (getline(ingrediente_ss, ingrediente, ';')) {
            ingredientes.push_back(ingrediente);
        }

        // Criar objeto Receita
        Receita receita(name, descricao, restricao, ingredientes, (fav == "true"));
        Receita receita1;

        // Adicionar a receita à lista receitaList passada por referência
        receitaList.addReceita(receita);
    }

    file.close();
}

void MockData::loadMockRestricoes(restricoesList &restricoesList1) {
    ifstream file("../data/MockRestricoes.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    string line;
    getline(file, line);  // Skip header

    while (getline(file, line)) {
        stringstream iss(line);
        string restricao;

        getline(iss, restricao, ',');

        // Criar objeto Restricao e adicionar à restricoesList
        Restricao restricaoObj(restricao);
        restricoesList1.addRestricoes(restricaoObj);
    }

    file.close();  // Fechar o arquivo após a leitura
}


void MockData::generateData(ClientList& clientList, IngredienteList& ingredienteList, ReceitaList& receitaList, restricoesList& restricoesList) {
    loadMockClientes(clientList);
    loadMockIngrediente(ingredienteList);
    loadMockReceitas(receitaList);
    loadMockRestricoes(restricoesList);
}

int main() {
    ClientList clientList;
    IngredienteList ingredienteList;
    ReceitaList receitaList;
    restricoesList restricoesList;

    MockData mockData;
    mockData.generateData(clientList, ingredienteList, receitaList, restricoesList);

    // Further processing if needed

    return 0;
}