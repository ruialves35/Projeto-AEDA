#include "BuyNowUI.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

void Administrador();

void Cliente();

using namespace std;

BuyNowUI::BuyNowUI() {
    lerCategorias();
    lerProdutos();
    lerProdutosLojaOnline();
    lerProdutosLojaFisica();
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
        Administrador();
    }

    if(result==2){
        Cliente();
    }

}

void BuyNowUI::Cliente() {

    //Pede nome ao cliente
    cout << "Por favor insira o seu nome" << endl;
    string nome;
    getline(cin,nome);

    //Pede contribuinte ao cliente
    cout << "Por favor insira o seu numero de contribuinte" << endl;
    string contribuinte;
    getline(cin,contribuinte);
    stringstream streamContribuinte(contribuinte);
    int contribuinteNumero=0;
    streamContribuinte >> contribuinteNumero;


    bool clienteRegistado=false;
    Cliente cliente= Cliente(nome,contribuinte);
    ClienteRegistado clienteR =ClienteRegistado(nome,contribuinte,"");

    vector <Produto> produtos = bn.getProdutos();
    vector<Produto*> carrinho = {};
    //pede para o cliente escolher a opcao
    string input;
    bool validInput = true;
    int result;
    do {
        validInput = true;
        cout << "Por favor insira 1 se desejar adicionar produtos ao carrinho, 2 se deseja efetuar o pagamento e 3 se desejar se registar no sistema" << endl;
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
        else if (result < 1 || result > 3) {
            cout << "O numero introduzido nao e correto" << endl;
            validInput = false;
        }
    } while (!validInput);


    if(result==1){

        bool exit =false;
        while(!exit) {
            bool validInput2 = false;
            cout << "Por favor introduza o número da categoria" << endl;
            vector <Categoria> categorias = bn.getCategorias();
            for (int i = 0; i < categorias.size(); i++) {
                cout << i << " - " << categorias[i].getNomeCategoria() << endl;
            }
            cout << endl <<categorias.size() << " - terminar compra\n";
            while (!validInput2) {
                getline(cin, input);
                istringstream checkinput2(input);
                if (cin.eof()) {
                    validInput2 = false;
                    cin.clear();
                    cout << "Por favor introduza um valor" << endl;

                } else if (!(checkinput2 >> result)) {        //is not a number or a number with letters/symbols.
                    cout << "Por favor introduza um valor" << endl;
                    validInput2 = false;
                } else if (result < 0 || result > categorias.size()) {
                    cout << "O numero introduzido nao e correto" << endl;
                    validInput2 = false;
                } else
                    validInput2 = true;
            }
            if(input==categorias.size()){
                exit=true;
                break;
            }
            string categoria = categorias[input];

            cout << "Por favor introduza o número do produto" << endl;
            for (int i = 0; i < produtos.size(); i++) {
                cout << produtos[i].getId() << " - " << produtos[i].getNomeProduto() << endl;
            }
            validInput2 = false;
            while (!validInput2) {
                getline(cin, input);
                istringstream checkinput2(input);
                if (cin.eof()) {
                    validInput2 = false;
                    cin.clear();
                    cout << "Por favor introduza um valor" << endl;

                } else if (!(checkinput2 >> result)) {        //is not a number or a number with letters/symbols.
                    cout << "Por favor introduza um valor" << endl;
                    validInput2 = false;
                } else if (result < 0 || result >= categorias.size()) {
                    cout << "O numero introduzido nao e correto" << endl;
                    validInput2 = false;
                } else
                    validInput2 = true;
            }
            int idProd;
            for (int i = 0; i < produtos.size(); i++) {
                if (produtos[i].getId() == input) {
                    idProd = i;
                    break;
                }

            }

            carrinho.push_back(&produtos[idProd]);

        }

    }

    if(result==2){
        int total = 0;
        for (auto i :carrinho){
            total+=i.getValor();
        }
        int pag;
        cout << "Como deseja efetuar o pagamento?" << endl;
        cout <<"1 - Mbway" << endl;
        cout <<"2 - Transferencia" << endl;
        cout <<"3 - Multibanco" << endl;
        cout << endl << "Total a pagar: "<<total <<endl;

        cout << "Escreva o numero da opcao com que deseja pagar"<< endl;
        bool validInput3=false;
        while (!validInput3) {
            getline(cin, input);
            istringstream checkinput2(input);
            if (cin.eof()) {
                validInput3 = false;
                cin.clear();
                cout << "Por favor introduza um valor" << endl;

            } else if (!(checkinput3 >> result)) {        //is not a number or a number with letters/symbols.
                cout << "Por favor introduza um valor" << endl;
                validInput3 = false;
            } else if (result < 0 || result > categorias.size()) {
                cout << "O numero introduzido nao e correto" << endl;
                validInput3 = false;
            } else
                validInput3 = true;
        }


        LojaOnline loja= bn.getLojaOnline();

        //********** VER ISTO`***********
        //verifica se o cliente esta registado ou nao e mete o apontador para o cliente na transacao (falta verificar como estao a ser guardados os clientes para o apontador ser o mesmo que esta no vetor da loja)
        //para resolver isso é só comparar o contribuinte com o do vetor de clientes (mas falta saber como estao a ser adicionados)
        //tratar do dinamic cast do cliente registado qnd é adicionado à transacao
        if(clienteRegistado)
            loja.addTransacao(new Transacao(new ClienteRegistado(clienteR), Date(), carrinho, new Pagamento(total)));
        else
            loja.addTransacao(new Transacao(new Client(cliente), Date(), carrinho, new Pagamento(total)));

        //seria melhor guardar a loja online como pointer para n ser preciso dar get e set para alterar!
        bn.setLojaOnline(loja);
    }

    if(result==3){

        //cliente registado ja criado em cima, falta so adicionar o email que tem que ser lido e adicionalo ao vetor
        

    }

}

void BuyNowUI::Administrador() {

    //pede para o cliente escolher a opcao
    string input;
    bool validInput = true;
    int result;
    do {
        validInput = true;
        cout << "Por favor insira 1 ver as estatisticas e 2 para ver o historico de transacoes" << endl;
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
    }

    if(result==2){
        bn.showTransacoes();
    }


}

void BuyNowUI::lerCategorias() {

    ifstream fin;
    string categoria,line;

    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Categorias.txt)");
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

    cout << "lidas as categorias" << endl;

    bn.showCategorias();

}

void BuyNowUI::lerProdutos() {

    ifstream fin;
    string stringProduto, stringCategoria, line;
    int codigo;
    double preco;

    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Produtos.txt)");
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

        //PRECISO DE UM GETCATEGORIA NA BUYNOW

        Categoria cat = bn.getCategoria(stringCategoria);

        Produto *prod = new Produto(stringProduto,codigo,preco,cat);
        bn.addProduto(prod);

    }

    cout << "lidos os produtos" << endl;

    bn.showProdutos();

}

void BuyNowUI::lerProdutosLojaOnline() {

    ifstream fin;
    string line;
    int codigo,quantidade;

    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Online.txt)");
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

        //PRECISO DE UM GETPRODUTO QUE ME RETORNE O PRODUTO DA BUYNOW COLOCANDO O CODIGO

        /*Produto prod;
        prod = bn.getProduto(codigo);
        bn.getLojaOnline().addProduto(*prod,quantidade);*/

    }

}

void BuyNowUI::lerProdutosLojaFisica() {

    //criar 3 lojas: porto, lisboa e braga
    string stringPorto = "porto";
    string stringLisboa = "lisboa";
    string stringBraga = "braga";
    LojaFisica lojaPorto(stringPorto);
    LojaFisica lojaLisboa(stringLisboa);
    LojaFisica lojaBraga(stringBraga);
    bn.addLojaFisica(lojaPorto);
    bn.addLojaFisica(lojaLisboa);
    bn.addLojaFisica(lojaBraga);

    //ler os produtos e adiciona-los as respetivas lojas
    ifstream fin;
    string line,localidadeLoja;
    int codigo,quantidade;

    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Fisica.txt)");
    if(!fin.is_open()){
        cerr << "Ficheiro dos produtos online nao encontrado\n";
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

        //PRECISO DE UM GETLOJAFISICA QUE ME DE A LOJA INTRODUZINDO A STRING DO NOME DA MESMA
        /*LojaFisica loja;
        loja = bn.getLojaFisica(localidadeLoja);

        Produto prod;
        prod = bn.getProduto(codigo);

        loja.addProduto(prod,quantidade);*/

    }


}






