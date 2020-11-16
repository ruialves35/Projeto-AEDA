#include "Reposicao.h"

using namespace std;

/**
 * Default Constructor
 */
Reposicao::Reposicao() {}

/**
 * Full constructor of Reposicao
 * @param lf LojaFisica of Reposicao
 * @param p Produto of Reposicao
 * @param quantidade Quantity of Produto
 */
Reposicao::Reposicao(LojaFisica lf, Produto *p, int quantidade): lojaFisica(lf), produto(p), quantidade(quantidade) {}

/**
 * Sets Produto of Reposicao
 * @param p new Produto
 */
void Reposicao::setProduto(Produto *p) { this->produto = p; }

/**
 * Gets Produto of Reposicao
 * @return Produto* that points to Produto
 */
Produto * Reposicao::getProduto() const { return produto; }

/**
 * Gets quantity of Produto reposto
 * @return int with quantity
 */
int Reposicao::getQuantidade() const {return quantidade; }

/**
 * Sets quantity of Produto reposto
 * @param quantidade new Quantity of Produto
 */
void Reposicao::setQuantidade(int quantidade) { this->quantidade = quantidade; }

/**
 * Gets LojaFisica where we got the produto
 * @return LojaFisica
 */
LojaFisica Reposicao::getLojaFisica() const { return lojaFisica; }


/**
 * Sets LojaFisica of Reposicao
 * @param lf new LojaFisica
 */
void Reposicao::setLojaFisica(LojaFisica lf) { this->lojaFisica = lf; }
