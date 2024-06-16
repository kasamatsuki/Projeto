#include "receita.h"
#include "receitaList.h"




Receita::Receita(std::string &nomeReceita,
                 std::string &descricao,
                 IngredienteList &ingredientes,
                 Restricao &restricao,
                 bool &fav)
        : name(nomeReceita), descricao(descricao), ingredientes(ingredientes), restricao(restricao), fav(fav) {

    SetNomeReceita(nomeReceita);
    SetDescricao(descricao);
    SetFav(fav);
    SetRestricao(restricao);
}

bool Receita::operator==(string& name) const {
    if(this->name == name){
        return true;
    }return false;
}

void Receita::SetNomeReceita(string &name)
{
    this->name = name;
}

void Receita::SetDescricao(std::string &descricao) {
    this->descricao = descricao;
}

void Receita::SetRestricao(Restricao &restricao) {
    this-> restricao = restricao;
}

void Receita::SetFav(bool &fav) {
    this->fav = !this->fav;
}
void Receita::SetIngredientes(IngredienteList &ingredientes) {
    this->ingredientes = ingredientes;
}

bool Receita::operator==(const Receita &obj) const{
    if (this->name == obj.name)
        return true;
    return false;
}
IngredienteList Receita::GetIngredientes() const {
    return this->ingredientes;
}

Restricao Receita::GetRestricao() const {
    return this->restricao;
}

void Receita::addIngrediente(const Ingrediente &ingrediente) {
    this->ingredientes.add(ingrediente);
}

void Receita::removeIngrediente(const Ingrediente &ingrediente) {
    this->ingredientes.remove(ingrediente);
}
bool Receita::getFav(){
    return fav;
}

string Receita::getNomeReceita() {
    return this->name;
}
std::string Receita::getDescricao() const {
    return this->descricao;
}

