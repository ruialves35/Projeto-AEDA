#ifndef AEDA_PRODUTO_H
#define AEDA_PRODUTO_H

#include <iostream>

using namespace std;

class Produto{
private:
    int id;
    string nomeProduto;
    //int stockFisico;
    //int stockOnline;
    double valor;
public:
    Produto();
    Produto(string nome, int id, double val);
    //int getStockFisico() const;
    //void setStockFisico(int stockFisico);
    //int getStockOnline() const;
    //void setStockOnline(int stockOnline);
    int getId() const;
    void setId(int newId);
    string getNomeProduto() const;
    void setNomeProduto(string nome);
    void setValor(double val);
    double getValor() const;
    friend bool operator < (const Produto &p1, const Produto &p2);
    friend bool operator == (const Produto &p1, const Produto &p2);
};

#endif //AEDA_PRODUTO_H
