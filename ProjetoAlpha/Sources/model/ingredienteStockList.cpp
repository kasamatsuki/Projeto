#include "ingredienteStockList.h"
#include "DuplicatedDataException.h"

// Método de busca
list<IngredienteStock>::iterator IngredientesStockList::search(const string& nomeIngrediente) {
    list<IngredienteStock>::iterator it = this->ingredientesStockList.begin();
    for (; it != this->ingredientesStockList.end(); ++it) {
        if (it->getIngrediente().getNomeIngrediente() == nomeIngrediente) {
            return it;
        }
    }
    return it;
}

// Retorna todos os ingredientes no estoque
list<IngredienteStock> IngredientesStockList::getAll() {
    list<IngredienteStock> newlist(this->ingredientesStockList);
    return newlist;
}

// Obtém um ingrediente no estoque pelo nome e quantidade
IngredienteStock* IngredientesStockList::get(const string& nomeIngrediente, const int& quantidade) {
    list<IngredienteStock>::iterator it = search(nomeIngrediente);
    if (it != this->ingredientesStockList.end() && it->getQuantidade() == quantidade) {
        return &(*it);
    }
    return nullptr;
}

// Adiciona um novo ingrediente ao estoque
void IngredientesStockList::add(const IngredienteStock& ingrediente_stock) {
    list<IngredienteStock>::iterator it = search(ingrediente_stock.getIngrediente().getNomeIngrediente());
    if (it == this->ingredientesStockList.end()) {
        this->ingredientesStockList.push_back(ingrediente_stock);
    } else {
        string msg = "Ingrediente: " + ingrediente_stock.getIngrediente().getNomeIngrediente();
        throw DuplicatedDataException(msg);
    }
}

// Remove um ingrediente do estoque
void IngredientesStockList::remove(const IngredienteStock& ingrediente_stock) {
    list<IngredienteStock>::iterator it = search(ingrediente_stock.getIngrediente().getNomeIngrediente());
    if (it != this->ingredientesStockList.end() && it->getQuantidade() == ingrediente_stock.getQuantidade()) {
        this->ingredientesStockList.erase(it);
    }
}

// Atualiza um ingrediente no estoque
void IngredientesStockList::update(const IngredienteStock& ingrediente_stock) {
    list<IngredienteStock>::iterator it = search(ingrediente_stock.getIngrediente().getNomeIngrediente());
    if (it != this->ingredientesStockList.end()) {
        it->setIngrediente(ingrediente_stock.getIngrediente());
        it->setQuantidade(ingrediente_stock.getQuantidade());
    }
}
