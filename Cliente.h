#ifndef AEDA_CLIENTE_H
#define AEDA_CLIENTE_H

#include <iostream>
using namespace std;

class Cliente{
private:
    string nomeCliente;
    int numContribuinteCliente;
public:
    Cliente();
    Cliente(string nome, int num);
    string getNome() const;
    void setNome(string nome);
    int getNumContribuinte() const;
    void setNumContribuinte(int numContribuinte);
    friend bool operator == (Cliente& c1, Cliente& c2);
    friend ostream& operator << (ostream &o, Cliente &c1);
};


#endif //AEDA_CLIENTE_H

