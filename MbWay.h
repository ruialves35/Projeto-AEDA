#ifndef AEDA_MBWAY_H
#define AEDA_MBWAY_H

#include <iostream>
#include "Transacao.h"

using namespace std;

class MbWay: public Transacao{
private:
    int numTelemovel;
public:
    int getNumTelemovel() const;
    void setNumTelemovel(int numTelemovel);
};


#endif //AEDA_MBWAY_H
