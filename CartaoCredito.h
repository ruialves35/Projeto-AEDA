#ifndef AEDA_CARTAOCREDITO_H
#define AEDA_CARTAOCREDITO_H


class CartaoCredito: public Transacao{
private:
    long int numCartao;
    Date validade;
public:
    long int getNumCartao() const;
    void setNumCartao(long int numCartao);
    void setValidade(date validade);
    Date getValidade() const;
}


#endif //AEDA_CARTAOCREDITO_H
