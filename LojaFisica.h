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
    vector<Produto*> produtos;
public:
    LojaFisica();
    LojaFisica(vector<Produto*> &p, string localidade);
    void addProduto(Produto* produto, int quantidade = 1);
    vector<Produto*> getProdutos() const;
    void setProdutos(vector <Produto*> produtos);
    int getStockFisico(Produto *p);
    void removeProduto(Produto *produto, int quantidade = 1);
    void showProdutos();
    bool operator == (const LojaFisica &l2);
};


#endif //AEDA_LOJAFISICA_H
