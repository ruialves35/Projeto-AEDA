#ifndef AEDA_PRODUTO_H
#define AEDA_PRODUTO_H

#include <iostream>
#include "Categoria.h"
#include <set>
using namespace std;


class FornecedorPtr;
class Fornecedor;
class Produto{
private:
    int id;
    string nomeProduto;
    //int stockFisico;
    //int stockOnline;
    double valor;
    Categoria categoria;
    set<FornecedorPtr> fornecedores;
public:
    Produto();
    Produto(string nome, int id, double val, Categoria categoria);
    //int getStockFisico() const;
    //void setStockFisico(int stockFisico);
    //int getStockOnline() const;
    //void setStockOnline(int stockOnline);
    void addFornecedor(Fornecedor * fornecedor);
    set<FornecedorPtr> getFornecedores() const;
    int getId() const;
    void setId(int newId);
    string getNomeProduto() const;
    void setNomeProduto(string nome);
    double getValor() const;
    void setValor(double val);
    Categoria getCategoria() const;
    void setCategoria(Categoria &cat);
    friend bool operator < (const Produto &p1, const Produto &p2);
    friend bool operator == (const Produto &p1, const Produto &p2);
};

#endif //AEDA_PRODUTO_H
