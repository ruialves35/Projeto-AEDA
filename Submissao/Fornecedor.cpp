#include "Fornecedor.h"

/**
 * Constructor of derived Class
 * Sets to "" the nomeFornecedor
 */

Fornecedor::Fornecedor(): nomeFornecedor(""){}
Fornecedor::Fornecedor(string nome): nomeFornecedor(nome){}

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