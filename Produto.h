#ifndef AEDA_PRODUTO_H
#define AEDA_PRODUTO_H

#include <iostream>

using namespace std;

class Produto{
private:
    string nomeProduto;
    int stockFisico;
    int stockOnline;
    double valor;
public:
    Produto();
    Produto(string nome, int fisico, int online, double val);
    int getStockFisico() const;
    void setStockFisico(int stockFisico);
    int getStockOnline() const;
    void setStockOnline(int stockOnline);
    string getNomeProduto() const;
    void setNomeProduto(string nome);
    void setValor(double val);
    double getValor() const;
};

#endif //AEDA_PRODUTO_H
