#ifndef AEDA_CLIENTEREGISTADO_H
#define AEDA_CLIENTEREGISTADO_H

#include <iostream>
#include "Cliente.h"
using namespace std;

class ClienteRegistado : public Cliente {
private:
    static int numeroClientesRegistados;
    int id;
    string email;
public:
    ClienteRegistado();
    ClienteRegistado(string nome, int numContribuint, string email);
    void setId(int id);
    int getId() const;
    string getEmail() const;
    void setEmail(string email);
    void setNumeroClientesRegistados(int ncr);
    int getNumeroClientesRegistados() const;
};


#endif //AEDA_CLIENTEREGISTADO_H
