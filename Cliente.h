#ifndef AEDA_CLIENTE_H
#define AEDA_CLIENTE_H

#include <iostream>

using namespace std;

class Cliente{
private:
    string nome;
    int numContribuinte;
public:
    string getNome(){
        return nome;
    }

    void setNome(string nome){
        this->nome=nome;
    }

    int getNumContribuinte(){
        return numContribuinte;
    }

    void setNumContribuinte(int numContribuinte){
        this->numContribuinte=numContribuinte;
    }

    Cliente(string nome, int numContribuinte);
};

Cliente::Cliente(string nome, int numContribuinte){
    this->nome=nome;
    this->numContribuinte=numContribuinte;
}



#endif //AEDA_CLIENTE_H

