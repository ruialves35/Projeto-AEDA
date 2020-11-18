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
    lerReposicoes();
    lerTransferencias();
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

/**
 * Setup of Administrador
 */
void BuyNowUI::Administrador() {
    //pede para o cliente escolher a opcao
    string input;
    bool validInput = true;
    bool endProgram = false;
    int result;
    while(!endProgram) {
        do {
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
            if (cin.eof()) {
                validInput = false;
                cin.clear();
                cout << endl << "Opção Inválida" << endl;
                Sleep(700);
                cout << string(50, '\n'); //Clear Screen
            } else if (!(checkinput >> result)) {        //is not a number or a number with letters/symbols.
                cout << endl << "Opção Inválida" << endl;
                Sleep(700);
                cout << string(50, '\n'); //Clear Screen
                validInput = false;
            } else if (result < 0 || result > 6) {
                cout << endl << "O numero introduzido nao e correto" << endl;
                Sleep(700);
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
                cout << "1: Ordenar por Valor" << endl;
                cout << "2: Ordenar por ID" << endl;
                cout << "3: Ordenar por Nome" << endl;
                cout << "4: Mostrar Produtos" << endl;
                cout << "5: Enter option" << endl;
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
            for (auto i : bn.getTransferencias()){
                cout << i->getInfo() << endl;
            }
        }

        else if (result == 4){   //reposicoes feitas a loja online
            for (auto i : bn.getReposicoes()){
                i.getInfo();
            }
        }

        else if (result == 5){   //Ver lojas fisicas da empresa
            for (auto i : bn.getLojasFisicas()){
                cout << i.getLocalidade() << endl;
            }
        }

        else if (result == 6){
            bn.showTransacoes();
        }
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

        //bn.getLojaOnline().addProduto(*bn.getProduto(codigo),quantidade);

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

void BuyNowUI::lerReposicoes() {

    ifstream fin;
    string line, stringLocalidade;
    int codigo, quantidade,dia,mes,ano;


    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Reposicoes.txt)");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> dia;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> mes;

        getline(fin,line);
        istringstream format3line(line);
        format2line >> ano;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> codigo;

        getline(fin,line);
        istringstream format5line(line);
        format5line >> quantidade;

        getline(fin,line);
        istringstream format6line(line);
        format6line >> stringLocalidade;

    }

}

void BuyNowUI::lerTransferencias() {

    ifstream fin;
    string line;
    int codigo, quantidade,dia,mes,ano;


    fin.open(R"(C:\Users\Sara\Desktop\AEDATreino\Reposicoes.txt)");
    if(!fin.is_open()){
        cerr << "Ficheiro das reposicoes nao encontrado\n";
        exit(1);
    }

    while(!fin.eof()){

        getline(fin,line);
        istringstream format1line(line);
        format1line >> dia;

        getline(fin,line);
        istringstream format2line(line);
        format2line >> mes;

        getline(fin,line);
        istringstream format3line(line);
        format2line >> ano;

        getline(fin,line);
        istringstream format4line(line);
        format4line >> codigo;

        getline(fin,line);
        istringstream format5line(line);
        format5line >> quantidade;

        /*Fornecedor f;
        Date d1(dia,mes,ano);
        Transferencia t1 = new Transferencia()
        bn.addTransferencia();*/

    }

}






