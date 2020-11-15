#ifndef AEDA_LOJAFISICA_H
#define AEDA_LOJAFISICA_H

#include <iostream>
#include <vector>
#include "Produto.h"
#include <map>
using namespace std;

class LojaFisica{
private:
    string localidade;
    map<Produto*, int> stockFisico;
    //vector<Produto*> produtos;

public:
    LojaFisica();
    LojaFisica(string localidade); //mudar
    void addProduto(Produto* produto, int quantidade = 1);
    void removeProduto(Produto *produto, int quantidade = 1);
    int getStockFisico(Produto *p);
    bool operator == (const LojaFisica &l2);

    //vector<Produto*> getProdutos() const;
    //void setProdutos(vector <Produto*> produtos);
    //void showProdutos();
};


#endif //AEDA_LOJAFISICA_H
