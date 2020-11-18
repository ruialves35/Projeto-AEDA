#ifndef AEDA_BUYNOWUI_H
#define AEDA_BUYNOWUI_H
#include "BuyNow.h"
#include "ClienteRegistado.h"
#include "Cliente.h"
#include "Pagamento.h"
#include "Multibanco.h"
#include "MbWay.h"
#include "CartaoCredito.h"

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
    void lerClientes();
    void lerLojasOnline();
    void lerProdutosLojaOnline();
    void lerProdutosLojaFisica();
    void lerReposicoes();
    void lerTransferencias();
    void LerTransacoes();
    void escreverTransacoes();
};


#endif //AEDA_BUYNOWUI_H

