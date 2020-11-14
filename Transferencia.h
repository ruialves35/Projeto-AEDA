#ifndef TRANSFERENCIA_H
#define TRANSFERENCIA_H

#include "Fornecedor.h"
#include "Produto.h"

class Transferencia {
private:
    Fornecedor fornecedor;
    Produto* produto;
    int quantidade;
public:
    Transferencia();
    Transferencia(Fornecedor &f, Produto* p, int quantidade);
    Fornecedor getFornecedor() const;
    void setFornecedor(Fornecedor &f);
    Produto* getProduto() const;
    void setProduto(Produto* p);
    string getInfo() const;
};


#endif //TRANSFERENCIA_H
