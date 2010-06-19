


//enumerado para definicao do horario da sessao
typedef enum e_sessao { manha=1, tarde, noite} T_SESSAO; 

//enumerado para definição do tipo de identificação
typedef enum e_identificacao {bi=1, ci, passaporte} T_IDENT;


//estrutura tipo de id
typedef struct s_id {
	int int_id;			//id de referencia
	void *ponteiro_id;	//apontador para a estrutura referida 
} T_ID;


//estrutura tipo de sala
typedef struct s_sala {
	int id_sala;		//id da sala, sequencial a partir de 1
	char *nome_sala;	//apontador para nome da sala
	char *desc_sala;	//apontador para a descricao da sala
	int filas;			//numero de filas na sala
	int lugares;		//numero de lugares por fila
} T_SALA;


//estrutura tipo de data
typedef struct s_data {
	int dia;
	int mes;
	int ano;
} T_DATA;


//estrutura tipo de espectaculo
typedef struct s_espectaculo {	
	int id_espectaculo;			//id do espectaculo, sequencial a partir de 1
	char *nome_espectaculo;		//apontador para o nome do espectaculo
	char *desc_espectaculo;		//apontador para a descricao do espectaculo
	T_DATA data_inicial;		//data de inicio das exibicoes
	T_DATA data_final;			//data final das exibicoes
	T_SESSAO sessao;			//enumerado manha=1, tarde, noite
} T_ESPECTACULO;



//estrutura tipo de exibicao
typedef struct s_exibicao {
	int id_exibicao;			//id da exibicao
	T_ID id_espectaculo;		//numero de id e ponteiro para espectaculo
	T_ID id_sala;				//numero de id e ponteiro para sala
	T_ID id_ocupacao;			//numero de id e ponteiro para ocupacao

} T_EXIBICAO;


typedef struct s_ocupacao {	//estrutura tipo de ocupacao
	int id_ocupacao;		//index da ocupacao
	int (*assento)[];		//apontador para o array com 0 se livre ou um id se ocupado 
	int lugares_total;		//numero de lugares total, calculado na definicao da estrutura
	int lugares_reservados;	//numero de lugares reservados, para facilitar calculos pedidos
} T_OCUPACAO;


//estrutura tipo de lugar
typedef struct s_lugar {	
	int fila;				//numero de fila
	int cadeira;			//numero da cadeira na fila
} T_LUGAR;

typedef struct s_reserva {	//estrutura tipo de reserva
	int id_reserva;			//index da reserva

//	int id_pessoa;
//	P_PESSOA p_pessoa;
	T_ID id_pessoa;			//numero de id e ponteiro para pessoa
	
//	int id_exibicao;
//	P_EXIBICAO p_exibicao;
	T_ID id_exibicao;		//numero de id e ponteiro para exibicao
	
	T_LUGAR lugar;			//assento no formato fila e cadeira
} T_RESERVA;

typedef struct pessoa{
	int id_pessoa;			//id da pessoa
	char *nome_pessoa;		//Apontador para o nome da pessoa
	T_IDENT identificacao; 	//Identificação do cliente
	//T_CONTACTO contacto;	//Tipo de contacto

	} T_PESSOA;




typedef T_ESPECTACULO *P_ESPECTACULO;
typedef T_SALA *P_SALA;
typedef T_RESERVA *P_RESERVA;
typedef T_OCUPACAO *P_OCUPACAO;
typedef T_EXIBICAO *P_EXIBICAO;
typedef T_PESSOA *P_PESSOA;


/*
 *Declarações das funções
 */
void imprimeCabecalho(char *str);
void imprimeMenu(char **vct_menu, int tamanho, int escolha);
void subMenu(int escolha_menu, int escolha_sub_menu);
void menu(void);
void leEspectador();
void leString(char* str, char* txt,int tam);
float leFloat(char* txt);
unsigned leUnsigned(char* txt);
unsigned short leUnsignedShort(char* txt);
unsigned leEnum(char* txt, unsigned min, unsigned max);