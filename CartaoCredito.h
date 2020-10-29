#ifndef AEDA_CARTAOCREDITO_H
#define AEDA_CARTAOCREDITO_H

#include "Transacao.h"
#include "Date.h"

class CartaoCredito: public Pagamento{
private:
    long int numCartao;
    Date validade;
public:
    CartaoCredito();
    CartaoCredito(double valor, long int numCartao, Date val);
    long int getNumCartao() const;
    void setNumCartao(long int numCartao);
    void setValidade(Date validade);
    Date getValidade() const;
    string getInfo() const;
};


#endif //AEDA_CARTAOCREDITO_H
