#include "LojaFisica.h"
#include <algorithm>
#include <iomanip>

using namespace std;
/**
 * Default constructor, doesnt do anything
 */
LojaFisica::LojaFisica(): localidade("") { }

/**
 * Constructor of LojaFisica
 * @param localidade Location of LojaFisica
 */
LojaFisica::LojaFisica(string localidade): localidade(localidade) {}

void LojaFisica::addProduto(Produto *produto, int quantidade) {
    if (stockFisico.find(produto) == stockFisico.end()){
        stockFisico[produto] = quantidade;
    }
    else{
        stockFisico[produto] += quantidade;
    }
}

/**
 * Removes a Quantity of Produto of LojaFisica
 * @param produto Produto to be removed
 * @param quantidade Quantity of produto
 */
void LojaFisica::removeProduto(Produto *produto, int quantidade) {
    if (stockFisico.find(produto) != stockFisico.end()){
        if (stockFisico[produto] < quantidade) stockFisico[produto] = 0;
        else stockFisico[produto] -= quantidade;
    }
    else stockFisico[produto] = 0;
}

/*
 * Removes a Product from vector of LojaFisica
 * @param produto Product to be removed
 * @param quantidade Quantity to be removed
void LojaFisica::removeProduto(Produto *produto, int quantidade) {
    vector<Produto*>::iterator it =find(produtos.begin(), produtos.end(), produto);
    if (it != produtos.end()){
        if (stockFisico[produto] < quantidade) produtos.erase(it);
        else stockFisico[produto] -= quantidade;
    }
}*/

/*
 * @return vector of Pointers that points to Produtos of LojaFisica
vector<Produto *> LojaFisica::getProdutos() const {
    return produtos;
}*/

/**
 * Gets the StockFisico of a Produto
 * @param p Produto to get StockFisico
 * @return 0 if there is no product, stock of Produto otherwise
 */
int LojaFisica::getStockFisico(Produto *p) {
    if (stockFisico.find(p) != stockFisico.end()) return stockFisico[p];
    return 0;
}

/**
 * Sets localidade of LojaFisica
 * @param localidade new Localidade
 */
void LojaFisica::setLocalidade(string localidade) { this -> localidade = localidade; }

/**
 * Gets localidade of Loja fisica
 * @return string with localidade
 */
string LojaFisica::getLocalidade() const { return localidade;}


/*
 * Sets produtos of LojaFisica
 * @param produtos Vector with Produtos of LojaFisica
void LojaFisica::setProdutos(vector<Produto *> produtos) {
    this->produtos = produtos;
}*/

/*
 * Displays Produtos of LojaFisica
void LojaFisica::showProdutos() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << endl;
    for (auto i: produtos){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << endl;
    }
}*/

/**
 * Operator == to compare 2 LojaFisica
 * @param l2 Second LojaFisica to compare
 * @return true if they are in the same location (there is just 1 LojaFisica for location)
 */
bool LojaFisica::operator==(const LojaFisica &l2) {
    return this->localidade == l2.localidade;
}