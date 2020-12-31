#include "Mensagem.h"
#include "Cliente.h"

int Mensagem::numeroMensagens = 0;

/**
 * Empty constructor of Mensagem
 */
Mensagem::Mensagem():mensagem(""), respondida(false) {
    numeroMensagens++;
    numero = numeroMensagens;
}

/**
 * Constructor with all parameters for Mensagem
 * @param msg String with Message sent by Cliente
 * @param cl Cliente that sent the Message
 */
Mensagem::Mensagem(string msg, Cliente cl): mensagem(msg), cliente(cl), respondida(false) {
    numeroMensagens++;
    numero = numeroMensagens;
    //cout << "NUMERO:" << numeroMensagens << endl;
    //cout <<"NUMERO COLOCADO:" << numero << endl;
}

/**
 * Constructor with all paremeters
 * @param msg string with message sent
 * @param cl Client that sent message
 * @param respondida Bool with condition of message (already seen or not)
 */
Mensagem::Mensagem(string msg, Cliente cl, bool respondida): mensagem(msg), cliente(cl), respondida(respondida){
    numeroMensagens++;
    //cout << "NUMERO:" << numeroMensagens << endl;
    numero = numeroMensagens;
    //cout <<"NUMERO COLOCADO:" << numero << endl;
}

/**
 * @return true if mensage was already seen by Administrador, false otherwise
 */
bool Mensagem::getRespondida() const { return respondida;}

/**
 * @return string with the Message sent by Client
 */
string Mensagem::getMensagem() const { return mensagem;}

/**
 * @return Pointer to Client that sent the Message
 */
Cliente Mensagem::getCliente() const { return cliente;}

/**
 * Sets respondida to true
 */
void Mensagem::setRespondida() {respondida = true;}

/**
 * @return int with number of Mensagem (id)
 */
int Mensagem::getNumero() const { return numero;}

/**
 * operator == to compare 2 Mensagem.
 * Messages are equal if they have same Client and message.
 * @param msg1 message to compare
 * @param msg2 message to compare
 * @return True if they are the same, false otherwise
 */
bool operator == (const Mensagem &msg1, const Mensagem &msg2){
    return msg1.numero == msg2.numero && msg1.cliente.getNumContribuinte() == msg2.cliente.getNumContribuinte();
}

/**
 * operator < to compare 2 Mensagem.
 * A Mensagem is smaller than other if was sent after the other one (has more number/identifier)
 * @param msg1 Mensagem to compare
 * @param msg2 Mensagem to compare
 * @return True if value of p1 < p2
 */
bool operator < (const Mensagem &msg1, const Mensagem &msg2){
    return msg1.numero < msg2.numero;
}

/**
 * Overloading operator << that gets information of a mensagem
 * @param o ostream to store the information
 * @param msg Message to get information
 * @return ostream with information
 */
ostream& operator << (ostream &o, const Mensagem &msg){
    o << "---------------------------------------------------------------------------------------------------------" << endl;
    o << "Numero: " << msg.getNumero() << endl;
    o << "Estado: ";
    if (msg.getRespondida()) o << "Respondida" << endl;
    else o << "Por Responder" << endl;
    o << "Nome Cliente: " << msg.getCliente().getNome() << endl;
    o << "Numero de Contribuinte do Cliente: " << msg.getCliente().getNumContribuinte() << endl << endl;
    o << "Mensagem:" << endl;
    o << msg.getMensagem() << endl;
    o << "---------------------------------------------------------------------------------------------------------" << endl;
    return o;
}