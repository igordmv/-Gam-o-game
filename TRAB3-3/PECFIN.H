#if ! defined( PECFIN_ )
#define PECFIN_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PFN  Pe�as finalizadas
*
*  Arquivo gerado:              PECFIN.h
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      1.00    idmv    20/10/2015  inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa as listas para armazenar as pe�as finalizadas
*     As listas de capturadas s�o estaticas no modulo, s� podem existir duas listas.
*     A estrutura possui uma cabe�a encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( PECFIN_OWN )
#define PECFIN_EXT
#else
#define PECFIN_EXT extern
#endif


#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: PFN Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do tabuleiro
*
***********************************************************************/

   typedef enum {

         PFN_CondRetOK = 0,
               /* Concluiu corretamente */

         PFN_CondRetListaVazia = 1,
               /* A lista n�o cont�m elementos */
		 
		 PFN_CondRetEstruturaNaoExiste = 2,
               /* A estrutura de pe�as finalizadas n�o foi criada */
		 
		 PFN_CondRetFaltouMemoria = 3, 
			   /* Faltou Memoria*/

		 PFN_CondRetJogadorNaoExiste = 4,
			   /* Jogador n�o existe */

		 PFN_CondRetQuantidadeErrada = 5,
			  /*Quantidade de pe�as contadas errada*/
		 
	     PFN_CondRetEstruturaJaExiste = 6,
			   
   } PFN_tpCondRet ;
   
/* Typedef para a estrutura encapsulada */

 typedef struct PFN_tpPecasFinalizadas * PFN_tppPecasFinalizadas ;
 

/***********************************************************************
*
*  $FC Fun��o: PFN  &Criar estrutura de pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura para armazenar as pe�as finalizadas
*	  Ele pode armazenar pe�as de qualquer tipo
*
*  $FV Valor retornado
*     PFN_CondRetOK - Se executou corretamente a cria�ao da estrutura
*	  PFN_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/
 /* Assertivas de Entrada PFN_CriarPecasFinalizadas
*  Ter memoria suficiente para criacao da estrutura de Listas
*  A Estrutura de Listas passada como par�metro n�o existe (pPecasFinalizadas[indice] == NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas,int indice);

/* Assertivas de Saida PFN_CriarPecasFinalizadas
*  A memoria referente a estrutura de lista tem que ser alocada
*  Para todo pPecasFinalizadas[indice] criado, pPecasFinalizadas[indice]->pFinalizadasUm != NULL e pPecasFinalizadas[indice]->pFinalizadasDois != NULL
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_CriarPecasFinalizadas */

/***********************************************************************
*
*  $FC Fun��o: PFN  &Destruir estrutura de pe�as finalizadas
*
*  $ED Descri��o da fun��o
*     Destr�i a estrutura de pe�as finalizadas
*
*  $FV Valor retornado
*     PFN_CondRetOK    - destruiu a estrutura sem problemas
*     PFN_CondRetTabuleiroNaoExiste - estrutura nao foi criada
*
***********************************************************************/

   /* Assertivas de Entrada PFN_DestruirPecasFinalizadas
*  Existir uma estrutura de Listas ja criada
*  A Estrutura de Listas passada como par�metro existe (pPecasFinalizadas[indice] != NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas,int indice);

   /* Assertivas de Saida PFN_DestruirPecasFinalizadas
*  A memoria referente a estrutura de lista tem que ser excluida ( free(pPecasFinalizadas[indice])
*  pPecasFinalizadas tem que ser NULL
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */


/***********************************************************************
*
*  $FC Fun��o: PFN  &Inserir peca
*
*  $ED Descri��o da fun��o
*     insere uma peca na lista correspontente passada como par�metro
*
*  $EP Par�metros
*     jogador    - lista onde a peca sera inserida
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu inserir corretamente
*	  PFN_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     PFN_CondRetJogadorNaoExiste - se a lista passada nao faz parte da estrutura de pecas finalizadas
*     PFN_CondRetEstruturaNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*
***********************************************************************/
   /* Assertivas de Entrada PFN_InserirPecasFinalizadas
*  A Estrutura de Listas passada como par�metro existe (pPecasFinalizadas[indice] != NULL)
*  jogador deve ter valor inteiro de 1 ou 2
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador);

   /* Assertivas de Saida PFN_InserirPecasFinalizadas
*  A lista referente ao jogador tem que ser incrementada. 
*  se for jogador 1, a lista sera um. se for jogador 2, sera a lista dois.
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */


/***********************************************************************
*
*  $FC Fun��o: PFN  &Contar peca finalizada
*
*  $ED Descri��o da fun��o
*		conta quantas pe�as j� foram finalizadas e retorna como par�metro
*
*  $EP Par�metros
*     jogador    - lista de onde a peca sera retirada
*	  finalizadas - retorno por refer�ncia de quantas pe�as h� na lista
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu retirar corretamente
*     PFN_CondRetJogadorNaoExiste - se o jogador passado nao faz parte do jogo
*     PFN_CondRetEstruturaNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*     PFN_CondRetListaVazia       - se nao houver pecas na lista
*
***********************************************************************/
   /* Assertivas de Entrada PFN_ContarPecaFinalizada
*  A Estrutura de Listas passada como par�metro existe (pPecasFinalizadas[indice] != NULL)
*  jogador deve ter valor inteiro de 1 ou 2
*  *finalizadas deve ser um ponteiro valido
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_ContarPecasFinalizadas */

   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador, int *finalizadas);
   
   /* Assertivas de Saida PFN_ContarPecasFinalizadas
*  A lista referente ao jogador tem que ser percorrida incrementando o ponteiro finalizadas. 
*  o ponteiro finalizadas deve conter o numero de pecas referentes a lista referente ao jogador.
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */



#undef PFIN_EXT

   /********** Fim do m�dulo de defini��o: PFN  pe�as finalizadas **********/

#else
#endif