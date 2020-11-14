#include "LojaFisica.h"
#include <algorithm>
#include <iomanip>

using namespace std;
/**
 * Default constructor, doesnt do anything
 */
LojaFisica::LojaFisica(){ localidade = ""; }

/**
 * Constructor with vector of Produto* already done
 * @param p vector of Produto*
 */
LojaFisica::LojaFisica(vector<Produto*> &p, string localidade) {
    this->localidade = localidade;
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

/*
 * Removes a Product from LojaFisica
 * @param produto Product to be removed

void LojaFisica::removeProduto(Produto *produto) {
    vector<Produto*>::iterator it =find(produtos.begin(), produtos.end(), produto);
    if (it != produtos.end()){
        produtos.erase(it);
    }
}
*/

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

/**
 * Gets the StockFisico of a Produto
 * @param p Produto to get StockFisico
 * @return 0 if there is no product, stock of Produto otherwise
 */
int LojaFisica::getStockFisico(Produto *p) {
    if (find(produtos.begin(), produtos.end(), p) != produtos.end()) return stockFisico[p];
    return 0;
}

/**
 * Sets produtos of LojaFisica
 * @param produtos Vector with Produtos of LojaFisica
 */
void LojaFisica::setProdutos(vector<Produto *> produtos) {
    this->produtos = produtos;
}

/**
 * Displays Produtos of LojaFisica
 */
void LojaFisica::showProdutos() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << endl;
    for (auto i: produtos){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << endl;
    }
}

bool LojaFisica::operator==(const LojaFisica &l2) {
    return this->localidade == l2.localidade;
}