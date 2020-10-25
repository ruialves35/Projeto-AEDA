#ifndef AEDA_LOJAFISICA_H
#define AEDA_LOJAFISICA_H


class LojaFisica{
private:
    vector<Produto*> produtos;
public:
    void addProduto(Produto &produto);
    vector<Produto*> getProdutos() const;
}


#endif //AEDA_LOJAFISICA_H
