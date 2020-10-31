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
    virtual ostream& getInfo(ostream &o) const;
};


#endif //PROJETO_PAGAMENTO_H
