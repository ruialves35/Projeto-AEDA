#include "NumeroTransacoes.h"

int NumeroTransacoes::numberOfTransacoes = 0;

/**
 * Constructor that increments the number of Transacoes of the shop
 */
NumeroTransacoes::NumeroTransacoes(){
    numberOfTransacoes++;
}

/**
 * Constructor that increments the number of Transacoes of the shop by n
 * @param num n to increment
 */
NumeroTransacoes::NumeroTransacoes(int num){
    numberOfTransacoes += num;
}

int NumeroTransacoes::getNumberOfTransacoes() const {return numberOfTransacoes;}

void NumeroTransacoes::setNumberOfTransacoes(int num) {
    numberOfTransacoes = num;
}

void NumeroTransacoes::addNumberOfTransacoes(int num) {
    numberOfTransacoes += num;
}