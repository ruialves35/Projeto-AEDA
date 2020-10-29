#include "Transacao.h"
#include <algorithm>

/**
 * Transacao empty constructor. Sets valorTotal to 0 and data 00/00/0000
 */
Transacao::Transacao() : valorTotal(0), data(){}

/**
 * Contructor of Transacao. Sets cliente to c, data to d and valorTotal to 0
 * @param c receives the client of Transacao
 * @param d receives the data of Transacao
 */
Transacao::Transacao(Cliente *c, Date &d): cliente(c), data(d), valorTotal(0){}

/**
 * Contructor of Transacao. Sets cliente to c, data to d, vector of all products to v and valorTotal to 0
 * @param c Client of Transacao
 * @param d Data of Transacao
 * @param v All products of transacao
 */
Transacao::Transacao(Cliente *c, Date &d, vector<Produto *> v): cliente(c), data(d), produtos(v), valorTotal(0){}

/**
 * Sets a Cliente to the Transcacao
 * @param c new Client of Transacao
 */
void Transacao::setCliente(Cliente *c) {
    cliente = c;
}

/**
 * Gets the client of the Transacao
 * @return Client of Transacao
 */
Cliente* Transacao::getCliente() const {
    return cliente;
}

/**
 * Gets the Date of Transacao
 * @return Date of Transacao
 */
Date Transacao::getDate() const {
    return data;
}

/**
 * Sets the Date of Transacao to d
 * @param d new Date of Transacao
 */
void Transacao::setDate(Date &d) {
    data = d;
}

/**
 * Add a Produto to Transacao.
 * @param p Product to be added
 */
void Transacao::addProduto(Produto *p) {
    if ( find(produtos.begin(), produtos.end(), p) == produtos.end()){
        produtos.push_back(p);
        quantidade[p] = 1;  //nao esta na transacao
    }
    else{
        quantidade[p] += 1;
    }
    valorTotal += p.getValor();
}

/**
 * Add a Quantity of a Produto to Transacao.
 * @param p Product to be added
 * @param quantidade Quantity of Product
 */
void Transacao::addProduto(Produto *p, int quantidade) {
    if (find(produtos.begin(), produtos.end(), p) == produtos.end()){
        produtos.push_back(p);
        this->quantidade[p] = quantidade;   //nao esta nos produtos ainda, e portanto tbm nao esta na quantidade
    }
    else{
        this->quantidade[p] += quantidade;  //ja esta nos produtos, é so acrescentar a quantidade.
    }
    valorTotal += p.getValor() * quantidade;
}

/**
 * Removes 1 Produto in the Transacao (quantity removed is one)
 * @param p Produto to be removed
 */
void Transacao::removeProduto(Produto *p) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), *p);
    if (it != produtos.end()){
        if (quantidade[p] == 1) {   //so tinha 1 produto, eliminar
            produtos.erase(it);
        }
        else{   //quantidade desse produto era > 1, só tiramos 1 e ficamos com os restantes
            quantidade[p]--;
        }
        valorTotal -= p.getValor();
    }
    cout << "The product wasn't in the Transaction already." << endl;
}

/**
 * Removes a Produto of the Transacao
 * @param p Produto to be removed
 * @param quantidade Quantity of the product removed
 */
void Transacao::removeProduto(Produto *p, int quantidade){
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), *p);
    if (it != produtos.end()){
        if (this->quantidade[p] - quantidade == 0){
            produtos.erase(it);
        }
        else{
            this->quantidade[p] -= quantidade;
        }
        valorTotal -= p.getValor() * quantidade;
    }
}

/**
 * Gets a quantity of a Produto in the Transacao
 * @param p Produto of which we want the quantity
 * @return Quantity of the Produto
 */
int Transacao::getQuantidade(Produto *p) const {
    map<Produto*, int>::const_iterator it = quantidade.find(p);
    if (it != quantidade.end()){
        return it->second;
    }
    return 0;
}


/**
 * Overloading of operator << that shows the Nome of the Cliente of the Transacao,
 * the Data of the Transacao, All Products of Transacao (including each value, quantity and total Value);
 * @param o ostream to get the Information of the Transacao
 * @param t Transacao of which we want to get the Information
 * @return ostream with all the information
 */
ostream & operator<<(ostream & o, const Transacao &t)
{
    o << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    o << "Nome: " << t.cliente->getNome() << endl;
    o << "Data: " << t.data << endl;
    o << setw(10) <<  "Produto " << setw(10) << "Valor" << setw(10) << "Quantidade" << setw(10) << "Total" << endl;
    for (auto i : t.produtos){
        map<Produto*, int>::const_iterator it = t.quantidade.find(i);
        o << i->getNomeProduto() << setw(10)<< i->getValor() << setw(10) << it->second
             << setw(10) << i->getValor()* it->second << endl;
    }
    o << "Valor Total: " << t.valorTotal;
    o << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    return o;
}
