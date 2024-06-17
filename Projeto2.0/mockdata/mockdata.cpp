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
    const int rows = 30;
    const int columns = 3;
    std::string data[rows][columns];

    std::ifstream file("../Data/MockIngredientes.csv");

    if (!file.is_open()) {
        std::cout << "File not opened" << std::endl;
        return;
    }

    // Ler os dados do arquivo CSV
    for(int row = 0; row < rows; ++row) {
        std::string line;
        getline(file, line);

        std::stringstream iss(line);

        for (int col = 0; col < columns; ++col) {
            std::string val;
            getline(iss, val, ',');
            data[row][col] = val;
        }
    }

    // Processar os dados lidos e adicionar à lista de ingredientes
    for(int i = 0; i < rows; ++i) {
        std::string name = data[i][0];
        std::string stockStr = data[i][1];
        std::string isAvailableStr = data[i][2];

        try {
            // Converter dados para os tipos apropriados
            int stock = std::stoi(stockStr);
            bool isAvailable = std::stoi(isAvailableStr) != 0; // Converte para bool

            // Criar objeto Ingrediente e adicioná-lo à lista de ingredientes
            Ingrediente ingrediente(name, stock, isAvailable);
            ingredienteList.add(ingrediente);
        } catch (const std::exception &e) {
            std::cerr << "Error converting data in row " << i << ": " << e.what() << std::endl;
        }
    }

    file.close();
}
/*

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
        string name, descricao, restricaoNome, ingredientes_str, fav;

        getline(iss, name, ',');
        getline(iss, descricao, ',');
        getline(iss, restricaoNome, ',');  // Assume restricaoNome é o nome da Restricao
        getline(iss, fav, ',');
        getline(iss, ingredientes_str, ',');

        // Processar lista de ingredientes
        vector<string> ingredientes;
        stringstream ingrediente_ss(ingredientes_str);
        string ingrediente;
        while (getline(ingrediente_ss, ingrediente, ';')) {
            ingredientes.push_back(ingrediente);
        }

        // Criar objeto Receita
        Receita receita(name, descricao, restricaoNome, (fav == "true"));

        // Adicionar ingredientes à receita
        for (const auto &ingrediente_str : ingredientes) {
            Ingrediente ingrediente(ingrediente_str);
            receita.addIngrediente(ingrediente);
        }

        // Adicionar a receita à lista receitaList passada por referência
        receitaList.addReceita(receita);
    }

    file.close();
}
*/
void MockData::loadMockRestricoes(restricoesList &restricoesList1) {
    ifstream file("../Data/MockRestricoes.csv");

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
   // loadMockReceitas(receitaList);
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