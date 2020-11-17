#ifndef TRANSFERENCIA_H
#define TRANSFERENCIA_H

#include "Fornecedor.h"
#include "Produto.h"
#include "Date.h"
class Transferencia {
private:
    Fornecedor fornecedor;
    Produto* produto;
    int quantidade;
    Date data;
public:
    Transferencia();
    Transferencia(Fornecedor &f, Produto* p, int quantidade, Date data);
    Fornecedor getFornecedor() const;
    void setFornecedor(Fornecedor &f);
    Produto* getProduto() const;
    void setProduto(Produto* p);
    Date getData() const;
    void setData(Date &data);
    string getInfo() const;
};


#endif //TRANSFERENCIA_H
