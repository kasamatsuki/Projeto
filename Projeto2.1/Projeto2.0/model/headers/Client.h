
#ifndef MODEL_HEADERS_CLIENT_H
#define MODEL_HEADERS_CLIENT_H

#include "User.h"

#include <string>
#include <list>

using namespace std;

class Client: protected User{

public:
    Client(string &pUsername, string &pPassword);
    Client(string &username, string &password,string &name);
    Client& get();
    string getUsername() const;
    string getPassword() const;
    string getName() const;

    bool doesPasswordMatch(string& password);

    bool operator == (const Client& obj) const;
    bool operator == (string& username) const;
};

#endif //MODEL_HEADERS_CLIENT_H
