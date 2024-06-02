//
// Created by diogo on 02/06/2024.
//

#ifndef PROJETOALPHA_DATA_H
#define PROJETOALPHA_DATA_H

class Data{
private:
    int dia;
    int mes;
    int ano;
    bool isLeapYear(int ano);
    bool isValid(int dia, int mes, int ano);
public:
    Data();
    Data(int dia, int mes, int ano);
    Data(const Data & data);
    void setDate(int dia, int mes, int ano);
    void getDate(int& dia, int& mes, int& ano) const;
    bool operator == (const Data& obj) const;
    bool operator > (const Data& obj)const;
    bool operator < (const Data& obj) const;
};


#endif //PROJETOALPHA_DATA_H
