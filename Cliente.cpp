#include "Cliente.h"
#include <iostream>

/**
 * Default Client contructor. Sets nomeCliente to "" and numContribuinteCliente to 0
 */
Cliente::Cliente(){
    nomeCliente = "";
    numContribuinteCliente = 0;
}

/**
 * Cliente constructor.
 * @param nome name of Cliente
 * @param num numeroContribuinte of Cliente
 */
Cliente::Cliente(string nome, int num) {
    nomeCliente = nome;
    numContribuinteCliente = num;
}

/**
 * @return nome of Cliente
 */
string Cliente::getNome() const{
    return nomeCliente;
}

/**
 * Sets name of Cliente
 * @param nome new Cliente's name
 */
void Cliente::setNome(string nome){
    nomeCliente=nome;
}

/**
 * @return numeroContribuinte of Cliente
 */
int Cliente::getNumContribuinte() const{
    return numContribuinteCliente;
}

/**
 * sets numeroContribuinte of Cliente
 * @param numContribuinte new numerContribuinte
 */
void Cliente::setNumContribuinte(int numContribuinte){
    numContribuinteCliente=numContribuinte;
}

/**
 * Compare 2 clientes and checks if they are the same client
 * @param c1 first client to compare
 * @param c2 second client to compare
 * @return true if they are the same (same name and numContribuinte), false otherwise
 */
bool operator == (Cliente &c1, Cliente &c2){
    if (c1.numContribuinteCliente == c2.numContribuinteCliente && c1.nomeCliente == c2.nomeCliente){
        return true;
    }
    return false;
}

string Cliente::getInfo() const {
    string info = "Nome: ";
    info += nomeCliente + "\n" + "Numero de Contribuinte: ";
    info += to_string(numContribuinteCliente) +"\n";
    return info;
}
/**
 * Overloading operator << to get to a ostream the information of a Client.
 * This information is his Name and Numero de Contribuinte
 * @param o ostream with information of Cliente
 * @param c1 Cliente that we want to get information
 * @return ostream with information
 */
ostream& operator << (ostream& o, Cliente &c1){
    o << c1.getInfo() << endl;
    return o;
}