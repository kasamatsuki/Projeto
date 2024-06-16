

#ifndef VIEWS_HEADERS_CLIENTVIEW_H
#define VIEWS_HEADERS_CLIENTVIEW_H

#include "Client.h"
#include "ClientList.h"

class ClientView {
public:
    string getUsername();
    string getPassword();
    string getName();
    void invalidUsername();
    void incorrectPassword();
    void clientNotFound();
};

#endif //VIEWS_HEADERS_CLIENTVIEW_H
