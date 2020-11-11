#include "LojaFisica.h"
#include <algorithm>

using namespace std;
/**
 * Default constructor, doesnt do anything
 */
LojaFisica::LojaFisica(){}

/**
 * Constructor with vector of Produto* already done
 * @param p vector of Produto*
 */
LojaFisica::LojaFisica(vector<Produto*> &p) {
    produtos = p;
    for (auto i : produtos){
        if (stockFisico.find(i) == stockFisico.end() ) stockFisico[i] = 1;
        else stockFisico[i]++;
    }
}

/**
 * Adds a quantity of a Produto to vector of Produto of the LojaFisica
 * @param produto Product that will be added to Loja Fisica
 * @param quantidade Quantity of the Produto
 */
void LojaFisica::addProduto(Produto *produto, int quantidade) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), produto);
    if ( it == produtos.end()) {
        produtos.push_back(produto);
        stockFisico[produto] = quantidade;
    }
    else{
        stockFisico[produto] += quantidade;
    }
}

/**
 * Removes a Product from LojaFisica
 * @param produto Product to be removed
 */
void LojaFisica::removeProduto(Produto *produto) {
    vector<Produto*>::iterator it =find(produtos.begin(), produtos.end(), produto);
    if (it != produtos.end()){
        produtos.erase(it);
    }
}

/**
 * Removes a Product from vector of LojaFisica
 * @param produto Product to be removed
 * @param quantidade Quantity to be removed
 */
void LojaFisica::removeProduto(Produto *produto, int quantidade) {
    vector<Produto*>::iterator it =find(produtos.begin(), produtos.end(), produto);
    if (it != produtos.end()){
        if (stockFisico[produto] < quantidade) produtos.erase(it);
        else stockFisico[produto] -= quantidade;
    }
}

/**
 * @return vector of Pointers that points to Produtos of LojaFisica
 */
vector<Produto *> LojaFisica::getProdutos() const {
    return produtos;
}