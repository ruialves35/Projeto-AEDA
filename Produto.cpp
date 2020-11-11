#include "Produto.h"

/**
 * Default Constructor of Produto
 * Sets to "" the nomeProduto and sets to 0 the value of the Produto
 */

Produto::Produto(): nomeProduto(""), valor(0) {}

/**
 * Constructor of Produto
 * @param nome name of Produto
 * @param id identification of Produto (to be set by the Shop Owner)
 * @param val value of Produto
 */
Produto::Produto(string nome, int id, double val): nomeProduto(nome), valor(val), id(id){}
/*
/**
 * sets Stock Fisico of Produto
 * @param fisico new stock fisico
 */
/*
void Produto::setStockFisico(int fisico){
    stockFisico = fisico;
}*/

/*
/**
 * sets Stock Online of Produto
 * @param online new stock online
 */
/*
void Produto::setStockOnline(int online){
    stockOnline = online;
}*/

/**
 * sets Nome of Produto
 * @param nome new Produto's name
 */
void Produto::setNomeProduto(string nome){
    nomeProduto = nome;
}

/**
 * sets Produto id
 * @param newId new Produto's id
 */
void Produto::setId(int newId) {
    id = newId;
}

/**
 * @return Produto's id
 */
int Produto::getId() const { return id; }

/**
 * @return nome Produto's name
 */
string Produto::getNomeProduto() const {return nomeProduto; }

/*
/**
 * @return Produto's id
 */
//int Produto::getStockFisico() const {return stockFisico;}

/*
/**
 * @return stock of Produto in the Online Shop
 */
//int Produto::getStockOnline() const {return stockOnline;}

/**
 * @return value of Produto
 */
double Produto::getValor() const {
    return valor;
}

/**
 * overloading of operator == to compare 2 products.
 * Products are equal if they have same id, nome, stock in online shop, stock in fisical shop and value.
 * @param p1 product to compare
 * @param p2 product to compare
 * @return True if they are the same, false otherwise
 */
bool operator == (const Produto &p1, const Produto &p2){
    return p1.id == p2.id && p1.nomeProduto == p2.nomeProduto && p1.valor == p2.valor;
}

/**
 * overloading of operator < to compare 2 products.
 * A product is smaller than other if his price is smaller than the price of the other
 * @param p1 product to compare
 * @param p2 product to compare
 * @return True if value of p1 < p2
 */
bool operator < (const Produto &p1, const Produto &p2){
    return p1.valor < p2.valor;
}