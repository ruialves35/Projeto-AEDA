#ifndef AEDA_LOJAONLINE_H
#define AEDA_LOJAONLINE_H

#include <iostream>
#include "Produto.h"
#include "Transacao.h"
#include <vector>

using namespace std;

//exception ClienteDoesNotExist

class ClienteDoesNotExist{
public:
    Cliente* c;
    ClienteDoesNotExist(Cliente* cl){
        c = cl;
    }
};

/*
std::ostream& operator<<(std::ostream &out, const ClienteDoesNotExist &cl){
    out << "O seguinte cliente nao existe na nossa base de dados: Nome" << cl.c->getNome() << " NumeroContribuinte: " << cl.c->getNumContribuinte() << endl;
    return out;
}
*/

//-------------------------------------------------------------------

class LojaOnline{
private:
    map<Produto*, int> stockOnline;
    vector<Produto*> produtos;
    vector<Transacao*> transacoes;
    vector<Cliente *> clientes;
    unsigned int stockMin;
public:
    LojaOnline(); //ta
    LojaOnline(vector<Produto*> p, vector<Transacao*> t, vector<Cliente*> c);//ta
    void showAllProdutos() const; //ta
    void showAllTransacoes() const; //ta
    void showClients() const;
    void addProduto(Produto *p, int quantidade = 1); //ta
    void removeProduto(Produto *p);
    void removeProduto(Produto *p, int quantidade);
    void addCliente(Cliente *c); //ta
    void addTransacao(Transacao *t); //ta
    Cliente* getCliente(Cliente *c);  //ta
    void removeCliente(Cliente *c); //ta
    void addProdutoToTransacao(Transacao* t, Produto* p, int quantidade = 1);   //ta
    void removeProdutoOfTransacao(Transacao* t, Produto* p, int quantidade = 1);    //ta
    void sortProdutosByValue();
    void sortProdutosByName();
    void sortProdutosById();
    void sortTransacaoByDate();
    static bool compareProdutosByValue(const Produto* p1, const Produto* p2){
        return (*p1).getValor() < (*p2).getValor();
    }

    static bool compareProdutosById(const Produto* p1, const Produto *p2){
        return (*p1).getId() == (*p2).getId();
    }

    static bool compareProdutosByName(const Produto* p1, const Produto *p2){
        return (*p1).getNomeProduto() < (*p2).getNomeProduto();
    }
    static bool compareTransacoesByDate(const Transacao* t1, const Transacao *t2){
        return (*t1).getDate() < (*t2).getDate();
    }
};


#endif //AEDA_LOJAONLINE_H
