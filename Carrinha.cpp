#include "Carrinha.h"
#include <iostream>

Carrinha::Carrinha(){
    id = 1;
    ocupacao = 0;
    ocupacaoMaxima = 20;
}

Carrinha::Carrinha(int idCarrinha, int ocupacaoCarrinha, int ocupacaoMaximaCarrinha) {
    id=idCarrinha;
    ocupacao=ocupacaoCarrinha;
    ocupacaoMaxima=ocupacaoMaximaCarrinha;
}

int Carrinha::getID() const{
    return id;
}

int Carrinha::getOcupacao() const{
    return ocupacao;
}

void Carrinha::SetOcupacao(int valor) {
    ocupacao=valor;
}

int Carrinha::getOcupacaoMaxima() const{
    return ocupacaoMaxima;
}

void Carrinha::SetOcupacaoMaxima(int valor) {
    ocupacao=valor;
}

int Carrinha::calcularEspacoLivre() const{
    return ocupacaoMaxima-ocupacao;
}

void Carrinha::addOcupacao(int valorAdicionado) {
    ocupacao+=valorAdicionado;
}

bool Carrinha::prontaDespachar() const {
    double percentagem = ocupacao/ocupacaoMaxima;
    if(percentagem < 0.9) {
        return false;
    }
    return true;
}

bool Carrinha::operator<(const Carrinha& c1) const {
    return ocupacaoMaxima - ocupacao > ocupacaoMaxima - c1.getOcupacao();
}


