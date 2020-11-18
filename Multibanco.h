#ifndef AEDA_MULTIBANCO_H
#define AEDA_MULTIBANCO_H

#include <iostream>
#include "Transacao.h"

using namespace std;

class Multibanco: public Pagamento {
private:
    int referencia;
public:
    Multibanco();
    Multibanco(int referencia);
    Multibanco(double valorTotal, int referencia);
    void setReferencia(int referencia);
    int getReferencia() const;
    void getInfo(ostream &o) const;
    string getTipo() const;

};


#endif //AEDA_MULTIBANCO_H
