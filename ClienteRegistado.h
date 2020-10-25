//
// Created by ruial on 24/10/2020.
//

#ifndef AEDA_CLIENTEREGISTADO_H
#define AEDA_CLIENTEREGISTADO_H


class ClienteRegistado : public Cliente {
private:
    string email;
public:
    string getEmail() const;
    void setEmail(string email);
};


#endif //AEDA_CLIENTEREGISTADO_H
