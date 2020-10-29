#include "Transacao.h"


Transacao::Transacao() : valorTotal(0){}

Date Transacao::getDate() const {
    return data;
}

void Transacao::setDate(Date &d) {
    data = d;
}

void Transacao::addProduto(Produto *p) {
    produtos.push_back(p);
}

void Transacao::removeProduto(Produto *p) {
    produtos.erase(find(produtos.begin(), produtos.end(), *p));
}



ostream & operator<<(ostream & o, const Transacao &t)
{
    o << "Nome: " << t.cliente.getNome() << endl;
    o << "Data: " << t.data << endl;
    o << setw(10) <<  "Produto " << setw(10) << "Valor" << setw(10) << "Quantidade" << setw(10) << "Total" << endl;
    for (auto i : t.produtos){
        o << i->getNomeProduto() << setw(10)<< i->getValorProduto() << setw(10) << i->quantidadeProduto()
             << setw(10) << i->getValorProduto()* i->quantidadeProduto() << endl;
    }

}
