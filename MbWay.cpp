#include "MbWay.h"

#include <string>

/**
 * Constructor of derived Class
 * Sets to 0 the numTelemovel and value of payment
 */
MbWay::MbWay(): Pagamento(), numTelemovel(0) {}

/**
 * Constructor of derived Class.
 * Set to 0 the value of payment and numTelemovel to a number
 * @param num number to set numTelemovel
 */
MbWay::MbWay(int num): Pagamento(), numTelemovel(num) {}

/**
 * Constructor of derived Class, sets valorTotal and numTelemovel
 * @param valor value to set ValorTotal
 * @param num value to set numTelemovel
 */
MbWay::MbWay(double valor, int num): Pagamento(valor), numTelemovel(num) {}


/**
 * @return n numTelemovel
 */
int MbWay::getNumTelemovel() const { return numTelemovel; }

/**
 * sets numTelemovel
 * @param num new numTelemovel
 */
void MbWay::setNumTelemovel(int num) {
    if (to_string(num).length() != 9){ cout <<"Wrong numTelemovel;" << endl; }
    else numTelemovel = num;
}

/**
 * Gets the information of the MbWay Payment
 * Info is of the form "MbWay\n Numero de Telemovel: ..."
 * @return string with the information
 */
void MbWay::getInfo(ostream& o) const {
    o << "MbWay\n";
    o << "Numero de Telemovel: " + to_string(numTelemovel);
}

/**
 * @return string with information
 */
string MbWay::getTipo() const { return "mbway";}