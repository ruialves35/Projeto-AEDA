#ifndef AEDA_BUYNOW_H
#define AEDA_BUYNOW_H

#include <iostream>
#include <Windows.h>
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

class ProdutoDoesNotExist{
public:
    int codigo;
    ProdutoDoesNotExist(int codigo){ this->codigo = codigo;}
    void showError() { cout << "O Produto com o codigo " << codigo << "nao existe." << endl;
    Sleep(600);
    }
};

class LojaFisicaDoesNotExist{
public:
    string localidade;
    LojaFisicaDoesNotExist(string localidade){ this->localidade = localidade;}
    void showError() { cout << "Não existe nenhuma loja fisica em " << localidade << endl;
        Sleep(600);
    }
};

/**
 * Exception Categoria Does Not Exist, on getCategoria of BuyNow
 */
class CategoriaDoesNotExist{
public:
    string nome;
    CategoriaDoesNotExist(string name){ nome = name; }
    void showError(){ cout << "A categoria " << nome << " nao existe." << endl; Sleep(600);}

};

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
    void removeCliente(string nome, int numContribuinte);
    void removeCliente(Cliente *cliente);
    bool checkCliente(Cliente &cliente);
    void addTransacao(Transacao *t);
    void removeTransacao(Transacao *t);
    void addProduto(Produto* p);
    void removeProduto(Produto* p);
    Produto* getProduto(int codigo) const;
    vector<Produto*> getProdutos() const;
    void addReposicao(Reposicao &reposicao);
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
    LojaFisica getLojaFisica(string localidade) const;
    vector<Cliente*> getClientes() const;
    Cliente* getCliente(string nome, int numContribuinte) const;
    LojaOnline getLojaOnline() const;
    vector<Transacao*> getTransacoes() const;
    vector<Transferencia*> getTransferencias() const;
    vector<Reposicao> getReposicoes() const;
    Categoria getCategoria(string categoria) const;
    vector<Categoria> getCategorias() const;
    void reporStock();
    void showTransacoes();
    void showProdutos();
    void showProdutosCategoria(string categoria);
    void showCategorias();
    void showClientes();
    void showReposicoes();
    void sortProdutosByValue();
    void sortProdutosByName();
    void sortProdutosById();

    static bool compareProdutosByValue(const Produto* p1, const Produto* p2){
        return (*p1).getValor() < (*p2).getValor();
    }

    static bool compareProdutosById(const Produto* p1, const Produto *p2){
        return (*p1).getId() == (*p2).getId();
    }

    static bool compareProdutosByName(const Produto* p1, const Produto *p2){
        return (*p1).getNomeProduto() < (*p2).getNomeProduto();
    }

    //void showAllProdutosOnline();
    //void showAllProdutosFisico();
};



#endif //AEDA_BUYNOW_H
