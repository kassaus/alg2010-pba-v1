
#define MAX_FICHEIRO 255
#define MAX_BUFFER 4096
#define LETRAS 26
#define DEBUG 1
#define TAMANHO_MINIMO_PALAVRA 9


/*
 * estruturas
 */
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
	int frequencia_letra;		//numero de palavras comešadas pela letra
	int frequencia_maxima;		//frequencia mais alta dentro da lista, para agilizar a impressao dos histogramas
	int maior_palavra;			//tamanho da maior palavra na lista
} CABECA;

typedef CABECA *PCABECA;


//estrutura para passar os valores na impressao
typedef struct s_contadores {
	int frequencia_total;	//frequencia maior 
	int tamanho_maximo_palavra;
} T_CONTADORES;

typedef T_CONTADORES *P_CONTADORES;


void insereFim( PPALAVRA palavra, PGENERICA ultimo);
void insereMeio( PPALAVRA palavra, PGENERICA anterior, PGENERICA seguinte);
void insereInicio( PPALAVRA palavra, PCABECA p_letra );
void procuraLugarNaLista( PPALAVRA palavra, CABECA array_letras[] ) ;
void converteString(char *buffer);
void processaFicheiro (FILE *fp_ficheiro, CABECA *array_letras[]);
void separaPalavras( char *buffer, CABECA array_letras[LETRAS]);
void inserePalavraArray(CABECA *array_letras, void *dados);
int comparaNomeCres(char *nome1, char *nome2);
int comparaFreqCres(int num1,int num2); 
int comparaFreqDecres(int num1,int num2 );
int comparaNomeCres(char *nome1, char *nome2);
int comparaNomeDecres(char *nome1, char *nome2);
void actualizaContadores(PCABECA p_letra, int frequencia_palavra, int tamanho_palavra);
void imprime( CABECA array_letras[] );
void imprimeCabecalho(char *cabecalho_1, char *cbecalho_2);
void imprimeLimite(int numero_caracteres, char limite);
void imprimeLinhaTabela(PGENERICA primeiro,P_CONTADORES contadores);
void imprimeLinhaHistograma(PGENERICA primeiro,P_CONTADORES contadores);
void imprimeDadosTotal(CABECA array_letras[]);
void imprimeDadosLista(PGENERICA p_primeiro);
//void imprimeDadosTotal(CABECA array_letras[]);
//void imprimeDados(PPALAVRA a);





