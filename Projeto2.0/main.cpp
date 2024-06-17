#include <iostream>
#include "FoodFinder.h"
#include "mockdata/MockData.h"
#include "Controller.h"



using namespace std;

int main() {

    FoodFinder foodFinder("FoodFinder");

    MockData mock;
    mock.generateData(foodFinder);

    Controller controller(foodFinder);
    controller.run();
    cout << "Application has exited" << endl;
    return 0;
}