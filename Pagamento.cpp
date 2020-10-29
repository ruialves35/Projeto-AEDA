#include "Pagamento.h"

Pagamento::Pagamento(): valor(0){}

Pagamento::Pagamento(double valorTotal): valor(valorTotal) {}

void Pagamento::show() const {
    cout << "Valor: " << valor << endl;
}
