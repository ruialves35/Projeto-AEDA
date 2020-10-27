#ifndef AEDA_CLIENTEREGISTADO_H
#define AEDA_CLIENTEREGISTADO_H

#include <iostream>
#include "Cliente.h"
using namespace std;

class ClienteRegistado : public Cliente {
private:
    string email;
public:
    string getEmail() const;
    void setEmail(string email);
};


#endif //AEDA_CLIENTEREGISTADO_H
