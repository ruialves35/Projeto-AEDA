#include "BuyNow.h"
#include <iomanip>

/**
 * Default constructor
 */
BuyNow::BuyNow() {}

/**
 * Liberta o espaço reservado dinamicamente para as transferencias, clientes e transacoes.
 * Pensar em colocar aqui a parte em que escreve em ficheiros toda a informaçao da BuyNow
 * MUST COMPLETE THIS DESTRUCTOR
 */
BuyNow::~BuyNow() {
    for (auto i: transferencias){   //transferencias sao alocadas dinamicamente, temos de libertar o espaço reservado
        delete i;
    }
}
/**
 * Constructor with all the information
 * @param lf vector with all the LojaFisicas
 * @param lo LojaOnline
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo): lojasFisicas(lf), lojaOnline(lo){}


/**
 * Constructor with all the information
 * @param lf vector with all the LojaFisicas
 * @param lo LojaOnline
 * @param tranferencias vector with all Transferencias Between Fornecedores and buyNow
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia *> tranferencias):
        lojasFisicas(lf), lojaOnline(lo) {
    this->transferencias = tranferencias;
}
/**
 * Adds a cliente to Clientes of BuyNow
 * @param cliente Cliente to add
 */
void BuyNow::addCliente(Cliente *cliente) {
    lojaOnline.addCliente(cliente);
}

/**
 * Removes a Cliente from Clientes of the BuyNow
 * @param cliente Cliente to be removed
 */
void BuyNow::removeCliente(Cliente *cliente) {
    lojaOnline.removeCliente(cliente);
}

/**
 * Adds a Transacao to BuyNow database(vector)
 * @param t Transacao to add
 */
void BuyNow::addTransacao(Transacao *t) {
    lojaOnline.addTransacao(t);
}

/**
 * Removes a Transacao from BuyNow database(vector)
 * @param t Transacao to be removed
 */
void BuyNow::removeTransacao(Transacao *t) {
    lojaOnline.removeTransacao(t);
    //throw exception
}

/**
 * Gets stockMin of Products of OnlineShop
 * @return integer with stockMin
 */
int BuyNow::getStockMin() const { return stockMin;}


/**
 * Gets stockOk of Products of Fisical Shops
 * @return integer with stockOK
 */
int BuyNow::getStockOk() const { return stockOk; }

/**
 * Sets stockOk of Products of Fisical Shops
 * @param stockOk
 */
void BuyNow::setStockOk(unsigned int stockOk) {
    this->stockOk = stockOk;
}

/**
 * Sets stockMin of Products of LojaOnline
 * @param stockMin new stockOk
 */
void BuyNow::setStockMin(unsigned int stockMin) {
    this->stockMin = stockMin;
}

/**
 * Adds a lojaFisica to BuyNow
 * @param lf LojaFisica to be added
 */
void BuyNow::addLojaFisica(LojaFisica &lf) {
    if (find(lojasFisicas.begin(), lojasFisicas.end(), lf) == lojasFisicas.end()) lojasFisicas.push_back(lf);
}

/**
 * Removes a Loja Fisica from BuyNow
 * @param lf LojaFisica to be removed
 */
void BuyNow::removeLojaFisica(LojaFisica &lf) {
    for (int i = 0; i < lojasFisicas.size(); i++){
        if (lojasFisicas[i] == lf) {
            lojasFisicas.erase(lojasFisicas.begin() + i);
            return;
        }
    }
    //throw excecao
}

/**
 * Adds a transferencia to vector of all transferencias of BuyNow
 * @param t transferencia to be added
 */
void BuyNow::addTransferencia(Transferencia *t) {
    if (find(transferencias.begin(), transferencias.end(), t) == transferencias.end())
        transferencias.push_back(t);
    //already exists
}

/**
 * Removes a Transferencia from vector of all Transferencias of BuyNow
 * @param t transferencia to be removed
 */
void BuyNow::removeTransferencia(Transferencia *t) {
    vector<Transferencia*>::iterator it = find(transferencias.begin(), transferencias.end(), t);
    if (it != transferencias.end()) transferencias.erase(it);
    //throws exception transferencia does not exist?
}

/**
 * Gets LojasFisicas of BuyNow
 * @return vector with all LojasFisicas
 */
vector<LojaFisica> BuyNow::getLojasFisicas() const { return lojasFisicas;}

/**
 * Get lojaOnline of BuyNow
 * @return
 */
LojaOnline BuyNow::getLojaOnline() const { return lojaOnline;}

/**
 * Get Clientes of BuyNow(stored in LojaOnline)
 * @return vector with clientes of BuyNow
 */
vector<Cliente *> BuyNow::getClientes() const { return lojaOnline.getClientes(); }


/**
 * Get Transacoes of BuyNow (stored in LojaOnline)
 * @return vector with Transacoes of BuyNow
 */
vector<Transacao *> BuyNow::getTransacoes() const { return lojaOnline.getTransacoes();}

/**
 * Get Transferencias between BuyNow and Fornecedores
 * @return vector with Transferencias
 */
vector<Transferencia *> BuyNow::getTransferencias() const { return transferencias;}

/**
 * Repoe o stock de todos os produtos da lojaOnline
 * Procura nas lojas fisicas e retira da lojaFisica com maior stock, caso esta continue a ter um stock
 * do produto > do que stockOK
 * Caso n encontre nenhuma loja vai buscar ao Fornecedor
 */
void BuyNow::reporStock() {
    vector<Produto*> produtos = lojaOnline.getProdutos();
    for (auto i : produtos){
        if (lojaOnline.getStockOnline(i) < stockMin){
            int repor = stockMin - lojaOnline.getStockOnline(i);   //quantidade que temos de repor
            int idxLojaMaiorStock = -1;
            int maiorStock = 0;
            for (int j = 0; j < lojasFisicas.size(); j++){
                if (lojasFisicas[j].getStockFisico(i) > maiorStock){
                    idxLojaMaiorStock = j;
                    maiorStock = lojasFisicas[j].getStockFisico(i);
                }
            }
            if (lojasFisicas[idxLojaMaiorStock].getStockFisico(i) - repor > stockOk){   //a loja tem stockSuficiente
                lojasFisicas[idxLojaMaiorStock].removeProduto(i, repor);    //retirar da lojaFisica
                lojaOnline.addProduto(i, repor);    //adicionar na lojaOnline
            }
            else{//nao encontrou nenhuma loja com stock Suficiente, buscar ao fornecedor
                Transferencia* t = new Transferencia (fornecedor, i, repor); //fornecedor, produto, quantidade
                lojaOnline.addProduto(i, repor);
                transferencias.push_back(t);
            }
        }
    }
}

/**
 * Displays All Produtos Available in LojasFisicas
 */
void BuyNow::showAllProdutosFisico() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << setfill(' ') << setw(15) << "Quantidade" << endl;
    for (auto i : lojasFisicas){//percorrer lojas
        vector<Produto*> produtos = i.getProdutos();
        for (auto j : produtos) { //percorrer produtos de cada loja
            cout << setfill(' ') << setw(15) << j->getNomeProduto() << setfill(' ') << setw(15) << j->getValor() << setfill(' ') << setw(15) << i.getStockFisico(j) << endl;
        }
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

/**
 * Displays All Produtos Available in LojaOnline, including price and quantity
 */
void BuyNow::showAllProdutosOnline() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << setfill(' ') << setw(15) << "Quantidade" << endl;
    for (auto i: lojaOnline.getProdutos()){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << setfill(' ') << setw(15) << lojaOnline.getStockOnline(i) << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}
