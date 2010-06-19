#include "stdafx.h"
#include <stdio.h>
#include "tipos.h"
#include <stdlib.h>
#include <string.h>

#define NUMERO_ITEMS 7
#define OPCOES_MENU 5


void menu(void){
	char *item_menu[OPCOES_MENU] = {"Criar", "Remover", "Listar", "Pesquisa Geral", "Pesquisa Personalizada"};

	char *sub_item_menu[NUMERO_ITEMS] = {"Salas", "Espetaculos", "Reservas", "Espectadores",
		"Salas por Nome", "Espectaculos por Nome e Numero", "Espectaculos de Sala ou Sessao numa Data"};
	int escolha_menu, escolha_sub_menu;

	for(;;){
		imprimeCabecalho("\t       Cinemas Lusofona\n");
		imprimeMenu(item_menu, OPCOES_MENU, '1');		
		rewind(stdin);
		escolha_menu = getchar();
		switch(escolha_menu)
		{
		case '1':
			system("CLS");
			imprimeCabecalho("\t\t   Criar\n");
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu);
			break;

		case '2':
			system("CLS");
			imprimeCabecalho("\t\t   Remover\n");
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu);
			break;

		case '3':
			system("CLS");
			imprimeCabecalho("\t\t   Listar\n");
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu);
			break;

		case '4':
			system("CLS");
			imprimeCabecalho("\tPesquisa Geral\n");
			imprimeMenu(sub_item_menu,4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu);
			break;

		case '5':
			system("CLS");
			imprimeCabecalho("\tPesquisa Personalizada\n");
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu);
			break;
		case '6':
			exit(1);
			break;

		default :
			break;
		}
	}
}

void subMenu(int escolha_menu, int escolha_sub_menu){
	for(;;){		
		switch(escolha_sub_menu)
		{
		case '1':


			break;
		case '2':

			break;
		case '3':

			break;
		case '4':
			if(escolha_sub_menu == '4' || escolha_sub_menu == '5'){
				menu();
			}

			break;
		case '5':
			menu();
			break;

		}
	}
}


void imprimeMenu(char **vct_menu, int tamanho, int escolha){
	int i, indice = 1;
	if(escolha == '1' || escolha == '2' || escolha == '3'){
		for(i = 0; i < tamanho; i++, indice++){
			printf("%d - %s\n", i + 1, vct_menu[i]);
		}
	}else{		
		for(i = tamanho; i < NUMERO_ITEMS; i++, indice++){

			printf("%d - %s\n", indice, vct_menu[i]);
		}
	}
	printf("%d - Sair\n", indice);
}

/*
*Imprime estrutura do cabeçalho, recebe apontador para caractere.
*/
void imprimeCabecalho(char *str){
	char cabecalho_tmp[100] = "\t\t**CINELUSO**\n\n";
	strcat(cabecalho_tmp,str);
	system("CLS");
	printf("<----------------------------------------->\n");
	printf(cabecalho_tmp);
	printf("<----------------------------------------->\n");

}