#ifndef AEDA_LOJAONLINE_H
#define AEDA_LOJAONLINE_H

#include <iostream>
#include "Produto.h"
#include "Transacao.h"
#include <vector>

using namespace std;

class LojaOnline{
private:
    vector<Produto*> produtos;
    vector<Transacao*> transacoesCompletas; //ja pagou
    vector<Transacao*> transacoes;  //por completar
    vector<Cliente *> clientes;
    unsigned int stockMin;
public:
    void showAllProdutos() const;
    void reporStock();
    void addProduto(Produto produto);
    void addCliente(Cliente *c);
    void addTransacao(Transacao *t);    //incrementar o numberOfTransacoes;
    Cliente& getCliente(Cliente *c);
    Cliente& getCliente(int pos);
    void removeCliente(Cliente *c);
    void buyProduto(Cliente *c, Produto* p);
    void addProdutoToTransacao(Transacao* t, Produto* p);
    void removeProdutoOfTransacao(Transacao* t, Produto* p);
    void removeProdutoOfTransacao(Transacao* t, Produto* p, int quantidade);
    void completeTransacao(Transacao* t);
    void showAllTransacoes() const;
    void showAllTransacoesCompletas() const;
    friend ostream& operator << (ostream &o, const LojaOnline);
};


#endif //AEDA_LOJAONLINE_H
