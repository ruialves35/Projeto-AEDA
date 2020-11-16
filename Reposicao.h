#ifndef BUYNOWUI_CPP_REPOSICAO_H
#define BUYNOWUI_CPP_REPOSICAO_H

#include "LojaFisica.h"

class Reposicao {
private:
    LojaFisica lojaFisica;
    Produto* produto;
    int quantidade;
public:
    Reposicao();
    Reposicao(LojaFisica lf, Produto* p, int quantidade);
    void setLojaFisica(LojaFisica lf);
    LojaFisica getLojaFisica() const;
    void setProduto(Produto* p);
    Produto* getProduto() const;
    void setQuantidade(int quantidade);
    int getQuantidade() const;
};


#endif //BUYNOWUI_CPP_REPOSICAO_H
