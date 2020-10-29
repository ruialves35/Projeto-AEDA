#include "Pagamento.h"
#include <string> //std::to_string

Pagamento::Pagamento(): valor(-1){}

Pagamento::Pagamento(double valorTotal) {
    if (valorTotal > 0){
        valor = valorTotal;
    }
    else{
        cout << "Wrong Value to the Pagamento. It must be a positive number. Set it again.";
        valor = -1;
    }
}

string Pagamento::getInfo() const {
    string info = "Valor: " + to_string(valor);
    return info;
}

double Pagamento::getValor() const {return valor;}

void Pagamento::setValor(double val) {
    if (val > 0){
        valor = val;
    }
    else{
        cout << "Wrong Value to the Pagamento. It must be a positive number. Set it again.";
        valor = -1; //erro
    }

}
