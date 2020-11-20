#ifndef AEDA_MBWAY_H
#define AEDA_MBWAY_H

#include <iostream>
#include "Transacao.h"

using namespace std;

class MbWay: public Pagamento{
private:
    int numTelemovel;
public:
    MbWay();
    MbWay(int num);
    MbWay(double valor, int num);
    int getNumTelemovel() const;
    void setNumTelemovel(int num);
    void getInfo(ostream& o) const;
    string getTipo() const;
};


#endif //AEDA_MBWAY_H
