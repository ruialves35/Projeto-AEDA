#ifndef PROJETO_NUMEROTRANSACOES_H
#define PROJETO_NUMEROTRANSACOES_H

#include <iostream>
using namespace std;

class NumeroTransacoes {
private:
    static int numberOfTransacoes;
public:
    NumeroTransacoes();
    NumeroTransacoes(int num);
    void setNumberOfTransacoes(int num);
    int getNumberOfTransacoes() const;
    void addNumberOfTransacoes(int num);
};


#endif //PROJETO_NUMEROTRANSACOES_H
