project(Projeto)
set(CMAKE_CXX_STANDARD 14)
add_executable(Projeto main.cpp
        headers/model/data.h
        headers/model/favoritos.h
        headers/model/favoritosList.h
        headers/model/ingrediente.h
        headers/model/ingredientesList.h
        headers/model/ingredientesStock.h
        headers/model/ingredienteStockList.h
        headers/model/preferencias.h
        headers/model/preferenciasList.h
        headers/model/receita.h
        headers/model/receitaList.h
        headers/model/registo.h
        headers/model/user.h
        headers/exceptions/DataConsistencyException.h
        headers/exceptions/DuplicatedDataException.h
        headers/exceptions/InvalidDataException.h
        sources/model/data.cpp
        sources/model/ingrediente.cpp
        sources/model/ingredienteList.cpp
        sources/model/preferencias.cpp
        sources/model/receita.cpp
        sources/model/Utils.cpp
        sources/model/Views.cpp)