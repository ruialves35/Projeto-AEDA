#ifndef AEDA_FORNECEDOR_H
#define AEDA_FORNECEDOR_H

#include <iostream>
#include "Produto.h"

using namespace std;

class Fornecedor{
private:
    string nomeFornecedor;
    int nif;
    Produto* produto;
    double preco;
    int quantidade;
public:
    Fornecedor();
    Fornecedor(string nome);
    Fornecedor(string nome, int nif, Produto* prod, double preco, int quantidade);
    string getNomeFornecedor() const;
    void setNome(string nome);
    void setPreco(int preco);
    int getPreco() const;
    void addQuantidade(int n = 1);
    void removeQuantidade(int n = 1);
    void setQuantidade(int quantidade);
    int getQuantidade() const;
    void setNif(int nif);
    int getNif() const;
    void setProduto(Produto* produto);
    Produto* getProduto() const;
    bool operator<(const Fornecedor& f1) const;
    bool operator==(const Fornecedor& f1) const;
};


#endif //AEDA_FORNECEDOR_H
