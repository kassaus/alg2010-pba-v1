#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "tipos.h"

/*Lê um conjunto de caracteres do teclado até ao \n exclusive.
*recebe por parâmetro um ponteiro para o destino do conjunto de caracteres a guardar, um ponteiro para um array
*de caracteres a imprimir no ecrâ e o tamanho do destino.
*/
void leString(char* str, char* txt, int tam)
{
	fflush(stdin);
	printf(txt);    

	scanf("%[^\n]", str);
	while (str[0]=='\0' || tam < (int)(strlen(str))) {
		printf("Erro! Insira novamente:");
		fflush(stdin);
		scanf("%[^\n]", str);
	}          	
}


float leFloat(char* txt) 
{
     float num;
     printf(txt);     
     while (scanf("%f", &num)!=1) {
           while(getchar() !='\n');
           printf("Erro! Insira novamente:");    
     }       
     return num;
}

unsigned leUnsigned(char* txt) 
{
     unsigned num;
     printf(txt);     
     while (scanf("%u", &num)!=1) {
           while(getchar() !='\n');
           printf("Erro! Insira novamente:");    
     }       
     return num;         
}

unsigned short leUnsignedShort(char* txt) 
{
     unsigned short num;
     printf(txt);     
     while (scanf("%hu", &num)!=1) {
           while(getchar() !='\n');
           printf("Erro! Insira novamente:");    
     }       
     return num;         
}

unsigned leEnum(char* txt, unsigned min, unsigned max) 
{
     unsigned num;
     printf(txt);     
     while (scanf("%u", &num)!=1 || num<min || num>max) {
           while(getchar() !='\n');
           printf("Erro! Insira novamente:");   
     }       
     return num;         
}
