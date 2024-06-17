cmake_minimum_required(VERSION 3.24)
project(FoodFinder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WIN32_EXECUTABLE OFF)

set(PROJECT_CONTROLLER_DIR
        ${PROJECT_SOURCE_DIR}/controller)
include_directories(
        ${PROJECT_CONTROLLER_DIR})
set(CONTROLLER_SOURCE_FILES
        ${PROJECT_CONTROLLER_DIR}/Controller.h
        ${PROJECT_CONTROLLER_DIR}/Controller.cpp
)

set(PROJECT_EXCEPTION_DIR
        ${PROJECT_SOURCE_DIR}/exception)
set(PROJECT_EXCEPTION_HEADERS_DIR
        ${PROJECT_EXCEPTION_DIR}/headers)
set(PROJECT_EXCEPTION_SOURCES_DIR
        ${PROJECT_EXCEPTION_DIR}/sources)
include_directories(
        ${PROJECT_EXCEPTION_HEADERS_DIR}
        ${PROJECT_EXCEPTION_SOURCES_DIR})
set(EXCEPTION_SOURCE_FILES
        ${PROJECT_EXCEPTION_HEADERS_DIR}/InvalidDataException.h
        ${PROJECT_EXCEPTION_SOURCES_DIR}/InvalidDataException.cpp
)

set(PROJECT_MODEL_DIR
        ${PROJECT_SOURCE_DIR}/model)
set(PROJECT_MODEL_HEADERS_DIR
        ${PROJECT_MODEL_DIR}/headers)
set(PROJECT_MODEL_SOURCES_DIR
        ${PROJECT_MODEL_DIR}/sources)
include_directories(
        ${PROJECT_MODEL_HEADERS_DIR}
        ${PROJECT_MODEL_SOURCES_DIR})
set(MODEL_SOURCE_FILES
        ${PROJECT_MODEL_HEADERS_DIR}/Client.h
        ${PROJECT_MODEL_SOURCES_DIR}/Client.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/ClientList.h
        ${PROJECT_MODEL_SOURCES_DIR}/ClientList.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/Date.h
        ${PROJECT_MODEL_SOURCES_DIR}/Date.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/ingrediente.h
        ${PROJECT_MODEL_SOURCES_DIR}/ingrediente.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/receita.h
        ${PROJECT_MODEL_SOURCES_DIR}/receita.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/restricoes.h
        ${PROJECT_MODEL_SOURCES_DIR}/restricoes.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/receitaList.h
        ${PROJECT_MODEL_SOURCES_DIR}/receitaList.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/restricoesList.h
        ${PROJECT_MODEL_SOURCES_DIR}/restricoesList.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/ingredienteList.h
        ${PROJECT_MODEL_SOURCES_DIR}/ingredienteList.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/User.h
        ${PROJECT_MODEL_SOURCES_DIR}/user.cpp
        ${PROJECT_MODEL_HEADERS_DIR}/FoodFinder.h
        ${PROJECT_MODEL_SOURCES_DIR}/FoodFinder.cpp


)

set(PROJECT_VIEWS_DIR
        ${PROJECT_SOURCE_DIR}/VIEWS)
set(PROJECT_VIEWS_HEADERS_DIR
        ${PROJECT_VIEWS_DIR}/headers)
set(PROJECT_VIEWS_SOURCES_DIR
        ${PROJECT_VIEWS_DIR}/sources)
include_directories(
        ${PROJECT_VIEWS_HEADERS_DIR}
        ${PROJECT_VIEWS_SOURCES_DIR})
set(VIEWS_SOURCE_FILES
        ${PROJECT_VIEWS_HEADERS_DIR}/Utils.h
        ${PROJECT_VIEWS_SOURCES_DIR}/Utils.cpp
        ${PROJECT_VIEWS_HEADERS_DIR}/ClientView.h
        ${PROJECT_VIEWS_SOURCES_DIR}/ClientView.cpp
        ${PROJECT_VIEWS_HEADERS_DIR}/RestricoesView.h
        ${PROJECT_VIEWS_SOURCES_DIR}/RestricaoView.cpp
        ${PROJECT_VIEWS_HEADERS_DIR}/IngredienteView.h
        ${PROJECT_VIEWS_SOURCES_DIR}/IngredienteView.cpp
        ${PROJECT_VIEWS_HEADERS_DIR}/ReceitaView.h
        ${PROJECT_VIEWS_SOURCES_DIR}/ReceitaView.cpp
        ${PROJECT_VIEWS_HEADERS_DIR}/View.h
        ${PROJECT_VIEWS_SOURCES_DIR}/View.cpp
)


set(SOURCE_FILES
        controller/Controller.h
        controller/Controller.cpp
        mockdata/mockData.h
        mockdata/mockData.cpp
        main.cpp)



add_executable(
        FoodFinder
        main.cpp
        ${SOURCE_FILES}
        ${MODEL_SOURCE_FILES}
        ${VIEWS_SOURCE_FILES}
        ${EXCEPTION_SOURCE_FILES}
        main.cpp
)