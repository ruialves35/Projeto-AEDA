#include "BuyNowUI.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>

using namespace std;

BuyNowUI::BuyNowUI() {
    //Fornecedor f;
    //f.setNome("Manel");
    //bn.setFornecedor(f);
    lerCategorias();
    lerProdutos();
    lerClientes();
    lerLojasFisicas();
    lerProdutosLojaOnline();
    lerProdutosLojaFisica();
    lerFornecedores();
    lerReposicoes();
    lerTransferencias();
    lerTransacoes();
    lerMensagens();
    lerCarrinhas();

    UI();

    escreverMensagens();
    escreverCategorias();
    escreverProdutos();
    escreverClientes();
    escreverLojasFisicas();
    escreverProdutosLojaFisica();
    escreverTransacoes();
    escreverTransferencias();
    escreverReposicoes();
    escreverLojaOnline();
    escreverFornecedores();
    escreverCarrinhas();

    //cout << "ooooo" << endl;
}


void BuyNowUI::UI() {

    string input;
    bool validInput = true;
    int result;
    do {
        validInput = true;
        cout << "Por favor insira 1 se for administrador e 2 se for cliente" << endl;
        getline(cin, input);
        istringstream checkinput(input); // get into a strinsgtream
        if (cin.eof()) {
            validInput = false;
            cin.clear();
            cout << "Por favor introduza um valor" << endl;
        }
        else if (!(checkinput >> result)) {		//is not a number or a number with letters/symbols.
            cout << "Por favor introduza um valor" << endl;
            validInput = false;
        }
        else if (result < 1 || result > 2) {
            cout << "O numero introduzido nao e correto" << endl;
            validInput = false;
        }
    } while (!validInput);

    if(result==1){
        administrador();
    }

    if(result==2){
        cliente();
    }

}

void BuyNowUI::cliente() {

    //Pede nome ao cliente
    cout << "Por favor insira o seu nome" << endl;
    string nome;
    getline(cin,nome);
    int contribuinteNumero = 0;

    //Pede contribuinte ao cliente
    bool validNumeroContribuinte = false;
    while(!validNumeroContribuinte) {
        cout << "Por favor insira o seu numero de contribuinte" << endl;
        string contribuinte;
        getline(cin, contribuinte);
        stringstream streamContribuinte(contribuinte);
        if (cin.eof()) {
            validNumeroContribuinte = false;
            cin.clear();
            cout << "Por favor introduza um valor" << endl;
        }
        else if (!(streamContribuinte >> contribuinteNumero)) {		//is not a number or a number with letters/symbols.
            cout << "Por favor introduza um valor" << endl;
            validNumeroContribuinte = false;
            Sleep(1000);
        }
        else{
            validNumeroContribuinte = true;
        }
    }

    //pede para o cliente escolher a opcao
    string input;
    bool endClient = false;
    vector<Produto*> carrinho;

    while(!endClient) {
        int result;
        bool validInput = true;
        do {
            validInput = true;
            cout << "0: Terminar Programa" << endl;
            cout << "1: Ver Produtos" << endl;
            cout << "2: Adicionar Produto ao Carrinho "<< endl;
            cout << "3: Efetuar Pagamento" << endl;
            cout << "4: Efetuar registo no sistema" << endl;
            cout << "5: Enviar Mensagem Eletronica" << endl;
            cout << "   Enter option: ";
            getline(cin, input);
            istringstream checkinput(input); // get into a strinsgtream
            if (cin.eof()) {
                validInput = false;
                cin.clear();
                cout << "Por favor introduza um valor" << endl;

            } else if (!(checkinput >> result)) {        //is not a number or a number with letters/symbols.
                cout << "Por favor introduza um valor" << endl;
                validInput = false;

            } else if (result < 0 || result > 5) {
                cout << "O numero introduzido nao e correto. Tem de ser entre 0 e 4" << endl;
                validInput = false;
            }
            else validInput = true;
        } while (!validInput);

        if (result == 0) {  //terminar
            endClient = true;
        }
        else if (result == 1) { //ver produtos
            bool validCategoria = false;
            string inputCategoria;
            do {
                cout << string(50, '\n'); //Clear Screen
                cout << "CATEGORIAS DISPONIVEIS" << endl;
                bn.showCategorias();
                Sleep(1000);
                cout << endl;
                cout << "Introduza a Categoria dos Produtos que deseja ver (uma das indicadas acima)" << endl;
                cout << "Categoria: ";
                getline(cin, inputCategoria);
                istringstream checkinput(inputCategoria); // get into a strinsgtream
                if (cin.eof()) {
                    validInput = false;
                    cin.clear();
                    cout << endl << "Categoria Inválida" << endl;
                    Sleep(7000);
                }
                else{
                    for (auto i : bn.getCategorias()){
                        if (i.getNomeCategoria() == inputCategoria)
                            validCategoria = true;
                    }
                }
                if (!validCategoria){
                    cout << endl << "Categoria Inválida" << endl;
                    Sleep(1000);
                }
            }while(!validCategoria);

            bool validSortOption = false;
            string ordenarInput;
            do{
                cout << endl;
                cout << "1: Ordenar por Valor" << endl;
                cout << "2: Ordenar por ID" << endl;
                cout << "3: Ordenar por Nome" << endl;
                cout << "4: Mostrar Produtos" << endl;
                cout << "   Enter option: ";
                getline(cin, ordenarInput);
                if (ordenarInput == "1")
                    bn.sortProdutosByValue();
                else if ( ordenarInput == "2")
                    bn.sortProdutosById();
                else if (ordenarInput == "3")
                    bn.sortProdutosByName();
                else if (ordenarInput == "4")
                    validSortOption = true;
                else{
                    cout << endl << "Opção Inválida" << endl;
                    Sleep(1000);
                    cout << string(50, '\n'); //Clear Screen
                }
            }while(!validSortOption);
            bn.showProdutosCategoria(inputCategoria);
            Sleep(7000);
        }

        else if (result == 2) {  //adicionar produto ao carrinho
            string input;
            bool validOption = false;
            do {
                cout << endl;
                cout << "Caso queira voltar para traz, introduza 0." << endl;
                cout << "Caso contrario, introduza o nome do produto. (Sensivel a Maiusculas, espacos e minusculas, certifique-se de que escreveu da forma correta)" << endl;
                cout << endl;
                cout << "Opcao: ";
                getline(cin, input);
                if (input == "0") break;
                for (auto i : bn.getProdutos()) {
                    if (i->getNomeProduto() == input){
                        string quantInput;
                        int quantidade;
                        cout << "Introduza a Quantidade de " << i->getNomeProduto() << " que deseja adicionar: ";
                        getline(cin, quantInput);
                        istringstream checkQuantidade(quantInput); // get into a strinsgtream

                        if (cin.eof()){
                            cin.clear();
                            cout << "Por favor introduza um valor correto para a quantidade " << endl;
                            Sleep(3000);
                            break;
                        }
                        else if (!(checkQuantidade >> quantidade)){
                            cout << "Por favor introduza um valor correto para a quantidade" << endl;
                            Sleep(3000);
                            break;
                        }
                        else {
                            validOption = true;
                            while (quantidade > 0) {
                                carrinho.push_back(i);
                                quantidade--;
                            }
                        }
                    }
                }
                if (!validOption) cout << "Produto invalido." << endl;
            } while(!validOption);
        }
        else if (result == 3) { //efetuar pagamento
            if (carrinho.size() == 0){
                cout << endl;
                cout << "Nao tens nada no carrinho. Introduz la produtos. " << endl;
                Sleep(1000);
                continue;
            }
            string opcaoPagar;
            int opcao;
            bool validOptionPagar = false;
            while(!validOptionPagar) {
                cout << endl;
                cout << "0: Retroceder" << endl;
                cout << "1: Multibanco" << endl;
                cout << "2: MbWay " << endl;
                cout << "3: Cartao de Credito" << endl;
                cout << "   Introduza a opcao de pagamento: ";
                getline(cin, opcaoPagar);
                istringstream checkInput(opcaoPagar); // get into a strinsgtream
                if (cin.eof()) {
                    cin.clear();
                    cout << endl << "Opcao Invalida" << endl;
                    Sleep(5000);
                    cout << string(50, '\n'); //Clear Screen
                } else if (!(checkInput >> opcao)) {
                    cout << "Opcao Invalida" << endl;
                } else if (opcao < 0 || opcao > 3) {
                    cout << "Opcao Invalida" << endl;
                }
                else{
                    //se opcao for 0 ele volta para tras
                    if (opcao == 0) validOptionPagar = true;

                    else if (opcao ==1){    //Multibanco
                        string referencia;
                        int ref;
                        cout << "Introduza a referencia multibanco: ";
                        getline(cin, referencia);
                        istringstream checkRef(referencia);
                        if (referencia.size() != 9){
                            cout << endl << "Referencia Invalida." << endl;
                            Sleep(5000);
                            cout << string(50, '\n'); //Clear Screen
                        }
                        else if (cin.eof()){
                            cin.clear();
                            cout << endl << "Numero de referencia Invalida" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');   //Clear Screen
                        }
                        else if (!(checkRef >> ref)){
                            cout << endl << "Numero de referencia Invalida" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');
                        }
                        else{
                            Cliente *c = new Cliente(nome, contribuinteNumero);

                            validOptionPagar = true;
                            Multibanco *multi = new Multibanco(ref);

                            time_t theTime = time(NULL);
                            struct tm *aTime = localtime(&theTime);
                            int day = aTime->tm_mday;
                            int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                            int year = aTime->tm_year + 1900; // Year is # years since 1900
                            Date data(day, month, year);

                            Transacao *t = new Transacao(c, data, carrinho, multi);
                            bn.addTransacao(t);
                            for (auto i : carrinho){
                                bn.removeProdutoOnline(i);
                            }
                            bn.reporStock();
                            bn.adicionarEncomenda(carrinho.size());
                            carrinho.clear();
                        }
                    }
                    else if (opcao == 2){    //MbWay
                        string inputNum;
                        int numTelemovel;
                        cout << "Introduza o seu numero de telemovel: ";
                        getline(cin, inputNum);
                        istringstream checkNum(inputNum);
                        if (inputNum.size() != 9){
                            cout << endl << "Numero de telemovel invalido" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');
                        }
                        else if (cin.eof()){
                            cin.clear();
                            cout << endl << "Numero de telemovel Invalido" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');   //Clear Screen
                        }
                        else if (!(checkNum >> numTelemovel)){
                            cout << endl << "Numero de telemovel Invalido" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');
                        }
                        else{
                            Cliente* c = new Cliente(nome, contribuinteNumero);
                            validOptionPagar = true;
                            MbWay *mb = new MbWay(numTelemovel);

                            time_t theTime = time(NULL);
                            struct tm *aTime = localtime(&theTime);
                            int day = aTime->tm_mday;
                            int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                            int year = aTime->tm_year + 1900; // Year is # years since 1900
                            Date data(day, month, year);

                            Transacao *t = new Transacao(c, data, carrinho, mb);
                            bn.addTransacao(t);
                            for (auto i : carrinho){
                                bn.removeProdutoOnline(i);
                            }
                            bn.reporStock();
                            bn.adicionarEncomenda(carrinho.size());
                            carrinho.clear();
                        }

                    }
                    else if (opcao == 3){   //cartao credito
                        string numCartao;
                        cout << "Introduza numero do cartao: ";
                        getline(cin, numCartao);
                        bool isNumber = true;
                        for (auto i : numCartao){
                            if (!isdigit(i)) {
                                isNumber = false;
                                break;
                            }
                        }
                        if (numCartao.size() != 15 && numCartao.size() != 16){
                            cout << endl << "Numero do Cartao Invalida. O numero do cartao tem de ter 15 ou 16 numeros." << endl;
                            Sleep(5000);
                            cout << string(50, '\n');   //Clear Screen
                        }
                        else if(cin.eof()){
                            cin.clear();
                            cout << endl << "Numero de Cartao Invalido" << endl;
                            Sleep(5000);
                            cout << string(50, '\n');   //Clear Screen
                        }
                        else if (!isNumber){
                            cout << endl << "O valor que introduziu nao e um numero de Cartao de Credito" << endl;
                            Sleep(5000);
                            cout << string(50, '\n'); //clear screen
                        }
                        else{
                            Cliente *c = new Cliente(nome, contribuinteNumero);
                            string data;
                            int day, month, year;
                            char carater;
                            cout << "Introduza a data de validade do cartao de credito (deve ser da forma DD/MM/AAAA): ";
                            getline(cin, data);
                            istringstream validData(data);
                            if (!(validData >> day >> carater >> month >>carater >> year)){
                                cout << "Data de Cartao Invalida" << endl;
                                Sleep(5000);
                                cout << string(50, '\n');
                            }
                            else {
                                validOptionPagar = true;
                                Date d1(day, month, year);

                                time_t theTime = time(NULL);
                                struct tm *aTime = localtime(&theTime);
                                int day2 = aTime->tm_mday;
                                int month2 = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                                int year2 = aTime->tm_year + 1900; // Year is # years since 1900
                                Date data(day2, month2, year2);

                                CartaoCredito *cc = new CartaoCredito(numCartao, d1);
                                Transacao *t = new Transacao(c, data, carrinho, cc);
                                bn.addTransacao(t);
                                for (auto i : carrinho){
                                    bn.removeProdutoOnline(i);
                                }
                                bn.reporStock();
                                bn.adicionarEncomenda(carrinho.size());
                                carrinho.clear();
                            }
                        }
                    }
                }
            }
        }
        else if (result == 4){  //registar um cliente
            bool alreadyExist = false;
            for (auto i : bn.getClientes()){
                Cliente *c = dynamic_cast<ClienteRegistado*>(i);
                if (c != NULL){
                    if (c->getNome() == nome && c->getNumContribuinte() == contribuinteNumero){
                        alreadyExist = true;
                        break;
                    }
                }
            }
            if (alreadyExist){
                cout << "Ja estas registado no sistema. " << endl;
                Sleep(3000);
            }
            else{
                string email;
                cout << "Introduz o teu endereco de email: ";
                getline(cin, email);
                bn.removeCliente(nome, contribuinteNumero);
                Cliente* c = new ClienteRegistado(nome, contribuinteNumero, email);
                bn.addCliente(c);
            }
        }
        else if (result == 5){  //Enviar uma mensagem eletronica
            bool isRegistered = false;
            Cliente *client;
            for (auto i : bn.getClientes()){
                client = dynamic_cast<ClienteRegistado*>(i);
                if (client != NULL){
                    if (client->getNome() == nome && client->getNumContribuinte() == contribuinteNumero){
                        isRegistered = true;
                        client = new Cliente(i->getNome(), i->getNumContribuinte());
                        break;
                    }
                }
            }
            if (!isRegistered){ //Ainda nao esta registado
                cout << "Tem de se registar primeiro no sistema." << endl;
                Sleep(1000);
            }
            else{   //Ja esta registado, pode enviar mensagens
                string mensagem;
                cout << "Introduza a mensagem que quer enviar." << endl;
                getline(cin, mensagem);
                Mensagem msg(mensagem, *client);
                bn.addMensagem(msg);
            }
        }
    }
}


/**
 * Setup of Administrador
 */
void BuyNowUI::administrador() {
    //pede para o cliente escolher a opcao
    string input;
    bool validInput = true;
    bool endProgram = false;
    int result;
    while(!endProgram) {
        do {
            input = "";
            validInput = true;
            cout << "0: End Program" << endl;
            cout << "1: Ver Produtos da Empresa" << endl;
            cout << "2: Ver Clientes da Empresa" << endl;
            cout << "3: Ver compras feitas pela Empresa ao Fornecedor" << endl; //Transferencias
            cout << "4: Ver Reposicoes feitas a Loja Online" << endl;
            cout << "5: Ver Lojas Fisicas da Empresa" << endl;
            cout << "6: Ver Transacoes feitas pelos Clientes a Loja Online" << endl;
            cout << "7: Ver Todos os Fornecedores da Empresa" << endl;
            cout << "8: Comprar Produto a Fornecedor" << endl;
            cout << "9: Remover Fornecedor" << endl;
            cout << "10: Adicionar Fornecedor" << endl;
            cout << "11: Ver todas as Mensagens" << endl;
            cout << "12: Responder a uma Mensagem" << endl;
            cout << "13: Remover Mensagem" << endl;
            //---------------------------------------------------------------------
            cout << "14: Districuicao das carrinhas com maior ocupacao" << endl;
            cout << "15: Distribuicao de uma carrinha atraves do id da mesma" << endl;
            cout << "16: Ver todas as carrinhas disponiveis" << endl;
            cout << "17: Adicionar uma carrinha" << endl;
            cout << "18: Remover Carrinha" << endl;
            //----------------------------------------------------------------------
            cout << endl;
            cout << "Enter option: ";
            getline(cin, input);
            istringstream checkinput(input); // get into a strinsgtream
            bool isNumber = true;
            for (auto i:input){
                if (!(isdigit(i))) {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber){
                validInput = false;
                cout << endl << "Introduza apenas um numero. "  << endl;
                Sleep(2000);
            }
            else if (cin.eof()) {
                validInput = false;
                cin.clear();
                cout << endl << "Opção Inválida" << endl;
                Sleep(1000);
                cout << string(50, '\n'); //Clear Screen
            } else if (!(checkinput >> result)) {        //is not a number or a number with letters/symbols.
                cout << endl << "Opção Inválida" << endl;
                Sleep(1000);
                cout << string(50, '\n'); //Clear Screen
                validInput = false;
            } else if (result < 0 || result > 18) { //--------------ESTA-----------------------------------------------
                cout << endl << "O numero introduzido nao e correto" << endl;
                Sleep(1000);
                cout << string(50, '\n'); //Clear Screen
                validInput = false;
            }
        } while (!validInput);

        if (result == 0){   //special key, ends program
            endProgram = true;
        }

        else if (result == 1) {  //quer ver os produtos
            bool validCategoria = false;
            string inputCategoria;
            do {
                cout << "CATEGORIAS DISPONIVEIS" << endl;
                bn.showCategorias();
                Sleep(1000);
                cout << endl;
                cout << "Introduza a Categoria dos Produtos que deseja ver (uma das indicadas acima)" << endl;
                cout << "Categoria: ";
                getline(cin, inputCategoria);
                istringstream checkinput(inputCategoria); // get into a strinsgtream
                if (cin.eof()) {
                    validInput = false;
                    cin.clear();
                    cout << endl << "Categoria Inválida" << endl;
                    Sleep(500);
                    cout << string(50, '\n'); //Clear Screen
                }
                else{
                    for (auto i : bn.getCategorias()){
                        if (i.getNomeCategoria() == inputCategoria)
                            validCategoria = true;
                    }
                }
                if (!validCategoria){
                    cout << endl << "Categoria Inválida" << endl;
                    Sleep(500);
                    cout << string(50, '\n'); //Clear Screen
                }
            }while(!validCategoria);

            bool validSortOption = false;
            string ordenarInput;
            do{
                cout << endl;
                cout << "1: Ordenar por Valor" << endl;
                cout << "2: Ordenar por ID" << endl;
                cout << "3: Ordenar por Nome" << endl;
                cout << "4: Mostrar Produtos" << endl;
                cout << "   Introduza a opcao que pretender: ";
                getline(cin, ordenarInput);
                if (ordenarInput == "1")
                    bn.sortProdutosByValue();
                else if ( ordenarInput == "2")
                    bn.sortProdutosById();
                else if (ordenarInput == "3")
                    bn.sortProdutosByName();
                else if (ordenarInput == "4")
                    validSortOption = true;
                else{
                    cout << endl << "Opção Inválida" << endl;
                    Sleep(700);
                    cout << string(50, '\n'); //Clear Screen
                }
            }while(!validSortOption);
            bn.showProdutosCategoria(inputCategoria);
            Sleep(2000);
        }

        else if (result == 2) {  //ver Clientes da empresa
            bn.showClientes();
        }

        else if (result == 3){   //ver compras feitas pela empresa ao fornecedor
            cout << endl;
            for (auto i : bn.getTransferencias()){
                cout << i->getInfo() << endl;
            }
            cout << endl;
        }

        else if (result == 4){   //reposicoes feitas a loja online
            cout << endl;
            for (auto i : bn.getReposicoes()){
                cout << i.getInfo() << endl;
            }
        }

        else if (result == 5){   //Ver lojas fisicas da empresa
            cout << endl;
            for (auto i : bn.getLojasFisicas()){
                cout << i.getLocalidade() << endl;
            }
            cout << endl;
        }

        else if (result == 6){  //display all transacoes
            bn.showTransacoes();
        }

        else if (result == 7){  //display all fornecedores
            set<FornecedorPtr> fornecedores = bn.getFornecedores();
            cout << setfill(' ') << setw(30) << "NOME" << setfill(' ') << setw(30)  << "PRODUTO" << setfill(' ') << setw(30) << "PRECO" << endl;
            for (set<FornecedorPtr>::iterator it = fornecedores.begin(); it != fornecedores.end(); it++){
                cout << setfill(' ') << setw(30) << it->getNomeFornecedor() << setfill(' ') << setw(30) << it->getProduto()->getNomeProduto() << setfill(' ') << setw(30) << it->getPreco() << endl;
            }
        }

        else if (result == 8){ //Comprar Produto a Fornecedor
            bn.showProdutos();
            cout << endl;
            string nomeProduto;
            cout << "Qual destes produtos deseja comprar? " << endl;
            getline(cin, nomeProduto);
            try{
                string nomeFornecedor;
                Produto* prod = bn.getProduto(nomeProduto);
                set<FornecedorPtr> fornecedores = prod->getFornecedores();

                cout << setfill(' ') << setw(30) << "NOME" << setfill(' ') << setw(30)  << "PRODUTO"
                     << setfill(' ') << setw(30) << "PRECO" << setfill(' ') << setw(30) << "STOCK";

                for (set<FornecedorPtr>::iterator it = fornecedores.begin(); it != fornecedores.end(); it++){
                    cout << setfill(' ') << setw(30) << it->getNomeFornecedor() << setfill(' ') << setw(30)
                         << it->getProduto()->getNomeProduto() << setfill(' ') << setw(30)
                         << it->getPreco() << setfill(' ') << setw(30) << it->getFornecedor()->getQuantidade();
                }
                cout << "\nA qual fornecedor quer comprar o produto?" << endl;
                cout << "Nome do Fornecedor:";
                getline(cin, nomeFornecedor);

                FornecedorPtr fptr = prod->getFornecedor(nomeFornecedor);
                int quantity;
                cout << "\nQue quantidade desse produto quer comprar?" << endl;
                string inputQuantidade;
                getline(cin, inputQuantidade);
                istringstream checkinput(inputQuantidade); // get into a strinsgtream
                if (cin.eof()) {
                    cin.clear();
                    cout << endl << "Quantidade Invalida" << endl;
                    Sleep(300);
                    cout << string(50, '\n'); //Clear Screen
                }else if (!(checkinput >> quantity)){
                    cout << "Quantidade Invalida" << endl;
                    Sleep(300);
                    cout << string(50, '\n'); //Clear Screen
                }else if (quantity > fptr.getQuantidade()){
                    cout << "O Fornecedor nao tem stock suficiente" << endl;
                    Sleep(300);
                }
                else {
                    time_t theTime = time(NULL);
                    struct tm *aTime = localtime(&theTime);
                    int day = aTime->tm_mday;
                    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                    int year = aTime->tm_year + 1900; // Year is # years since 1900
                    Date data(day, month, year);
                    //cout << "QUANTIDADE:" << quantity << endl;
                    Transferencia* transferencia = new Transferencia(fptr, prod, quantity, data);
                    bn.addTransferencia(transferencia);
                    bn.addProdutoOnline(prod, quantity);
                }

            }
            catch(ProdutoDoesNotExistNome pd){
                pd.showError();
            }
            catch(FornecedorProdutoDoesNotExist f){
                f.showError();
            }
            catch(...){
                cout << "Nome invalido." << endl;
                Sleep(300);
            }
        }
        else if (result == 9){  //remover Fornecedor
            string inputNif;
            int nif;
            cout << "Introduza o nif do Fornecedor: ";
            getline(cin, inputNif);
            istringstream checkNif(inputNif);

            if (cin.eof()) {
                cin.clear();
                cout << endl << "Nif Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else if (!(checkNif >> nif)){
                cout << "Nif Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else{

                try {
                    Fornecedor* f = bn.getFornecedor(nif);
                    bn.removeFornecedor(f);

                }
                catch(FornecedorDoesNotExist fornecedor){
                    fornecedor.showError();
                    cout << "O fornecedor nao foi removido." << endl;
                    Sleep(300);
                }
                catch(...){
                    cout << "Nao foi possivel remover o fornecedor" << endl;
                    Sleep(300);
                }
            }
        }
        else if (result == 10){ //Adicionar Fornecedor
            string inputNif;
            int nif;
            cout << "Introduza o nif do Fornecedor: ";
            getline(cin, inputNif);
            istringstream checkNif(inputNif);

            if (cin.eof()) {
                cin.clear();
                cout << endl << "Nif Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else if (!(checkNif >> nif)){
                cout << "Nif Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else{
                try{    //Ja existe fornecedor
                    Fornecedor* fornecedor = bn.getFornecedor(nif);
                    cout << "Ja existe um fornecedor com esse nif, como tal nao pode ser adicionado denovo." << endl;
                    Sleep(500);
                }
                catch(FornecedorDoesNotExist f) {   //nao existe fornecedor, pode se adicionar
                    string nome;
                    cout << "Introduza o nome do Fornecedor: ";
                    getline(cin, nome);
                    if (cin.eof()) {
                        cin.clear();
                        cout << endl << "Nome Invalido" << endl;
                        Sleep(300);
                        cout << string(50, '\n'); //Clear Screen
                    }
                    else {
                        string sId;
                        int id;
                        cout << "Introduza o ID do Produto a vender: ";
                        getline(cin, sId);
                        istringstream checkId(sId);
                        if (cin.eof()) {
                            cin.clear();
                            cout << endl << "Nif Invalido" << endl;
                            Sleep(300);
                            cout << string(50, '\n'); //Clear Screen
                        }
                        else if (!(checkId >> id)) {
                            cout << "ID Invalido" << endl;
                            Sleep(300);
                            cout << string(50, '\n'); //Clear Screen
                        }
                        else {
                            try {   //O produto existe
                                Produto *prod = bn.getProduto(id);  //BUSCAR O PRODUTO
                                string inputPreco;
                                cout << "\nIntroduza o preco a que o Fornecedor vende o Produto: ";
                                getline(cin, inputPreco);
                                double preco;           //PRECO DO PRODUTO
                                istringstream checkPreco(inputPreco);
                                if (cin.eof()) {
                                    cin.clear();
                                    cout << endl << "Preco Invalido" << endl;
                                    Sleep(300);
                                    cout << string(50, '\n'); //Clear Screen
                                }
                                else if (!(checkPreco >> preco)) {
                                    cout << "Preco Invalido" << endl;
                                    Sleep(300);
                                    cout << string(50, '\n'); //Clear Screen
                                }
                                else{
                                    string inputQuantidade;
                                    cout << "Introduza a Quantidade de Produto que o Fornecedor tem: ";
                                    getline(cin, inputQuantidade);
                                    int quantidade;         //QUANTIDADE A QUE VENDE
                                    istringstream checkQuantidade(inputQuantidade);
                                    if (cin.eof()) {
                                        cin.clear();
                                        cout << endl << "Preco Invalido" << endl;
                                        Sleep(300);
                                        cout << string(50, '\n'); //Clear Screen
                                    }
                                    else if (!(checkQuantidade >> quantidade)) {
                                        cout << "Quantidade Invalida" << endl;
                                        Sleep(300);
                                        cout << string(50, '\n'); //Clear Screen
                                    }
                                    else{
                                        Fornecedor* fo = new Fornecedor(nome, nif, prod, preco, quantidade);
                                        bn.addFornecedor(fo);   //ADICIONAR O FORNECEDOR À BUYNOW E AO PRODUTO
                                        prod->addFornecedor(fo);
                                        cout << "Fornecedor adicionado com sucesso. " << endl << endl;
                                    }
                                }
                            }
                            catch (ProdutoDoesNotExist prod) {  //O produto nao existe entao o fornecedor nao o pode vender, pelo menos à BuyNow
                                prod.showError();
                                cout << "\nO Fornecedor nao foi adicionado." << endl;
                                Sleep(300);
                            }
                        }
                    }
                }
            }
        }
        else if (result == 11){//Ver todas as Mensagens
            for (auto i : bn.getMensagens()){
                cout << i << endl;
            }
        }
        else if (result == 12){ //Responder a uma mensagem
            string numeroMsg;
            cout << "Introduza o Numero da Mensagem a qual quer responder: ";
            getline(cin, numeroMsg);

            int numMsg;
            istringstream checkNumeroMsg(numeroMsg);
            if (cin.eof()) {
                cin.clear();
                cout << endl << "Numero da Mensagem Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else if (!(checkNumeroMsg >> numMsg)) {
                cout << "Numero da Mensagem Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else {   //everything ok
                for (auto &i : bn.getMensagens()) {
                    if (i.getNumero() == numMsg) {
                        Mensagem newMsg = i;
                        bn.removeMensagem(i);   //remover
                        newMsg.setRespondida(); //alterar
                        bn.addMensagem(newMsg); //voltar a adicionar
                    }
                }
            }
        }
        else if (result == 13) { //Remover Mensagem
            string numero;
            cout << "Insira o numero da mensagem que deseja apagar: ";
            getline(cin, numero);

            int numMsg;
            istringstream checkNumero(numero);
            if (cin.eof()) {
                cin.clear();
                cout << endl << "ID da Carrinha Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else if (!(checkNumero >> numMsg)) {
                cout << "Numero da Mensagem invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else {   //apagar Mensagem
                if (bn.removeMensagem(numMsg)){
                    cout << "A Mensagem foi apagada com sucesso.\n\n";
                    Sleep(500);
                }
                else{
                    cout << "Erro ao apagar a mensagem\n\n";
                    Sleep(500);
                }
            }
        }
        else if (result == 14){ //Distribuicao das carrinhas com maior ocupacao
            bn.despacharCarrinhas();
            cout << "Carrinhas despachadas"<< endl;
            cout << endl;
        }

        else if (result == 15){ //Distribuicao de uma carrinha com o id
            cout << "Insira o id da carrinha que deseja despachar" << endl;
            string valorIntroduzido;
            getline(cin, valorIntroduzido);
            int valorID = stoi(valorIntroduzido);
            bn.despacharCarrinhaPorID(valorID);
            cout << "Carrinha despachada" << endl;
            cout << endl;
        }

        else if (result == 16){ //Ver todas as carrinhas disponiveis
            bn.informacoesCarrinhas();
        }

        else if(result==17){    //Adicionar uma carrinha
            string numeroID;
            cout << "Insira o id da carrinha que deseja criar: ";
            getline(cin, numeroID);

            int numID;
            istringstream checkNumeroMsg(numeroID);
            if (cin.eof()) {
                cin.clear();
                cout << endl << "ID da Carrinha Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else if (! (checkNumeroMsg >> numID)){
                cout << "Id Invalido" << endl;
                Sleep(500);
                cout << string(50, '\n');
            }
            else if (!(bn.verificarCarrinhaID(numID))) {
                cout << "ID da Carrinha Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else {   //everything ok
                string valorIntroduzido;
                cout << "Insira a ocupacao da carrinha que deseja criar" << endl;
                getline(cin, valorIntroduzido);
                int valorOcupacao = stoi(valorIntroduzido);
                cout << "Insira a ocupacao maxima da carrinha que deseja criar" << endl;
                getline(cin, valorIntroduzido);
                int valorOcupacaoMaxima = stoi(valorIntroduzido);
                Carrinha *novaCar = new Carrinha(numID,valorOcupacao,valorOcupacaoMaxima);
                bn.adicionarCarrinha(*novaCar);
                cout << "Carrinha adicionada" << endl;
            }

        }
        else if (result == 18){ //Remover Carrinha

            string numeroID;
            cout << "Insira o id da carrinha que deseja apagar: ";
            getline(cin, numeroID);

            int numID;
            istringstream checkNumeroMsg(numeroID);
            if (cin.eof()) {
                cin.clear();
                cout << endl << "ID Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }else if (! (checkNumeroMsg >> numID)){
                cout << "Id Invalido" << endl;
                Sleep(500);
                cout << string(50, '\n');
            }
            else if (!(bn.verificarCarrinhaID(numID))) {
                cout << numID << endl;
                cout << "ID da Carrinha Invalido" << endl;
                Sleep(300);
                cout << string(50, '\n'); //Clear Screen
            }
            else {
                bn.eliminarCarrinha(numID);
            }
        }
        //----------------------------------------------------------------------------------------------------------------
    }
}

/**
 * Le as categorias da Loja, guardadas no ficheiro Categorias.txt
 */
void BuyNowUI::lerCategorias() {

    ifstream fin;
    string categoria,line;

    fin.open("Categorias.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das categorias nao encontrado\n";
        exit(1);
    }
    getline(fin,line);

    while(!fin.eof()){
        categoria = line;
        Categoria cat(categoria);
        bn.addCategoria(cat);
        getline(fin,line);

    }

}


/**
 * Ler fornecedores da BuyNow
 */
void BuyNowUI::lerFornecedores() {
    ifstream fin;
    fin.open("Fornecedores.txt");
    if (!fin.is_open()){
        cerr << "Ficheiro dos Fornecedores nao encontrado\n";
        exit(1);
    }

    string nome, line;
    int nif, idProduto;
    double preco;
    int quantidade;

    //int n = 0;

    getline(fin, line);
    while(!fin.eof()){

        nome = line;

        getline(fin, line);
        stringstream formatline(line);

        string show;
        formatline >> show;
        nif = stoi(show);

        getline(fin, line);
        stringstream formatline2(line);
        formatline2 >> idProduto;
        //cout << "ID: " << idProduto << endl;

        getline(fin, line);
        stringstream formatline3(line);
        formatline3 >> preco;
        //cout << "PRECO: " << preco << endl;

        getline(fin, line);
        stringstream formatline4(line);
        formatline4 >> quantidade;
        //cout << "QUANTIDADE: " << quantidade << endl;

        for (auto &i : bn.getProdutos()){
            if (i->getId() == idProduto){
                Fornecedor *fornecedor = new Fornecedor(nome, nif, i, preco, quantidade);
                i->addFornecedor(fornecedor);   //adicionar este fornecedor neste produto
                bn.addFornecedor(fornecedor);   //adicionar este fornecedor a bst com todos os fornecedores

                //cout << "MAIS UM FORNECEDOR: " << fornecedor->getNomeFornecedor() << fornecedor->getNif() << fornecedor->getProduto()->getId() << fornecedor->getPreco() << fornecedor->getQuantidade()<< endl;
                //++n;

                /*
                set<Fornecedor*>::const_iterator it2 = bn.getFornecedores().begin();
                while(it2 != bn.getFornecedores().end()){
                    cout << "NOME:: " << (*it2)->getNomeFornecedor() << endl;
                    it2++;
                }*/
                break;
            }
        }

        getline(fin, line);
    }


}
void BuyNowUI::lerProdutos() {

    ifstream fin;
    string stringProduto, stringCategoria, line;
    int codigo;
    double preco;

    fin.open("Produtos.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro dos produtos nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        stringProduto = line;

        getline(fin,line);
        stringCategoria = line;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> codigo;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> preco;

        Categoria cat = bn.getCategoria(stringCategoria);

        Produto *prod = new Produto(stringProduto,codigo,preco,cat);
        bn.addProduto(prod);
        getline(fin,line);
    }

}

void BuyNowUI::lerProdutosLojaOnline() {

    ifstream fin;
    string line;
    int codigo,quantidade;

    fin.open("Online.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro dos produtos online nao encontrado\n";
        exit(1);
    }

    getline(fin, line);
    int stockMin = stoi(line);
    bn.setStockMin(stockMin);
    getline(fin, line);
    int stockOk = stoi(line);
    bn.setStockOk(stockOk);

    getline(fin,line);
    while(!fin.eof()){

        istringstream format1line(line);
        format1line >> codigo;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> quantidade;

        bn.addProdutoOnline(bn.getProduto(codigo),quantidade);
        getline(fin,line);

    }
}

void BuyNowUI::lerProdutosLojaFisica() {

    //ler os produtos e adiciona-los as respetivas lojas
    ifstream fin;
    string line,localidadeLoja;
    int codigo, quantidade;

    fin.open("Fisica.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro dos produtos fisica nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        localidadeLoja = line;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> codigo;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> quantidade;

        //Produto *prod;
        //prod = bn.getProduto(codigo);

        bn.addProdutoLojaFisica(localidadeLoja, bn.getProduto(codigo), quantidade);
        //cout << bn.getLojaFisica(localidadeLoja).getStockFisico(bn.getProduto(codigo));
        getline(fin,line);

    }


}

void BuyNowUI::lerReposicoes() {

    ifstream fin;
    string line, stringLocalidade;
    int codigo, quantidade,dia,mes,ano;
    char caracter;


    fin.open("Reposicoes.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        istringstream format1line(line);
        format1line >> dia >> caracter >> mes >> caracter >> ano;

        Date d1(dia,mes,ano);

        getline(fin,line);
        istringstream format2line(line);
        format2line >> codigo;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> quantidade;

        getline(fin,line);
        stringLocalidade=line;

        LojaFisica l1;
        l1=bn.getLojaFisica(stringLocalidade);

        Produto *prod;
        prod = bn.getProduto(codigo);

        Reposicao rep(l1,prod,quantidade,d1);
        bn.addReposicao(rep);
        getline(fin,line);

    }

}

void BuyNowUI::lerTransferencias() {
    /*
    BSTItrIn<Fornecedor*> it3(bn.getFornecedores());
    int n = 0;
    while(!it3.isAtEnd()){
        cout << "NUMERO: " << ++n << endl;
        it3.advance();
    }*/

    ifstream fin;
    string line;
    int codigo, quantidade, dia, mes, ano;
    char caracter;
    int nifFornecedor;


    fin.open("Transferencias.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das transferencias nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        istringstream format1line(line);
        format1line >> dia >> caracter >> mes >> caracter >> ano;
        //cout << "ANO: " << ano << endl;

        getline(fin,line);
        istringstream fline(line);
        fline >> nifFornecedor;
        //cout << "NIF: " << nifFornecedor << endl;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> codigo;
        //cout << "CODIGO Produto: " << codigo << endl;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> quantidade;
        //cout << "QUANTIDADE: " << to_string(quantidade) << endl;

        try {
            Produto *prod = bn.getProduto(codigo);
            FornecedorPtr f(bn.getFornecedor(nifFornecedor));
            Date d1(dia,mes,ano);
            Transferencia *t1 = new Transferencia(f,prod,quantidade,d1);
            bn.addTransferencia(t1);
        } catch (FornecedorDoesNotExist f) {
            f.showError();
        } catch (ProdutoDoesNotExist p){
            p.showError();
        }
        getline(fin,line);

    }
    /*
    set<Fornecedor*>::iterator it = bn.getFornecedores().begin();
    while(it != bn.getFornecedores().end()){
        cout << (*it)->getNomeFornecedor() << endl;
        it++;
    }*/
}

void BuyNowUI::lerClientes() {

    ifstream fin;
    string line, stringNome,stringEmail;
    int numContribuinte;


    fin.open("Clientes.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        stringNome=line;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> numContribuinte;

        getline(fin,line);
        stringEmail=line;

        Cliente *c1 = new ClienteRegistado(stringNome,numContribuinte,stringEmail);
        bn.addCliente(c1);
        getline(fin, line);

    }

}

void BuyNowUI::lerTransacoes() {

    ifstream fin;
    string line, stringNome,numCartao,multibanco,mbway,cartao,stringTipoPagamento;
    int diaA,diaB,mesA,mesB,anoA,anoB,contribuinte,numTelemovel,referencia,codigo,quantidade;
    char caracter;
    multibanco="multibanco";
    mbway="mbway";
    cartao="cartao de credito";


    fin.open("Transacoes.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){
        istringstream format1line(line);
        format1line >> diaA >> caracter >> mesA >> caracter >> anoA;

        Date d1(diaA,mesA,anoA);

        getline(fin,line);
        stringNome=line;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> contribuinte;

        getline(fin,line);
        Transacao *tran = new Transacao();
        try {
            Cliente *c1 = bn.getCliente(stringNome, contribuinte);
            tran->setCliente(c1);
            tran->setDate(d1);
        }
        catch(ClienteDoesNotExist c){
            Cliente *c1 = new Cliente(c.nome, c.numContribuinte);
            tran->setCliente(c1);
            tran->setDate(d1);
        }
        catch(...){
            cout << "Error on Ler Transacoes\n" << endl;
            Sleep(300);
        }

        if(line==multibanco){

            getline(fin,line);
            istringstream format5line(line);
            format5line >> referencia;

            Pagamento *pag = new Multibanco(referencia);
            tran->setPagamento(pag);

        }
        else if(line==mbway){

            getline(fin,line);
            istringstream format5line(line);
            format5line >> numTelemovel;

            Pagamento *pag = new MbWay(numTelemovel);
            tran->setPagamento(pag);

        }
        else if(line==cartao){

            getline(fin,line);
            numCartao=line;

            getline(fin,line);
            istringstream format6line(line);
            format6line >> diaB >> caracter >> mesB >> caracter >> anoB;

            Date d2(diaB,mesB,anoB);

            Pagamento *pag = new CartaoCredito(numCartao,d2);
            tran->setPagamento(pag);

        }

        getline(fin,line);

        while (line!="-"){

            istringstream format11line(line);
            format11line >> codigo;

            getline(fin,line);
            istringstream format12line(line);
            format12line >> quantidade;

            tran->addProduto(bn.getProduto(codigo),quantidade);

            getline(fin,line);

        }

        bn.addTransacao(tran);
        getline(fin,line);

    }

}

/**
 * Le informacao Das lojas fisicas do ficheiro NomesFisicas.txt
 */
void BuyNowUI::lerLojasFisicas() {

    ifstream fin;
    string localidade,line;

    fin.open("NomesFisicas.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das lojas online (suas localizacoes) nao encontrado\n";
        exit(1);
    }
    getline(fin,line);

    while(!fin.eof()){
        localidade=line;
        LojaFisica loja(localidade);
        bn.addLojaFisica(loja);
        getline(fin,line);
    }

}

/**
 * Escreve a informacao das Reposicoes em ficheiro Reposicoes.txt
 */
void BuyNowUI::escreverReposicoes() {
    ofstream out;
    out.open("Reposicoes.txt");
    for (auto i : bn.getReposicoes()){
        out << i.getData() << endl;
        out << i.getProduto()->getId() << endl;
        out << i.getQuantidade() << endl;
        out << i.getLojaFisica().getLocalidade() << endl;
    }
    out.close();
}


/**
 * Escreve a informacao das Transferencias em ficheiro Transferencias.txt
 */
void BuyNowUI::escreverTransferencias() {
    ofstream out;
    out.open("Transferencias.txt");
    for (auto i : bn.getTransferencias()){
        out << i->getData() << endl;
        out << i->getNifFornecedor() << endl;
        out << i->getProduto()->getId() << endl;
        out << i->getQuantidade() << endl;
    }
    out.close();
}

/**
 * Escreve a informacao dos Fornecedores no ficheiro Fornecedores.txt
 */
void BuyNowUI::escreverFornecedores() {
    ofstream out;
    out.open("Fornecedores.txt");
    set<FornecedorPtr> f = bn.getFornecedores();
    for (set<FornecedorPtr>::iterator it = f.begin(); it != f.end(); it++){
        out << it->getNomeFornecedor() << endl;
        out << it->getNif() << endl;
        out << it->getProduto()->getId() << endl;
        out << it->getPreco() << endl;
        out << it->getQuantidade() << endl;
    }
    out.close();
}

/**
 * Escreve a informacao das Transacoes em ficheiros
 */
void BuyNowUI::escreverTransacoes() {
    ofstream out;
    out.open("Transacoes.txt");
    for (auto i : bn.getTransacoes()){
        out << i->getDate() << endl;
        out << i->getCliente()->getNome() << endl;
        out << i->getCliente()->getNumContribuinte() << endl;
        Multibanco *pag = dynamic_cast<Multibanco*>(i->getPagamento());
        if (pag != NULL){
            out << "multibanco" << endl;
            out << pag->getReferencia() << endl;
        }
        else{
            CartaoCredito *pag2 = dynamic_cast<CartaoCredito*>(i->getPagamento());
            if (pag2 != NULL ){
                out << "cartao de credito" << endl;
                out << pag2->getNumCartao() << endl;
                out << pag2->getValidade() << endl;
            }
            else{
                MbWay *pag3 = dynamic_cast<MbWay*>(i->getPagamento());
                if (pag3 != NULL){
                    out << "mbway" << endl;
                    out << pag3->getNumTelemovel() << endl;
                }
            }
        }
        for (auto j : i->getProdutos()){
            out << j->getId() << endl;
            out << i->getQuantidade(j) << endl;
        }
        out << "-" << endl;
    }
    out.close();
}

void BuyNowUI::escreverCategorias() {

    ofstream outStream;
    outStream.open("Categorias.txt");
    for(auto i: bn.getCategorias()){
        outStream << i.getNomeCategoria() << endl;
    }

    outStream.close();

}

void BuyNowUI::escreverProdutos() {

    ofstream outStream;
    outStream.open("Produtos.txt");
    for(auto i: bn.getProdutos()){
        outStream << i->getNomeProduto() << endl;
        outStream << i->getCategoria().getNomeCategoria() << endl;
        outStream << i->getId() << endl;
        outStream << i->getValor() << endl;
    }

    outStream.close();

}

void BuyNowUI::escreverClientes() {

    ofstream outStream;
    outStream.open("Clientes.txt");
    for(auto i: bn.getClientes()){
        ClienteRegistado *cr = dynamic_cast<ClienteRegistado*>(i);
        if(cr!=NULL){
            outStream << cr->getNome() << endl;
            outStream << cr->getNumContribuinte() << endl;
            outStream << cr->getEmail() << endl;
        }
    }

    outStream.close();

}

void BuyNowUI::escreverLojasFisicas() {

    ofstream outStream;
    outStream.open("NomesFisicas.txt");
    for(auto i: bn.getLojasFisicas()){
        outStream << i.getLocalidade() << endl;
    }

    outStream.close();

}

void BuyNowUI::escreverProdutosLojaFisica() {

    ofstream outStream;
    outStream.open("Fisica.txt");
    for(auto i: bn.getLojasFisicas()){
        for (auto j : bn.getProdutos()){
            if (bn.getLojaFisica(i.getLocalidade()).getStockFisico(j) != 0) {
                outStream << i.getLocalidade() << endl;
                outStream << j->getId() << endl;
                outStream << i.getStockFisico(j) << endl;
            }
        }
    }

    outStream.close();
}

/**
 * Escreve a informaçao da Loja Online no ficheiro Online.txt
 * escreve na forma id\n quantidade \n id \n quantidade.....
 */
void BuyNowUI::escreverLojaOnline() {
    ofstream out;
    out.open("Online.txt");
    out << bn.getStockMin() << endl;
    out << bn.getStockOk() << endl;
    for (auto i : bn.getProdutos()){    //percorrer produtos e ver se algum tem stock na Online
        if (bn.getLojaOnline().getStockOnline(i) != 0){
            out << i->getId() << endl;
            out << bn.getLojaOnline().getStockOnline(i) << endl;
        }
    }
    out.close();
}

/**
 * Escreve a Informacao das Mensagnes no ficheiro Mensagens.txt
 * escreve na forma NumContribuinte Cliente\n Mensagem \n 0(nao respondida) ou 1(respondida)
 */
void BuyNowUI::escreverMensagens() {
    ofstream out;
    out.open("Mensagens.txt");
    //cout << "SIZE:" << bn.getMensagens().size() << endl;
    for (auto i : bn.getMensagens()){
        out << i.getCliente().getNumContribuinte() << endl;
        out << i.getMensagem() << endl;
        if (i.getRespondida()){
            out << 1 << endl;
        }
        else
            out << 0 << endl;
    }
}

/**
 * Le as mensagens existentes no ficheiro "Mensagens.txt"
 */
void BuyNowUI::lerMensagens() {
    ifstream fin;
    string line;
    fin.open("Mensagens.txt");

    if(!fin.is_open()){
        cerr << "Ficheiro das Mensagens nao encontrado\n";
        exit(1);
    }

    getline(fin, line);
    while(!fin.eof()){
        int numContribuinte;
        string mensagem;
        bool respondida;

        stringstream getNumContr(line);
        getNumContr >> numContribuinte;

        getline(fin, mensagem);

        getline(fin, line);
        if (line == "0"){
            respondida = false;
        }else respondida = true;

        Cliente cliente;
        for (auto i : bn.getClientes()){
            if (i->getNumContribuinte() == numContribuinte){
                cliente = *i;
                break;
            }
        }

        Mensagem msg(mensagem, cliente, respondida);
        bn.addMensagem(msg);

        getline(fin, line);
    }
}

void BuyNowUI::lerCarrinhas() {

    ifstream fin;
    string line;
    int id,ocupacao,ocupacaoMaxima;
    double preco;

    fin.open("Carrinhas.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das carrinhas nao encontrado\n";
        exit(1);
    }

    getline(fin,line);

    while(!fin.eof()){

        istringstream format3line(line);
        format3line >> id;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> ocupacao;

        getline(fin,line);
        istringstream format5line(line);
        format5line >> ocupacaoMaxima;

        Carrinha *carr=new Carrinha (id,ocupacao,ocupacaoMaxima);
        bn.adicionarCarrinha(*carr);

        getline(fin,line);
    }

}

void BuyNowUI::escreverCarrinhas() {

    ofstream outStream;
    outStream.open("Carrinhas.txt");

    priority_queue<Carrinha> pqB = bn.queueAtual();

    while(!pqB.empty()){
        Carrinha carr = pqB.top();
        pqB.pop();
        outStream << carr.getID() << endl;
        outStream << carr.getOcupacao() << endl;
        outStream << carr.getOcupacaoMaxima() << endl;
    }

    outStream.close();

}