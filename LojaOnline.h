#ifndef AEDA_LOJAONLINE_H
#define AEDA_LOJAONLINE_H

#include <iostream>
#include "Produto.h"
#include "Transacao.h"
#include "BuyNow.h"
#include <vector>

using namespace std;

class LojaOnline{
private:
    vector<Produto*> produtos;
    vector<Transacao*> transacoes;  //por completar
    vector<Cliente *> clientes;
    unsigned int stockMin;
public:
    LojaOnline();
    void showAllProdutos() const;
    void showAllTransacoes() const;
    void reporStock();
    void addProduto(Produto *p);
    void addCliente(Cliente *c);
    void addTransacao(Transacao *t);    //incrementar o numberOfTransacoes;
    Cliente& getCliente(Cliente *c);
    void removeCliente(Cliente *c);
    void addProdutoToTransacao(Transacao* t, Produto* p);
    void removeProdutoOfTransacao(Transacao* t, Produto* p);
    void removeProdutoOfTransacao(Transacao* t, Produto* p, int quantidade);
};


#endif //AEDA_LOJAONLINE_H
