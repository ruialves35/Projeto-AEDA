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
    MbWay(double valor, int num);
    int getNumTelemovel() const;
    void setNumTelemovel(int num);
    string getInfo() const;
};


#endif //AEDA_MBWAY_H
