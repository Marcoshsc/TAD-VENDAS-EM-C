#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "produto.h"
#define TAM 50

typedef struct vendas_est
{
    TData dataRealizacao;
    TData prazoPagamento;
    char idCliente[TAM];
    int codigoProduto;
    int formaPagamento;
    int quantidade;
    float valorTotal;

} TVendas;

typedef struct listaVendas
{

    int numeroCadastrados;
    TVendas vendasExecutadas[TAM];

} TListaVendas;

void InsereVenda(TListaVendas* listaVendas, TVendas venda, TListaProduto* listaProduto, TListaClientes listaClientes);

void relatorioVenda(TVendas venda);

void lerVenda(TVendas* venda);

void InicializaModuloVenda(TListaVendas* listaVendas);

int PesquisarVenda(TListaVendas listaVendas, TVendas venda);

void AlterarVenda(TListaVendas* listaVendas, TVendas venda, TListaProduto* listaProduto, TListaClientes listaClientes);

void imprimeTodasAsVendas(TListaVendas listaVendas);

void ExcluirVenda(TListaVendas* listaVendas, TVendas venda);

#endif // VENDAS_H_INCLUDED
