#include "Pagamento.h"
#include <string> //std::to_string
#include <sstream>

Pagamento::Pagamento(): valor(-1){}

Pagamento::Pagamento(double valorTotal) {
    if (valorTotal >= 0){
        valor = valorTotal;
    }
    else{
        cout << "Wrong Value to the Pagamento. It must be a number >= 0. Set it again.";
        valor = -1;
    }
}

void Pagamento::getInfo(ostream& o) const {
    o << "Valor: " << to_string(valor);
}

double Pagamento::getValor() const {return valor;}

void Pagamento::setValor(double val) {
    if (val >= 0){
        valor = val;
    }
    else{
        cout << "Wrong Value to the Pagamento. It must be a positive number. Set it again.";
        valor = -1; //erro
    }

}
