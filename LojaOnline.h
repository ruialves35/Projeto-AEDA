#ifndef AEDA_LOJAONLINE_H
#define AEDA_LOJAONLINE_H

class LojaOnline{
private:
    vector<Produto*> produtos;
    vector<Transacao*> transacoes;
public:
    void addProduto(Produto produto);
}


#endif //AEDA_LOJAONLINE_H
