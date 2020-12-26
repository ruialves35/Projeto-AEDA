#ifndef LOJAONLINE_CPP_CARRINHA_H
#define LOJAONLINE_CPP_CARRINHA_H

#include <iostream>
using namespace std;

class Carrinha {
private:
    int id;
    int ocupacao;
    int ocupacaoMaxima;

public:
    Carrinha();
    Carrinha(int idCarrinha, int ocupacaoCarrinha, int ocupacaoMaximaCarrinha);
    int getID() const;
    int setID(int novoid);
    int getOcupacao() const;
    void SetOcupacao(int valor);
    int getOcupacaoMaxima() const;
    void SetOcupacaoMaxima(int valor);
    int calcularEspacoLivre() const;
    void addOcupacao(int valorAdicionado);
    bool prontaDespachar() const;
    bool operator<<(const Carrinha& c1) const;
};



#endif //LOJAONLINE_CPP_CARRINHA_H
