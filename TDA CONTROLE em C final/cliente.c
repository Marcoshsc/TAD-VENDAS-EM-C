#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cliente.h"

#define TAM 50

/**
 * PARAMETROS:
 * - char* texto: texto a ser alterado.
 * FUNCIONAMENTO:
 * - Modifica a ultima posicao do vetor de caracteres para '\0', caso o mesmo nao esteja
 * completamente preenchido.
*/
void conserta(char* texto)
{
    if(texto[strlen(texto) - 1] == '\n')
        texto[strlen(texto) - 1] = '\0';
}

/**
 * PARAMETROS:
 * - TListaClientes* listaClientes: endereco de um modulo de clientes ja inicializado;
 * - TCliente cliente: cliente com todos os campos preenchidos.
 * FUNCIONAMENTO:
 * - Insere o cliente recebido como parametro no modulo, também recebido como parametro.
*/
void InsereCliente(TListaClientes* listaClientes, TCliente cliente)
{
    if(listaClientes->numeroCadastrados < TAM) {
        listaClientes->clientesCadastrados[listaClientes->numeroCadastrados] = cliente;
        listaClientes->numeroCadastrados++;
        printf("Cliente cadastrado com sucesso.\n");
    }
    else {
        printf("Nao foi possivel cadastrar o cliente.\n");
    }
}

/**
 * PARAMETROS:
 * - TCliente cliente: cliente com todos os dados preenchidos.
 * FUNCIONAMENTO:
 * - Imprime um relatorio das informacoes do cliente recebido.
*/
void relatorioCliente(TCliente cliente)
{
    char tipoCliente[30];
    if(cliente.tipo)
        sprintf(tipoCliente, "Pessoa Jur�dica");
    else
        sprintf(tipoCliente, "Pessoa F�sica");

    printf("\nTipo: %s\nNome: %s\nID: %s\nData de nascimento/Criacao: %d/%d/%d\nLogradouro: %s\nBairro: %s\nNumero: %d\nComplemento: %s\nCidade: %s\nCEP: %s\nEstado: %s\nPa�s: %s\n",
           tipoCliente, cliente.nome, cliente.id, cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano,
           cliente.enderecoCliente.logradouro,cliente.enderecoCliente.bairro, cliente.enderecoCliente.numero,
           cliente.enderecoCliente.complemento, cliente.enderecoCliente.cidade, cliente.enderecoCliente.cep,
           cliente.enderecoCliente.estado, cliente.enderecoCliente.pais);
    if(cliente.tipo == 0)
        printf("RG: %s\n", cliente.identidade);
}

/**
 * PARAMETROS:
 * - TCliente* cliente: endereco de um cliente.
 * FUNCIONAMENTO:
 * - Le todos os campos do cliente recebido como parametro.
*/
void lerCliente(TCliente* cliente)
{
    printf("Digite o tipo do cliente, (0) para Pessoa f�sica e (1) para Pessoa Jur�dica: ");
    scanf("%d", &cliente->tipo);
    if(cliente->tipo == 0) {
        printf("Nome do cliente: ");
        fflush(stdin);
        fgets(cliente->nome, TAM, stdin);
        conserta(cliente->nome);
        printf("CPF do cliente: ");
        fflush(stdin);
        fgets(cliente->id, TAM, stdin);
        conserta(cliente->id);
        printf("RG do cliente: ");
        fflush(stdin);
        fgets(cliente->identidade, TAM, stdin);
        conserta(cliente->identidade);
        printf("Data de nascimento do cliente (dd/MM/yyyy): ");
        fflush(stdin);
        scanf("%d%d%d", &cliente->dataNascimento.dia, &cliente->dataNascimento.mes, &cliente->dataNascimento.ano);
    }
    else {
        printf("Nome da empresa: ");
        fflush(stdin);
        fgets(cliente->nome, TAM, stdin);
        conserta(cliente->nome);
        printf("CNPJ da empresa: ");
        fflush(stdin);
        fgets(cliente->id, TAM, stdin);
        conserta(cliente->id);
        printf("Data de criacao da empresa (dd/MM/yyyy): ");
        fflush(stdin);
        scanf("%d%d%d", &cliente->dataNascimento.dia, &cliente->dataNascimento.mes, &cliente->dataNascimento.ano);
    }
    printf("Cadastro de Endereco\nLogradouro: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.logradouro, TAM, stdin);
    conserta(cliente->enderecoCliente.logradouro);
    printf("Numero: ");
    fflush(stdin);
    scanf("%d", &cliente->enderecoCliente.numero);
    printf("Bairro: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.bairro, TAM, stdin);
    conserta(cliente->enderecoCliente.bairro);
    printf("Cidade: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.cidade, TAM, stdin);
    conserta(cliente->enderecoCliente.cidade);
    printf("Complemento: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.complemento, TAM, stdin);
    conserta(cliente->enderecoCliente.complemento);
    printf("CEP: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.cep, TAM, stdin);
    conserta(cliente->enderecoCliente.cep);
    printf("Estado: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.estado, TAM, stdin);
    conserta(cliente->enderecoCliente.estado);
    printf("Pais: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente.pais, TAM, stdin);
    conserta(cliente->enderecoCliente.pais);
}

/**
* PARAMETROS:
* - TListaClientes listaClientes: modulo de clientes ja inicializado;
* - TCliente cliente: cliente com id preenchido.
* FUNCIONAMENTO:
* - Varre o modulo em busca do cliente;
* - Caso encontrado, retorna seu indice;
* - Caso nao encontrado, retorna -1.
*/
int PesquisarCliente(TListaClientes listaClientes, TCliente cliente)
{
    if(listaClientes.numeroCadastrados == 0) {
        return -1;
    }
    for(int i = 0; i < listaClientes.numeroCadastrados; i++) {
        if(!(strcmp(listaClientes.clientesCadastrados[i].id, cliente.id))) {
            return i;
        }
    }
    return -1;
}

/**
 * PARAMETROS:
 * - TListaClientes* listaClientes: endereco de um modulo de clientes não inicializado.
 * FUNCIONAMENTO:
 * - Atribui o valor 0 ao campo numeroCadastrados.
*/
void InicializaModuloCliente(TListaClientes* listaClientes)
{
    listaClientes->numeroCadastrados = 0;
}

/**
* PARAMETROS:
* - TListaClientes* listaClientes: endereco de um modulo de clientes ja inicializado;
* - TCliente cliente: cliente com id preenchido.
* FUNCIONAMENTO:
* - Busca pelo cliente via funcao PesquisarCliente;
* - Caso encontrado, re-leitura dos dados via funcao lerCliente;
* - Caso nao encontrado, imprime mensagem informativa.
*/
void AlterarCliente(TListaClientes* listaClientes, TCliente cliente)
{
    int i = PesquisarCliente(*listaClientes, cliente);
    if(i == -1)
        printf("Cliente nao encontrado.\n");
    else {
        printf("Cliente encontrado. Alterando Cliente:\n");
        lerCliente(&listaClientes->clientesCadastrados[i]);
        printf("Cliente alterado com sucesso.\n");
    }
}

/**
 * PARAMETROS:
 * - TListaClientes listaClientes: modulo de clientes ja inicializado;
 * FUNCIONAMENTO:
 * - Imprime um relatorio de cada um dos clientes dentro do modulo, via
 * funcao relatorioCliente.
*/
void imprimeTodosOsClientes(TListaClientes listaClientes)
{
    if(listaClientes.numeroCadastrados == 0) {
        printf("Nao existem clientes cadastrados.\n");
    }
    else {
        printf("IMPRIMINDO TODOS OS CLIENTES\n");
        for(int i = 0; i < listaClientes.numeroCadastrados; i++) {
            relatorioCliente(listaClientes.clientesCadastrados[i]);
        }
    }
}

/**
 * PARAMETROS:
 * - TListaClientes* listaClientes: endereco de um modulo de clientes ja inicializado;
 * - TCliente cliente: cliente com o id preenchido.
 * FUNCIONAMENTO:
 * - Procura pelo cliente dentro do modulo, via funcao PesquisarCliente;
 * - Caso encontrado, remove o cliente do modulo.
*/
void ExcluirCliente(TListaClientes* listaClientes, TCliente cliente)
{
    int i = PesquisarCliente(*listaClientes, cliente);
    if(i == -1) {
        printf("Cliente nao encontrado.\n");
    }
    else {
        for(int j = i; j < listaClientes->numeroCadastrados - 1; j++) {
            listaClientes->clientesCadastrados[j] = listaClientes->clientesCadastrados[j+1];
        }
        listaClientes->numeroCadastrados--;
        printf("Cliente excluido com sucesso.\n");
    }
}

/*
void quitaDebito(TListaClientes* listaClientes)
{
    char confirmacao;
    char idCliente[TAM];
    printf("ID do cliente procurado: ");
    fflush(stdin);
    fgets(idCliente, TAM, stdin);
    conserta(idCliente);
    TCliente* cliente = buscaPorId(idCliente, listaClientes);
    if(!cliente) {
        printf("Cliente n�o encontrado.\n");
        return;
    }
    if(cliente->debitos) {
        printf("D�BITO PENDENTE:\n");
        relatorioVenda(cliente->debitos);
        printf("CONFIRMAR PAGAMENTO? 's' para sim : ");
        fflush(stdin);
        scanf("%c", &confirmacao);
        if(confirmacao == 's') {
            cliente->debitos = NULL;
            printf("D�bito quitado.\n");
        }
        else {
            printf("Opera��o cancelada.\n");
            return;
        }
    }
    else {
        printf("Cliente n�o possui d�bitos.\n");
    }
}
*/

