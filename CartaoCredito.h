#ifndef AEDA_CARTAOCREDITO_H
#define AEDA_CARTAOCREDITO_H

#include "Transacao.h"
#include "Date.h"

class CartaoCredito: public Pagamento{
private:
    string numCartao;
    Date validade;
public:
    CartaoCredito();
    CartaoCredito(string numCartao, Date val);
    CartaoCredito(double valor, string numCartao, Date val);
    string getNumCartao() const;
    void setNumCartao(string numCartao);
    void setValidade(Date validade);
    Date getValidade() const;
    void getInfo(ostream& o) const;
};


#endif //AEDA_CARTAOCREDITO_H
