#include "Produto.h"

/**
 * Constructor of derived Class
 * Sets to "" the nomeProduto and sets to 0 the stockFisico, stockOnline and valor
 */

Produto::Produto(): nomeProduto(""), stockFisico(0), stockOnline(0), valor(0) {}

Produto::Produto(string nome, int fisico, int online, double val): nomeProduto(nome), stockFisico(fisico), stockOnline(online), valor(val){}

/**
 * sets nome, fisico and online
 */

void Produto::setStockFisico(int fisico){
    stockFisico = fisico;
}

void Produto::setStockOnline(int online){
    stockOnline = online;
}

void Produto::setNomeProduto(string nome){
    nomeProduto = nome;
}

/**
 * @return nome nomeProduto, fisico stockFisico, online stockOnline
 */

string Produto::getNomeProduto() const {return nomeProduto; }

int Produto::getStockFisico() const {return stockFisico;}

int Produto::getStockOnline() const {return stockOnline;}