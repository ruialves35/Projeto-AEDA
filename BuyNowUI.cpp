#include "BuyNowUI.h"

#include <iostream>

void Administrador();

void Cliente();

using namespace std;

BuyNowUI::BuyNowUI() {
    UI();
}

void BuyNowUI::UI() {
    cout << "Por favor insira 1 se for administrador e 2 se for cliente" << endl;
    int utilizador;
    cin >> utilizador;

    if(utilizador==1){
        Administrador();
    }

    if(utilizador==2){
        Cliente();
    }
}

void BuyNowUI::Cliente() {

        cout << "Por favor insira 1 se desejar adicionar produtos ao carrinho, 2 se deseja efetuar o pagamento e 3 se desejar se registar no sistema" << endl;

        int opcao;
        cin >> opcao;

        if(opcao==1){

        }

        if(opcao==2){

            cout << "efetuacao de pagamento" << endl;

        }

        if(opcao==3){

        }

}

void BuyNowUI::Administrador() {
    cout << "Por favor insira 1 ver as estatisticas e 2 para ver o historico de transacoes" << endl;
    int opcao;
    cin >> opcao;

    if(opcao==1){

    }

    if(opcao==2){

    }
}


