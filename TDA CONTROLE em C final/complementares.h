#ifndef COMPLEMENTARES_H_INCLUDED
#define COMPLEMENTARES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define TAM 50

typedef struct data_est
{

    int dia;
    int mes;
    int ano;

} TData;

typedef struct endereco_est
{

    char logradouro[TAM];
    char bairro[TAM];
    int numero;
    char cidade[TAM];
    char estado[TAM];
    char pais[TAM];
    char complemento[TAM];
    char cep[TAM];

} TEndereco;

#endif // COMPLEMENTARES_H_INCLUDED
