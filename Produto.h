#ifndef AEDA_PRODUTO_H
#define AEDA_PRODUTO_H


class Produto{
private:
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
}



#endif //AEDA_PRODUTO_H
