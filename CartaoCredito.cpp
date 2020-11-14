#include "CartaoCredito.h"
#include <string> //std::to_string

/**
 * Constructor of Cartao Credito.
 * Sets Payment value to 0, number of card to 0 and Date of the payment to 00/00/0000
 */
CartaoCredito::CartaoCredito(): Pagamento(), numCartao(""), validade(Date()) {}

/**
 * Constructor of Cartao Credito
 * @param valor valor do Pagamento
 * @param numCartao Numero do Cartao de Credito de onde vai pagar (string with length 16)
 * @param val Validade do cartao de credito
 */
CartaoCredito::CartaoCredito(double valor, string numCartao, Date val): Pagamento(valor), numCartao(numCartao), validade(val) {}

/**
 * Constructor of Cartao Credito
 * @param numCartao numero do Cartao de Credito de onde vai pagar
 * @param val Validade do cartao de credito
 */
CartaoCredito::CartaoCredito(string numCartao, Date val): Pagamento(), numCartao(numCartao), validade(val) {}

/**
 * Gets the number of card
 * @return number of card as string
 */
string CartaoCredito::getNumCartao() const {return numCartao;}

/**
 * Sets the number of card
 * @param numCartao new card number
 */
void CartaoCredito::setNumCartao(string numCartao) {
    if (numCartao.length() != 15 && numCartao.length() != 16){
        cout << "Wrong numCartao." << endl;
    }
    else this->numCartao = numCartao;
}


/**
 * Sets validade of card
 * @param validade new Validade
 */
void CartaoCredito::setValidade(Date validade) {
    this->validade = validade;
}

/**
 * gets the validade of the card
 * @return Data de validade do cartao
 */
Date CartaoCredito::getValidade() const {return validade;}


/**
 * returns a string with information of Cartao de Credito
 * This information is of the form "Cartao de Credito\n. Numero do Cartao: ....\n. Validade: .....\n."
 * @return string with information
 */
void CartaoCredito::getInfo(ostream& o) const {
    o << "Cartao de Credito.\nNumero do Cartao: " << numCartao;
    o << "\nValidade: " + validade.getInfo() + "\n";
}