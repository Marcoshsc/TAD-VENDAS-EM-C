#ifndef PROVA_H_INCLUDED
#define PROVA_H_INCLUDED
#define TAM 50

#include "vendas.h"

typedef struct notaFiscal_est {

    char idCliente[TAM];
    TData dataNota;
    int codigoProdutos[TAM];
    int qtdProdutos;

} TNotaFiscal;

typedef struct moduloNotaFiscal_est {

    TNotaFiscal notasCadastradas[TAM];
    int numeroCadastrados;

} TModuloNotaFiscal;

void produtoMaisVendido(TListaProduto moduloProduto, TListaVendas moduloVendas);

void totalAVista(TListaVendas moduloVendas);

void produtosEmComum(TCliente cliente1, TCliente cliente2, TListaVendas moduloVendas);

void notaFiscal(TData dataNota, TCliente cliente, TListaVendas moduloVendas);

#endif // PROVA_H_INCLUDED
