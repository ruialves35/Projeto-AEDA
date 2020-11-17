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
Transferencia::Transferencia(Fornecedor &f, Produto *p, int quantidade, Date data):
fornecedor(f), produto(p), quantidade(quantidade), data(data) {}

/**
 * Gets the fornecedor
 * @return Fornecedor
 */
Fornecedor Transferencia::getFornecedor() const { return fornecedor;}

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
void Transferencia::setFornecedor(Fornecedor &f) {fornecedor = f;}

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
    string info = "Fornecedor: ";
    info += fornecedor.getNomeFornecedor() + "\n";
    info += "Produto: " + produto->getNomeProduto();
    info += "Quantidade: " + to_string(quantidade);
    return info;
}