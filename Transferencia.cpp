#include "Transferencia.h"
#include "Fornecedor.h"
#include "Produto.h"

using namespace std;

/**
 * Default constructor of Transferencia
 */
Transferencia::Transferencia() {}

/**
 * Constructor with all information needed
 * @param f Fornecedor
 * @param p Produto that BuyNow bought to Fornecedor
 * @param quantidade quantity of Produto
 */
Transferencia::Transferencia(FornecedorPtr &f, Produto *p, int quantidade, Date data):
fornecedor(f), produto(p), quantidade(quantidade), data(data) {
    preco = f.getPreco() * quantidade;
}

/**
 * Gets the fornecedor
 * @return Fornecedor
 */
Fornecedor* Transferencia::getFornecedor() const { return fornecedor.getFornecedor();}

/**
 * @return Date of Transferencia
 */
Date Transferencia::getData() const { return data; }

/**
 * Sets Date of Transferencia
 * @param data new Date
 */
void Transferencia::setData(Date &data) { this->data = data;}

/**
 * Sets the Fornecedor
 * @param f new Fornecedor
 */
void Transferencia::setFornecedor(FornecedorPtr &f) { fornecedor = f; }

/**
 * @return Produto
 */
Produto * Transferencia::getProduto() const { return produto; }

/**
 * Sets a new Produto to Transferencia
 * @param p new Produto
 */
void Transferencia::setProduto(Produto *p) { produto = p; }

/**
 * Gets the information of Transferencia (Fornecedor and his name, Produto and quantity of Produto)
 * @return string with all information of Transferencia
 */
string Transferencia::getInfo() const {
    string info = "Data: " + data.getInfo() + "\n";
    info += "Fornecedor: ";
    info += fornecedor.getNomeFornecedor() + "\n";
    info += "NIF: ";
    info += to_string(fornecedor.getNif()) + "\n";
    info += "Produto: " + produto->getNomeProduto() + "\n";
    info += "Quantidade: " + to_string(quantidade) + "\n";
    info += "Preco Total: " + to_string(quantidade * fornecedor.getPreco()) + "\n";
    return info;
}

/**
 * sets quantity of produto reposto
 * @param quantidade new quantity
 */
void Transferencia::setQuantidade(int quantidade) { this->quantidade = quantidade;}

/**
 * @return quantidade de produto reposto
 */
int Transferencia::getQuantidade() const {return quantidade;}

/**
 * @return Nif of Fornecedor
 */
int Transferencia::getNifFornecedor() const { return fornecedor.getNif();}

/**
 * @return Preco of Transferencia
 */
double Transferencia::getPreco() const { return fornecedor.getPreco() * quantidade; }