#if ! defined ( DADOS_ )
#define DADOS_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Dados
*
*  Arquivo gerado:              DADOS.h
*  Letras identificadoras:      DADO
*
*  Nome da base de software:   Jogo de Gamao
*
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	  2.00	  idmv   15/09/2015  Finalizacao
*     1.00    idmv   15/09/2015  Inicio da implementacao
*
*  $ED Descri��o do m�dulo
*     Cria uma estrutura com dois Dado.
*     Destroi uma estrutura com doi Dados.
*     Gera um valor de 1 a 6 para os dados.
*     Cada dado � homog�neo quanto ao tipo dos dados que armazena.
*     Uma estrutura dado armazena DOIS VALORES DE DADO, ou seja, sao
*     dois dados em apenas uma estrutura, isso porque no jogo de gamao,
*     SEMPRE serao jogados dois dados!
***************************************************************************/
 
#if defined( DADOS_OWN )
#define DADOS_EXT
#else
   #define DADOS_EXT extern
#endif



/* Tipo refer�ncia para um dado */

typedef struct DADO_tpDado * DADO_tppDado ; 


/***********************************************************************
*
*  $TC Tipo de dados: DADO Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do dado
*
***********************************************************************/
typedef enum	{
		DADO_tpCondRetOK = 0 ,
		// quando da tudo certo

	    DADO_tpCondRetFaltouMemoria   = 1,
		// quando nao aloca a memoria necessaria
   
		DADO_tpCondRetEstruturaVazia  = 2,
		// quando tenta destruir um dado q n existe
	
		DADO_tpCondRetDadoJaExiste    = 3
		// quando tenta criar um dado que ja existe
     
} DADO_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: DADO  &Criar dado
*
*  $ED Descri��o da fun��o
*     Cria um dado de indice i dentro de um vetor
*
*  $EP Par�metros
*  * vet - vetor de dados
*  indice - indice no qual o dado vai ser criado
*
*  $FV Valor retornado
*     DADO_tpCondRetOK - Se executou corretamente
*     DADO_tpCondRetFaltouMemoria - Se ocorreu falta de memoria
*     DADO_tpCondRetDadoJaExiste - Se ja houver elemento criado no indice dado
*
***********************************************************************/

/* Assertiva de Entrada DADO_CriaDado
*  Existir memoria suficiente para a estrutura DADO_tppDado
*  Para todo vet[indice], vet[indice] == NULL
* 
*  Fim Assertiva de Entrada DADO_CriaDado */

DADO_tpCondRet DADO_CriaDado(DADO_tppDado *  vet, int indice);

/* Assertiva de Saida DADO_CriaDado
*  Memoria foi alocada para vet[indice]
*  vet[indice] != NULL
*  A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_CriaDado */

/***********************************************************************
*
*  $FC Fun��o: DADO  &Destruir dado
*
*  $ED Descri��o da fun��o
*     Destroi um dado de indice i dentro de um vetor
*
*  $EP Par�metros
*  pDado - dado a ser destruido
*
*  $FV Valor retornado
*   DADO_tpCondRetOK - Se executou corretamente
*   DADO_tpCondRetEstruturaVazia - Se o indice dado no vetor for NULL
*
***********************************************************************/

/* Assertiva de Entrada DADO_DestroiDado
*  Tem que haver um dado alocado para ser destruido ( para todo pDado, pDado != NULL)
*
*  Fim Assertiva de Entrada DADO_DestroiDado */

DADO_tpCondRet DADO_DestroiDado (DADO_tppDado  pDado);

/* Assertiva de Saida DADO_DestroiDado
* O dado foi destruido (para todo pDado, pDado = NULL)
* A memoria alocada para pDado tem que ter sido liberada
* A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_DestoiDado */

/***********************************************************************
*
*  $FC Fun��o: DADO  &Gera Valor Dado
*
*  $ED Descri��o da fun��o
*     Gera valor de 1 a 6 de um dado de indice i dentro de um vetor
*
*  $EP Par�metros
*  pDado -  dado a ser excluido
*
*  $FV Valor retornado
*     DADO_tpCondRetEstruturaVazia - Se o dado for igual a null
*     DADO_tpCondRetOK - Se executou corretamente
*	  
*		
***********************************************************************/

/* Assertiva de Entrada DADO_GeraValorDado 
*  Tem que existir um dado criado ( pDado != NULL)
*  pDado->valorDado1 = NULL && pDado->valorDado2 = NULL
*
*  Fim Assertiva de Entrada DADO_GeraValorDado */

DADO_tpCondRet DADO_GeraValorDado (DADO_tppDado  pDado);

/* Assertiva de Saida DADO_GeraValorDado
*  pDado->valorDado1 e pDado->valorDado2 recebem valor aleatorio entre
   1 e 6
*  A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_GeraValorDado */


#undef DADOS_EXT
/********** Fim do m�dulo de defini��o: M�dulo Dados **********/

#else
#endif
