#ifndef AEDA_FORNECEDOR_H
#define AEDA_FORNECEDOR_H

#include <iostream>

using namespace std;

class Fornecedor{
private:
    string nome;
public:
    string getNome() const;
    void setNome(string nome);
};


#endif //AEDA_FORNECEDOR_H
