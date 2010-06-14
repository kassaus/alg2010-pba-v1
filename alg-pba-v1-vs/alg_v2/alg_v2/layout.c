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



void imprimeLimite(int numero_caracteres, char limite){
	int i;
	for(i = 0; i < numero_caracteres; i++){
		printf("%c", limite);
	}

}


void imprimeLinhaTabela(PGENERICA primeiro, P_CONTADORES contadores){
	PGENERICA ptr_primeiro = primeiro;
	PPALAVRA ptr_palavra;
	int para_ecra= 1;
	for ( ptr_primeiro = primeiro; ptr_primeiro ; ptr_primeiro = ptr_primeiro->seg){
		if(para_ecra%4 == 0){
			imprimeLimite((strlen("frequencia") + contadores->tamanho_maximo_palavra+2), '-');
	printf("\n");
			system("PAUSE");
		}else{
		 ptr_palavra = ptr_primeiro->dados;
	imprimeLimite((strlen("frequencia") + contadores->tamanho_maximo_palavra+2), '-');
	printf("\n");
	imprimeLimite(1,'|');
	printf("%9.5d", contadores->frequencia_total);
	imprimeLimite(1,'|');
	printf("%-*.*s", contadores->tamanho_maximo_palavra, contadores->tamanho_maximo_palavra, ptr_palavra->nome);
	imprimeLimite(1,'|');
	printf("\n");	
	}
	para_ecra++;
	}
	imprimeLimite((strlen("frequencia") + contadores->tamanho_maximo_palavra+2), '-');
	printf("\n");
}

void imprimeLinhaHistograma(PGENERICA primeiro, P_CONTADORES contadores){

}






