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



    }

    if(result==2){

        cout << "efetuacao de pagamento" << endl;

    }

    if(result==3){

        

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

    fin.open("C:\\Users\\Sara\\Desktop\\AEDATreino\\Categorias.txt");
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

    fin.open("C:\\Users\\Sara\\Desktop\\AEDATreino\\Produtos.txt");
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






