#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "produto.h"
#define TAM 50

/**
 * PARAMETROS:
 * - TListaProduto* listaProduto: endereco de um modulo de produtos ja inicializado;
 * - TProduto produto: produto com todos os campos preenchidos.
 * FUNCIONAMENTO:
 * - Insere o produto recebido como parametro no modulo, também recebido como parametro.
*/
void InsereProduto(TListaProduto* listaProduto, TProduto produto)
{
    if(listaProduto->numeroCadastrados < TAM) {
        listaProduto->produtosCadastrados[listaProduto->numeroCadastrados] = produto;
        listaProduto->numeroCadastrados++;
        printf("Produto cadastrado com sucesso.\n");
    }
    else {
        printf("Nao foi possivel cadastrar o produto.\n");
    }
}

/**
 * PARAMETROS:
 * - TProduto produto: produto com todos os campos preenchidos.
 * FUNCIONAMENTO:
 * - Imprime as informacoes contidas dentro do produto recebido.
*/
void relatorioProduto(TProduto produto)
{
    printf("Codigo: %d\nNome:%s\nDescricao: %s\nData: %d/%d/%d\nLote: %s\nPreco: %.2f\nEstoque: %d\n",
        produto.codigo, produto.nome, produto.descricao, produto.dataFabricacao.dia,
        produto.dataFabricacao.mes, produto.dataFabricacao.ano, produto.numeroLote,
        produto.precoUnitario, produto.quantidadeEmEstoque);
}

/**
 * PARAMETROS:
 * - TProduto* produto: endereco de um produto não necessariamente com campos preenchidos.
 * FUNCIONAMENTO:
 * - Faz a leitura de todos os campos do produto recebido.
*/
void lerProduto(TProduto* produto)
{
    char resposta;
    printf("Digite o codigo do produto: ");
    scanf("%d", &produto->codigo);
    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(produto->nome, TAM, stdin);
    conserta(produto->nome);
    printf("Digite a descricao do produto: ");
    fflush(stdin);
    fgets(produto->descricao, TAM, stdin);
    conserta(produto->descricao);
    printf("Data de fabricacao do produto (dd/MM/yyyy): ");
    fflush(stdin);
    scanf("%d%d%d", &produto->dataFabricacao.dia, &produto->dataFabricacao.mes, &produto->dataFabricacao.ano);
    printf("Lote do produto: ");
    fflush(stdin);
    fgets(produto->numeroLote, TAM, stdin);
    conserta(produto->numeroLote);
    printf("Preco unitario do produto: ");
    fflush(stdin);
    scanf("%f", &produto->precoUnitario);
    printf("Deseja cadastrar algum estoque para o produto? 's' para sim ");
    fflush(stdin);
    scanf("%c", &resposta);
    if(resposta == 's') {
        do {
        printf("Estoque inicial do produto: ");
        fflush(stdin);
        scanf("%d", &produto->quantidadeEmEstoque);
        if(produto->quantidadeEmEstoque < 0)
            printf("Digite uma quantidade valida de estoque.\n");
        } while(produto->quantidadeEmEstoque < 0);
    }
    else {
        produto->quantidadeEmEstoque = 0;
    }
}

/**
 * PARAMETROS:
 * - TListaProduto listaProduto: modulo de produtos ja inicializado;
 * - TProduto produto: produto com o codigo preenchido.
 * FUNCIONAMENTO:
 * - Varre o modulo em busca do produto recebido;
 * - Caso encontrado, retorna seu indice;
 * - Caso não encontrado, retorna -1.
*/
int PesquisarProduto(TListaProduto listaProduto, TProduto produto)
{
    if(listaProduto.produtosCadastrados == 0) {
        return -1;
    }
    for(int i = 0; i < listaProduto.numeroCadastrados; i++) {
        if(listaProduto.produtosCadastrados[i].codigo == produto.codigo) {
            return i;
        }
    }
    return -1;
}

/**
 * PARAMETROS:
 * - TListaProduto* listaProduto: endereco de um modulo de produtos não inicializado;
 * FUNCIONAMENTO:
 * - Insere o produto recebido como parametro no modulo, também recebido como parametro.
*/
void InicializaModuloProduto(TListaProduto* listaProduto)
{
    listaProduto->numeroCadastrados = 0;
}

/**
 * PARAMETROS:
 * - TListaProduto listaProduto: modulo de produtos ja inicializado.
 * FUNCIONAMENTO:
 * - Imprime relatorio de todos os produtos dentro do modulo, via funcao relatorioProduto.
*/
void imprimeTodosOsProdutos(TListaProduto listaProduto)
{
    if(listaProduto.numeroCadastrados == 0)
        printf("Nao ha produtos cadastrados.\n");
    else {
        printf("IMPRIMINDO TODOS OS PRODUTOS\n");
        for(int i = 0; i < listaProduto.numeroCadastrados; i++) {
            relatorioProduto(listaProduto.produtosCadastrados[i]);
            printf("\n");
        }
    }
}

/**
 * PARAMETROS:
 * - TListaProduto* listaProduto: endereco de um modulo de produtos ja inicializado;
 * - TProduto produto: produto com o codigo preenchido.
 * FUNCIONAMENTO:
 * - Pesquisa pelo produto no modulo, via funcao PesquisarProduto;
 * - Caso encontrado, re-leitura dos dados do mesmo, via funcao lerProduto;
*/
void AlterarProduto(TProduto produto, TListaProduto* listaProduto)
{
    int i = PesquisarProduto(*listaProduto, produto);
    if(i != -1) {
        printf("Produto Encontrado!\nAlteracao de produto:\n");
        lerProduto(&listaProduto->produtosCadastrados[i]);
        printf("Alteracao efetuada com sucesso.\n");
    }
    else
        printf("Produto nao encontrado.\n");
}

void ExcluirProduto(TListaProduto* listaProduto, TProduto produto)
{
    int i = PesquisarProduto(*listaProduto, produto);
    if(i == -1) {
        printf("Produto nao encontrado.\n");
    }
    else {
        for(int j = i; j < listaProduto->numeroCadastrados; j++) {
            listaProduto->produtosCadastrados[j] = listaProduto->produtosCadastrados[j+1];
        }
        listaProduto->numeroCadastrados--;
        printf("Produto excluido com sucesso.\n");
    }
}
