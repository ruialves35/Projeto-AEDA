#include "Fornecedor.h"

/**
 * Constructor of derived Class
 * Sets to "" the nomeFornecedor
 */
Fornecedor::Fornecedor(): nomeFornecedor(""), nif(0), produto(), preco(0), quantidade(0){}

Fornecedor::Fornecedor(string nome): nomeFornecedor(nome){}

/**
 * Constructor with all parameters of Fornecedor
 * @param nome of Fornecedor
 * @param nif of Fornecedor (identifies it)
 * @param prod Product that Fornecedor is selling
 * @param preco Price of selling
 * @param quantidade Quantity that he's selling
 */
Fornecedor::Fornecedor(string nome, int nif, Produto* prod, double preco, int quantidade): nomeFornecedor(nome){}

/**
 * sets nome of Fornecedor
 */
void Fornecedor::setNome(string nome){
    nomeFornecedor = nome;
}

/**
 * @return nome nomeFornecedor
 */
string Fornecedor::getNomeFornecedor() const {return nomeFornecedor; }


/**
 * sets price that Fornecedor is selling the product
 * @param preco Price
 */
void Fornecedor::setPreco(int preco) { this->preco = preco; }

/**
 * @return Price that Fornecedor is selling the product
 */
int Fornecedor::getPreco() const { return preco;}

/**
 * Adds a quantity of Product that Fornecedor is selling
 * @param n quantity to be added
 */
void Fornecedor::addQuantidade(int n) {
    this->quantidade += n;
}

/**
 * Removes quantity of product selling. If there is not that much quantity, puts it to 0
 * @param n quantity to be removed
 */
void Fornecedor::removeQuantidade(int n) {
    if (quantidade - n < 0){
        quantidade = 0;
    }
    else quantidade -= n;
}

/**
 * @return Quantity of product selling by Fornecedor
 */
int Fornecedor::getQuantidade() const { return quantidade;}

/**
 * Sets Quantity that Fornecedor is selling
 * @param quantidade new Quantity
 */
void Fornecedor::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

/**
 * Sets nif of a Fornecedor
 * @param nif
 */
void Fornecedor::setNif(int nif) { this->nif = nif; }

/**
 * @return int Nif of Fornecedor
 */
int Fornecedor::getNif() const {return nif;}

/**
 * Sets the product that Fornecedor is selling
 * @param produto product
 */
void Fornecedor::setProduto(Produto *produto) {
    this->produto = produto;
}

/**
 * @return Product* to the product that Fornecedor is selling
 */
Produto * Fornecedor::getProduto() const {return produto;}

/**
 * operator < for Fornecedor. They are compared in ascending order by preco
 * then for descending order of quantidade
 * and then alphabetically by name
 * @param f1 Fornecedor to be compared
 * @return true if f < f1, false otherwise, by rule discribed above
 */
bool Fornecedor::operator<(const Fornecedor &f1) const {
    if (preco == f1.preco){
        if (quantidade == f1.quantidade){
            return nomeFornecedor < f1.nomeFornecedor;
        }
        else return quantidade > f1.quantidade; //quero ordenar pelo que tem maior quantidade primeiro
    }
    else return preco < f1.preco;
}

/**
 * @param f1 Fornecedor to be compared
 * @return true if they are the same person (same nif)
 */
bool Fornecedor::operator==(const Fornecedor &f1) const {
    return nif == f1.nif;
}
