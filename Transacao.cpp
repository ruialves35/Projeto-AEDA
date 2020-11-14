#include "Transacao.h"
#include <algorithm>
#include <iomanip>

int Transacao::numberOfTransacoes = 0;

/**
 * Transacao empty constructor. Sets valorTotal to 0 and data 00/00/0000
 */
Transacao::Transacao(): valorTotal(0), data(){
    numberOfTransacoes++;
    number = getNumberOfTransacoes();
}


/**
 * Contructor of Transacao. Sets cliente to c, data to d and valorTotal to 0
 * @param c receives the client of Transacao
 * @param d receives the data of Transacao
 */
Transacao::Transacao(Cliente *c, Date &d):  cliente(c), data(d), valorTotal(0){
    numberOfTransacoes++;
    number = numberOfTransacoes;
}

/**
 * Contructor of Transacao. Sets cliente to c, data to d, vector of all products to v and valorTotal to 0
 * @param c Client of Transacao
 * @param d Data of Transacao
 * @param v All products of transacao
 */
Transacao::Transacao(Cliente *c, Date &d, vector<Produto *> &v): cliente(c), data(d), produtos(v),
                                                                 valorTotal(0){
    numberOfTransacoes++;
    number = numberOfTransacoes;
    for (auto i : produtos){
        if (quantidade.find(i) == quantidade.end() ) quantidade[i] = 1;
        else quantidade[i]++;
        valorTotal += i->getValor();
    }
}

/**
 * Constructor of Transacao. Sets cliente to c, data to d, vector of all products to v, valorTotal
 * to 0 and tipoPagamento to p
 * @param c
 * @param d
 * @param v
 * @param p
 */
Transacao::Transacao(Cliente *c, Date &d, vector<Produto *> &v, Pagamento *p): cliente(c), data(d), produtos(v),
                                                                               valorTotal(0), tipoPagamento(p){
    numberOfTransacoes++;
    number = numberOfTransacoes;
    for (auto i : produtos){
        if (quantidade.find(i) == quantidade.end() ) quantidade[i] = 1;
        else quantidade[i]++;
        valorTotal += i->getValor();
    }
    p->setValor(valorTotal);
}

/**
 * @return the number of the transacao
 */
int Transacao::getNumber() const {
    return number;
}

/**
 * @return the number of Transacoes created
 */
int Transacao::getNumberOfTransacoes() const {
    return numberOfTransacoes;
}

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



/*
 * Add a Produto to Transacao.
 * @param p Product to be added

void Transacao::addProduto(Produto *p) {
    if ( find(produtos.begin(), produtos.end(), p) == produtos.end()){
        produtos.push_back(p);
        quantidade[p] = 1;  //nao esta na transacao
    }
    else{
        quantidade[p] += 1;
    }
    valorTotal += p->getValor();
}
*/

/**
 * Add a Quantity of a Produto to Transacao.
 * @param p Product to be added
 * @param quantidade Quantity of Product (predefinition 1)
 */
void Transacao::addProduto(Produto *p, int quantidade) {
    if (find(produtos.begin(), produtos.end(), p) == produtos.end()){
        produtos.push_back(p);
        this->quantidade[p] = quantidade;   //nao esta nos produtos ainda, e portanto tbm nao esta na quantidade
    }
    else{
        this->quantidade[p] += quantidade;  //ja esta nos produtos, é so acrescentar a quantidade.
    }
    valorTotal += p->getValor() * quantidade;
}



/**
 * Sets a type of payment
 * @param p Type of Payment
 */
void Transacao::setPagamento(Pagamento* p) {
    tipoPagamento = p;
    tipoPagamento->setValor(valorTotal);
}

/**
 * Gets the type of payment
 * @return Type of payment (MbWay, Multibanco, CartaoCredito)
 */
Pagamento * Transacao::getPagamento() const {
    return tipoPagamento;
}

/**
 * gets the total value of Transacao
 * @return valorTotal
 */
double Transacao::getValorTotal() const { return valorTotal; }

/**
 * Removes 1 Produto in the Transacao (quantity removed is one)
 * @param p Produto to be removed
 */
void Transacao::removeProduto(Produto *p) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), p);
    if (it != produtos.end()){
        if (quantidade[p] == 1) {   //so tinha 1 produto, eliminar
            produtos.erase(it);
        }
        else{   //quantidade desse produto era > 1, só tiramos 1 e ficamos com os restantes
            quantidade[p]--;
        }
        valorTotal -= p->getValor();
    }
    cout << "The product wasn't in the Transaction already." << endl;
}

/**
 * Removes a Produto of the Transacao
 * @param p Produto to be removed
 * @param quantidade Quantity of the product removed
 */
void Transacao::removeProduto(Produto *p, int quantidade){
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), p);
    if (it != produtos.end()){
        if (this->quantidade[p] - quantidade <= 0){
            produtos.erase(it);
        }
        else{
            this->quantidade[p] -= quantidade;
        }
        valorTotal -= p->getValor() * quantidade;
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
 * sort Produtos of Transacao by name
 */
void Transacao::sortByName() {
    sort(produtos.begin(), produtos.end(), compareProdutosByName);
}

/**
 * sort Produtos of Transacao by Id
 */
void Transacao::sortById() {
    sort(produtos.begin(), produtos.end(), compareProdutosById);
}

/**
 * sort Produtos of Transacao by value
 */
void Transacao::sortByValue() {
    sort(produtos.begin(), produtos.end(), compareProdutosByValue);
}

/**
 * Overloading of operator << that shows the Nome of the Cliente of the Transacao,
 * the Data of the Transacao, All Products of Transacao (including each value, quantity and total Value);
 * @param o ostream to get the Information of the Transacao
 * @param t Transacao of which we want to get the Information
 * @return ostream with all the information
 */
ostream & operator<<(ostream &o, const Transacao &t)
{
    o << "---------------------------------------------------------------------------------------------------------" << endl;
    o << "Nome Cliente: " << t.cliente->getNome() << endl;
    o << "Numero de Contribuinte: " << t.cliente->getNumContribuinte() << endl;
    o << "Data: " << t.data << endl;
    o << "Transacao n: " << t.number << endl;
    o << "Pagamento: ";
    t.tipoPagamento->getInfo(o);
    o << endl;
    o << setfill(' ') << setw(15) << "Produto" << setfill(' ') << setw(15) << "Preco" << setfill(' ') << setw(15) << "Quantidade" << setfill(' ') << setw(15) << "Total" << endl;
    for (auto i : t.produtos){
        o << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << setfill(' ') << setw(15) << t.getQuantidade(i)
          << setfill(' ') << setw(15) << i->getValor()* t.getQuantidade(i) << endl;
    }
    o << endl;
    o << "TOTAL: " << t.valorTotal << endl;
    o << "------------------------------------------------------------------------------------------------------" << endl;
    return o;
}

/**
 * operator == that says if a transacao is equal to another
 * @param t1 one Transacao to compare
 * @param t2 the other Transacao to compare
 * @return true if Transacao are the same(same identifier number), false otherwise
 */
bool operator == (const Transacao &t1, const Transacao &t2){
    if (t1.number == t2.number) return true;
    return false;
}

