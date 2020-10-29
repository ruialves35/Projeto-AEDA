#ifndef PROJETO_PAGAMENTO_H
#define PROJETO_PAGAMENTO_H

#include <iostream>

using namespace std;

class Pagamento {
    double valor;
public:
    Pagamento();
    Pagamento(double valorTotal);
    virtual void show() const;
};


#endif //PROJETO_PAGAMENTO_H
