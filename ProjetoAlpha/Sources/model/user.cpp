#include "user.h"

// Inicialização estática da variável num_users
int User::num_users = 0;

// Construtor que recebe todos os parâmetros necessários
User::User( int& num,const string& nome, const string& email, const string& password, const string& role, const Data& nasc){
    this->num_users = num_users++;
    this->num = num;
    this->nome = nome;
    this->email = email;
    this->password = password;
    this->role = role;
    this->nasc = nasc;
}

User::User(const User& obj) {
    this->nome = obj.nome;
    this->email = obj.email;
    this->password = obj.password;
    this->role = obj.role;
    this->num = obj.num;
    this->nasc = obj.nasc;
    this->receitas = obj.receitas;
}

User::~User() {}

// Getter para o nome
const string& User::getName() const {
    return nome;
}

// Setter para o nome
void User::setName(const string& name) {
    nome = name;
}

// Getter para o email
string& User::getEmail() {
    return email;
}

// Setter para o email
void User::setEmail(const string& email) {
    this->email = email;
}

// Getter para a senha
string& User::getPassword() {
    return password;
}

// Setter para a senha
void User::setPassword(const string& password) {
    this->password = password;
}

// Getter para a data de nascimento
const Data& User::getBirthday() const {
    return nasc;
}

// Setter para a data de nascimento
void User::setBirthday(const Data& birthday) {
    nasc = birthday;
}

// Getter para o número do usuário
int User::getNumber() const {
    return num;
}

// Setter para o número do usuário
void User::setNumber(int num) {
    this->num = num;
}

// Getter para a lista de receitas
ReceitaList User::getReceitas() const {
    return receitas;
}

// Setter para a lista de receitas
void User::setReceitas(const ReceitaList& receitas) {
    this->receitas = receitas;
}

// Sobrecarga do operador de igualdade para comparar dois usuários
bool User::operator==(const User& obj) const {
    return (num == obj.num);
}

// Sobrecarga do operador de igualdade para comparar um usuário com um número inteiro
bool User::operator==(int nr) const {
    return (num == nr);
}
