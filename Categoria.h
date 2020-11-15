#ifndef AEDA_CATEGORIA_H
#define AEDA_CATEGORIA_H

#include <iostream>

using namespace std;

class Categoria{
private:
    string nomeCategoria;
public:
    Categoria();
    Categoria(string nome);
    string getNomeCategoria() const;
    void setNome(string nome);
    bool operator == (Categoria &c2);
};


#endif //AEDA_CATEGORIA_H

