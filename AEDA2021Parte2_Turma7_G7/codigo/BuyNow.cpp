#include "BuyNow.h"
#include <iomanip>
#include <time.h>   //Get current Date

/**
 * Default constructor
 */
BuyNow::BuyNow(): fornecedores(){}

/**
 * Liberta o espaço reservado dinamicamente para as transferencias, clientes e transacoes.
 */
BuyNow::~BuyNow() {
    /*
    set<FornecedorPtr>::iterator iter;
    set<FornecedorPtr> forn = produtos[2]->getFornecedores();
    cout << "PRODUTO NAME" << produtos[2]->getNomeProduto() << endl;
    cout << "SIZE:" << forn.size() << endl;
    int n = 0;
    for (iter = forn.begin(); iter != forn.end(); iter++){
        cout << ++n << endl;
        cout << "FORNECEDORES:" << iter->getNomeFornecedor() << endl;
    }*/

    vector<Produto *>::iterator it;
    for (it = produtos.begin(); it != produtos.end(); it++){
        delete(*it);
    }

    vector<Cliente *>::iterator it2;
    for (it2 = clientes.begin(); it2 != clientes.end(); it2++){
        delete(*it2);
    }

    vector<Transferencia*>::iterator it3;
    for (it3 = transferencias.begin(); it3 != transferencias.end(); it3++){   //transferencias sao alocadas dinamicamente, temos de libertar o espaço reservado
        delete(*it3);
    }

    set<FornecedorPtr>::iterator it4;
    for (it4 = fornecedores.begin(); it4 != fornecedores.end(); it4++){
        delete it4->getFornecedor();
    }

    //cout << "Oioioi" << endl;
}
/**
 * Constructor with all the information
 * @param lf vector with all the LojaFisicas
 * @param lo LojaOnline
 * @param stockOk stockOk of Produtos of
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, int stockOk, int stockMin):
        lojasFisicas(lf), lojaOnline(lo), stockOk(stockOk), stockMin(stockMin), fornecedores()
{}


/**
 * Constructor with all the information
 * @param lf vector with all the LojaFisicas
 * @param lo LojaOnline
 * @param tranferencias vector with all Transferencias Between Fornecedores and buyNow
 */
BuyNow::BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia *> tranferencias, int stockOk, int stockMin):
        lojasFisicas(lf), lojaOnline(lo), transferencias(tranferencias),stockOk(stockOk), stockMin(stockMin),
        fornecedores() {}

/**
 * Adds a cliente to Clientes of BuyNow
 * @param cliente Cliente to add
 */
void BuyNow::addCliente(Cliente *cliente) {
    if (find(clientes.begin(), clientes.end(), cliente) == clientes.end())
        clientes.push_back(cliente);
}


/**
 * Gets a Cliente
 * @param nome Nome of Cliente
 * @param numContribuinte numero de contribuinte of Cliente
 * @return pointer that points to Cliente
 */
Cliente * BuyNow::getCliente(string nome, int numContribuinte) const {
    for (auto i : clientes){
        if ( i->getNome() == nome && i->getNumContribuinte() == numContribuinte)
            return i;
    }
    throw ClienteDoesNotExist(nome, numContribuinte);
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
 * @return vector with all categorias of BuyNow
 */
vector<Categoria> BuyNow::getCategorias() const { return categorias;}

/**
 * @return vector with all reposicoes of BuyNow
 */
vector<Reposicao> BuyNow::getReposicoes() const { return reposicoes;}
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
 * Shows information of Clientes
 */
void BuyNow::showClientes() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    for (auto i : clientes){
        cout << (*i) << endl;
    }
}

/**
 * Adds a Reposicao if is not already in vector of Reposicoes
 * @param reposicao to be added
 */
void BuyNow::addReposicao(Reposicao &reposicao) {
    if (find(reposicoes.begin(), reposicoes.end(), reposicao) == reposicoes.end())
        reposicoes.push_back(reposicao);
}

/**
 * Gets Produtos Of BuyNow
 * @return vector with Produtos
 */
vector<Produto *> BuyNow::getProdutos() const { return produtos; }


/**
 * sort Produtos of Transacao by name
 */
void BuyNow::sortProdutosByName() {
    sort(produtos.begin(), produtos.end(), compareProdutosByName);
}

/**
 * sort Produtos of Transacao by Id
 */
void BuyNow::sortProdutosById() {
    sort(produtos.begin(), produtos.end(), compareProdutosById);
}

/**
 * sort Produtos of Transacao by value
 */
void BuyNow::sortProdutosByValue() {
    sort(produtos.begin(), produtos.end(), compareProdutosByValue);
}

/**
 * Gets a Produto of BuyNow.
 * In case the Produto does not exist in BuyNow throws an error
 * @param codigo Id Of produto
 * @return Produto
 */
Produto * BuyNow::getProduto(int codigo) const {
    for (auto i : produtos) {
        if (i->getId() == codigo)
            return i;
    }
    throw ProdutoDoesNotExist(codigo);
}

/**
 * Gets a Produto of Buy Now.
 * In case the Produto Does not exist in Buy Now throws an error
 * @param nome Nome of Produto
 * @return Pointer to Produto
 */
Produto* BuyNow::getProduto(string nome) const {
    for (auto i : produtos){
        if (i->getNomeProduto() == nome)
            return i;
    }
    throw ProdutoDoesNotExistNome(nome);
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
            //cout << "ok\n";
            int repor = stockMin - lojaOnline.getStockOnline(i);   //quantidade que temos de repor
            //cout << "ok2\n";
            int idxLojaMaiorStock = -1;
            int maiorStock = 0;
            for (int j = 0; j < lojasFisicas.size(); j++){
                if (lojasFisicas[j].getStockFisico(i) > maiorStock){
                    idxLojaMaiorStock = j;
                    maiorStock = lojasFisicas[j].getStockFisico(i);
                }
            }
            //cout << "ok3\n";
            //cout << idxLojaMaiorStock << ".n\n";
            //cout << lojasFisicas[idxLojaMaiorStock].getStockFisico(i) <<"." << endl;
            if (idxLojaMaiorStock == -1){//nao encontrou nenhuma loja com stock Suficiente, buscar ao fornecedor
                //cout << "oi " << endl;
                time_t theTime = time(NULL);
                struct tm *aTime = localtime(&theTime);
                int day = aTime->tm_mday;
                int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                int year = aTime->tm_year + 1900; // Year is # years since 1900
                //cout << "data?" << endl;
                Date data(day, month, year);
                //cout << "aqui" << endl;
                set<FornecedorPtr> fornecedoresProd = i->getFornecedores();
                set<FornecedorPtr>::iterator prodIter;
                FornecedorPtr forn;
                //use BST of each product to find the best Fornecedor to restore the stock
                bool found = false;
                for (prodIter = fornecedoresProd.begin(); prodIter != fornecedoresProd.end(); prodIter++){
                    if (prodIter->getQuantidade() >= repor ){
                        forn = (*prodIter);
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "THERE IS NO FORNECEDOR WITH THAT QUANITTY OF PRODUCT AND STOCK HAS NOT BEEN REPLACED" << endl;
                    continue;
                }
                /*
                set<FornecedorPtr>::iterator it = fornecedores.begin();
                while(it != fornecedores.end()){   //search for fornecedor, BST ta por ordem busca o mais barato
                    //cout << "NOME: " << (*it).getNomeFornecedor() << endl;
                    if ((*it).getQuantidade() >= repor && (*it).getProduto()->getId() == i->getId()){ //is selling it
                        //cout << "Produto: " << (*it).getProduto()->getId() << endl;
                        //cout << "FORNECEDOR: " << (*it).getNomeFornecedor() << endl;
                        forn = (*it);
                        break;
                    }
                    it++;
                }*/
                Transferencia* t = new Transferencia (forn, i, repor, data); //fornecedor, produto, quantidade
                lojaOnline.addProduto(i, repor);
                transferencias.push_back(t);
            }
            else if (lojasFisicas[idxLojaMaiorStock].getStockFisico(i) - repor > stockOk){   //a loja tem stockSuficiente
                //cout << "oi2" << endl;
                lojasFisicas[idxLojaMaiorStock].removeProduto(i, repor);    //retirar da lojaFisica
                lojaOnline.addProduto(i, repor);    //adicionar na lojaOnline
                time_t theTime = time(NULL);
                struct tm *aTime = localtime(&theTime);

                int day = aTime->tm_mday;
                int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                int year = aTime->tm_year + 1900; // Year is # years since 1900
                Date data(day, month, year);
                Reposicao reposicao(lojasFisicas[idxLojaMaiorStock], i, repor, data);
                reposicoes.push_back(reposicao);
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
 * Adds a Produto to LojaFisica
 * @param localidade localidade of LojaFisica
 * @param p Produto to be added
 * @param quantidade Quantity of Produto
 */
void BuyNow::addProdutoLojaFisica(string localidade, Produto *p, int quantidade) {
    vector<LojaFisica>::iterator it;
    for (it = lojasFisicas.begin(); it != lojasFisicas.end(); it++){
        if (it->getLocalidade() == localidade) {
            it->addProduto(p, quantidade);
            break;
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
//Fornecedor BuyNow::getFornecedor() const{ return fornecedor; }

/**
 * Sets fornecedor of Buy Now
 * @param f Fornecedor
 */
//void BuyNow::setFornecedor(Fornecedor &f) { fornecedor = f; }

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
void BuyNow::showProdutosCategoria(string categoria) {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(30) << "Produto" << setfill(' ') << setw(30) << "Preco" << endl;
    for (auto i: produtos){
        if (i->getCategoria().getNomeCategoria() == categoria){
            cout << setfill(' ') << setw(30) << i->getNomeProduto() << setfill(' ') << setw(30) << i->getValor() << endl;
        }
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}

/**
 * Removes a Cliente of BuyNow database
 * @param nome of cliente
 * @param numContribuinte Numero de contribuinte of Cliente
 */
void BuyNow::removeCliente(string nome, int numContribuinte) {
    vector<Cliente*>::iterator it;
    for (it = clientes.begin(); it != clientes.end(); it++){
        if ((*it)->getNome() == nome && (*it)->getNumContribuinte() == numContribuinte){
            clientes.erase(it);
            break;
        }
    }
}

/**
 * Gets Categoria with name categoria.
 * If Categoria does not exist in BuyNow, throw error
 * @param categoria Categoria to show
 * @return Categoria
 */
Categoria BuyNow::getCategoria(string categoria) const {
    for (auto i: categorias){
        if (i.getNomeCategoria() == categoria) return i;
    }
    throw CategoriaDoesNotExist(categoria);
}

/**
 * Gets Loja fisica in a localidade
 * @param localidade of Loja Fisica
 * @return LojaFisica
 */
LojaFisica BuyNow::getLojaFisica(string localidade) const {
    for (auto i: lojasFisicas){
        if (i.getLocalidade() == localidade) return i;
    }
    //throw exception
    throw LojaFisicaDoesNotExist(localidade);
}
/**
 * Displays all Produtos of BuyNow and each price
 */
void BuyNow::showProdutos() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << setfill(' ') << setw(30) << "Produto " << setfill(' ') << setw(30) << "Preco" << endl;
    for (auto i : produtos){
        cout << setfill(' ') << setw(30) << i->getNomeProduto() << setfill(' ') << setw(30) << i->getValor() << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

/**
 * Displays all Reposicoes of BuyNow
 */
void BuyNow::showReposicoes() {
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    for (auto i : reposicoes){
        cout << i.getInfo() << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

/**
 * Adds a fornecedor to BST of fornecedores
 * @param f fornecedor to be added
 */
void BuyNow::addFornecedor(Fornecedor *f) {
    fornecedores.insert(f);
}

/**
 * Gets all fornecedores of BuyNow
 * @return Bst with pointers to all fornecedores
 */
set<FornecedorPtr> BuyNow::getFornecedores() const { return fornecedores; }

/**
 * Gets fornecedor with this nif
 * @param nif of Fornecedor
 * @return Pointer to fornecedor
 */
Fornecedor * BuyNow::getFornecedor(int nif) const {
    set<FornecedorPtr>::iterator it = fornecedores.begin();
    while(it != fornecedores.end()){
        if ((*it).getNif() == nif){
            return (*it).getFornecedor();
        }
        it++;
    }
    throw FornecedorDoesNotExist(nif);
}

/**
 * Removes a Fornecedor of BuyNow
 * Removes the Fornecedor from produtos database.
 * @param f fornecedor to be removed
 */
void BuyNow::removeFornecedor(Fornecedor *f) {
    set<FornecedorPtr>::iterator it;
    for (it = fornecedores.begin(); it != fornecedores.end(); it++){
        if ((*it) == f){
            fornecedores.erase(it);
            break;
        }
    }
    for (auto &i : produtos){
        i->removeFornecedor(f->getNomeFornecedor());
    }
}

/**
 * Adds a message to hash with messages
 * @param msg Message to be added
 */
void BuyNow::addMensagem(Mensagem &msg) { mensagens.insert(msg);}

/**
 * Checks if a Mensagem was responded or not.
 * @param msg Mensagem to be responded
 * @return True if was responded, False if wasnt or wasnt sent yet
 */
bool BuyNow::checkMensagem(Mensagem &msg) const {
    //cout << "IS THIS DOING IT RIGHT?" << endl;
    for (auto i : mensagens){
        if (i == msg){
            //cout << "YES" << endl;
            return i.getRespondida();
        }
    }
    return false;
}

/**
 * Responds to a Mensagem
 * @param msg Message to be responded
 */
void BuyNow::answerMensagem(Mensagem &msg) {
    // << "IS THIS DOING IT RIGHT?" << endl;
    for (HashTableMensagem::iterator it = mensagens.begin(); it != mensagens.end(); it++){
        if ((*it) == msg){
            Mensagem newMsg = (*it);
            it = mensagens.erase(it);
            newMsg.setRespondida();
            mensagens.insert(newMsg);
        }
    }
    //cout << "YES" << endl;
}

/**
 * @return HashTable with all mensagens
 */
HashTableMensagem BuyNow::getMensagens() const {
    return mensagens;
}

/**
 * Removes a message of BuyNow
 * @param msg Message to be removed
 * @return true if removed, false otherwise
 */
bool BuyNow::removeMensagem(Mensagem msg) {
    // << "IS THIS DOING IT RIGHT?" << endl;
    for( HashTableMensagem::iterator it = mensagens.begin(); it != mensagens.end(); it++){
        if (it->getNumero() == msg.getNumero()){
            mensagens.erase(it);
            return true;
        }
    }
    //cout << "YES" << endl;
    return false;
}

/**
 * Removes a message of BuyNow
 * @param id number of Message to be removed
 * @return true if removed, false otherwise
 */
bool BuyNow::removeMensagem(int id) {
    for( HashTableMensagem::iterator it = mensagens.begin(); it != mensagens.end(); it++){
        if (it->getNumero() == id){
            mensagens.erase(it);
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------------------------------------------

void BuyNow::adicionarEncomenda(int tamanhoEncomenda) {
    priority_queue<Carrinha> carr;
    //Caso caiba numa carrinha
    while(!carrinhas.empty()){
        Carrinha carrinhaNova = carrinhas.top();
        carrinhas.pop();
        if(carrinhaNova.calcularEspacoLivre() > tamanhoEncomenda){
            carrinhaNova.addOcupacao(tamanhoEncomenda);
            carr.push(carrinhaNova);
            while(!carrinhas.empty()){
                Carrinha carrinhaNova = carrinhas.top();
                carrinhas.pop();
                carr.push(carrinhaNova);
            }
            carrinhas = carr;
            return;
        }
        carr.push(carrinhaNova);
    }
    carrinhas = carr;
    carr.empty();
    //Caso fique separado em diferentes carrinhas
    while(tamanhoEncomenda!=0){
        Carrinha carrinhaNova = carrinhas.top();
        carrinhas.pop();
        if(tamanhoEncomenda > carrinhaNova.calcularEspacoLivre()){
            tamanhoEncomenda = tamanhoEncomenda - carrinhaNova.calcularEspacoLivre();
            carrinhaNova.addOcupacao(carrinhaNova.calcularEspacoLivre());
        }
        else {
            carrinhaNova.addOcupacao(tamanhoEncomenda);
            carr.push(carrinhaNova);
            while(!carrinhas.empty()){
                Carrinha carrinhaNova = carrinhas.top();
                carrinhas.pop();
                carr.push(carrinhaNova);
            }
            carrinhas = carr;
            return;
        }
        carr.push(carrinhaNova);
    }

}

void BuyNow::despacharCarrinhas() {

    priority_queue<Carrinha> carr;

    while(!carrinhas.empty()){
        Carrinha carrinhaNova = carrinhas.top();
        carrinhas.pop();
        if(carrinhaNova.prontaDespachar()){
            carrinhaNova.SetOcupacao(0);
        }
        carr.push(carrinhaNova);
    }

    carrinhas = carr;

}

void BuyNow::despacharCarrinhaPorID(int id) {

    priority_queue<Carrinha> carr;

    while(!carrinhas.empty()){
        Carrinha carrinhaNova = carrinhas.top();
        carrinhas.pop();
        if(carrinhaNova.getID()==id){
            carrinhaNova.SetOcupacao(0);
        }
        carr.push(carrinhaNova);
    }

    carrinhas=carr;
}

void BuyNow::adicionarCarrinha(Carrinha carr) {

    carrinhas.push(carr);

}

priority_queue<Carrinha> BuyNow::queueAtual() const {
    return carrinhas;
}

void BuyNow::informacoesCarrinhas() {

    priority_queue<Carrinha> copia = carrinhas;

    while(!copia.empty()){
        Carrinha carrinhaNova = copia.top();
        copia.pop();
        cout << "ID: " << carrinhaNova.getID() << endl;
        cout << "Espaco Ocupado: " << carrinhaNova.getOcupacao() << endl;
        cout << "Espaco Maximo: " << carrinhaNova.getOcupacaoMaxima() << endl;
        cout << "Espaco Livre: " << carrinhaNova.calcularEspacoLivre() << endl;
        cout << "------------------------------------------------" << endl;
    }

}

bool BuyNow::verificarCarrinhaID(int id) {

    priority_queue<Carrinha> copia = carrinhas;

    while(!copia.empty()) {
        Carrinha carrinhaNova = copia.top();
        copia.pop();
        if(carrinhaNova.getID()==id){
            return true;
        }
    }

    return false;
}

void BuyNow::eliminarCarrinha(int id){
    priority_queue<Carrinha> carr;
    bool encontrou = false;
    while(!carrinhas.empty()) {
        Carrinha carrinhaNova = carrinhas.top();
        carrinhas.pop();
        if(carrinhaNova.getID() == id && !encontrou){
            encontrou = true;
        }
        else{
            carr.push(carrinhaNova);
        }
    }
    carrinhas = carr;
}