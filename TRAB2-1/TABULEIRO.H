#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira

*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      3.00    idmv   22/09/2015   finalizacao completa
*      2.00    idmv   20/09/2015   validacao final
*      1.00    idmv   19/09/2015   inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa um tabuleiro de gamao.
*     O tabuleiro possue uma cabe�a encapsulando o seu estado.
*     � possivel criar um tabuleiro, deletar um tabuleiro,
*     inserir peca em um tabuleiro, retirar peca de um tabuleiro,
*     mover peca de um tabuleiro e contar pecas de um tabuleiro.
*
*     Observacao importante: O modulo do tabuleiro nao se importa
*     com as regras do gamao, o modulo do jogo apenas chamara as 
*	  fun��es do tabuleiro caso essas regras sejam previamente 
*	  testadas, por exemplo: o jogo avaliar� se o jogador poder�
*	  mover a pe�a para uma casa X, caso ele puder ele chama o 
*	  modulo tabuleiro.
***************************************************************************/

#if defined( TABULEIRO_OWN )
#define TABULEIRO_EXT
#else
#define TABULEIRO_EXT extern
#endif


#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do tabuleiro
*
***********************************************************************/

   typedef enum {

        TAB_CondRetOK = 0,
               /* Concluiu corretamente */   

        TAB_CondRetCasaVazia = 1 ,
               /* A Casa n�o cont�m elementos */

		TAB_CondRetFaltouMemoria =2, 
	       /* Faltou Memoria*/
	   
	   	TAB_CondRetErroNaEstrutura =3,
	       /* Erro na estrutura do tabuleiro*/
			   
        TAB_CondRetTabuleiroNaoExiste =4 ,
              /* O tabuleiro n�o foi criado */

        TAB_CondRetCasaNaoExiste = 5,
	      /* Casa buscada nao existe*/

		TAB_CondRetTabuleiroJaExiste = 6
	      /* Tabuleiro ja existe */
   
   } TAB_tpCondRet ;



   /***estrutura encapsulada***/

typedef struct TAB_tpTabuleiro * tppTabuleiro;


	
/***********************************************************************
*
*  $FC Fun��o: TAB  &Cria Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria uma tabuleiro de gamao, com 24 casas. 
*     Ele pode armazenar pe�as de qualquer tipo
*
*  $EP Par�metros
*     * pTabuleiro - ponteiro para tabuleiro passado como referencia
*     indice - indice do tabuleiro a ser criado.
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente a cria�ao do tabuleiro
*     TAB_CondRetFaltouMemoria - Se houve algum problema de memoria
*	  TAB_CondRetTabuleiroJaExiste  - tabuleiro ja foi criado
***********************************************************************/

/* Assertivas de Entrada TAB_CriaTabuleiro
*  Ter memoria suficiente para criacao da estrutura de tabuleiro
*  O tabuleiro passado como par�metro n�o existe (pTabuleiro[indice] == NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada TAB_CriaTabuleiro */

	TAB_tpCondRet TAB_CriaTabuleiro( tppTabuleiro * pTabuleiro,int indice);

/* Assertivas de Saida TAB_CriaTabuleiro
*  A memoria referente a estrutura do tabuleiro tem que ser alocada
*  Para todo pTabuleiro[indice] criado, pTabuleiro[indice]->pCasaCorr != NULL e pTabuleiro[indice]->pBasedoTabuleiro != NULL
*  A funcao retornara um TAB_tpCondRet
*
*  Fim Assertiva de Saida TAB_criaTabuleiro /

/***********************************************************************
*
*  $FC Fun��o: TAB  &Destroi tabuleiro
*
*  $ED Descri��o da fun��o
*     Destr�i o tabuleiro criado.
*
*  $EP Par�metros
*     * pTabuleiro - vetor de tabuleiro passado como referencia
*     indice - indice do tabuleiro a ser destruido
*	  
*
*  $FV Valor retornado
*     TAB_CondRetOK - destruiu
*     TAB_CondRetTabuleiroNaoExiste - tabuleiro nao foi criado
*
***********************************************************************/

/* Assertivas de entrada TAB_DestroiTabuleiro
*  Existir um tabuleiro ja criado (pTabuleiro[indice] != NULL)
*  Valem as assertivas estruturais de LDECC.
* 
*  Fim Assertivas de Entrada TAB_DestroiTabuleiro */

	TAB_tpCondRet TAB_DestroiTabuleiro(tppTabuleiro * pTabuleiro,int indice);

/*  Assertiva de Saida TAB_DestroiTabuleiro
*   O tabuleiro deve ser destruido (para todo pTabuleiro[indice], 
    pTabuleiro[�ndice]->pCasaCorr = NULL e pTabuleiro[�ndice]->pBasedoTabuleiro = NULL)
*	Para todo pTabuleiro, pTabuleiro = NULL
*   A memoria deve ser liberada para todo pTabuleiro
*   A funcao retorna um TAB_tpCondRet
*
*   Fim Assertiva de Saida TAB_DestroiTabuleiro */
	
/***********************************************************************
*
*  $FC Fun��o: TAB  &Quantidade de Pecas Casa
*
*  $ED Descri��o da fun��o
*     conta o numero de pecas na casa e retorna o valor por referencia
*
*  $EP Par�metros
*     pTabuleiro - Tabuleiro a ser trabalhado
*     casa - casa onde sera contado o nmr de pecas
*     *qtd  - quatidade de pe�as na casa
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu contar corretamente
*     TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*     TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

/* Assertivas de Entrada TAB_QuantidadePecasCasa
*  Existir um tabuleiro ja criado
*  Existir a casa que se deseja acessar (pTabuleiro != NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada TAB_QuantidadePecasCasa */

    TAB_tpCondRet TAB_QuantidadePecasCasa(tppTabuleiro pTabuleiro, int casa, int *qtd);

/* Assertiva de Saida TAB_QuantidadePecasCasa
  O endere�o de qtd possui a quantidade de pe�as na casa passada (entre 0 e 12)
*  A funcao retorna um TAB_tpCondRet
*
*  Fim Assertiva de Saida TAB_QuantidadePecaCasa */

/***********************************************************************
*
*  $FC Fun��o: TAB  &Retirar peca
*
*  $ED Descri��o da fun��o
*     retira uma peca na casa do tabuleiro passada como parametroe retorna por referencia
*
*  $EP Par�metros
*     pTabuleiro - Tabuleiro a ser trabalhado
*     ** pPeca - ponteiro para a peca a ser recebida
*     casa - casa onde a peca sera retirada
*
*  $FV Valor retornado
*     TAB_CondRetOK - se conseguiu inserir corretamente
*     TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*     TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

/* Assertivas de Entrada TAB_RetiraPeca
*  Existir um tabuleiro ja criado
*  Existir a casa que se deseja acessar (pTabuleiro[�ndice] != NULL)
*  Existir uma pe�a na casa acessada.
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertiva de Entrada TAB_RetiraPeca */

    TAB_tpCondRet TAB_RetiraPeca(tppTabuleiro pTabuleiro, void **peca, int casa);
	
/* Assertiva de Saida TAB_RetiraPeca
*  Retirou a pe�a no topo da casa indicada
  O endere�o de peca possui a peca que foi retirada
*  A funcao retornara um TAB_tpCondRet
*
*  Fim Assertiva de Saida TAB_RetiraPeca */

/***********************************************************************
*
*  $FC Fun��o: TAB  &Insere Peca
*
*  $ED Descri��o da fun��o
*     insere uma peca na casa do tabuleiro passada como parametro 
*
*  $EP Par�metros
*     pTabuleiro - Tabuleiro a ser trabalhado
*   * pPeca - ponteiro para a pe�a a ser inserida
*     casa - casa onde a peca sera inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - se conseguiu inserir corretamente
*     TAB_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste  - se o tabuleiro nao foi criado
*     TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

/* Assertivas de Entrada TAB_InserePeca
*  Existir Tabuleiro ja Criado
*  Casa tem que ser entre 0 e 23
*  Existir a casa onde ser� inserida a pe�a (pTabuleiro[�ndice] != NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertiva de Entrada TAB_InserePeca  */

	TAB_tpCondRet TAB_InserePeca(tppTabuleiro pTabuleiro, void *pPeca, int casa);

/* Assertiva de Saida TAB_InserePeca
*  Inseriu a pe�a no topo da casa indicada
*  A funcao retornara um TAB_tpCondRet
*
*  Fim Assertiva de Saida TAB_InserePeca */

/***********************************************************************
*
*  $FC Fun��o: TAB  &Mover peca
*
*  $ED Descri��o da fun��o
*     move uma peca na casa do tabuleiro para outra casa
*
*  $EP Par�metros
*     pTabuleiro - Tabuleiro a ser modificado
*     casa    - casa onde a peca sera retirada
*     qtd_movimentos  - numero de movimentos a andar com a pe�a
*
*  $FV Valor retornado
*     TAB_CondRetOK - se conseguiu mover corretamente
*     TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste - se o tabuleiro nao foi criado
*     TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

/* Assertiva de Entrada TAB_MovePeca
*  Existir um tabuleiro ja criado
*  Existir uma pe�a na casa fornecida como par�metro
*  Existir pelo menos uma casa no tabuleiro para qual essa pe�a pode se mover.
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertiva de Entrada TAB_MovePeca */

    TAB_tpCondRet TAB_MovePeca(tppTabuleiro pTabuleiro, int casa, int qtd_movimentos);

/* Assertiva de Saida TAB_MovePeca
*  Valem as assetivas de saida das fun��es TAB_RetiraPeca e TAB_InserePeca
*  A funcao retornara um TAB_tpCondRet
*
*  Fim Assertiva de Saida TAB_MovePeca */


#undef TABULEIRO_EXT


/*********** Fim do m�dulo de defini��o: TAB Modulo Tabuleiro **********/


#else
#endif
