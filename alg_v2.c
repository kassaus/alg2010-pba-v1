/*esquema trabalho goritmia
grupo PBA
*/


/*
versao de introducao à bruta


*/



// estruturas

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FICHEIRO 255
#define MAX_BUFFER 4096
#define LETRAS 26
#define DEBUG 1



typedef struct s_palavra {
		char *nome;
		int contador;
} PALAVRA;

typedef PALAVRA *PPALAVRA;

typedef struct s_generica {
	struct s_generica *seg;		//apontador para a estrutura seguinte
	struct s_generica *ant;		//apontador para a estrutura anterior
	void *dados;				//apontador para a parte de dados, neste caso  a estrutura PALAVRA
} GENERICA;

typedef GENERICA *PGENERICA;

typedef struct s_cabeca {
	PGENERICA *primeiro;		//apontador para o primeiro da lista
	int (*ordenacao)() ;		//apontador para a funcao de ordenacao em vigor

	//talvez fosse bom colocarmos depois aqui mais alguma coisa, estilo contadores totais para nos ajudar nas contas
	
	//PPALAVRA *ultimo;
} CABECA;

typedef CABECA *PCABECA;

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


void imprimeDadosLista(PGENERICA p_primeiro);
void imprimeDadosTotal(CABECA array_letras[]);
void insereFim( PPALAVRA palavra, PGENERICA ultimo);
void insereMeio( PPALAVRA palavra, PGENERICA anterior, PGENERICA seguinte);
void insereInicio( PPALAVRA palavra, PCABECA p_letra );

void procuraLugarNaLista( PPALAVRA palavra, CABECA array_letras[] ) ;



void processaFicheiro (FILE *fp_ficheiro, CABECA array_letras[]);
void separaPalavras( char *buffer, CABECA array_letras[LETRAS]);
void inserePalavraArray(CABECA *array_letras, void *dados);
void imprimeDados(PPALAVRA a);
void imprime(PGENERICA cabeca, void (*print));
int comparaNomeCres(char *nome1, char *nome2);
int comparaFreqCres(int num1,int num2); 
int comparaFreqDecres(int num1,int num2 );
int comparaNomeCres(char *nome1, char *nome2);
int comparaNomeDecres(char *nome1, char *nome2);


/* main verificar se recebe argumento se nao receber, pedir ficheiro

 *tentar abrir ficheiro em "r" se nao conseguir, pedir de novo ou 0 para sair

 *processaFicheiro(FILE *fp_ficheiro, )

 */


int main(int argc, char *argv[]){

	CABECA array_letras[LETRAS];
	FILE *fp_ficheiro;
	char ficheiro[MAX_FICHEIRO];


 
	memset(array_letras, 0, sizeof(CABECA) * LETRAS);
	array_letras->ordenacao = NULL;

	

	if (argc==2) strcpy(ficheiro, argv[1]);	// se receber argumento

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

/*
PGENERICA pesquisa(PGENERICA cabeca, int (*compara)(), void *valor)
{
	PGENERICA ptr;
	for(ptr=cabeca; ptr; ptr=ptr->prox)
		if((*compara)(ptr->dados, valor))
			return ptr;
	return NULL;
}
*/

void converteString(char *buffer);


/* funcao de comparacao por numero crescente recebe os valores a e b para comparar
 *devolve -1 se menor, 0 se igual e 1 se maior
 */
int comparaFreqCres(int num1,int num2 ) {
//.....
}

/* funcao de comparacao por numero decrescente recebe os valores a e b para comparar
 *devolve 1 se menor, 0 se igual e -1 se maior
 */
int comparaFreqDecres(int num1,int num2 ) {
//.....
}


/* funcao de comparacao por nome crescente recebe os valores a e b para comparar
 *devolve -1 se menor, 0 se igual e 1 se maior
 */
int comparaNomeCres(char *nome1, char *nome2) {
//.....
}

/* funcao de comparacao por nome decrescente recebe os valores a e b para comparar
 *devolve 1 se menor, 0 se igual e -1 se maior
 */
int comparaNomeDecres(char *nome1, char *nome2) {
//.....
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


	while ( fgets(buffer, MAX_BUFFER, fp_ficheiro)!= NULL ) {  //enquanto existirem linhas	
		converteString(buffer);						//converte os caracteres em ascii
		if (DEBUG) printf("linha %d ", linha++);
		separaPalavras(buffer, array_letras);		//retira as palavras da linha
	}

	if (DEBUG) imprimeDadosTotal(array_letras);
}

/* separaPalavras
 *
 * recebe a string a processar e o array de letras para introducao
 * procura pela letra, quando encontra letra procura por "nao letra"
 * 
 */

void separaPalavras( char *buffer, CABECA array_letras[LETRAS]) {

	int i=0, j=0, fim_linha=0;
	//char palavra[MAX_PALAVRA];
	PPALAVRA palavra;
	int teste;

	

	do { 
		if(buffer[i] == '\n' && buffer[i] == '\0')		
			break;

		while ( (buffer[i]==' ' && buffer[i]!='\0' && buffer[i]!='\n' && buffer[i]=='.') && i<MAX_BUFFER  )
			i++;  //varre ate encontrar letra          
		
		
		// vector_palavras[count++] = &buffer[i];

		j = i;		//guarda a posicao do inicio da palavra

		while (buffer[i]!=' ' && i<MAX_BUFFER && buffer[i]!='\0' && buffer[i]!='\n' && buffer[i]!='.' )
			i++; 

		if (i>=MAX_BUFFER)
			break;


		if (buffer[i] !='\0'){
				buffer[i] = '\0';				
		}
		else {
			fim_linha = 1;
		}
		i++;

		if ( (i-j-1) >1){	//se a string for "nula" tem apenas o \0

			if (DEBUG) printf("Entrou na criacao da estrutura palavra\n");
			palavra = malloc( sizeof(PPALAVRA) );
			palavra->nome = malloc(i-j-1);		//*******ver melhor, sera apenas i-j?????
			strcpy(palavra->nome, buffer+j );
			palavra->contador =1;
//			teste = buffer[0]-'a';
//			inserePalavraArray( &array_letras[buffer[0]-'a'], palavra);

			insereInicio( palavra, &array_letras[buffer[j]-'a']  );


			if (DEBUG) printf("palavra x%sx\n", palavra->nome);

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

/* insereArrayLetras

recebe ponteiro para a estrutura palavra

e o array de letras

verifica a primeira letra da palavra

insere no fim da lista respectiva


*/



/* inserePalavraArray
 * recebe o ponteiro do array de estruturas genericas
 * verifica a primeira letra da palavra
 * insere a palavra no sitio certo
 */
/*
void inserePalavraArray(CABECA array_letras, void *dados){

	PGENERICA item, ptr;
	PPALAVRA palavra;

	item = malloc(sizeof(PGENERICA));
	palavra = (PPALAVRA) dados;


	item->seg = array_letras->primeiro;
	item->ant = NULL;
	item->dados = dados;
	array_letras->primeiro = item;
}

void imprime(PGENERICA cabeca, void (*print)()){
PGENERICA ptr;
for(ptr = cabeca; ptr; ptr = ptr->seg)
(*print)(ptr->dados);
}

void imprimeDados(PPALAVRA a){
	printf("%s", a->nome);
}

*/



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
void procuraLugarNaLista( PPALAVRA palavra, CABECA array_letras[] ) {

//	int letra= palavra->nome[0];	// a primeira letra da palavra, para sabermos em que lista a colocar
	PGENERICA ptr;						// ponteiro para percorrer a lista generica
	CABECA letra;

	//colocamos o ptr para o inicio da lista generica na letra certa
	letra = array_letras[ palavra->nome[0]-'a' ];
	ptr = letra.primeiro;


	if (!ptr) insereInicio(palavra, &letra);		//se a lista estiver vazia

	
	
	// procurar pelo lugar certo

	/*
	se ordenado por numero crescente
		se for igual, contador ++
		se for menor, introduzir antes
		se for maior, seguir para o proximo no

	se ordenado por numero decrescente
		se for igual, contador++
		se for maior, introduzir antes
		se for menor, continuar para o proximo no

	se ordenado por frequencia
		procurar pela palavra certa com um algoritmo de pesquisa linear, pois as palavras nao estao em ordem nenhuma
		se nao encontrarmos a palavra
			se ordenado por frequencia crescente, colocar no inicio
			se ordenado por frequencia decrescente, colocar no fim
		se encontrarmos, incrementar a frequencia e verificar se existem alteracoes na ordem das frequencias
			se sim, retirar a palavra em questao e mandar colocar de novo




	*/
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
		if (array_letras[i].primeiro) imprimeDadosLista(array_letras[i].primeiro);
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

	for ( ptr =p_primeiro; ptr->seg ; ptr = ptr->seg){
		p_palavra = ptr->dados;
		printf("palavra %s, frequencia %d\n", p_palavra->nome, p_palavra->contador);
//		printf("");
//		printf("");
	}



}