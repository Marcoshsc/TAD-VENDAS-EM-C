#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define TAM 50
#include "complementares.h"

typedef struct cliente_est
{

    char nome[TAM];
    char id[TAM];
    char identidade[TAM];
    int tipo;
    TData dataNascimento;
    TEndereco enderecoCliente;

} TCliente;

typedef struct listaClientes
{

    int numeroCadastrados;
    TCliente clientesCadastrados[TAM];

} TListaClientes;

void conserta(char* texto);

void InsereCliente(TListaClientes* listaClientes, TCliente cliente);

void relatorioCliente(TCliente cliente);

void lerCliente(TCliente* cliente);

int PesquisarCliente(TListaClientes listaClientes, TCliente cliente);

void InicializaModuloCliente(TListaClientes* listaClientes);

void AlterarCliente(TListaClientes* listaClientes, TCliente cliente);

void imprimeTodosOsClientes(TListaClientes listaClientes);

void ExcluirCliente(TListaClientes* listaClientes, TCliente cliente);

// void quitaDebito(TListaClientes* listaClientes);

#endif // CLIENTE_H_INCLUDED
