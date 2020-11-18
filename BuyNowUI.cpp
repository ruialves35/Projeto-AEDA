#include "BuyNowUI.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

BuyNowUI::BuyNowUI() {
    Fornecedor f("Manel");
    bn.setFornecedor(f);
    lerCategorias();
    lerProdutos();
    lerClientes();
    lerLojasOnline();
    lerProdutosLojaOnline();
    lerProdutosLojaFisica();
    lerReposicoes();
    lerTransferencias();
    LerTransacoes();
    UI();
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

    while(!endClient) {
        vector<Produto*> carrinho;

        int result;
        bool validInput = true;
        do {
            validInput = true;
            cout << "0: Terminar Programa" << endl;
            cout << "1: Ver Produtos" << endl;
            cout << "2: Adicionar Produto ao Carrinho "<< endl;
            cout << "3: Efetuar Pagamento" << endl;
            cout << "4: Efetuar registo no sistema" << endl;
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

            } else if (result < 0 || result > 4) {
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
                    Sleep(7000);
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
                cout << "   Enter option: " << endl;
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
                cout << "Caso queira voltar para traz, introduza 0." << endl;
                cout << "Caso contrario, introduza o nome do produto. (Sensivel a Maiusculas, espacos e minusculas, certifique-se de que escreveu da forma correta)" << endl;
                cout << "Opcao: " << endl;
                getline(cin, input);
                if (input == "0") break;
                for (auto i : bn.getProdutos()) {
                    if (i->getNomeProduto() == input){
                        string quantInput;
                        int quantidade;
                        cout << "Introduza a Quantidade de" << i->getNomeProduto() << " que deseja adicionar: ";
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
            } while(!validOption);
        }

        else if (result == 3) { //efetuar pagamento
            string opcaoPagar;
            int opcao;
            bool validOptionPagar = false;
            while(!validOptionPagar) {
                cout << endl;
                cout << "0: Retroceder" << endl;
                cout << "1: Multibanco" << endl;
                cout << "2: MbWay " << endl;
                cout << "3: Cartao de Credito" << endl;
                cout << "   Introduza a opcao de pagamento: " << endl;
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
                            Cliente c(nome, contribuinteNumero);

                            validOptionPagar = true;
                            Multibanco multi(ref);

                            time_t theTime = time(NULL);
                            struct tm *aTime = localtime(&theTime);
                            int day = aTime->tm_mday;
                            int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                            int year = aTime->tm_year + 1900; // Year is # years since 1900
                            Date data(day, month, year);

                            Transacao *t = new Transacao(&c, data, carrinho, &multi);
                            bn.addTransacao(t);
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
                            Cliente c(nome, contribuinteNumero);
                            validOptionPagar = true;
                            MbWay mb(numTelemovel);

                            time_t theTime = time(NULL);
                            struct tm *aTime = localtime(&theTime);
                            int day = aTime->tm_mday;
                            int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
                            int year = aTime->tm_year + 1900; // Year is # years since 1900
                            Date data(day, month, year);

                            Transacao *t = new Transacao(&c, data, carrinho, &mb);
                            bn.addTransacao(t);
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
                            Cliente c(nome, contribuinteNumero);
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

                                CartaoCredito cc(numCartao, d1);
                                Transacao *t = new Transacao(&c, data, carrinho, &cc);
                                bn.addTransacao(t);
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
                cout << "Introduz o teu endereco de email (so a parte antes do arroba): ";
                getline(cin, email);
                bn.removeCliente(nome, contribuinteNumero);
                Cliente* c = new ClienteRegistado(nome, contribuinteNumero, email);
                bn.addCliente(c);
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
                Sleep(2000);
                cout << string(50, '\n'); //Clear Screen
            } else if (!(checkinput >> result)) {        //is not a number or a number with letters/symbols.
                cout << endl << "Opção Inválida" << endl;
                Sleep(2000);
                cout << string(50, '\n'); //Clear Screen
                validInput = false;
            } else if (result < 0 || result > 6) {
                cout << endl << "O numero introduzido nao e correto" << endl;
                Sleep(2000);
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
                    Sleep(700);
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
                    Sleep(700);
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

        else if (result == 6){
            bn.showTransacoes();
        }
    }
}

void BuyNowUI::lerCategorias() {

    ifstream fin;
    string categoria,line;

    fin.open("Categorias.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das categorias nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){
        getline(fin,line);
        istringstream format1line(line);
        format1line >> categoria;
        Categoria cat(categoria);
        bn.addCategoria(cat);
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

    while(!fin.eof()){


        getline(fin,line);
        istringstream format1line(line);
        format1line >> stringProduto;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> stringCategoria;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> codigo;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> preco;

        Categoria cat = bn.getCategoria(stringCategoria);

        Produto *prod = new Produto(stringProduto,codigo,preco,cat);
        bn.addProduto(prod);

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

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> codigo;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> quantidade;

        bn.addProdutoOnline(bn.getProduto(codigo),quantidade);

    }

}

void BuyNowUI::lerProdutosLojaFisica() {

    //ler os produtos e adiciona-los as respetivas lojas
    ifstream fin;
    string line,localidadeLoja;
    int codigo,quantidade;

    fin.open("Fisica.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro dos produtos fisica nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> localidadeLoja;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> codigo;

        getline(fin,line);
        istringstream format3line(line);
        format2line >> quantidade;

        Produto *prod;
        prod = bn.getProduto(codigo);

        bn.addProdutoLojaFisica(localidadeLoja,prod,quantidade);

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

    while(!fin.eof()){

        getline(fin,line);
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
        istringstream format4line(line);
        format4line >> stringLocalidade;

        LojaFisica l1;
        l1=bn.getLojaFisica(stringLocalidade);

        Produto *prod;
        prod = bn.getProduto(codigo);

        Reposicao rep(l1,prod,quantidade,d1);
        bn.addReposicao(rep);
    }

}

void BuyNowUI::lerTransferencias() {

    ifstream fin;
    string line;
    int codigo, quantidade,dia,mes,ano;
    char caracter;


    fin.open("Transferencias.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das transferencias nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> dia >> caracter >> mes >> caracter >> ano;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> codigo;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> quantidade;

        Fornecedor f = bn.getFornecedor();
        Produto *prod = bn.getProduto(codigo);
        Date d1(dia,mes,ano);
        Transferencia *t1 = new Transferencia(f,prod,quantidade,d1);
        bn.addTransferencia(t1);

    }

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

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> stringNome;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> numContribuinte;

        getline(fin,line);
        istringstream format3line(line);
        format2line >> stringEmail;

        Cliente *c1 = new ClienteRegistado(stringNome,numContribuinte,stringEmail);
        bn.addCliente(c1);

    }

}

void BuyNowUI::LerTransacoes() {

    ifstream fin;
    string line, stringNome,numCartao,multibanco,mbway,cartao;
    int diaA,diaB,mesA,mesB,anoA,anoB,contribuinte,stringTipoPagamento,numTelemovel,referencia,codigo,quantidade;
    char caracter;
    multibanco="multibanco";
    mbway="mbway";
    cartao="cartao de credito";


    fin.open("Transacoes.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> diaA >> caracter >> mesA >> caracter >> anoA;

        Date d1(diaA,mesA,anoA);

        getline(fin,line);
        istringstream format2line(line);
        format2line >> stringNome;

        getline(fin,line);
        istringstream format3line(line);
        format3line >> contribuinte;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> stringTipoPagamento;

        Transacao *tran = new Transacao();
        Cliente *c1 = bn.getCliente(stringNome,contribuinte);
        tran->setCliente(c1);
        tran->setDate(d1);

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
            istringstream format5line(line);
            format5line >> numCartao;

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

    }

}

void BuyNowUI::lerLojasOnline() {

    ifstream fin;
    string localidade,line;

    fin.open("NomesFisicas.txt");
    if(!fin.is_open()){
        cerr << "Ficheiro das lojas online (suas localizacoes) nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){
        getline(fin,line);
        istringstream format1line(line);
        format1line >> localidade;
        LojaFisica loja(localidade);
        bn.addLojaFisica(loja);
    }

}






