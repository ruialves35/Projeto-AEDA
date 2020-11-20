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

/**
 * Operator == to check if 2 Categoria are the same
 * @param c2 Second Categoria to compare
 * @return true if they have the same name, false otherwise
 */
bool Categoria::operator==(Categoria &c2) { return this->nomeCategoria == c2.nomeCategoria; }