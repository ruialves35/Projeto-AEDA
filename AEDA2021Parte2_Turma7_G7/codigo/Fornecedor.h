#ifndef AEDA_FORNECEDOR_H
#define AEDA_FORNECEDOR_H

#include <iostream>

using namespace std;

class Produto;

class Fornecedor{
private:
    string nomeFornecedor;
    int nif;
    Produto* produto;
    double preco;
    int quantidade;
public:
    Fornecedor();
    Fornecedor(string nome, int nif, Produto* prod, double preco, int quantidade);
    string getNomeFornecedor() const;
    void setNome(string nome);
    void setPreco(int preco);
    double getPreco() const;
    void addQuantidade(int n = 1);
    void removeQuantidade(int n = 1);
    void setQuantidade(int quantidade);
    int getQuantidade() const;
    void setNif(int nif);
    int getNif() const;
    void setProduto(Produto* produto);
    Produto* getProduto() const;
    //bool operator<(const Fornecedor& f1) const;
    //bool operator==(const Fornecedor& f1) const;
};

class FornecedorPtr{
private:
    Fornecedor* fornecedor;
public:
    FornecedorPtr();
    FornecedorPtr (Fornecedor* fornecedor);
    FornecedorPtr (string nome, int nif, Produto* prod, double preco, int quantidade);
    Produto* getProduto() const;
    int getNif() const;
    int getQuantidade() const;
    string getNomeFornecedor() const;
    void setNome(string nome);
    void setPreco(int preco);
    double getPreco() const;
    void addQuantidade(int n = 1);
    void removeQuantidade(int n = 1);
    void setQuantidade(int quantidade);
    Fornecedor* getFornecedor() const;
    void setFornecedor(Fornecedor* newForn);
    bool operator<(const FornecedorPtr& f1) const;
    bool operator==(const FornecedorPtr& f1) const;
};

#endif //AEDA_FORNECEDOR_H
