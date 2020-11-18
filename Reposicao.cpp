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
Reposicao::Reposicao(LojaFisica lf, Produto *p, int quantidade, Date data):
        lojaFisica(lf), produto(p), quantidade(quantidade), data(data) {}

/**
 * Sets Produto of Reposicao
 * @param p new Produto
 */
void Reposicao::setProduto(Produto *p) { this->produto = p; }

/**
 * @return Date of Transferencia
 */
Date Reposicao::getData() const { return data; }

/**
 * Sets Date of Transferencia
 * @param data new Date
 */
void Reposicao::setData(Date &data) { this->data = data;}

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
 * @return string with Information of Reposicao
 */
string Reposicao::getInfo() const {
    string info = "Loja Fisica: ";
    info += lojaFisica.getLocalidade() + "\n";
    info += "Produto: " + produto->getNomeProduto();
    info += "Quantidade: " + to_string(quantidade);
    info += "Data: " + data.getInfo();
}

/**
 * Sets LojaFisica of Reposicao
 * @param lf new LojaFisica
 */
void Reposicao::setLojaFisica(LojaFisica lf) { this->lojaFisica = lf; }


/**
 * Says if 2 reposicoes are the same
 * @param r1
 * @return
 */
bool Reposicao::operator==(Reposicao r1) {
    if (lojaFisica == r1.lojaFisica){
        if (produto == r1.produto){
            if (quantidade == r1.quantidade){
                if (data == r1.data){
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

