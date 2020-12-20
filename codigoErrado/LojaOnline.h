#ifndef AEDA_LOJAONLINE_H
#define AEDA_LOJAONLINE_H

#include <iostream>
#include "Produto.h"
#include "Transacao.h"
#include <vector>

using namespace std;

class LojaOnline{
private:
    map<Produto*, int> stockOnline;
    vector<Transacao*> transacoes;
    //vector<Cliente *> clientes;
    //vector<Produto*> produtos;
    //unsigned int stockMin;
public:
    LojaOnline();
    LojaOnline(vector<Transacao*> t);
    void showAllTransacoes() const;
    //void showAllProdutos();
    //void showClients() const;
    //void removeProduto(Produto *p);
    //void addStockOnline(Produto* p, int quantidade = 1);
    //vector<Produto*> getProdutos() const;
    //vector<Cliente*> getClientes() const;
    //void setProdutos(vector<Produto*> produtos);
    //Cliente* getCliente(Cliente *c);
    //void removeCliente(Cliente *c);
    //void addCliente(Cliente *c);
    //void sortProdutosByValue();
    //void sortProdutosByName();
    //void sortProdutosById();

    void addProduto(Produto *p, int quantidade = 1);
    void removeProduto(Produto *p, int quantidade = 1);
    int getStockOnline(Produto* p);
    vector<Transacao*> getTransacoes() const;
    void addTransacao(Transacao *t);
    void removeTransacao(Transacao *t);
    void addProdutoToTransacao(Transacao* t, Produto* p, int quantidade = 1);
    void removeProdutoOfTransacao(Transacao* t, Produto* p, int quantidade = 1);
    void sortTransacaoByDate();
    static bool compareTransacoesByDate(const Transacao* t1, const Transacao *t2){
        return (*t1).getDate() < (*t2).getDate();
    }

    /*
    static bool compareProdutosByValue(const Produto* p1, const Produto* p2){
        return (*p1).getValor() < (*p2).getValor();
    }

    static bool compareProdutosById(const Produto* p1, const Produto *p2){
        return (*p1).getId() == (*p2).getId();
    }

    static bool compareProdutosByName(const Produto* p1, const Produto *p2){
        return (*p1).getNomeProduto() < (*p2).getNomeProduto();
    }*/

};


#endif //AEDA_LOJAONLINE_H
