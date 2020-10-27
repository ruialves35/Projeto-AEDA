#ifndef AEDA_LOJAFISICA_H
#define AEDA_LOJAFISICA_H

#include <iostream>
#include <vector>
#include "Produto.h"

using namespace std;

class LojaFisica{
private:
    vector<Produto*> produtos;
public:
    void addProduto(Produto &produto);
    vector<Produto*> getProdutos() const;
};


#endif //AEDA_LOJAFISICA_H
