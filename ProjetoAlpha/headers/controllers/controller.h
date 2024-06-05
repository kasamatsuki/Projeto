//
// Created by vasco on 05/06/2024.
//

#ifndef TRABALHO_DE_FSOFT_CONTROLLER_H
#define TRABALHO_DE_FSOFT_CONTROLLER_H
#include "Views.h"
#include "registoView.h"
#include "utils.h"
//mais includes(resto do header/views)

class Controller{

private:
    registoView RegistoView;
    View view;
    //resto dos views


public:
    //Falta criar a App.h que será onde tem os containers todos Controller(App& app);
    void run();
};
#endif //TRABALHO_DE_FSOFT_CONTROLLER_H
