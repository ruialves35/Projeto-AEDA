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
Fornecedor::Fornecedor(string nome, int nif, Produto* prod, double preco, int quantidade): nomeFornecedor(nome), nif(nif), produto(prod), preco(preco), quantidade(quantidade){}

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
double Fornecedor::getPreco() const { return preco;}

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
 *//*
bool Fornecedor::operator<(const Fornecedor &f1) const {
    if (preco == f1.preco){
        if (quantidade == f1.quantidade){
            return nomeFornecedor < f1.nomeFornecedor;
        }
        else return quantidade > f1.quantidade; //quero ordenar pelo que tem maior quantidade primeiro
    }
    else return preco < f1.preco;
}*/

/**
 * @param f1 Fornecedor to be compared
 * @return true if they are the same person (same nif)
 *//*
bool Fornecedor::operator==(const Fornecedor &f1) const {
    return nif == f1.nif;
}*/

//----------------------------------------------------------------

/**
 * Empty constructor
 */
FornecedorPtr::FornecedorPtr() {}
/**
 * Constructor of FornecedorPtr
 * @param fornecedor
 */
FornecedorPtr::FornecedorPtr(Fornecedor *fornecedor) { this-> fornecedor = fornecedor;}

/**
 * Constructor with all parameters of a Fornecedor
 * @param nome name of Fornecedor
 * @param nif Nif of fornecedor
 * @param prod Product that Fornecedor is selling
 * @param preco price that he's selling the product
 * @param quantidade quantity that Fornecedor is selling
 */
FornecedorPtr::FornecedorPtr(string nome, int nif, Produto *prod, double preco, int quantidade) {
    fornecedor = new Fornecedor(nome, nif, prod, preco, quantidade);
}

/**
 * Gets product that Fornecedor is selling
 * @return Pointer to Product
 */
Produto * FornecedorPtr::getProduto() const { return fornecedor->getProduto(); }

/**
 * Gets nif of fornecedor
 * @return integer with nif
 */
int FornecedorPtr::getNif() const { return fornecedor->getNif(); }

/**
 * gets quantity that fornecedor has to sell
 * @return
 */
int FornecedorPtr::getQuantidade() const { return fornecedor->getQuantidade();}

/**
 * Gets nome of fornecedor
 * @return string with nome
 */
string FornecedorPtr::getNomeFornecedor() const { return fornecedor->getNomeFornecedor(); }

/**
 * Sets name of Fornecedor
 * @param nome new name
 */
void FornecedorPtr::setNome(string nome) {this->fornecedor->setNome(nome);}

/**
 * Sets price that Fornecedor is selling
 * @param preco new price
 */
void FornecedorPtr::setPreco(int preco) {this->fornecedor->setPreco(preco);}

/**
 * Gets price that Fornecedor is selling the Product
 * @return double with price
 */
double FornecedorPtr::getPreco() const {return this->fornecedor->getPreco();}

/**
 * Adds a quantity n of the product that Fornecedor is selling
 * @param n Quantity to be added
 */
void FornecedorPtr::addQuantidade(int n) {fornecedor->addQuantidade(n);}

/**
 * Removes a quantity n of the product that Fornecedor is selling
 * @param n Quantity to be removed
 */
void FornecedorPtr::removeQuantidade(int n) {fornecedor->removeQuantidade(n);}

/**
 * Sets quantity that fornecedor is selling the product
 * @param quantidade new Quantity
 */
void FornecedorPtr::setQuantidade(int quantidade) {fornecedor->setQuantidade(quantidade);}

/**
 * Gets the Fornecedor
 * @return Pointer to Fornecedor
 */
Fornecedor * FornecedorPtr::getFornecedor() const {return fornecedor;}

/**
 * Sets Fornecedor
 * @param newForn new Fornecedor
 */
void FornecedorPtr::setFornecedor(Fornecedor *newForn) { fornecedor = newForn;}

/**
 * Operator <, compares 2 fornecedores, by price, then for quantity and then for name
 * @param f1 Second fornecedor to compare
 * @return
 */
bool FornecedorPtr::operator<(const FornecedorPtr &f1) const {
    if (fornecedor->getPreco() == f1.getPreco()){
        if (fornecedor->getQuantidade() == f1.getQuantidade()){
            return fornecedor->getNomeFornecedor() < f1.getNomeFornecedor();
        }
        else return fornecedor->getQuantidade() > f1.getQuantidade(); //quero ordenar pelo que tem maior quantidade primeiro
    }
    else return fornecedor->getPreco() < f1.getPreco();
}

/**
 * operator ==, compares 2 fornecedores. (f == f1)
 * @param f1 Second fornecedor to compare
 * @return True if they have the same nif (so they are the same person), false otherwise
 */
bool FornecedorPtr::operator==(const FornecedorPtr &f1) const {
    return this->fornecedor->getNif() == f1.getNif();
}

