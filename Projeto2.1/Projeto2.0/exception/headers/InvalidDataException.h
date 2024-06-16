
#ifndef EXCEPTIONS_HEADERS_INVALIDDATAEXCEPTION_H_
#define EXCEPTIONS_HEADERS_INVALIDDATAEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class InvalidDataException :public exception{
private:
    string data;
public:
    InvalidDataException(string data);
    //override what function
    const char* what();
};

#endif //EXCEPTIONS_HEADERS_INVALIDDATAEXCEPTION_H_
