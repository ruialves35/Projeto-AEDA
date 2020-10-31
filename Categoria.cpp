#include "Categoria.h"
#include <iostream>

/**
 * Constructor of derived Class
 * Sets to "" the nomeCategoria
 */

Categoria::Categoria(): nomeCategoria(""){};
Categoria::Categoria(string nome): nomeCategoria(nome){};

/**
 * sets nome
 */
void Categoria::setNome(string nome) {
    nomeCategoria = nome;
}

/**
 * @return nome nomeCategoria
 */
string Categoria::getNomeCategoria() const {return nomeCategoria; }