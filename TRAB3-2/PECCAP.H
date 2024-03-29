#if ! defined( PECCAP_ )
#define PECCAP_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PCAP  Pe�as Capturadas
*
*  Arquivo gerado:              PECCAP.h
*  Letras identificadoras:      PCAP
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: rrvs - Rodrigo Rangel Vargas dos Santos

*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      2.00    rrvs   22/09/2015   finalizacao
*      1.00    rrvs   17/10/2015   inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa um vetor de pecas capturadas em um jogo de gamao.
*     O tabuleiro possue uma cabe�a encapsulando o seu estado.
*     � possivel criar um tabuleiro, deletar um tabuleiro,
*     inserir peca em um tabuleiro, retirar peca de um tabuleiro,
*     mover peca de um tabuleiro e contar pecas de um tabuleiro.
***************************************************************************/



#if defined( PCAP_OWN )
#define PCAP_EXT
#else
#define PCAP_EXT extern
#endif

#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: PCAP Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do modulo Pe�as Capturadas
*
***********************************************************************/

typedef enum {

	PCAP_CondRetOK = 0,
	/* Concluiu corretamente */

	PCAP_CondRetListaVazia = 1,
	/* Jogador nao possui pecas capturadas */

	PCAP_CondRetFaltouMemoria = 2,
	/* Faltou Memoria*/

	PCAP_CondRetQuantidadeErrada = 3,
	/* Quantidade errada de pecas */

	PCAP_CondRetEstruturaNaoExiste = 4,
	/* A estrutura n�o foi criada */

	PCAP_CondRetJogadorNaoExiste = 5,
	/* O jogador passado como parametro nao existe */

	PCAP_CondRetEstruturaJaExiste = 6
	/* Estrutura ja existe */

} PCAP_tpCondRet;



/***estrutura encapsulada***/

typedef struct PCAP_tpPecCap * tppPecCap;



/***********************************************************************
*
*  $FC Fun��o: PCAP  &Cria Pe�as Capturadas
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura PecCap, que ir� armazenar as pe�as 
*     capturadas ao longo de uma partida de gamao.
*     Pode armazenar pe�as de qualquer tipo.
*
*  $EP Par�metros
*     * pPecCap - vetor de  estruturas Pe�as Capturadas passado como referencia
*     indice - indice da estrutura a ser criada.
*
*  $FV Valor retornado
*     PCAP_CondRetOK - Se executou corretamente a cria�ao da estrutura
*     PCAP_CondRetFaltouMemoria - Se houve algum problema de memoria
*	  PCAP_CondRetEstruturaJaExiste  - Estrutura ja foi criada
*
***********************************************************************/

/* Assertivas de Entrada PCAP_CriaPecCap
*  Ter memoria suficiente para criacao da estrutura Pe�as Capturadas
*  A estrutura passado como par�metro n�o existe (pPecCap[indice] == NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PCAP_CriaPecCap */

	PCAP_tpCondRet PCAP_CriaPecCap(tppPecCap * pPecCap, int indice);

	/* Assertivas de Saida PCAP_CriaPecCap
*  A memoria referente a estrutura Pe�as Capturadas tem que ser alocada
*  Para todo pPecCap[indice] criado, pPecCap[indice]->PecasCapJ1 != NULL e pPecCap[indice]->PecasCapJ2 != NULL
*  A funcao retornara um PCAP_tpCondRet
*
*  Fim Assertiva de Saida PCAP_CriaPecCap /

/***********************************************************************
*
*  $FC Fun��o: PCAP  &Destroi Pe�as Capturadas
*
*  $ED Descri��o da fun��o
*     Destr�i a estrutura Pe�as Capturadas criada.
*
*  $EP Par�metros
*     * pPecCap - vetor de  estruturas Pe�as Capturadas passado como referencia
*     indice - indice da estrutura a ser destruida
*
*
*  $FV Valor retornado
*     PCAP_CondRetOK - destruiu
*     PCAP_CondRetEstruturaNaoExiste - Estrutura nao foi criada
*
***********************************************************************/

/* Assertivas de entrada PCAP_DestroiPecasCap
*  Existir uma estrutura ja criada
*  A Estrutura de Listas passada como par�metro existe (pPecCap[indice] != NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PCAP_DestroiPecasCap */

	PCAP_tpCondRet PCAP_DestroiPecasCap(tppPecCap * pPecCap, int indice);

	/*  Assertiva de Saida PCAP_DestroiPecasCap
	*	pPecCap deve ser = NULL
	*   A memoria referente a estrutura deve ser liberada (free(pPecCap[indice]))
	*   A funcao retorna um PCAP_tpCondRet
	*
	*   Fim Assertiva de Saida PCAP_DestroiPecasCap */

/***********************************************************************
*
*  $FC Fun��o: PCAP  &Quantidade de Pecas Capturadas
*
*  $ED Descri��o da fun��o
*     conta o numero de pecas capturadas do jogador desejado
*
*  $EP Par�metros
*     pPecCap - Estrutura guardando os dados do jogo atual
*     jogador - jogador do qual se deseja contar as pe�as capturadas
*     *qtd  - quatidade de pe�as capturadas
*
*  $FV Valor retornado
*     PCAP_CondRetOK - se conseguiu contar corretamente
*     PCAP_CondRetEstruturaNaoExiste - se a estrutura nao foi criada
*     PCAP_CondRetJogadorNaoExiste - se o jogador passado como parametro nao existe
*
***********************************************************************/

/* Assertivas de Entrada PCAP_QuantidadePecasCap
*  A estrutura passada como parametro existe (pPecCap[indice] != NULL)
*  Jogador deve ser valido (jogador == 1 ou jogador == 2)
*  *qtd deve ser um ponteiro valido
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PCAP_QuantidadePecasCap */

    PCAP_tpCondRet PCAP_QuantidadePecasCap(tppPecCap pPecCap, int jogador, int *qtd);

/* Assertiva de Saida PCAP_QuantidadePecasCap
*  o ponteiro qtd deve conter o numero de pecas referentes a lista referente ao jogador.
*  A funcao retorna um PCAP_tpCondRet
*
*  Fim Assertiva de Saida PCAP_QuantidadePecasCap */

/***********************************************************************
*
*  $FC Fun��o: PCAP  &Retirar peca
*
*  $ED Descri��o da fun��o
*     retira uma peca capturada da lista do jogador passado como referencia
*
*  $EP Par�metros
*     pPecCap - Estrutura a ser trabalhada
*     ** pPeca - ponteiro para a peca a ser recebida
*     jogador - jogador que ira retiar a peca
*
*  $FV Valor retornado
*     PCAP_CondRetOK - se conseguiu inserir corretamente
*     PCAP_CondRetListaVazia - se nao houverem pecas capturadas do jogador indicado
*     PCAP_CondRetEstruturaNaoExiste  - se a estrutura nao foi criada
*     PCAP_CondRetJogadorNaoExiste - se o jogador passado como parametro nao existe
*
***********************************************************************/

/* Assertivas de Entrada PCAP_RetiraPeca
*  A estrutura passada como parametro existe (pPecCap[indice] != NULL)
*  Existir uma pe�a a ser retirada.
*  Jogador deve ser valido (jogador == 1 ou jogador == 2)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertiva de Entrada PCAP_RetiraPeca */

    PCAP_tpCondRet PCAP_RetiraPeca(tppPecCap pPecCap, void **peca, int jogador);
	
/* Assertiva de Saida PCAP_RetiraPeca
*  Retirou a pe�a da lista referente ao jogador indicado
*  O endere�o de peca possui a peca que foi retirada
*  A funcao retornara um PCAP_tpCondRet
*
*  Fim Assertiva de Saida PCAP_RetiraPeca */

/***********************************************************************
*
*  $FC Fun��o: TAB  &Insere Peca
*
*  $ED Descri��o da fun��o
*     insere uma peca na casa do tabuleiro passada como parametro 
*
*  $EP Par�metros
*     pTabuleiro - Tabuleiro a ser trabalhado
*     *peca - ponteiro para a pe�a a ser inserida
*     casa - casa onde a peca sera inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - se conseguiu inserir corretamente
*     TAB_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste  - se o tabuleiro nao foi criado
*     PCAP_CondRetJogadorNaoExiste - se o jogador passado como parametro nao existe
*
***********************************************************************/

/* Assertivas de Entrada PCAP_InserePeca
*  A estrutura passada como parametro existe (pPecCap[indice] != NULL)
*  Jogador deve ser valido (jogador == 1 ou jogador == 2)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertiva de Entrada PCAP_InserePeca  */

	PCAP_tpCondRet PCAP_InserePeca(tppPecCap pPecCap, int jogador, void * peca);

/* Assertiva de Saida PCAP_InserePeca
*  pPecCap->QtdJ1 ou pPecCap->QtdJ2 sera incrementado, dependendo do jogador passado como parametro
*  A funcao retornara um PCAP_tpCondRet
*  Fim Assertiva de Saida PCAP_InserePeca */


#undef PCAP_EXT


/*********** Fim do m�dulo de defini��o: PCAP Modulo Pe�as Capturadas **********/


#else
#endif
