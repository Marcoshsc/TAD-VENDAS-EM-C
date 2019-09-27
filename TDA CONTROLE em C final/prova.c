#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova.h"

void produtoMaisVendido(TListaProduto moduloProduto, TListaVendas moduloVendas)
{
    if(moduloVendas.numeroCadastrados == 0) {
        printf("Não existem vendas cadastradas.\n");
        return;
    }
    int maior;
    int codigoMaior;

    for(int i = 0; i < moduloVendas.numeroCadastrados; i++) {
        int qtdVendida = moduloVendas.vendasExecutadas[i].quantidade;
        for(int j = i + 1; j < moduloVendas.numeroCadastrados; j++) {
            if(moduloVendas.vendasExecutadas[j].codigoProduto ==
               moduloVendas.vendasExecutadas[i].codigoProduto) {
                qtdVendida += moduloVendas.vendasExecutadas[i].quantidade;
            }
        }
        if(i == 0) {
            maior = qtdVendida;
            codigoMaior = moduloVendas.vendasExecutadas[i].codigoProduto;
        }
        else {
            if(maior < qtdVendida) {
                maior = qtdVendida;
                codigoMaior = moduloVendas.vendasExecutadas[i].codigoProduto;
            }
        }
    }
    printf("IMPRIMINDO PRODUTO MAIS VENDIDO:\n");
    TProduto aux;
    aux.codigo = codigoMaior;
    relatorioProduto(moduloProduto.produtosCadastrados[PesquisarProduto(moduloProduto, aux)]);
}

void totalAVista(TListaVendas moduloVendas)
{
    if(!moduloVendas.numeroCadastrados) {
        printf("Não há vendas cadastradas.\n");
        return;
    }
    int qtdVendas = 0;
    float valorVendas = 0;
    for(int i = 0; i < moduloVendas.numeroCadastrados; i++) {
        if(!moduloVendas.vendasExecutadas[i].formaPagamento) {
            valorVendas += moduloVendas.vendasExecutadas[i].valorTotal;
            qtdVendas++;
        }
    }
    printf("Foram executadas um total de %d vendas, totalizando R$%.2f.\n", qtdVendas, valorVendas);
}

/**
* Como não estava mais em prova, eu coloquei aqui uma cercada pra não deixar um mesmo código repetir duas vezes,
* e também funcionar o processo inverso. Ex: id 1 e 2, respectivamente, funcionam igual os ids 2 e 1, respectivamente.
*/
void produtosEmComum(TCliente cliente1, TCliente cliente2, TListaVendas moduloVendas)
{
    if(!moduloVendas.numeroCadastrados) {
        printf("Não há vendas cadastradas.\n");
        return;
    }
    int codigosImpressos[moduloVendas.numeroCadastrados];
    int qtdImpressos = 0;
    printf("Códigos dos produtos comprados em comum: ");
    for(int i = 0; i < moduloVendas.numeroCadastrados; i++) {
        if(!strcmp(cliente1.id, moduloVendas.vendasExecutadas[i].idCliente)) {
            for(int j = 0; j < moduloVendas.numeroCadastrados; j++) {
                if(!strcmp(moduloVendas.vendasExecutadas[j].idCliente, cliente2.id) && moduloVendas.vendasExecutadas[j].codigoProduto ==
                   moduloVendas.vendasExecutadas[i].codigoProduto) {
                        int contains = 0;
                        for(int k = 0; k < qtdImpressos; k++) {
                            if(codigosImpressos[k] == moduloVendas.vendasExecutadas[i].codigoProduto) {
                                contains = 1;
                            }
                        }
                        if(!contains) {
                            printf("%d ", moduloVendas.vendasExecutadas[i].codigoProduto);
                            codigosImpressos[qtdImpressos] = moduloVendas.vendasExecutadas[i].codigoProduto;
                            qtdImpressos++;
                        }
                   }
            }
        }
    }
    if(!qtdImpressos)
        printf("Nenhum produto em comum.\n");
    printf("\n");
}

void notaFiscal(TData dataNota, TCliente cliente, TListaVendas moduloVendas)
{
    printf("-------------- IMPRIMINDO NOTA FISCAL DIA %d/%d/%d CLIENTE CPF %s --------------\n\n", dataNota.dia, dataNota.mes,
           dataNota.ano, cliente.id);
    float valorTotal = 0;
    printf("COMPRAS EXECUTADAS:\n");
    for(int i = 0; i < moduloVendas.numeroCadastrados; i++) {
        TVendas vendaAtual = moduloVendas.vendasExecutadas[i];
        if(!(strcmp(vendaAtual.idCliente, cliente.id)) && (vendaAtual.dataRealizacao.dia == dataNota.dia) &&
           (vendaAtual.dataRealizacao.mes == dataNota.mes) && (vendaAtual.dataRealizacao.ano == dataNota.ano)) {
                valorTotal += vendaAtual.valorTotal;
                relatorioVenda(vendaAtual);
        }
    }
    printf("\nValor total da Nota: R$%.2f\n", valorTotal);
}
