//
// Created by diogo on 16/06/2024.
//

#ifndef MY_PROJECT_MOCKDATA_H
#define MY_PROJECT_MOCKDATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "FoodFinder.h"
#include <algorithm>

#include <cstring>

using namespace std;

class MockData {
private:
    void loadMockClients(ClientList& clientList);
    void loadMockIngrediente(IngredienteList& ingredienteList);
    void loadMockReceitas(ReceitaList& receitaList);
    void loadMockRestricoes(restricoesList& restricoesList1);
public:
    void generateData(FoodFinder& foodFinder);

};


#endif //MY_PROJECT_MOCKDATA_H