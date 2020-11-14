#ifndef AEDA_BUYNOW_H
#define AEDA_BUYNOW_H

#include <iostream>
#include "LojaFisica.h"
#include "LojaOnline.h"
#include "Cliente.h"
#include "Transacao.h"
#include <vector>
#include "Fornecedor.h"
#include "Transferencia.h"
using namespace std;

class BuyNow {
private:
    vector<LojaFisica> lojasFisicas;
    LojaOnline lojaOnline;
    Fornecedor fornecedor;
    int stockOk;
    int stockMin;
    vector<Transferencia*> transferencias;  //entre Fornecedor e loja
public:
    BuyNow();
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo);
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia*> tranferencias);
    ~BuyNow();
    void addCliente(Cliente *cliente);
    void removeCliente(Cliente *cliente);
    void addTransacao(Transacao *t);
    void removeTransacao(Transacao *t);
    void addLojaFisica(LojaFisica &lf);
    void removeLojaFisica(LojaFisica &lf);
    int getStockOk() const;
    int getStockMin() const;
    void setStockOk(unsigned int stockOk);
    void setStockMin(unsigned int stockMin);
    void addTransferencia(Transferencia * t);
    void removeTransferencia(Transferencia * t);
    vector<LojaFisica> getLojasFisicas() const;
    vector<Cliente*> getClientes() const;
    LojaOnline getLojaOnline() const;
    vector<Transacao*>getTransacoes() const;
    vector<Transferencia*>getTransferencias() const;
    void reporStock();
    void showAllProdutosOnline();
    void showAllProdutosFisico();
};



#endif //AEDA_BUYNOW_H
