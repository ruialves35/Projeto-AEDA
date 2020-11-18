#ifndef AEDA_BUYNOWUI_H
#define AEDA_BUYNOWUI_H
#include "BuyNow.h"


class BuyNowUI {
private:
    BuyNow bn;
public:
    BuyNowUI();
    void UI();
    void cliente();
    void administrador();
    void lerCategorias();
    void lerProdutos();
    void lerProdutosLojaOnline();
    void lerProdutosLojaFisica();
    void lerReposicoes();
    void lerTransferencias();
};


#endif //AEDA_BUYNOWUI_H
