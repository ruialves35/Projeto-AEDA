//
// Created by ruial on 24/10/2020.
//

#include "Cliente.h"
#include "../Projeto AEDA - Usar/Cliente.h"

#include <iostream>

string Cliente::getNome() const{
    return nomeCliente;
}

void Cliente::setNome(string nome){
    nomeCliente=nome;
}

int Cliente::getNumContribuinte() const{
    return numContribuinteCliente;
}

void Cliente::setNumContribuinte(int numContribuinte){
    numContribuinteCliente=numContribuinte;
}

Cliente::Cliente() {

}
