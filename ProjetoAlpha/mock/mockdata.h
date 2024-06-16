/*
 * MockData.h
 *
 *  Created on: 15/06/2024
 *      Author: ChatGPT
 */

#ifndef MOCKDATA_H
#define MOCKDATA_H

#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include<vector>
#include "receita.h"
#include "receitaList.h"
#include "ingredientesList.h"
#include "preferenciasList.h"

class MockData {
private:
    const int NUM_INGREDIENTES = 10;
    const int NUM_PREFERENCIAS = 5;
    const int NUM_RECEITAS = 10;

    const std::vector<std::string> nome_ingredientes = {
            "Tomate", "Cebola", "Alho", "Cenoura", "Batata",
            "Frango", "Arroz", "Feijão", "Queijo", "Massa"
    };

    const std::vector<std::string> descricao_ingredientes = {
            "Vegetal vermelho", "Vegetal redondo", "Vegetal aromático",
            "Vegetal alaranjado", "Vegetal tuberoso",
            "Carne de ave", "Grão básico", "Grão básico", "Laticínio", "Base de farinha"
    };

    const std::vector<std::string> nome_preferencias = {
            "Sem glúten", "Vegetariano", "Vegano", "Sem lactose", "Baixo teor de gordura"
    };

    const std::vector<std::string> nome_receitasw = {
            "Lasanha de Frango", "Salada Caesar", "Risoto de Cogumelos", "Sopa de Legumes",
            "Tacos Mexicanos", "Quiche de Queijo", "Estrogonofe de Carne", "Macarrão ao Molho Branco",
            "Bolo de Chocolate", "Pudim de Leite"
    };

    const std::vector<std::string> descricao_receitas = {
            "Deliciosa lasanha de frango com molho de tomate e queijo gratinado",
            "Clássica salada Caesar com croutons crocantes e molho especial",
            "Risoto cremoso de cogumelos frescos e queijo parmesão",
            "Sopa leve e nutritiva com uma variedade de legumes frescos",
            "Tacos crocantes com carne temperada e molho de guacamole",
            "Quiche assado com queijo derretido e recheio de vegetais",
            "Estrogonofe russo tradicional com carne macia e molho cremoso",
            "Macarrão penne coberto com um delicioso molho branco caseiro",
            "Bolo de chocolate úmido com cobertura de ganache de chocolate",
            "Pudim de leite cremoso e caramelizado, perfeito como sobremesa"
    };



    void insertIngredientes(ingredientesList& container);
    void insertPreferencias(preferenciasList& container);
    void insertReceitas(ReceitaList& container, ingredientesList& ingredientes, preferenciasList& preferencias);

};

#endif /* MOCKDATA_H */
