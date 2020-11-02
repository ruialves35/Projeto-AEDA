#ifndef AEDA_MULTIBANCO_H
#define AEDA_MULTIBANCO_H

#include <iostream>
#include "Transacao.h"

using namespace std;

//exception WrongReferencia
class WrongReferencia{
public:
    int referencia;
    WrongReferencia(int referencia) {
        this->referencia = referencia;
    }
};
/*
ostream& operator << (ostream& o, const WrongReferencia ref){
    o << "Referencia Inválida. A referencia tem de ter 9 digitos." << endl;
    return o;
}
*/

class Multibanco: public Pagamento {
private:
    int referencia;
public:
    Multibanco();
    Multibanco(double valorTotal, int referencia);
    void setReferencia(int referencia);
    int getReferencia() const;
    void getInfo(ostream &o) const;
};


#endif //AEDA_MULTIBANCO_H
