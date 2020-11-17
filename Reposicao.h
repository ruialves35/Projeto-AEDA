#ifndef BUYNOWUI_CPP_REPOSICAO_H
#define BUYNOWUI_CPP_REPOSICAO_H

#include "LojaFisica.h"
#include "Date.h"
class Reposicao {
private:
    LojaFisica lojaFisica;
    Produto* produto;
    int quantidade;
    Date data;
public:
    Reposicao();
    Reposicao(LojaFisica lf, Produto* p, int quantidade, Date data);
    void setLojaFisica(LojaFisica lf);
    LojaFisica getLojaFisica() const;
    void setProduto(Produto* p);
    Produto* getProduto() const;
    void setQuantidade(int quantidade);
    int getQuantidade() const;
    Date getData() const;
    void setData(Date &data);
};


#endif //BUYNOWUI_CPP_REPOSICAO_H
