
#ifndef EXCEPTION_HEADERS_DUPLICATEENTRYEXCEPTION_H_
#define EXCEPTION_HEADERS_DUPLICATEENTRYEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class DuplicateEntryException : public exception{
private:
    string data;
public:
    DuplicateEntryException(string data);
    //override what function
    const char* what();
};

#endif //EXCEPTION_HEADERS_DUPLICATEENTRYEXCEPTION_H_