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

#include "mockdata.h"

using namespace std;

void MockData::loadMockClientes(ClientList& clientList) {
    int rows = 4;
    int columns = 3;
    string data[rows][columns];

    ifstream file("../data/MockClientes.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    for(int row = 0; row < rows; ++row)
    {
        string line;
        getline(file, line);

        stringstream iss(line);

        for (int col = 0; col < columns; ++col)
        {
            string val;
            getline(iss, val, ',');
            data[row][col] = val;
        }
    }
    for(int i = 1; i < rows; ++i){
        Client client(data[i][0],data[i][1],data[i][2]);
        clientList.addClient(client);
    }
}


void MockData::loadMockIngrediente(IngredienteList &ingredienteList) {
    const int rows = 5;
    const int columns = 3;
    std::string data[rows][columns];

    std::ifstream file("../Data/MockIngrediente.csv");

    if (!file.is_open()) {
        std::cout << "File not opened" << std::endl;
        return;
    }

    for(int row = 0; row < rows; ++row) {
        string line;
        getline(file, line);

        std::stringstream iss(line);

        for (int col = 0; col < columns; ++col) {
            std::string val;
            getline(iss, val, ';');
            data[row][col] = val;
        }
    }

    for(int i = 1; i < rows; ++i) {
        //name	description	category	brand 	ean	stock	supplierPrice	sellingPrice	isAvailable
        replace(data[i][1].begin(), data[i][1].end(), ',', '.');
        replace(data[i][2].begin(), data[i][2].end(), ',', '.');

        int stock = 0;
        std::stringstream ss_stock(data[i][1]);
        ss_stock >> stock;
        bool isAvailable = (data[i][2] == "1");

        // Criar o objeto Ingrediente usando os dados convertidos
        Ingrediente ingrediente(data[i][0],
                                stock,         // stock (convertido para int)
                                isAvailable); // isAvailable (convertido para bool)

        // Adicionar o ingrediente à lista de ingredientes
        ingredienteList.add(ingrediente);
    }
}

void MockData::loadMockReceitas(ReceitaList &receitaList) {
    const int rows = 4;
    const int columns = 5;
    std::string data[rows][columns];

    std::ifstream file("../Data/MockReceitas.csv");

    if (!file.is_open()) {
        std::cout << "File not opened" << std::endl;
        return;
    }

    for(int row = 0; row < rows; ++row) {
        string line;
        getline(file, line);

        std::stringstream iss(line);

        for (int col = 0; col < columns; ++col) {
            std::string val;
            getline(iss, val, ';');
            data[row][col] = val;
        }
    }

    for (int i = 0; i < rows; ++i) {
        //name	description	category	brand 	ean	stock	supplierPrice	sellingPrice	isAvailable
        bool isFav = (data[i][4] == "1");
        Ingrediente ingrediente(data[i][2], 1, true); // Criar o objeto Ingrediente
        Restricao restricao(data[i][3]); // Criar o objeto Restricao

        // Criar a lista de ingredientes e adicionar o ingrediente criado
        IngredienteList ingredienteList;
        ingredienteList.add(ingrediente);

        // Criar o objeto Receita usando os dados convertidos
        Receita receita(data[i][0],
                        data[i][1],
                        ingredienteList,
                        restricao,
                        isFav);

        // Adicionar a receita à lista de receitas
        receitaList.addReceita(receita);
    }
}
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


void MockData::generateData(FoodFinder &foodFinder) {
    loadMockClientes(foodFinder.getClientList());
    loadMockIngrediente(foodFinder.getIngredienteList());
    loadMockReceitas(foodFinder.getReceitaList());
   loadMockRestricoes(foodFinder.getRestricoesList());
}
