cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(my_project)

# Especificar o padrão do C++
set(CMAKE_CXX_STANDARD 17)

# Adicionar diretório dos headers
include_directories(${CMAKE_SOURCE_DIR}/headers/model ${CMAKE_SOURCE_DIR}/headers/exceptions ${CMAKE_SOURCE_DIR}/headers/views)

# Adicionar arquivos fonte
add_executable(my_project
        main.cpp
        sources/model/data.cpp

)