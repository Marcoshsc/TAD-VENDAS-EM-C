#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "prova.h"

/**
 * Exibe mensagem principal do programa, que direciona para cada um dos modulos.
*/
void MSG_MENU()
{
    system("cls");
    printf("\n>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<\n");
    printf("\n\t1. MODULO 1 - PRODUTO");
    printf("\n\t2. MODULO 2 - CLIENTE");
    printf("\n\t3. MODULO 3 - VENDA");
    printf("\n\t4. MODULO 4 - PROVA");
    printf("\n\t5. SAIR");
}

/**
 * Exibe mensagem para cada um dos modulos, recebendo o seu numero como parametro.
*/
void MSG_SUBMENU(int numero_modulo)
{
    system("cls");
    printf("\n>>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<", numero_modulo);
    printf("\n\n\t1. INSERIR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR TODOS");
    printf("\n\t6. SAIR");
}

/**
 * PARAMETROS:
 * - TListaProduto* modulo1: modulo de produtos ja inicializado.
 * - TProduto produto: produto sem campos preenchidos.
 * FUNCIONAMENTO:
 * - Executa as funcionalidades do modulo de produtos.
*/
void SubMenuModulo1(TListaProduto* modulo1, TProduto produto)
{

    int opcao;
    do {
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                system("cls");
                lerProduto(&produto);
                InsereProduto(modulo1, produto);
                system("PAUSE");
            } break;
            case 2: {
                system("cls");
                printf("Digite o codigo do produto buscado: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);
                int i = PesquisarProduto(*modulo1, produto);
                if(i == -1) {
                    printf("Produto nao encontrado.\n");
                    system("PAUSE");
                }
                else {
                    printf("Produto encontrado.\n\n");
                    relatorioProduto(modulo1->produtosCadastrados[i]);
                    system("PAUSE");
                }
            } break;
            case 3: {
                system("cls");
                printf("Digite o codigo do produto a ser alterado: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);
                AlterarProduto(produto, modulo1);
                system("PAUSE");
            } break;
            case 4: {
                system("cls");
                printf("Digite o codigo do produto a ser exclu�do: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);
                ExcluirProduto(modulo1, produto);
                system("PAUSE");
            } break;
            case 5: {
                system("cls");
                imprimeTodosOsProdutos(*modulo1);
                system("PAUSE");
            } break;
            case 6:
                break;
            default:
                printf("\n>>>> MSG: Digite uma opcao valida!!! <<<<\n");
                system("PAUSE");
        }
    } while(opcao != 6);


}

/**
 * PARAMETROS:
 * - TListaClientes* modulo2: modulo de clientes ja inicializado.
 * - TCliente cliente: cliente sem campos preenchidos.
 * FUNCIONAMENTO:
 * - Executa as funcionalidades do modulo de clientes.
*/
void SubMenuModulo2(TListaClientes* modulo2, TCliente cliente)
{
    int opcao;
    do {
        MSG_SUBMENU(2);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                system("cls");
                lerCliente(&cliente);
                InsereCliente(modulo2, cliente);
                system("PAUSE");
            } break;
            case 2: {
                system("cls");
                printf("Digite o CPF/CNPJ do cliente buscado: ");
                fflush(stdin);
                fgets(cliente.id, TAM, stdin);
                conserta(cliente.id);
                int i = PesquisarCliente(*modulo2, cliente);
                if(i == -1) {
                    printf("Cliente nao encontrado.\n");
                    system("PAUSE");
                }
                else {
                    printf("Cliente encontrado.\n\n");
                    relatorioCliente(modulo2->clientesCadastrados[i]);
                    system("PAUSE");
                }
            } break;
            case 3: {
                system("cls");
                printf("Digite o CPF/CNPJ do cliente a ser alterado: ");
                fflush(stdin);
                fgets(cliente.id, TAM, stdin);
                conserta(cliente.id);
                AlterarCliente(modulo2, cliente);
                system("PAUSE");
            } break;
            case 4: {
                system("cls");
                printf("Digite o CPF/CNPJ do cliente a ser excluido: ");
                fflush(stdin);
                fgets(cliente.id, TAM, stdin);
                conserta(cliente.id);
                ExcluirCliente(modulo2, cliente);
                system("PAUSE");
            } break;
            case 5: {
                system("cls");
                imprimeTodosOsClientes(*modulo2);
                system("PAUSE");
            } break;
            case 6:
                break;
            default:
                printf("\n>>>> MSG: Digite uma opcao valida!!! <<<<\n");
                system("PAUSE");
        }
    } while(opcao != 6);
}

/**
 * PARAMETROS:
 * - TListaVendas* modulo3: modulo de vendas ja inicializado.
 * - TVendas venda: venda sem campos preenchidos.
 * - TListaProduto* modulo1: modulo de produtos ja inicializado.
 * - TListaClientes modulo2: modulo de clientes ja inicializado.
 * FUNCIONAMENTO:
 * - Executa as funcionalidades do modulo de vendas.
*/
void SubMenuModulo3(TListaVendas* modulo3, TVendas venda, TListaProduto* modulo1, TListaClientes modulo2)
{
    int opcao;
    do {
        MSG_SUBMENU(3);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                system("cls");
                lerVenda(&venda);
                InsereVenda(modulo3, venda, modulo1, modulo2);
                system("PAUSE");
            } break;
            case 2: {
                system("cls");
                printf("PESQUISAR VENDA\n");
                printf("Digite o codigo do produto relacionado a venda buscada: ");
                fflush(stdin);
                scanf("%d", &venda.codigoProduto);
                printf("Digite o CPF/CNPJ do cliente relacionado a venda buscada: ");
                fflush(stdin);
                fgets(venda.idCliente, TAM, stdin);
                conserta(venda.idCliente);
                printf("Dia de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.dia);
                printf("Mes de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.mes);
                printf("Ano de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.ano);
                int i = PesquisarVenda(*modulo3, venda);
                if(i == -1) {
                    printf("Venda nao encontrada.\n");
                    system("PAUSE");
                }
                else {
                    printf("Venda encontrada.\n\n");
                    relatorioVenda(modulo3->vendasExecutadas[i]);
                    system("PAUSE");
                }
            } break;
            case 3: {
                system("cls");
                printf("Digite o codigo do produto relacionado a venda buscada: ");
                fflush(stdin);
                scanf("%d", &venda.codigoProduto);
                printf("Digite o CPF/CNPJ do cliente relacionado a venda buscada: ");
                fflush(stdin);
                fgets(venda.idCliente, TAM, stdin);
                conserta(venda.idCliente);
                printf("Dia de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.dia);
                printf("Mes de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.mes);
                printf("Ano de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.ano);
                AlterarVenda(modulo3, venda, modulo1, modulo2);
                system("PAUSE");
            } break;
            case 4: {
                system("cls");
                printf("Digite o codigo do produto relacionado a venda buscada: ");
                fflush(stdin);
                scanf("%d", &venda.codigoProduto);
                printf("Digite o CPF/CNPJ do cliente relacionado a venda buscada: ");
                fflush(stdin);
                fgets(venda.idCliente, TAM, stdin);
                conserta(venda.idCliente);
                printf("Dia de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.dia);
                printf("Mes de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.mes);
                printf("Ano de realizacao da venda: ");
                fflush(stdin);
                scanf("%d", &venda.dataRealizacao.ano);
                ExcluirVenda(modulo3, venda);
                system("PAUSE");
            } break;
            case 5: {
                system("cls");
                imprimeTodasAsVendas(*modulo3);
                system("PAUSE");
            } break;
            case 6:
                break;
            default:
                printf("\n>>>> MSG: Digite uma opcao valida!!! <<<<\n");
                system("PAUSE");
        }
    } while(opcao != 6);
}

void SubMenuModulo4(TListaProduto moduloProduto, TListaVendas moduloVendas, TListaClientes moduloCliente)
{
    int opcao;
    do {
        system("cls");
        printf(">>>>>>>>>>>>>>> MODULO PROVA <<<<<<<<<<<<<<<<<\n");
        printf("\n\t1. IMPRIMIR O PRODUTO MAIS VENDIDO");
        printf("\n\t2. IMPRIMIR O TOTAL E QUANTIDADE DE VENDAS A VISTA");
        printf("\n\t3. CODIGOS DOS PRODUTOS COMPRADOS EM COMUM POR DOIS CLIENTES");
        printf("\n\t4. NOTA FISCAL");
        printf("\n\t5. SAIR");
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                system("cls");
                produtoMaisVendido(moduloProduto, moduloVendas);
                system("PAUSE");
            } break;
            case 2: {
                system("cls");
                totalAVista(moduloVendas);
                system("PAUSE");
            } break;
            case 3: {
                TCliente cliente1, cliente2;
                system("cls");
                printf("Digite o id do primeiro cliente: ");
                fflush(stdin);
                fgets(cliente1.id, TAM, stdin);
                conserta(cliente1.id);
                printf("Digite o id do segundo cliente: ");
                fflush(stdin);
                fgets(cliente2.id, TAM, stdin);
                conserta(cliente2.id);
                int pc1 = PesquisarCliente(moduloCliente, cliente1);
                int pc2 = PesquisarCliente(moduloCliente, cliente2);
                if(pc1 == -1 || pc2 == -1) {
                    printf("Clientes não encontrados.\n");
                    system("PAUSE");
                    break;
                }
                produtosEmComum(cliente1, cliente2, moduloVendas);
                system("PAUSE");
            } break;
            case 4: {
                system("cls");
                TCliente cliente;
                TData data;
                printf("Digite o id do cliente: ");
                fflush(stdin);
                fgets(cliente.id, TAM, stdin);
                conserta(cliente.id);
                int pc = PesquisarCliente(moduloCliente, cliente);
                if(pc == -1) {
                    printf("Cliente não econtrado.\n");
                    system("PAUSE");
                    break;
                }
                printf("Digite o dia da nota: ");
                fflush(stdin);
                scanf("%d", &data.dia);
                printf("Digite o mês da nota: ");
                fflush(stdin);
                scanf("%d", &data.mes);
                printf("Digite o ano da nota: ");
                fflush(stdin);
                scanf("%d", &data.ano);
                notaFiscal(data, cliente, moduloVendas);
                system("PAUSE");
            } break;
            case 5:
                break;
            default:
                printf("\n>>>> MSG: Digite uma opcao valida!!! <<<<\n");
                system("PAUSE");
        }
    } while(opcao != 5);
}


