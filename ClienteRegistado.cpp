#include "ClienteRegistado.h"

using namespace std;

int ClienteRegistado::numeroClientesRegistados = 0;

/**
 * Default constructor of a ClienteRegistado. Sets nome of Cliente to "", id to 0, numContribuinte to 0 and email to ""
 */
ClienteRegistado::ClienteRegistado(): Cliente(), id(0), email("") {
    numeroClientesRegistados++;
}

/**
 * Constructor of ClienteRegistado.
 * @param nome name of Cliente
 * @param numContribuinte numero de contribuinte of Cliente
 * @param email email of Cliente
 */
ClienteRegistado::ClienteRegistado(string nome, int numContribuinte, string email): Cliente(nome, numContribuinte),
                                                                                    email(email){
    numeroClientesRegistados++;
}

/**
 * Sets id of ClienteRegistado
 * @param id new Id
 */
void ClienteRegistado::setId(int id) { this-> id = id;}

/**
 * @return id of ClienteRegistado
 */
int ClienteRegistado::getId() const {return id;}

/**
 * @return number of ClientesRegistados of online shop
 */
int ClienteRegistado::getNumeroClientesRegistados() const {
    return numeroClientesRegistados;
}

/**
 * Sets number of ClientesRegsitados of Online Shop
 * @param ncr new number of ClientesRegistados
 */
void ClienteRegistado::setNumeroClientesRegistados(int ncr) {
    numeroClientesRegistados = ncr;
}

/**
 * @return email of ClienteRegistado
 */
string ClienteRegistado::getEmail() const {return email;}

/**
 * Sets email of ClienteRegistado
 * @param email new email
 */
void ClienteRegistado::setEmail(string email) {
    this->email= email;
}
