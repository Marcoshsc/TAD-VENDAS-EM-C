#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "vendas.h"
#define TAM 50


/**
 * PARAMETROS:
 * - TListaVendas* modulo3: modulo de vendas ja inicializado.
 * - TVendas venda1: venda com todos os campos preenchidos.
 * - TListaProduto* modulo1: modulo de produtos ja inicializado.
 * - TListaClientes modulo2: modulo de clientes ja inicializado.
 * FUNCIONAMENTO:
 * Verifica se o cliente e o produto cadastrados na venda existem;
 * Em caso positivo, verifica se o produto tem estoque suficiente para completar a compra;
 * Em caso positivo, cadastra o preço final da compra na venda, e a insere dentro do modulo de vendas.
*/
void InsereVenda(TListaVendas* modulo3, TVendas venda1, TListaProduto* modulo1, TListaClientes modulo2)
{
    TProduto produtoAuxiliar;
    TCliente clienteAuxiliar;
    int indiceProduto, indiceCliente;
    produtoAuxiliar.codigo = venda1.codigoProduto;
    strcpy(clienteAuxiliar.id, venda1.idCliente);
    indiceProduto = PesquisarProduto(*modulo1, produtoAuxiliar);
    indiceCliente = PesquisarCliente(modulo2, clienteAuxiliar);
    if(indiceProduto != -1 && indiceCliente != -1) {
        if(modulo1->produtosCadastrados[indiceProduto].quantidadeEmEstoque >= venda1.quantidade) {
            venda1.valorTotal = (float)(venda1.quantidade * modulo1->produtosCadastrados[indiceProduto].precoUnitario);
            modulo1->produtosCadastrados[indiceProduto].quantidadeEmEstoque -= venda1.quantidade;
            if(modulo3->numeroCadastrados < TAM) {
                modulo3->vendasExecutadas[modulo3->numeroCadastrados] = venda1;
                modulo3->numeroCadastrados++;
                printf("Venda cadastrada com sucesso.\n");
            }
            else {
                printf("Nao foi possivel cadastrar a venda.\n");
            }
        }
        else {
        printf("Estoque insuficiente para a conclusao da venda.\n");
        }
    }
    else {
       printf("Produto ou Cliente nao encontrados.\n");
    }
}

/**
 * PARAMETROS:
 * - TVendas venda: venda com todos os campos preenchidos.
 * FUNCIONAMENTO:
 * Imprime todos os campos da venda.
*/
void relatorioVenda(TVendas venda)
{
    if(venda.prazoPagamento.dia != -1) {
        printf("\nCodigo Produto: %d\nQuantidade: %d\nComprador(CPF/CNPJ): %s\nData de realizacao: %d/%d/%d\nVencimento: %d/%d/%d\nValor Total: %.2f\n",
            venda.codigoProduto, venda.quantidade, venda.idCliente, venda.dataRealizacao.dia,
            venda.dataRealizacao.mes, venda.dataRealizacao.ano, venda.prazoPagamento.dia, venda.prazoPagamento.mes,
            venda.prazoPagamento.ano, venda.valorTotal);
    }
    else {
        printf("\nCodigo Produto: %d\nQuantidade: %d\nComprador(CPF/CNPJ): %s\nData de realizacao: %d/%d/%d\nVencimento: Venda a vista\nValor Total: %.2f\n",
            venda.codigoProduto, venda.quantidade, venda.idCliente, venda.dataRealizacao.dia,
            venda.dataRealizacao.mes, venda.dataRealizacao.ano, venda.valorTotal);
    }
}

/**
 * PARAMETROS:
 * - TVendas* venda: venda nao necessariamente com os campos preenchidos.
 * FUNCIONAMENTO:
 * Faz a leitura de todos os campos da venda recebida como parâmetro.
*/
void lerVenda(TVendas* venda)
{
    printf("Digite o codigo do produto: ");
    fflush(stdin);
    scanf("%d", &venda->codigoProduto);
    printf("Digite a quantidade a ser comprada: ");
    fflush(stdin);
    scanf("%d", &venda->quantidade);
    printf("ID Comprador: ");
    fflush(stdin);
    fgets(venda->idCliente, TAM, stdin);
    conserta(venda->idCliente);
    printf("Data de realizacao da compra (dd/MM/yyyy): ");
    fflush(stdin);
    scanf("%d%d%d", &venda->dataRealizacao.dia, &venda->dataRealizacao.mes, &venda->dataRealizacao.ano);
    printf("Modo de pagamento: (0)A vista (1)A Prazo : ");
    fflush(stdin);
    scanf("%d", &venda->formaPagamento);
    if(venda->formaPagamento) {
        printf("Data de vencimento (dd/MM/yyyy) : ");
        fflush(stdin);
        scanf("%d%d%d", &venda->prazoPagamento.dia, &venda->prazoPagamento.mes, &venda->prazoPagamento.ano);
    }
    else {
        venda->prazoPagamento.dia = -1;
        venda->prazoPagamento.mes = -1;
        venda->prazoPagamento.ano = -1;
    }
}

/**
 * PARAMETROS:
 * - TListaVendas* listaVendas: modulo de vendas nao inicializado.
 * FUNCIONAMENTO:
 * - Atribui valor 0 ao campo numeroCadastrados do modulo de vendas recebido.
*/
void InicializaModuloVenda(TListaVendas* listaVendas)
{
    listaVendas->numeroCadastrados = 0;
}

/**
 * PARAMETROS:
 * - TListaVendas listaVendas: modulo de vendas ja inicializado.
 * - TVendas venda: venda com os campos codigoProduto, idCliente e dataRealizacao preenchidos.
 * FUNCIONAMENTO:
 * - Varre o modulo procurando pela venda recebida como parametro;
 * - Caso encontrada, retorna seu indice;
 * - Caso contrario, retorna -1.
*/
int PesquisarVenda(TListaVendas listaVendas, TVendas venda)
{
    for(int i = 0; i < listaVendas.numeroCadastrados; i++) {
        if(venda.codigoProduto == listaVendas.vendasExecutadas[i].codigoProduto &&
           (!strcmp(venda.idCliente, listaVendas.vendasExecutadas[i].idCliente)) &&
           venda.dataRealizacao.dia == listaVendas.vendasExecutadas[i].dataRealizacao.dia &&
           venda.dataRealizacao.mes == listaVendas.vendasExecutadas[i].dataRealizacao.mes &&
           venda.dataRealizacao.ano == listaVendas.vendasExecutadas[i].dataRealizacao.ano) {
                return i;
           }
    }
    return -1;
}

/**
 * PARAMETROS:
 * - TListaVendas* modulo3: modulo de vendas ja inicializado.
 * - TVendas venda: venda com os campos codigoProduto, idCliente e dataRealizacao preenchidos.
 * - TListaProduto* modulo1: modulo de produtos ja inicializado.
 * - TListaClientes modulo2: modulo de clientes ja inicializado.
 * FUNCIONAMENTO:
 * - Verifica se a venda recebida existe, via funcao PesquisarVenda;
 * - Em caso positivo, faz a releitura da venda via funcao lerVenda;
 * - Apos a leitura, caos seja confirmado que o cliente recadastrado existe, existem as opcoes:
 * - CASO 1: codigo do produto é igual ao da venda pre-editada
 *      VERTENTE 1: novo estoque cadastrado é maior do que o anterior.
 *           Nesse caso, verifica-se a disponibilidade extra de estoque do produto;
 *           Em caso positivo, confirma a alteração da venda e decresce o estoque do produto;
 *           Em caso negativo, volta a venda ao seu estado original.
 *       VERTENTE 2: novo estoque cadastrado é menor do que o anterior.
 *          Nesse caso, confirma a alteração da venda e acrescenta o estoque que sobrou ao produto;
 * - CASO 2: codigo do produto é diferente ao da venda pre-editada
 *      VERTENTE 1: produto da venda pre-editada ja foi excluido
 *          Nesse caso, verifica-se o estoque do novo produto cadastrado e, caso suficiente, confirma
 *          alteração da venda e decresce do estoque do produto a quantidade comprada;
 *      VERTENTE 2: produto da venda pre-editada ainda existe
 *          Nesse caso, verifica-se o estoque do novo produto cadastrado e, caso suficiente, confirma
 *          alteração da venda, decresce do estoque do produto atual a quantidade comprada, e acrescenta
 *          ao produto anterior a quantidade anterior da venda.
*/
void AlterarVenda(TListaVendas* listaVendas, TVendas venda, TListaProduto* listaProduto, TListaClientes listaClientes)
{
    int i = PesquisarVenda(*listaVendas, venda);
    if(i == -1) {
        printf("\nVenda nao encontrada.\n");
    }
    else {
        printf("\nVenda encontrada. Alterando venda:\n");
        TVendas vendaAnterior = listaVendas->vendasExecutadas[i];
        lerVenda(&listaVendas->vendasExecutadas[i]);
        TCliente clientePrevio;
        strcpy(clientePrevio.id, listaVendas->vendasExecutadas[i].idCliente);
        if(PesquisarCliente(listaClientes, clientePrevio) == -1) {
            listaVendas->vendasExecutadas[i] = vendaAnterior;
            printf("\nCliente nao encontrado.\nNao foi possivel Alterar a venda.\n");
            return;
        }
        if(vendaAnterior.codigoProduto == listaVendas->vendasExecutadas[i].codigoProduto) {
            TProduto produtoAux;
            produtoAux.codigo = vendaAnterior.codigoProduto;
            if(PesquisarProduto(*listaProduto, produtoAux) == -1) {
                listaVendas->vendasExecutadas[i] = vendaAnterior;
                printf("Produto alterado nao existe mais.\nNao foi possivel alterar a venda.\n");
                return;
            }
            TProduto* produtoDaVenda = &listaProduto->produtosCadastrados[PesquisarProduto(*listaProduto, produtoAux)];
            if(vendaAnterior.quantidade < listaVendas->vendasExecutadas[i].quantidade) {
                int quantidadeMudada = listaVendas->vendasExecutadas[i].quantidade - vendaAnterior.quantidade;
                if(produtoDaVenda->quantidadeEmEstoque >= quantidadeMudada) {
                    produtoDaVenda->quantidadeEmEstoque -= quantidadeMudada;
                    printf("\nVenda alterada com sucesso.\n");
                }
                else {
                    listaVendas->vendasExecutadas[i] = vendaAnterior;
                    printf("\nEstoque Insuficiente.\nNao foi possivel alterar a venda.\n");
                    return;
                }
            }
            else {
                if(vendaAnterior.quantidade > listaVendas->vendasExecutadas[i].quantidade) {
                    produtoDaVenda->quantidadeEmEstoque += vendaAnterior.quantidade - listaVendas->vendasExecutadas[i].quantidade;
                    printf("\nVenda alterada com sucesso.\n");
                }
            }
        }
        else {
            TProduto produtoPrevio;
            produtoPrevio.codigo = listaVendas->vendasExecutadas[i].codigoProduto;
            int codigoProduto = PesquisarProduto(*listaProduto, produtoPrevio);
            if(codigoProduto == -1) {
                listaVendas->vendasExecutadas[i] = vendaAnterior;
                printf("\nProduto nao encontrado.\nNao foi possivel alterar a venda.\n");
                return;
            }
            else {
                TProduto* produtoEscolhido = &listaProduto->produtosCadastrados[codigoProduto];
                if(produtoEscolhido->quantidadeEmEstoque >= listaVendas->vendasExecutadas[i].quantidade) {
                    produtoEscolhido->quantidadeEmEstoque -= listaVendas->vendasExecutadas[i].quantidade;
                    produtoPrevio.codigo = vendaAnterior.codigoProduto;
                    if(!(PesquisarProduto(*listaProduto, produtoPrevio) == -1)) {
                        TProduto* produtoAnterior = &listaProduto->produtosCadastrados[PesquisarProduto(*listaProduto, produtoPrevio)];
                        produtoAnterior->quantidadeEmEstoque += vendaAnterior.quantidade;
                    }
                    printf("\nVenda alterada com sucesso.\n");
                }
                else {
                    listaVendas->vendasExecutadas[i] = vendaAnterior;
                    printf("\nEstoque Insuficiente.\nNao foi possivel Alterar a venda.\n");
                    return;
                }
            }
        }
    }
}

/**
 * PARAMETROS:
 * - TListaVendas listaVendas: modulo de vendas ja inicializado.
 * FUNCIONAMENTO:
 * - Imprime relatorio de cada venda cadastrada via funcao relatorioVenda.
*/
void imprimeTodasAsVendas(TListaVendas listaVendas)
{
    if(!listaVendas.numeroCadastrados)
        printf("Nao existem vendas cadastradas.");
    else {
        printf("IMPRIMINDO VENDAS:\n");
        for(int i = 0; i < listaVendas.numeroCadastrados; i++) {
            relatorioVenda(listaVendas.vendasExecutadas[i]);
        }
    }
}

/**
 * PARAMETROS:
 * - TListaVendas* listaVendas: modulo de vendas ja inicializado.
 * - TVendas venda: venda com os campos codigoProduto, idCliente e dataRealizacao preenchidos.
 * FUNCIONAMENTO:
 * - Procura pela venda dentro do modulo, via funcao PesquisarVenda;
 * - Caso encontrado, remove a venda do modulo.
*/
void ExcluirVenda(TListaVendas* listaVendas, TVendas venda)
{
    int i = PesquisarVenda(*listaVendas, venda);
    if(i == -1) {
        printf("Venda nao encontrada.\n");
    }
    else {
        for(int j = i; j < listaVendas->numeroCadastrados - 1; j++) {
            listaVendas->vendasExecutadas[j] = listaVendas->vendasExecutadas[j+1];
        }
        listaVendas->numeroCadastrados--;
        printf("Venda excluida com sucesso.\n");
    }
}
