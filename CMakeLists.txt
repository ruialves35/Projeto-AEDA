cmake_minimum_required(VERSION 3.17)
project(Projeto)

set(CMAKE_CXX_STANDARD 11)

add_executable(Projeto main.cpp Date.cpp Date.h BuyNowUI.cpp BuyNowUI.h BuyNow.cpp BuyNow.h CartaoCredito.cpp CartaoCredito.h
        Categoria.cpp Categoria.h Cliente.cpp Cliente.h ClienteRegistado.cpp ClienteRegistado.h Fornecedor.cpp Fornecedor.h
        LojaOnline.cpp LojaOnline.h LojaFisica.cpp LojaFisica.h MbWay.cpp MbWay.h Multibanco.cpp Multibanco.h
        Produto.cpp Produto.h Transacao.cpp Transacao.h)

