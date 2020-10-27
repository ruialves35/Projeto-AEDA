#ifndef AEDA_MULTIBANCO_H
#define AEDA_MULTIBANCO_H

#include <iostream>
#include "Transacao.h"

class Multibanco: public Transacao {
private:
    int referencia;
public:
    void setReferencia(int referencia);
    int getReferencia() const;
};


#endif //AEDA_MULTIBANCO_H
