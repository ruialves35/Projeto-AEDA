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
 * @param stockOk stockOk of Produtos of
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, int stockOk, int stockMin):
        lojasFisicas(lf), lojaOnline(lo), stockOk(stockOk), stockMin(stockMin){}


/**
 * Constructor with all the information
 * @param lf vector with all the LojaFisicas
 * @param lo LojaOnline
 * @param tranferencias vector with all Transferencias Between Fornecedores and buyNow
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia *> tranferencias, int stockOk, int stockMin):
        lojasFisicas(lf), lojaOnline(lo), transferencias(tranferencias),stockOk(stockOk), stockMin(stockMin) {}

/**
 * Adds a cliente to Clientes of BuyNow
 * @param cliente Cliente to add
 */
void BuyNow::addCliente(Cliente *cliente) {
    if (find(clientes.begin(), clientes.end(), cliente) == clientes.end())
        clientes.push_back(cliente);
}

/**
 * Removes a Cliente from Clientes of the BuyNow
 * @param cliente Cliente to be removed
 */
void BuyNow::removeCliente(Cliente *cliente) {
    vector<Cliente*>::iterator it = find(clientes.begin(), clientes.end(), cliente);
    if (it != clientes.end()) clientes.erase(it);
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
 * Adds a lojaFisica to BuyNow
 * @param lf LojaFisica to be added
 */
void BuyNow::addLojaFisica(LojaFisica &lf) {
    if (find(lojasFisicas.begin(), lojasFisicas.end(), lf) == lojasFisicas.end())
        lojasFisicas.push_back(lf);
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
    //throw excecao LojaFisica does not exist
}

/**
 * Adds a Produto to LojaOnline
 * @param p Produto
 * @param quantidade Quantity of Produto
 */
void BuyNow::addProdutoOnline(Produto *p, int quantidade) {
    lojaOnline.addProduto(p, quantidade);
}

/**
 * Removes a Produto of LojaOnline
 * @param p Produto
 * @param quantidade Quantity of Produto
 */
void BuyNow::removeProdutoOnline(Produto *p, int quantidade) {
    lojaOnline.removeProduto(p, quantidade);
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
vector<Cliente *> BuyNow::getClientes() const { return clientes; }


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
 * Shows categorias available in BuyNow
 */
void BuyNow::showCategorias() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Categoria" << endl;
    for (auto i : categorias){
        cout << setfill(' ') << setw(15) << i.getNomeCategoria() << endl;
    }
}

/**
 * Repoe o stock de todos os produtos da lojaOnline
 * Procura nas lojas fisicas e retira da lojaFisica com maior stock, caso esta continue a ter um stock
 * do produto > do que stockOK
 * Caso n encontre nenhuma loja vai buscar ao Fornecedor
 */
void BuyNow::reporStock() {
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

/*
 * Displays All Produtos Available in LojasFisicas
void BuyNow::showAllProdutosFisico() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << setfill(' ') << setw(15) << "Quantidade" << endl;
    for (auto i : produtos){
        for (auto j : lojasFisicas){
            if (j.getStockFisico(i) > 0){
                cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << setfill(' ') << setw(15) << lojaOnline.getStockOnline(i) << endl;
            }
        }
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}*/

/*
 * Displays All Produtos Available in LojaOnline, including price and quantity
void BuyNow::showAllProdutosOnline() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << setfill(' ') << setw(15) << "Quantidade" << endl;
    for (auto i: produtos){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << setfill(' ') << setw(15) << lojaOnline.getStockOnline(i) << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}*/

/**
 * Adds a Produto to BuyNow (Now they are selling this Produto)
 * @param p Produto to be added
 */
void BuyNow::addProduto(Produto *p) {
    if (find(produtos.begin(), produtos.end(), p) == produtos.end())
        produtos.push_back(p);
}

/**
 * Removes a Produto of BuyNow (Now they don't sell this Produto anymore)
 * Goes to all LojasFisicas and delete the product from there
 * Goes to LojaOnline and delete the product from there
 * @param p Product to be removed
 */
void BuyNow::removeProduto(Produto *p) {
    vector<Produto*>::iterator it = find(produtos.begin(), produtos.end(), p);
    if (it != produtos.end()){
        produtos.erase(it); //remove da loja
        for (auto i : lojasFisicas){
            i.removeProduto(p, i.getStockFisico(p)); //tira das lojas fisicas
        }
        lojaOnline.removeProduto(p, lojaOnline.getStockOnline(p)); //tira da loja Online
    }
}

/**
 * Adds a Produto to a specific LojaFisica
 * @param lf LojaFisica that will get the Produto
 * @param p Produto
 * @param quantidade Quantity of Produto
 */
void BuyNow::addProdutoLojaFisica(LojaFisica &lf, Produto *p, int quantidade) {
    for (auto i: lojasFisicas){
        if (i == lf){
            i.addProduto(p, quantidade);
        }
    }
}

/**
 * Removes a Produto to a specific LojaFisica
 * @param lf LojaFisica from which we want to remove the Produto
 * @param p Produto
 * @param quantidade Quantity of Produto
 */
void BuyNow::removeProdutoLojaFisica(LojaFisica &lf, Produto *p, int quantidade) {
    for (auto i: lojasFisicas){
        if (i == lf){
            i.removeProduto(p, quantidade);
        }
    }
}

/**
 * Adds a Categoria to BuyNow database(vector)
 * @param c Categoria to be added
 */
void BuyNow::addCategoria(Categoria &c) {
    for (auto i : categorias){
        if (i.getNomeCategoria() == c.getNomeCategoria()) return;
    }
    categorias.push_back(c);
}

/**
 * Checks if a Cliente is already in DataBase
 * @param cliente Cliente to check
 * @return true if already exists, false otherwise
 */
bool BuyNow::checkCliente(Cliente &cliente) {
    for (auto i : clientes){
        if ((*i) == cliente) return true;
    }
    return false;
}

/**
 * Gets Fornecedor of BuyNow
 * @return Fornecedor
 */
Fornecedor BuyNow::getFornecedor() const{ return fornecedor; }

/**
 * Sets fornecedor of Buy Now
 * @param f Fornecedor
 */
void BuyNow::setFornecedor(Fornecedor &f) { fornecedor = f; }

/**
 * Shows Transacoes of LojaOnline of BuyNow
 */
void BuyNow::showTransacoes() {
    lojaOnline.showAllTransacoes();
}

/**
 * Removes a Categoria of BuyNow
 * @param c Categoria
 */
void BuyNow::removeCategoria(Categoria &c) {
    vector<Categoria>::iterator it;
    for (it = categorias.begin(); it != categorias.end(); it++){
        if (it->getNomeCategoria() == c.getNomeCategoria())
            categorias.erase(it);
    }
}
/**
 * Shows Produto of a Categoria
 * @param categoria string with name of Categoria of which we want to show Produtos
 */
void BuyNow::showProdutosCategoria(string categoira) {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << endl;
    for (auto i: produtos){
        if (i->getCategoria().getNomeCategoria() == categoira){
            cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << endl;
        }
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

/**
 * Displays all Produtos of BuyNow and each price
 */
void BuyNow::showProdutos() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(15) << "Produto " << setfill(' ') << setw(15) << "Preco" << endl;
    for (auto i : produtos){
        cout << setfill(' ') << setw(15) << i->getNomeProduto() << setfill(' ') << setw(15) << i->getValor() << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}
