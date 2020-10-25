#ifndef AEDA_BUYNOW_H
#define AEDA_BUYNOW_H


class BuyNow {
private:
    LojaFisica lojaFisica;
    LojaOnline lojaOnline;
    vector <Cliente*> cliente;
    vector <Transacao*> transações;
    int stockOk;
    int stockMin;
public:
    BuyNow();
    ~BuyNow();
    void addCliente(Cliente &cliente);
    void removeCliente(string nome);
    int getStockOk() const;
    int getStockMin() const;
    void setStockOk(unsigned int stockOk);
    void setStockMin(unsigned int stockMin);
}



#endif //AEDA_BUYNOW_H
