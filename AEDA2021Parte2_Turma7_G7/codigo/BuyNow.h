#ifndef AEDA_BUYNOW_H
#define AEDA_BUYNOW_H

#include <iostream>
#include <Windows.h>
#include <set>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

#include "LojaFisica.h"
#include "LojaOnline.h"
#include "Cliente.h"
#include "Transacao.h"
#include "Fornecedor.h"
#include "Transferencia.h"
#include "Categoria.h"
#include "Reposicao.h"
#include "Mensagem.h"
#include "bst.h"
#include "Carrinha.h"

using namespace std;

/**
 * Exception ProdutoDoesNotExistNome throwed on bn.getProduto, shows produto's id
 */
class ProdutoDoesNotExist{
public:
    int codigo;
    ProdutoDoesNotExist(int codigo){ this->codigo = codigo;}
    void showError() { cout << "O Produto com o codigo " << to_string(codigo) << "nao existe." << endl;
        Sleep(600);
    }
};

/**
 * Exception ProdutoDoesNotExistNome throwed on bn.getProduto, shows produto's name
 */
class ProdutoDoesNotExistNome{
public:
    string nome;
    ProdutoDoesNotExistNome(string nome) { this->nome = nome; }
    void showError(){ cout << "O Produto " << nome << " nao existe na loja." << endl; Sleep(300); }
};

/**
 * Exception LojaFisicaDoesNotExist throwed on getLojaFisica
 */
class LojaFisicaDoesNotExist{
public:
    string localidade;
    LojaFisicaDoesNotExist(string localidade){ this->localidade = localidade;}
    void showError() { cout << "Não existe nenhuma loja fisica em " << localidade << endl;
        Sleep(600);
    }
};

/**
 * Exception Categoria Does Not Exist, on getCategoria of BuyNow
 */
class CategoriaDoesNotExist{
public:
    string nome;
    CategoriaDoesNotExist(string name){ nome = name; }
    void showError(){ cout << "A categoria " << nome << " nao existe." << endl; Sleep(600);}

};

/**
 * Exception ClienteDoesNotExist, throwed on getCliente of BuyNow
 */
class ClienteDoesNotExist{
public:
    string nome;
    int numContribuinte;
    ClienteDoesNotExist(string nome, int numContribuinte){this->nome = nome; this->numContribuinte = numContribuinte;}
    void showError(){ cout << "O cliente de nome " << nome << " e numero de contribuinte " << to_string(numContribuinte) << " nao existe." << endl; Sleep(600);}
};

/**
 * Exception FornecedorDoesNotExist, throwed on getFornecedor of BuyNow
 */
class FornecedorDoesNotExist{
public:
    int nif;
    FornecedorDoesNotExist(int nif){this->nif = nif;}
    void showError(){ cout << "O fornecedor com nif " << to_string(nif) << " nao existe. " << endl;     Sleep(600);}

};
//-----------------------------------------------------------------------

struct MensagemHash {

    int operator()(const Mensagem& msg) const {
        int result = 0;
        for (auto i : to_string(msg.getCliente().getNumContribuinte())){
            result += stoi(&i);
        }
        return result + msg.getNumero();    //numContribuinte identifica o cliente + Numero da mensagem
    }

    bool operator()(const Mensagem& msg1, const Mensagem& msg2) const {
        return msg1.getNumero() == msg2.getNumero() && msg1.getCliente().getNumContribuinte() == msg2.getCliente().getNumContribuinte();
    }
};


typedef unordered_set<Mensagem, MensagemHash, MensagemHash> HashTableMensagem;

class BuyNow {
private:
    vector<Produto *> produtos;
    vector<Cliente *> clientes;
    vector<Categoria> categorias;
    vector<Reposicao> reposicoes;

    set<FornecedorPtr> fornecedores;
    HashTableMensagem mensagens;

    vector<LojaFisica> lojasFisicas;
    LojaOnline lojaOnline;
    //Fornecedor fornecedor;
    int stockOk;
    int stockMin;
    vector<Transferencia*> transferencias;  //entre Fornecedor e loja

    //----------------------------------------------------------------

    priority_queue<Carrinha> carrinhas; //lista de prioridade de carrinhas

    //-----------------------------------------------------------------

public:
    BuyNow();
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, int stockOk, int stockMin);
    BuyNow(vector<LojaFisica> &lf, LojaOnline &lo, vector<Transferencia*> tranferencias, int stockOk, int stockMin);
    ~BuyNow();

    void addFornecedor(Fornecedor* f);
    void removeFornecedor(Fornecedor* f);
    set<FornecedorPtr> getFornecedores() const;
    Fornecedor* getFornecedor(int nif) const;

    void addMensagem(Mensagem &msg);
    bool removeMensagem(Mensagem msg);
    bool removeMensagem(int id);
    bool checkMensagem(Mensagem &msg) const;
    void answerMensagem(Mensagem &msg);
    HashTableMensagem getMensagens() const;

    void addCategoria(Categoria &c);
    void removeCategoria(Categoria &c);
    //Fornecedor getFornecedor() const;
    //void setFornecedor(Fornecedor &f);
    void addCliente(Cliente *cliente);
    void removeCliente(string nome, int numContribuinte);
    void removeCliente(Cliente *cliente);
    bool checkCliente(Cliente &cliente);
    void addTransacao(Transacao *t);
    void removeTransacao(Transacao *t);
    void addProduto(Produto* p);
    void removeProduto(Produto* p);
    Produto* getProduto(int codigo) const;
    Produto* getProduto(string nome) const;
    vector<Produto*> getProdutos() const;
    void addReposicao(Reposicao &reposicao);
    void addLojaFisica(LojaFisica &lf);
    void removeLojaFisica(LojaFisica &lf);
    void addProdutoLojaFisica(LojaFisica &lf, Produto* p, int quantidade = 1);
    void addProdutoLojaFisica(string localidade, Produto* p, int quantidade = 1);
    void removeProdutoLojaFisica(LojaFisica &lf, Produto* p, int quantidade = 1);
    void addProdutoOnline(Produto* p, int quantidade = 1);
    void removeProdutoOnline(Produto* p, int quantidade = 1);
    int getStockOk() const;
    int getStockMin() const;
    void setStockOk(unsigned int stockOk);
    void setStockMin(unsigned int stockMin);
    void addTransferencia(Transferencia * t);
    void removeTransferencia(Transferencia * t);
    vector<LojaFisica> getLojasFisicas() const;
    LojaFisica getLojaFisica(string localidade) const;
    vector<Cliente*> getClientes() const;
    Cliente* getCliente(string nome, int numContribuinte) const;
    LojaOnline getLojaOnline() const;
    vector<Transacao*> getTransacoes() const;
    vector<Transferencia*> getTransferencias() const;
    vector<Reposicao> getReposicoes() const;
    Categoria getCategoria(string categoria) const;
    vector<Categoria> getCategorias() const;
    void reporStock();
    void showTransacoes();
    void showProdutos();
    void showProdutosCategoria(string categoria);
    void showCategorias();
    void showClientes();
    void showReposicoes();
    void sortProdutosByValue();
    void sortProdutosByName();
    void sortProdutosById();

    static bool compareProdutosByValue(const Produto* p1, const Produto* p2){
        return (*p1).getValor() < (*p2).getValor();
    }

    static bool compareProdutosById(const Produto* p1, const Produto *p2){
        return (*p1).getId() == (*p2).getId();
    }

    static bool compareProdutosByName(const Produto* p1, const Produto *p2){
        return (*p1).getNomeProduto() < (*p2).getNomeProduto();
    }

    void adicionarEncomenda(int tamanhoEncomenda);
    void despacharCarrinhas();
    void despacharCarrinhaPorID(int id);
    void adicionarCarrinha(Carrinha carr);
    priority_queue<Carrinha> queueAtual() const;
    void informacoesCarrinhas();
    bool verificarCarrinhaID(int id);
    void eliminarCarrinha(int id);
};



#endif //AEDA_BUYNOW_H
