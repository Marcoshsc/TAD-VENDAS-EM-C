#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "menu.h"

#define TAM 50

int main()
{
    /**
    *TListaCliente == TModuloCliente
    *TListaProduto == TModuloProduto
    *TListaVendas == TModuloVenda
    */
    setlocale(LC_ALL, "Portuguese");
    TListaProduto modulo1;
    TListaClientes modulo2;
    TListaVendas modulo3;
    InicializaModuloProduto(&modulo1);
    InicializaModuloCliente(&modulo2);
    InicializaModuloVenda(&modulo3);
    TProduto produto;
    TCliente cliente;
    TVendas venda;
    int opcao;
    do {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                SubMenuModulo1(&modulo1, produto);
                break;
            case 2:
                SubMenuModulo2(&modulo2, cliente);
                break;
            case 3:
                SubMenuModulo3(&modulo3, venda, &modulo1, modulo2);
                break;
            case 4:
                SubMenuModulo4(modulo1, modulo3, modulo2);
                break;
            case 5:
                printf(">>>> MSG: Saindo do programa...!!! <<<<\n");
                system("PAUSE");
                break;
            default:
                printf(">>>> MSG: Digite uma opcao valida!!! <<<<\n");
                system("PAUSE");
        }
    } while(opcao != 5);

    return 0;
}
