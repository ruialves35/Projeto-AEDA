#ifndef AEDA_CLIENTE_H
#define AEDA_CLIENTE_H

#include <iostream>

using namespace std;

class Cliente{
private:
    string nome;
    int numContribuinte;
public:
    string getNome() const;
    void setNome(string nome);
    int getNumContribuinte() const;
    void setNumContribuinte(int numContribuinte);
};


#endif //AEDA_CLIENTE_H
