#ifndef AEDA_BUYNOWUI_H
#define AEDA_BUYNOWUI_H
#include "BuyNow.h"


class BuyNowUI {
private:
    BuyNow bn;
public:
    BuyNowUI();
    void UI();
    void Cliente();
    void Administrador();
    void guardarCategorias();
    void guardarProdutos();
};


#endif //AEDA_BUYNOWUI_H
