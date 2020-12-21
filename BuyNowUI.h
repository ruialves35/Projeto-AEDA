#ifndef AEDA_BUYNOWUI_H
#define AEDA_BUYNOWUI_H
#include "BuyNow.h"
#include "ClienteRegistado.h"
#include "Cliente.h"
#include "Pagamento.h"
#include "Multibanco.h"
#include "MbWay.h"
#include "CartaoCredito.h"
#include "Fornecedor.h"

class BuyNowUI {
private:
    BuyNow bn;
public:
    BuyNowUI();
    void UI();
    void cliente();
    void administrador();
    void lerCategorias();
    void escreverCategorias();
    void lerProdutos();
    void escreverProdutos();
    void lerClientes();
    void escreverClientes();
    void lerLojasFisicas();
    void escreverLojasFisicas();
    void lerProdutosLojaOnline();
    void lerProdutosLojaFisica();
    void escreverProdutosLojaFisica();
    void lerReposicoes();
    void lerTransferencias();
    void LerTransacoes();
    void escreverTransacoes();
    void escreverTransferencias();
    void escreverReposicoes();
    void escreverLojaOnline();
    void lerFornecedores();
    void escreverFornecedores();
};


#endif //AEDA_BUYNOWUI_H

