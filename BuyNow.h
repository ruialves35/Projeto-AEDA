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
#include "Categoria.h"
#include "Reposicao.h"
using namespace std;

/**
 * Exception Categoria Does Not Exist, on getCategoria of BuyNow
 */
class CategoriaDoesNotExist{
public:
    string nome;
    CategoriaDoesNotExist(string name){ nome = name; }
};

template <class N>
std::ostream& operator<<(std::ostream &out, const CategoriaDoesNotExist cat){
    out << "Categoria does not exist: " << cat.nome << endl;
    return out;
}
//-----------------------------------------------------------------------
class BuyNow {
private:
    vector<Produto *> produtos;
    vector<Cliente *> clientes;
    vector<Categoria> categorias;
    vector<Reposicao> reposicoes;

    vector<LojaFisica> lojasFisicas;
    LojaOnline lojaOnline;
    Fornecedor fornecedor;
    int stockOk;
    int stockMin;
    vector<Transferencia*> transferencias;  //entre Fornecedor e loja
public:
    BuyNow();
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, int stockOk, int stockMin);
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia*> tranferencias, int stockOk, int stockMin);
    ~BuyNow();
    void addCategoria(Categoria &c);
    void removeCategoria(Categoria &c);
    Fornecedor getFornecedor() const;
    void setFornecedor(Fornecedor &f);
    void addCliente(Cliente *cliente);
    void removeCliente(Cliente *cliente);
    bool checkCliente(Cliente &cliente);
    void addTransacao(Transacao *t);
    void removeTransacao(Transacao *t);
    void addProduto(Produto* p);
    void removeProduto(Produto* p);
    void addLojaFisica(LojaFisica &lf);
    void removeLojaFisica(LojaFisica &lf);
    void addProdutoLojaFisica(LojaFisica &lf, Produto* p, int quantidade = 1);
    void addProdutoLojaFisica(string localidade, Produto* p, int quantidade = 1);
    void removeProdutoLojaFisica(LojaFisica &lf, Produto* p, int quantidade = 1);
    void addProdutoOnline(Produto* p, int quantidade = 1);
    void removeProdutoOnline(Produto* p, int quantidade = 1);
    int getStockOk() const;
    int getStockMin() const;
    void setStockOk(unsigned int stockOk);
    void setStockMin(unsigned int stockMin);
    void addTransferencia(Transferencia * t);
    void removeTransferencia(Transferencia * t);
    vector<LojaFisica> getLojasFisicas() const;
    vector<Cliente*> getClientes() const;
    LojaOnline getLojaOnline() const;
    vector<Transacao*> getTransacoes() const;
    vector<Transferencia*> getTransferencias() const;
    Categoria getCategoria(string categoria) const;
    void reporStock();
    void showTransacoes();
    void showProdutos();
    void showProdutosCategoria(string categoria);
    void showCategorias();


    //void showAllProdutosOnline();
    //void showAllProdutosFisico();
};



#endif //AEDA_BUYNOW_H
