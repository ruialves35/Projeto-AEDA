#include "Carrinha.h"
#include <iostream>

/**
 * Constructor of derived Class
 */
Carrinha::Carrinha(){
    id = 1;
    ocupacao = 0;
    ocupacaoMaxima = 20;
}

/**
 * Constructor with all parameters of Carrinha
 * @param idCarrinha of Carrinha (to identify)
 * @param ocupacaoCarrinha of Carrinha
 * @param ocupacaoMaximaCarrinha of Carrinha
 */
Carrinha::Carrinha(int idCarrinha, int ocupacaoCarrinha, int ocupacaoMaximaCarrinha) {
    id=idCarrinha;
    ocupacao=ocupacaoCarrinha;
    ocupacaoMaxima=ocupacaoMaximaCarrinha;
}

/**
 * returns id of the Carrinha
 * @return id Carrinha
 */
int Carrinha::getID() const{
    return id;
}

/**
 * sets id of the Carrinha
 * @param novoID ID
 */
void Carrinha::setID(int novoid) {
    id = novoid;
}

/**
 * returns current ocupation of the Carrinha
 * @return ocupacao Carrinha
 */
int Carrinha::getOcupacao() const{
    return ocupacao;
}

/**
 * sets Ocupacao of the Carrinha
 * @param valor new ocupation
 */
void Carrinha::SetOcupacao(int valor) {
    ocupacao=valor;
}

/**
 * returns maximum ocupation of the Carrinha
 * @return ocupacaoMaxima Carrinha
 */
int Carrinha::getOcupacaoMaxima() const{
    return ocupacaoMaxima;
}

/**
 * sets OcupacaoMaxima of the Carrinha
 * @param valor new maximum ocupation
 */
void Carrinha::SetOcupacaoMaxima(int valor) {
    ocupacao=valor;
}

/**
 * Calculates the free pace in the Carrinha
 * @return ocupacaoMaxima-ocupacao of the Carrinha
 */
int Carrinha::calcularEspacoLivre() const{
    return ocupacaoMaxima-ocupacao;
}

/**
 * Adds ocupation to the Carrinha
 * @param valorAdicionado value added to the ocupation
 */
void Carrinha::addOcupacao(int valorAdicionado) {
    ocupacao=ocupacao+valorAdicionado;
}

/**
 * Verifies weather a Carrinha reached 90 percent ocupation
 * @return true if it reched, false otherwise
 */
bool Carrinha::prontaDespachar() const {
    double percentagem = (double)ocupacao/ocupacaoMaxima;
    if(percentagem < 0.9) {
        return false;
    }
    return true;
}
/**
 * Operator <, compares 2 carrinhas by free ocupation
 * @param f1 Second Carrinha to compare
 * @return True if it has smaller ocupation, false otherwise
 */
bool Carrinha::operator <(const Carrinha& c1) const {
    return ocupacaoMaxima - ocupacao > c1.getOcupacaoMaxima() - c1.getOcupacao();
}
