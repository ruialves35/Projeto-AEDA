#ifndef PROJETOAEDACOPIA_MENSAGEM_H
#define PROJETOAEDACOPIA_MENSAGEM_H

#include <iostream>
#include "Cliente.h"

using namespace std;

class Mensagem {
private:
    static int numeroMensagens;
    int numero;
    string mensagem;
    Cliente cliente;
    bool respondida;
public:
    Mensagem();
    Mensagem(string msg, Cliente cl);
    Mensagem(string msg, Cliente cl, bool respondida);
    string getMensagem() const;
    Cliente getCliente() const;
    bool getRespondida() const;
    void setRespondida();
    int getNumero() const;

    friend ostream& operator << (ostream &o, const Mensagem &msg);
    friend bool operator < (const Mensagem &msg1, const Mensagem &msg2);
    friend bool operator == (const Mensagem &msg1, const Mensagem &msg2);
};


#endif //PROJETOAEDACOPIA_MENSAGEM_H
