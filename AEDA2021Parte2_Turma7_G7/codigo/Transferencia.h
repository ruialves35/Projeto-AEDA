#ifndef TRANSFERENCIA_H
#define TRANSFERENCIA_H

#include "Fornecedor.h"
#include "Produto.h"
#include "Date.h"
class Transferencia {
private:
    FornecedorPtr fornecedor;
    Produto* produto;
    int quantidade;
    Date data;
    int preco;
public:
    Transferencia();
    Transferencia(FornecedorPtr &f, Produto* p, int quantidade, Date data);
    Fornecedor* getFornecedor() const;
    void setFornecedor(FornecedorPtr &f);
    Produto* getProduto() const;
    void setProduto(Produto* p);
    Date getData() const;
    void setData(Date &data);
    string getInfo() const;
    int getQuantidade() const;
    void setQuantidade(int quantidade);
    int getNifFornecedor() const;
    double getPreco() const;
};


#endif //TRANSFERENCIA_H
