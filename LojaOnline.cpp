#include "LojaOnline.h"
#include <algorithm>
using namespace std;

LojaOnline::LojaOnline() {}

/**
 * displays all product available in the store, each quantity and price
 */
void LojaOnline::showAllProdutos() const {
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Nome do Produto" << setw(10) << "Quantidade Disponivel" << setw(10) << "Preco" << endl << endl;
    for (auto i : produtos){
        cout << i->getNomeProduto() << setw(10)<< i->getStockOnline() << setw(10) << i->getValor() << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}


void LojaOnline::addProduto(Produto *p) {
    produtos.push_back(p);
}

void LojaOnline::addCliente(Cliente *c) {
    clientes.push_back(c);
}

void LojaOnline::addTransacao(Transacao *t) {
    transacoes.push_back(t);
}

void LojaOnline::removeCliente(Cliente *c) {
    vector<Cliente*>::iterator it = find(clientes.begin(), clientes.end(), c);
    clientes.erase(it);
}

void LojaOnline::showAllTransacoes() const {
    for (auto i : transacoes){
        cout << i << endl;
    }
}