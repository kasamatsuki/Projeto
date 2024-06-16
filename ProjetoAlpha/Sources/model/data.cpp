//
// Created by simpgod on 05-06-2024.
//
#include "InvalidDataException.h"
#include <string>
#include "../../headers/model/data.h"

using namespace std;

bool Data::isLeapYear(int ano){
    // If a ano is multiple of 400,
    // then it is a leap ano
    if (ano % 400 == 0)
        return true;
    // Else If a ano is multiple of 100,
    // then it is not a leap ano
    if (ano % 100 == 0)
        return false;
    // Else If a ano is multiple of 4,
    // then it is a leap ano
    if (ano % 4 == 0)
        return true;
    return false;


}
bool Data::isValid(int dia, int mes, int ano){
    bool result = true;
    if(dia <= 0 || dia > 31 || mes <= 0 || mes > 12){
        result = false;
    }else{
        switch(mes){
            case 2:
                if(isLeapYear(ano) == true){
                    if(dia > 29){
                        result = false;
                    }
                }else{
                    if(dia > 28){
                        result = false;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(dia > 30){
                    result = false;
                }
                break;
        }
    }
    return result;

}
Data::Data(){
    //default Data
    setDate(1,1, 1900);
}
Data::Data(int dia, int mes, int ano){
    setDate(dia, mes, ano);
}
Data::Data(const Data& Data){
    setDate(Data.dia, Data.mes, Data.ano);
}
void Data::setDate(int dia, int mes, int ano){
    if(isValid(dia, mes, ano)){
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    else{
        string msg =to_string(dia)+ "/"+to_string(mes)+"/"+to_string(ano);
        throw InvalidDataException(msg);
    }
}
void Data::getDate(int& dia, int& mes, int& ano) const{
    dia = this->dia;
    mes = this->mes;
    ano = this->ano;
}
bool Data::operator == (const Data& obj) const{
    if(this->dia == obj.dia && this->mes == obj.mes && this->ano == obj.ano){
        return true;
    }
    return false;
}
bool Data::operator > (const Data& obj)const{
    if(this->ano > obj.ano){
        return true;
    }
    if(this->mes > obj.mes){
        return true;
    }
    if(this->dia > obj.dia){
        return true;
    }
    return false;
}
bool Data::operator < (const Data& obj) const{
    if(*this == obj){
        return false;
    }

    if(*this > obj){
        return false;
    }
    return true;
}