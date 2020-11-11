#ifndef AEDA_LOJAFISICA_H
#define AEDA_LOJAFISICA_H

#include <iostream>
#include <vector>
#include "Produto.h"
#include <map>
using namespace std;

class LojaFisica{
private:
    map<Produto*, int> stockFisico;
    vector<Produto*> produtos;
public:
    LojaFisica();
    LojaFisica(vector<Produto*> &p);
    void addProduto(Produto* produto, int quantidade = 1);
    vector<Produto*> getProdutos() const;
    int getStockFisico(Produto *p);
    void removeProduto(Produto *produto);
    void removeProduto(Produto *produto, int quantidade);
};


#endif //AEDA_LOJAFISICA_H
