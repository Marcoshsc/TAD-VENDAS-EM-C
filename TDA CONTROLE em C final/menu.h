#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "vendas.h"

void MSG_MENU();

void MSG_SUBMENU(int numero_modulo);

void SubMenuModulo1(TListaProduto* modulo1, TProduto produto);

void SubMenuModulo2(TListaClientes* modulo2, TCliente cliente);

void SubMenuModulo3(TListaVendas* modulo3, TVendas venda, TListaProduto* modulo1, TListaClientes modulo2);

void SubMenuModulo4(TListaProduto moduloProduto, TListaVendas moduloVendas, TListaClientes moduloCliente);

#endif // MENU_H_INCLUDED
