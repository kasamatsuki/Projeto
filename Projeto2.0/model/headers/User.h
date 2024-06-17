
#ifndef MODEL_HEADERS_USER_H
#define MODEL_HEADERS_USER_H

#include <string>
#include "iostream"

using namespace std;

class User{
protected:
    string username;
    string password;
    string name;
    string role;
    User();
    User(string& pUsername, string& pPassword);
    void setUsername(string& pUsername);
public:
    string getUsername() const;

    void setName(string pName);
    void setPassword(string& pPassword);
    void setRole(string pRole);
    void printUserInfo();

    string getPassword();
    string getName();
    string getRole();

};

#endif //MODEL_HEADERS_USER_H