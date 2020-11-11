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
}

/**
 * Adds a Produto to vector of Produto of the LojaFisica
 * @param produto
 */
void LojaFisica::addProduto(Produto *produto, int quantidade) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), produto);
    if ( it == produtos.end()) {
        produto->setStockFisico(quantidade);
        produtos.push_back(produto);
    }
    else{
        (*it)->setStockFisico((*it)->getStockFisico() + quantidade);
    }
}

/**
 * @return vector of Pointers that points to Produtos of LojaFisica
 */
vector<Produto *> LojaFisica::getProdutos() const {
    return produtos;
}