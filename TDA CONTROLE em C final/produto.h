#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#define TAM 50

typedef struct produto_est
{

    int codigo;
    char nome[TAM];
    char descricao[TAM];
    TData dataFabricacao;
    char numeroLote[TAM];
    float precoUnitario;
    int quantidadeEmEstoque;

} TProduto;

typedef struct listaProduto
{

    int numeroCadastrados;
    TProduto produtosCadastrados[TAM];

} TListaProduto;

void InsereProduto(TListaProduto* listaProduto, TProduto produto);

void relatorioProduto(TProduto produto);

void lerProduto(TProduto* produto);

int PesquisarProduto(TListaProduto listaProduto, TProduto produto);

void InicializaModuloProduto(TListaProduto* listaProduto);

void imprimeTodosOsProdutos(TListaProduto listaProduto);

void AlterarProduto(TProduto produto, TListaProduto* listaProduto);

void ExcluirProduto(TListaProduto* listaProduto, TProduto produto);

#endif // PRODUTO_H_INCLUDED
