#ifndef AEDA_TRANSACAO_H
#define AEDA_TRANSACAO_H

#include <iostream>
#include <algorithm>

#include "Date.h"
#include "Produto.h"
#include "Cliente.h"
#include "Pagamento.h"

using namespace std;


class Transacao{
private:
    static int numberOfTransacoes;
    int number;
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
    Transacao(Cliente *c, Date &d, vector<Produto*> v, Pagamento *p);
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
    int getNumber() const;
    double getValorTotal() const;
    void sortByValue();
    void sortByName();

    static bool compareProdutosByValue(const Produto* p1, const Produto* p2){
        return (*p1).getValor() < (*p2).getValor();
    }

    static bool compareProdutosById(const Produto* p1, const Produto *p2){
        return (*p1).getId() == (*p2).getId();
    }

    static bool compareProdutosByName(const Produto* p1, const Produto *p2){
        return (*p1).getNomeProduto() < (*p2).getNomeProduto();
    }

    friend ostream& operator << (ostream &o, const Transacao &t);
    friend bool operator == (const Transacao &t1, const Transacao &t2);
};


#endif //AEDA_TRANSACAO_H
