//
// Created by ricardo.franca on 24/05/2023.
//

#include "InvalidDataException.h"
#include <string>
#include <ctime>
#include "Date.h"

using namespace std;

bool Date:: isLeapYear(int year){
    // If a year is multiple of 400,
    // then it is a leap year
    if (year % 400 == 0)
        return true;
    // Else If a year is multiple of 100,
    // then it is not a leap year
    if (year % 100 == 0)
        return false;
    // Else If a year is multiple of 4,
    // then it is a leap year
    if (year % 4 == 0)
        return true;
    return false;


}
bool Date::isValid(int day, int month, int year){
    bool result = true;
    if(day <= 0 || day > 31 || month <= 0 || month > 12){
        result = false;
    }else{
        switch(month){
            case 2:
                if(isLeapYear(year)){
                    if(day > 29){
                        result = false;
                    }
                }else{
                    if(day > 28){
                        result = false;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(day > 30){
                    result = false;
                }
                break;
        }
    }
    return result;

}
Date::Date(){
    time_t currentTime = time({});
    tm* now = localtime(&currentTime);
    setDate(now->tm_mday,(now->tm_mon+1), (now->tm_year+1900));
}

void Date::setDate(int day, int month, int year){
    if(isValid(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else{
        string msg =to_string(day)+ "/"+to_string(month)+"/"+to_string(year);
        throw InvalidDataException(msg);
    }
}

bool Date::operator == (const Date& obj) const{
    if(this->day == obj.day && this->month == obj.month && this->year == obj.year){
        return true;
    }
    return false;
}
bool Date::operator > (const Date& obj)const{
    if(this->year > obj.year){
        return true;
    }
    if(this->month > obj.month){
        return true;
    }
    if(this->day > obj.day){
        return true;
    }
    return false;
}
bool Date::operator < (const Date& obj) const{
    if(*this == obj){
        return false;
    }

    if(*this > obj){
        return false;
    }
    return true;
}

string Date::getDate() {
    return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}
