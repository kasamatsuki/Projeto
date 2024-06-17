//
// Created by diogo on 16/06/2024.
//
#ifndef VIEWS_HEADERS_UTILS_H
#define VIEWS_HEADERS_UTILS_H

#include <string>
#include "InvalidDataException.h"
#include "Date.h"

using namespace std;

class Utils{
public:
    static int getNumber(const string&  label);
    static unsigned int getUInt(const string& label);
    static float getFloat(const string& label);
    static string getString(const string&  label);
    static bool stringIsNumber(string& s);
    static bool getBool(const string &label);
};

#endif //VIEWS_HEADERS_UTILS_H