#include "LojaOnline.h"
#include <algorithm>
#include <vector>
using namespace std;

LojaOnline::LojaOnline() {}

/**
 * Constructor of LojaOnline
 * @param p vector of the Products of the shop
 * @param t vector of Transacoes done by the shop
 * @param c vector of Clients of the shop
 */
LojaOnline::LojaOnline(vector<Produto *> p, vector<Transacao *> t, vector<Cliente *> c):produtos(p), transacoes(t), clientes(c) {
    for (auto i : produtos){
        if ( stockOnline.find(i) == stockOnline.end() ) stockOnline[i] = 1;
        else stockOnline[i]++;
    }
}



/**
 * Adds a quantity of a Product to the LojaOnline stock
 * @param p product to be added
 * @param quantidade quantity of the product
 */
void LojaOnline::addProduto(Produto *p, int quantidade) {
    vector<Produto*>::iterator iter = find(produtos.begin(), produtos.end(), p);
    if (iter == produtos.end()){
        stockOnline[p] = quantidade;
        produtos.push_back(p);
    }
    else{
        stockOnline[p] += quantidade;
    }
}

/**
 * Removes a product from LojaOnline
 * @param p Product to be removed
 */
void LojaOnline::removeProduto(Produto *p) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), p);
    if (it != produtos.end()){
        produtos.erase(it);
    }
}

/**
 * Removes a quantity of a Product to the LojaOnline stock
 * If doesnt put a quantity, it is set to 1 by default (check .h file)
 * @param p product to be added
 * @param quantidade quantity of the product
 */
void LojaOnline::removeProduto(Produto *p, int quantidade) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), p);
    if (it != produtos.end()){
        if (stockOnline[p] < quantidade) produtos.erase(it);
        else stockOnline[p] -= quantidade;
    }
}

/**
 * Add a client to the Online Shop
 * @param c client to be added
 */
void LojaOnline::addCliente(Cliente *c) {
    vector<Cliente*>::iterator it = find(clientes.begin(), clientes.end(), c);
    if (it == clientes.end()){
        clientes.push_back(c);
    }
}

/**
 * Adds a Transacao to the Online Shop
 * @param t Transacao to be added
 */
void LojaOnline::addTransacao(Transacao *t) {
    vector<Transacao*>::iterator it = find(transacoes.begin(), transacoes.end(), t);
    if (it == transacoes.end()) {
        transacoes.push_back(t);
    }
}

/**
 * Removes a client from the Online Shop
 * @param c client to be removed
 */
void LojaOnline::removeCliente(Cliente *c) {
    vector<Cliente*>::iterator it = find(clientes.begin(), clientes.end(), c);
    if (it != clientes.end()) {
        clientes.erase(it);
    }
}

/**
 * Displays all Transacoes of the Online Shop
 */
void LojaOnline::showAllTransacoes() const {
    for (auto i : transacoes){
        cout << i << endl;
    }
}

/**
 * displays all clients of LojaOnline
 */
void LojaOnline::showClients() const {
    for (auto i: clientes){
        cout << i->getInfo() << endl;
    }
}

/**
 * displays all products available in the store, each quantity and price
 */
void LojaOnline::showAllProdutos() const {
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto" << setfill(' ') << setw(15) << "Quantidade " << setfill(' ') << setw(15) << "Preco" << endl << endl;
    for (auto i : produtos){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15)<< i->getStockOnline() << setfill(' ') << setw(15) << i->getValor() << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

/**
 * Gets a Cliente of LojaOnline. Throws an error if Cliente is not in data base of Loja Online.
 * @param c client to be getted
 * @return
 */
Cliente* LojaOnline::getCliente(Cliente *c) {
    vector<Cliente*>::iterator it = find(clientes.begin(), clientes.end(), c);
    if (it == clientes.end()){
        throw ClienteDoesNotExist(c);
    }

    return (*it);
}

/**
 * Adds a quantity of a Product to a Transacao of Online Shop
 * @param t Transacao to be changed
 * @param p Product to be added
 * @param quantidade quantity of the product to be added
 */
void LojaOnline::addProdutoToTransacao(Transacao *t, Produto *p, int quantidade) {
    t->addProduto(p, quantidade);
}

/**
 * Removes a quantity of a Produto presented in Transacao of Online Shop
 * @param t
 * @param p
 * @param quantidade
 */
void LojaOnline::removeProdutoOfTransacao(Transacao *t, Produto *p, int quantidade) {
    t->removeProduto(p, quantidade);
}

/**
 * Sort Produtos of the Online Shop by id
 */
void LojaOnline::sortProdutosById() {
    sort(produtos.begin(), produtos.end(), compareProdutosById);
}

/**
 * Sort Produtos of the Online Shop by name
 */
void LojaOnline::sortProdutosByName() {
    sort(produtos.begin(), produtos.end(), compareProdutosByName);
}

/**
 * Sort Produtos of the Online Shop by value
 */
void LojaOnline::sortProdutosByValue() {
    sort(produtos.begin(), produtos.end(), compareProdutosByValue);
}

/**
 * Sort Transacoes of the Online Shop by Date
 */
void LojaOnline::sortTransacaoByDate() {
    sort(transacoes.begin(), transacoes.end(), compareTransacoesByDate);
}

