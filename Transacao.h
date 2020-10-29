#ifndef AEDA_TRANSACAO_H
#define AEDA_TRANSACAO_H

#include <iostream>
#include <algorithm>

#include "Date.h"
#include "Produto.h"
#include "Cliente.h"

using namespace std;

class Transacao {
private:
    Date data;
    vector<Produto*> produtos;
    double valorTotal;
    //estatisticas(por definir)
    Cliente cliente;

public:
    Transacao();
    Date getDate() const;
    void setDate(Date &d);
    void addProduto(Produto* p);
    void removeProduto(Produto *p);
    friend ostream& operator << (ostream &o, const Transacao &t);
};


#endif //AEDA_TRANSACAO_H
