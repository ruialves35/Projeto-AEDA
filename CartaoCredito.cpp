#include "CartaoCredito.h"
#include <string> //std::to_string

CartaoCredito::CartaoCredito(): Pagamento(), numCartao(0), validade(Date()) {}

CartaoCredito::CartaoCredito(double valor, long numCartao, Date val): Pagamento(valor), numCartao(numCartao), validade(val) {}

long CartaoCredito::getNumCartao() const {return numCartao;}

void CartaoCredito::setNumCartao(long numCartao) {
    if (to_string(numCartao).length() != 15 && to_string(numCartao).length() != 16){
        cout << "Wrong numCartao." << endl;
    }
    else this->numCartao = numCartao;
}

void CartaoCredito::setValidade(Date validade) {
    this->validade = validade;
}

Date CartaoCredito::getValidade() const {return validade;}


/**
 * returns a string with information of Cartao de Credito
 * This information is of the form "Cartao de Credito\n. Numero do Cartao: ....\n. Validade: .....\n."
 * @return string with information
 */
string CartaoCredito::getInfo() const {
    string info = "Cartao de Credito.\nNumero do Cartao: " + numCartao;
    info += "\nValidade: " + validade.getInfo() + "\n";
}