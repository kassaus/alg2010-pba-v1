/*esquema trabalho goritmia
grupo PBA
*/


/*
limpeza de funcoes e organizacao de codigo


faltam as rotinas para actualizar os dados da estrutura cabeca com as frequencias maximas e individuais
*/

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipos.h"


//sera que deveremos colocar o '-' por causa das palavras hifenizadas?
	unsigned char tabela_ascii[] = {'.','.','.', '.', '.', '.', '.', '.', '.', '.',
									'.','.','.', '.', '.', '.', '.', '.', '.', '.', '.',
									'.','.', '.', '.', '.', '.', '.', '.', '.', '.','.',
									'.', '.', '.', '.', '.', '.', '.', '.', '.','.','.',
									'.', '.', '.', '.', '.', '.', '.', '.','.','.', '.',
									'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
									'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
									'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
									'w', 'x', 'y', 'z', '.', '.', '.', '.', '.', '.', 
									'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
									'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
									'w', 'x', 'y', 'z',  '.', '.', '.', '.', '.', '.', '.',
									'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
									'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
									'.', '.', '.', '.', '.', '.', 'z', 'y', '.','.','.', '.',
									'.', '.', '.', '.', '.', '.','.','.','.', '.', '.', '.', '.',
									'.', '.', '.','.','.','.', '.', '.', '.', '.', '.', '.', '.',
									'.', '.', 'a', 'a', 'a', 'a', 'a', 'a','.','c','e','e','e','e',
									'i','i','i','i','.','n','o','o','o','o','o','x', '.','u','u','u','u',
									'y','.','.', 'a','a','a','a','a','a', '.','c', 'e','e','e','e','a',
									'i','i','i','.','n', 'o','o','o','o','o','.','.','u','u','u','u', 'y',
									'.','y'};






/* main 
 *verificar se recebe argumento se nao receber, pedir ficheiro
 *tentar abrir ficheiro em "r" se nao conseguir, pedir de novo ou 0 para sair
 *processa o ficheiro
 *
 */
int main(int argc, char *argv[]){

	CABECA array_letras[LETRAS];
	FILE *fp_ficheiro;
	char ficheiro[MAX_FICHEIRO];
	int i;

	//inicializacao do array de estruturas cabeca
	memset(array_letras, 0, sizeof(CABECA) * LETRAS);
	for (i=0; i<LETRAS; i++){
		array_letras[i].ordenacao = comparaFreqCres;
	}	

	if (argc==2)						// se receber argumento
		strcpy(ficheiro, argv[1]);	
	if (argc==1){						// se nao receber argumento
		printf("Qual o ficheiro a processar? :");	// pedir o ficheiro
		fflush(stdin);
		scanf("%[^\n]", ficheiro);
	}

	fp_ficheiro = fopen(ficheiro, "r");		// abre em modo leitura
	if (!fp_ficheiro){ 
		printf("Nao foi possivel abrir o ficheiro %s", ficheiro);
		system("pause");
		return(-1);
	}
	
	processaFicheiro(fp_ficheiro, array_letras);


	system("PAUSE");

}


/* funcao de comparacao por frequencia crescente recebe os valores a e b para comparar
 *devolve -1 se menor, 0 se igual e 1 se maior
 */
int comparaFreqCres(int num1,int num2 ) {
	if( num1 == num2 )
		return 0;
	if ( num1 < num2)
		return -1;
	return 1;
}

/* funcao de comparacao por frequencia  decrescente recebe os valores a e b para comparar
 *devolve 1 se menor, 0 se igual e -1 se maior
 */
int comparaFreqDecres(int num1,int num2 ) {
	if( num1 == num2 )
		return 0;
	if ( num1 > num2)
		return -1;
	return 1;
}


/* funcao de comparacao por nome crescente recebe os valores a e b para comparar
 *devolve -1 se nome 1 menor, 0 se igual e 1 se nome1 maior
 */
int comparaNomeCres(char *nome1, char *nome2) {
	return strcmp(nome1, nome2);
}

/* funcao de comparacao por nome decrescente recebe os valores a e b para comparar
 * devolve 1 se nome1 menor, 0 se igual e -1 se nome1 maior
 */
int comparaNomeDecres(char *nome1, char *nome2) {
	return strcmp(nome2, nome1);
}

/* processaFicheiro
recebe o filepointer para o ficheiro, aberto em leitura
e o array das letras
tentar depois ver o tipo de ficheiro e processar o header e footer em nova funcao

do{
retira uma linha do ficheiro
converter os caracteres 
chama o separaPalavras(char *buffer)
} while EOF
retorna????
*/
void processaFicheiro (FILE *fp_ficheiro, CABECA array_letras[]) {

	char buffer[MAX_BUFFER];
	int linha=0;

	while ( fgets(buffer, MAX_BUFFER, fp_ficheiro)!= NULL ) {	//enquanto existirem linhas	
		converteString(buffer);									//converte os caracteres em ascii
		if (DEBUG) printf("linha %d ", linha++);
		separaPalavras(buffer, array_letras);					//retira as palavras da linha
	}

	if (DEBUG) imprimeDadosTotal(array_letras);

	return;
}


/* separaPalavras
 *
 * recebe a string a processar e o array de letras para introducao
 * procura pela letra, quando encontra letra procura por "nao letra"
 * 
 */
void separaPalavras( char *buffer, CABECA array_letras[LETRAS]) {

	int i=0, j=0, fim_linha=0;
	PPALAVRA palavra;
	//int teste;

	

	do {
		while ( (buffer[i]==' ' && buffer[i]!='\0' && buffer[i]!='\n' && buffer[i]=='.') && i<MAX_BUFFER  )
			i++;  //varre ate encontrar letra          
		
		if( buffer[i] == '\n' || buffer[i] == '\0' || i>= MAX_BUFFER)	//se for o fim da linha ou da string
			break;

		j = i;		//guarda a posicao do inicio da palavra

		while (buffer[i]!=' ' && i<MAX_BUFFER && buffer[i]!='\0' && buffer[i]!='\n' && buffer[i]!='.' )
			i++; 

		if (i>=MAX_BUFFER)		//se chegou ao fim do buffer sem encontrar \n ou \0 é porque cortou uma palavra a meio...
			break;				//e nao vamos contar com ela

		if (buffer[i] !='\0'){
				buffer[i] = '\0';				
		}
		else {
			fim_linha = 1;
		}

		i++;

		if ( (i-j) >= 2){	//se a string for "nula" tem apenas o \0

			if (DEBUG) printf("Entrou na criacao da estrutura palavra\n");
			palavra = malloc( sizeof(PPALAVRA) );
			palavra->nome = malloc(i-j);
			strcpy(palavra->nome, buffer+j );
			palavra->contador =1;


	//		insereInicio( palavra, &array_letras[buffer[j]-'a']  );

			procuraLugarNaLista(palavra, &array_letras[buffer[j]-'a'] );

			if (DEBUG) printf("palavra <%s>\n", palavra->nome);

		}

		if (fim_linha)
			break;

		//system("pause");

	} while ( i<MAX_BUFFER && buffer[i]!='\0' && buffer[i]!='\n'); 

	system("pause");
	return;
}


/*Converte uma string para minusculas e sem acentos.
 *converteString recebe por parametro um ponteiro para array.
 */
void converteString(char *buffer){
	int i = 0;
	do{
		buffer[i] = tabela_ascii[(unsigned char)buffer[i]];
		i++;
	}while(buffer[i] != '\0' && buffer[i] != '\n');
}



/* procuraLugarNaLista
 *
 * recebe
 *		ponteiro para a estrutura palavra
 *		ponteiro para o array de letras
 *
 * vai introduzir o elemento recebido no local certo, verificando
 *		o metodo de ordenacao da lista em questao
 *		se encontrar uma palavra ja na lista, apenas incrementa o contador no numero recebido
 *		senao fica atenta ao lugar certo de colocacao
 *
 * chama funcao para colocar a palavra na lista
 *
 * nao devolve nada
 */
void procuraLugarNaLista( PPALAVRA palavra, PCABECA p_letra) {

	PGENERICA ptr, ant;						// ponteiros para percorrer a lista generica
	int ret;		//valor de retorno das funcoes de ordenacao
	PPALAVRA palavra1;
	int tamanho_palavra;	//tamanho da palavra recebida, calculado com strlen

	//colocamos o ptr para o inicio da lista generica na letra certa
	ptr = p_letra->primeiro;

	p_letra->frequencia_letra += palavra->contador;		//aumentar a frequencia total

	if (ptr == NULL) {
		insereInicio(palavra, p_letra);		//se a lista estiver vazia
		if (DEBUG) printf("A inserir no inicio\n");
		
		return;
	}

	
	/* procurar pelo lugar certo
	 *	no caso em que esta ordenado por nome
	 *
	 * se ordenado por nome crescente
	 *	se for igual, contador ++
	 *	se for menor, introduzir antes
	 *	se for maior, seguir para a proxima estrutura generica
	 *
	 *se ordenado por nome decrescente
	 *	se for igual, contador++
	 *	se for maior, introduzir antes
	 *	se for menor, seguir para a proxima estrutura generica
	 */
	if ( p_letra->ordenacao ==comparaNomeCres || p_letra->ordenacao ==comparaNomeDecres ){
		do {
			palavra1= ptr->dados;
	
			ret = (p_letra->ordenacao)(palavra1->nome, palavra->nome);	
			//se a palavra for igual, o retorno é zero
			if (!ret) {
				if (DEBUG) printf("A palavra %s ja existe, a incrementar em %d o valor %d\n", palavra->nome, palavra->contador, palavra1->contador );
				palavra1->contador += palavra->contador;
				return;
			}
			//se a palavra ja na lista for "maior" (dependendo do metodo de ordenacao), queremos inserir antes
			if (ret >0){
				if (DEBUG) printf("A palavra %s vai ser inserida antes de %s\n", palavra->nome, palavra1->nome );
				if ( ptr->ant == NULL) //se o prt->ant nao existir, inserir no primeiro da lista
					insereInicio( palavra, p_letra);
				return;
			}	
			else {					//se for "menor" (dependendo do metodo de ordenacao), vamos para o seguinte ou 
				if (!ptr->seg){		//se estivermos no fim, insere no fim
					insereFim(palavra, ptr);
					if (DEBUG) printf("A inserir no fim");
					return;
				}
				ptr = ptr->seg;
			}

		} while (ptr);
	}

	/* no caso em que esta ordenado por frequencia
	 *
	 * procurar a palavra na lista
	 *		usando um algoritmo de pesquisa linear, pois a lista nao esta ordenada por nome
	 *			se encontrar, incrementar a frequencia da palavra
	 *				e verificar se agora a lista ficou fora de ordem, muito frequente em mudanca de palavras com grande repeticao
	 *				se ficou, retirar o elemento e mandar colocar de novo no local certo
	 *
	 *			se nao encontrar, mandar colocar no sitio certo tendo em conta o metodo de ordenacao,
	 *				similar à ordenação por nome 		
	 */
	if ( p_letra->ordenacao ==comparaFreqCres || p_letra->ordenacao ==comparaFreqDecres ) {
		//poderiamos ter colocado apenas um else, mas se adicionarmos mais metodos de ordenacao o codigo fica garantido

		do {		//varrer a lista em busca linear, procurando a palavra 
			palavra1= ptr->dados;

			if ( strcmp(palavra1->nome, palavra->nome) ==0 ){		//se encontrar a palavra
				palavra1->contador += palavra->contador;						//incrementa o contador
				if (DEBUG) printf("Encontrou a palavra e incrementa o contador\n");
				//verificar se ficou fora de sitio
				//actualizar os contadores em p_letra
				return;
			}
			ant= ptr->ant;
			ptr= ptr->seg;	
		} while (ptr); 
		
		//chega aqui se nao encontrar
		if (p_letra->ordenacao == comparaFreqCres){		//se ordem crescente
			insereInicio(palavra, p_letra);				//insere no inicio
			if (DEBUG) printf("nao encontrou a palavra e insere no inicio\n");
		}
		else{
			insereFim(palavra, ant);
			if (DEBUG) printf("nao encontrou a palavra e insere no fim\n\n");
		}
		//verificacao dos valores maximos na estrutura... ainda falta
		
		if ( p_letra->frequencia_maxima < palavra->contador)	//se a palavra tiver mais repeticoes do que o valor  
			p_letra->frequencia_maxima = palavra->contador;		//guardamos o valor novo

		tamanho_palavra = strlen (palavra->nome);
		if ( p_letra->maior_palavra < tamanho_palavra )
			p_letra->maior_palavra = tamanho_palavra;
		


	}


}








/* insereInicio
 *
 * recebe
 *		ponteiro para a palavra
 *		ponteiro para a cabeca da lista generica correspondente a letra
 * 
 * vai inserir nova estrutura generica em cabeca.primeiro e inserir nos dados a palavra
 */
void insereInicio( PPALAVRA palavra, PCABECA p_letra ){

	PGENERICA item, ptr;

	item = malloc(sizeof(GENERICA));

	if ( p_letra->primeiro == NULL){		//se a lista estiver vazia
		p_letra->primeiro = item;
		item->seg = NULL;
		item->ant = NULL;
	}
	else {							//se a lista tiver elementos
		ptr = p_letra->primeiro;
		p_letra->primeiro = item;
		item->ant = NULL;
		item->seg = ptr;
		ptr->ant = item;
	}
	item->dados = palavra;
}


/* insereMeio
 *
 * recebe
 *		ponteiro para a palavra
 *		ponteiro para a estrutura que fica como anterior 
 *		ponteiro para a estrutura que fica como seguinte
 *
 * vai inserir nova estrutura generica entre as duas e inserir nos dados a palavra
 */
void insereMeio( PPALAVRA palavra, PGENERICA anterior, PGENERICA seguinte) {

	PGENERICA item;

	item = malloc(sizeof(GENERICA));

	anterior->seg = item;
	seguinte->ant = item;
	item->ant = anterior;
	item->seg = seguinte;

	item->dados = palavra;

	return;
}


/* insereFim
 *
 * recebe
 *		ponteiro para a palavra
 *		ponteiro para a estrutura que esta actualmente em ultimo
 *
 * vai inserir nova estrutura generica no fim e inserir nos dados a palavra
 */
void insereFim( PPALAVRA palavra, PGENERICA ultimo){

	PGENERICA item;

	item = malloc(sizeof(GENERICA));

	ultimo->seg = item;
	item->ant = ultimo;
	item->seg = NULL;

	item->dados = palavra;

	return;
}

/* imprimeDadosTotal
 *
 * recebe
 *		ponteiro para o array de letras
 *
 * vai mandar imprimir todas as listas com elementos
 */
void imprimeDadosTotal(CABECA array_letras[]){

	PGENERICA ptr;
	int i;

	for ( i=0; i<LETRAS; i++){
		if (array_letras[i].primeiro) imprimeDadosLista(array_letras[i].primeiro );
	}

	return;
}

/* imprimeDadosLista
 *
 * recebe
 *		ponteiro para o primeiro elemento da lista
 *
 * vai mandar imprimir todas as listas com elementos
 */
void imprimeDadosLista(PGENERICA p_primeiro){
	
	PGENERICA ptr;
	PPALAVRA p_palavra;

	for ( ptr =p_primeiro; ptr ; ptr = ptr->seg){
		p_palavra = ptr->dados;
		printf("palavra %s, frequencia %d\n", p_palavra->nome, p_palavra->contador);
//		printf("");
//		printf("");
	}



}