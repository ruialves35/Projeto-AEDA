#ifndef PROJETO_PAGAMENTO_H
#define PROJETO_PAGAMENTO_H

#include <iostream>

using namespace std;

class Pagamento {
    double valor;
public:
    Pagamento();
    Pagamento(double valorTotal);
    void setValor(double val);
    double getValor() const;
    virtual void getInfo(ostream &o) const;
    virtual string getTipo() const;
};


#endif //PROJETO_PAGAMENTO_H
