#ifndef AEDA_PRODUTO_H
#define AEDA_PRODUTO_H

#include <iostream>

using namespace std;

class Produto{
private:
    Produto();
    Produto(string nome, int fisico, int online, double val);
    string nomeProduto;
    int stockFisico;
    int stockOnline;
    double valor;
public:
    int getStockFisico() const;
    void setStockFisico(int stockFisico);
    int getStockOnline() const;
    void setStockOnline(int stockOnline);
    string getNomeProduto() const;
    void setNomeProduto(string nome);
};

#endif //AEDA_PRODUTO_H
