#include "stdafx.h"
#include <stdio.h>
#include "tipos.h"
#include <stdlib.h>
#include <string.h>

extern unsigned char tabela_ascii[];

/*
*Imprime estrutura do cabeçalho, recebe apontador para caractere.
*/
void imprimeCabecalho(char *coluna_1, char *coluna_2){
	system("CLS");
	printf("%s %s", coluna_1, coluna_2);
	printf("\n");
}

//void imprimeLimites(int frequencia, char *palavra){
//	char limite[80] = {"--------------------------------------------------------------------------------"};
//	unsigned short tamanho_original = 10;
//
//		printf("%s%-*.*s","  ",tamanho_original, tamanho_original,limite);
//		printf("%-*.*s",tamanho_original, tamanho_original,limite);
//		printf("\n");
//		printf("%3s", "|");
//		printf("%*d%s",tamanho_original - 1, frequencia, "|");
//		printf("%s%*.1s", palavra, tamanho_original - strlen(palavra)-1, "|");
//		printf("\n");
//	
//}

/* imprimeDadosLista
*recebe ponteiro para o primeiro elemento da lista vai mandar imprimir todas as listas com elementos
*/
void imprimeDadosLista(CABECA p_primeiro){	
	PGENERICA ptr;
	PPALAVRA p_palavra;
	int tamanho_minimo_limite;	
	P_CONTADORES contadores;
	tamanho_minimo_limite = strlen("Frequencia  Palavra");
	imprimeCabecalho("Frequencia", " Palavra");
	if(1){
	imprimeLimite(tamanho_minimo_limite,'-');
	printf("\n");
	for ( ptr =p_primeiro.primeiro; ptr ; ptr = ptr->seg){
		p_palavra = ptr->dados;
		imprimeLinha(p_palavra->contador, p_palavra->nome, tamanho_minimo_limite);		
	}
	}else{
;
	}
	system("PAUSE");
}

void imprimeLimite(int numero_caracteres, char limite){
	int i;
	for(i = 0; i < numero_caracteres; i++){
		printf("%c", limite);
	}

}


void imprimeLinha(int frequencia, char *palavra, int tamanho_limite){
	int tamanho_minimo_limite = tamanho_limite;
	imprimeLimite(1,'|');
	printf("%9.4d",frequencia);
	imprimeLimite(1,'|');
	printf("%-*.*s", strlen("palavra"), strlen(palavra), palavra);
	imprimeLimite(1,'|');
	printf("\n");
	imprimeLimite(tamanho_minimo_limite, '-');
	printf("\n");
}



