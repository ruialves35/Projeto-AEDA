//
// Created by ruial on 24/10/2020.
//

#include "Fornecedor.h"

/**
 * Constructor of derived Class
 * Sets to "" the nomeFornecedor
 */

Fornecedor::Fornecedor(): nomeFornecedor(""){};
Fornecedor::Fornecedor(string nome): nomeFornecedor(nome){};

/**
 * sets nome
 */

void Categoria::setNome(string nome): nomeFornecedor(nome){};

/**
 * @return nome nomeFornecedor
 */

string Categoria::getNomeFornecedor() const {return nomeFornecedor};