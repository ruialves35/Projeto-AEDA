#ifndef AEDA_TRANSACAO_H
#define AEDA_TRANSACAO_H

#include <iostream>
#include <algorithm>

#include "Date.h"
#include "Produto.h"
#include "Cliente.h"
#include "Pagamento.h"

using namespace std;


class Transacao {
private:
    map<Produto*, int> quantidade;
    Date data;
    vector<Produto*> produtos;
    double valorTotal;
    //estatisticas(por definir)
    Cliente* cliente;
    Pagamento* tipoPagamento;

public:
    Transacao();
    Transacao(Cliente *c, Date &d);
    Transacao(Cliente *c, Date &d, vector<Produto*> v);
    Date getDate() const;
    void setDate(Date &d);
    void setCliente(Cliente *c);
    Cliente* getCliente() const;
    void addProduto(Produto* p);
    void addProduto(Produto* p, int quantidade);
    void removeProduto(Produto *p);
    void removeProduto(Produto *p, int quantidade);
    int getQuantidade(Produto *p) const;
    void setPagamento(Pagamento* p);
    Pagamento* getPagamento() const;
    friend ostream& operator << (ostream &o, const Transacao &t);
};


#endif //AEDA_TRANSACAO_H
