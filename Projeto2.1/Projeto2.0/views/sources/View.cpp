#include <iostream>
#include "View.h"
#include "Utils.h"

using namespace std;

View::View(){

}

//Menu for all users
int View::menuPrincipal(){
    int op = -1;
    do{
        cout << "\n _______________________\n";
        cout << " |           Menu        |\n";
        cout << " |                       |\n";
        cout << " | 1 - Login             |\n";
        cout << " | 2 - Sign up           |\n";
        cout << " |                       |\n";
        cout << " | 0 - Exit              |\n";
        cout << "\n _______________________\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}
int View::menuGeral(){
    int op = -1;
    do{
        cout << "\n  --------------------------\n";
        cout << " |         User Menu        |\n";
        cout << " |                          |\n";
        cout << " | 1 - Recipes              |\n";
        cout << " | 2 - Ingredients          |\n";
        cout << " | 3 - Restrictions         |\n";
        cout << " | 4 - User                 |\n";
        cout << " |                          |\n";
        cout << " | 0 - Logout               |\n";
        cout << "  --------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}
int View::menuUser(){
    int op = -1;
    do{
        cout << "\n  --------------------------\n";
        cout << " |         User Menu        |\n";
        cout << " |                          |\n";
        cout << " | 1 - See user datails     |\n";
        cout << " | 2 - Change Password      |\n";
        cout << " | 3 - Main Menu            |\n";
        cout << " |                          |\n";
        cout << " | 0 - Go back              |\n";
        cout << "  --------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}

int View::receitasMenu(){
    int op = -1;
    do{
        //ADD LIST OF THE PRODUCTS
        cout << "\n  ---------------------------------\n";
        cout << " |        Recipes Menu               |\n";
        cout << " |                                   |\n";
        cout << " | 1 - See recipes                   |\n";
        cout << " | 2 - Create recipe                 |\n";
        cout << " | 3 - Edit recipe                   |\n";
        cout << " | 4 - Delete Recipe                 |\n";
        cout << " | 5 - Search recipe                 |\n";
        cout << " |                                   |\n";
        cout << " | 0 - Go back                       |\n";
        cout << "  -----------------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 5);
    return op;
}


int View::ingredientesMenu(){
    int op = -1;
    do{
        //ADD LIST OF THE SUPPLIERS
        cout << "\n  ----------------------------------\n";
        cout << " |       Ingredients Menu            |\n";
        cout << " |                                   |\n";
        cout << " | 1 - See Ingredients               |\n";
        cout << " | 2 - Create Ingredients            |\n";
        cout << " | 3 - Remove Ingredients            |\n";
        cout << " | 4 - Edit Ingredients              |\n";
        cout << " | 5 - See Ingredients Stock         |\n";
        cout << " |                                   |\n";
        cout << " | 0 - Go back                       |\n";
        cout << "  -----------------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 5);
    return op;
}



int View::ingredientesStockMenu(){
    int op = -1;
    do{
        cout << "\n  ----------------------------------\n";
        cout << " |       Ingredients Stock Menu      |\n";
        cout << " |                                   |\n";
        cout << " | 1 - See Ingredients in Stock      |\n";
        cout << " | 2 - Add Stock                     |\n";
        cout << " | 3 - Remove Stock                  |\n";
        cout << " |                                   |\n";
        cout << " | 0 - Go back                       |\n";
        cout << "  -----------------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}


int View::restricoesMenu(){
    int op = -1;
    do{
        cout << "\n  ------------------------------\n";
        cout << " |      Restrictions Menu       |\n";
        cout << " |                              |\n";
        cout << " | 1 - View Restrictions        |\n";
        cout << " | 2 - Add Restrictions         |\n";
        cout << " | 3 - Remove Restrictions      |\n";
        cout << " |                              |\n";
        cout << " | 0 - Logout                   |\n";
        cout << "  ------------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}

