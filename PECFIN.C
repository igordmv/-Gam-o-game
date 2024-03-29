/***************************************************************************
*
*  $MCD M�dulo de implementa��o: PFN  Pe�as finalizadas
*
*  Arquivo gerado:              PECFIN.c
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      1.00    idm    20/10/2015  inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*      Implementa as listas para armazenar as pe�as finalizadas
*      As listas de Finalizadas s�o estaticas no modulo e s� podem existir duas listas.
*      A estrutura possui uma cabe�a encapsulando o seu estado.
*
***************************************************************************/
#define PECFIN_OWN
#include "PECFIN.H"
#undef PECFIN_OWN
#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: PFN Descritor das pe�as finalizadas
*
*
***********************************************************************/

   typedef struct Pecas_Finalizadas {

	   LIS_tppLista pFinalizadasUm;
	   /* Ponteiro para a cabeca da primeira lista de Finalizadas */

	   LIS_tppLista pFinalizadasDois;
	   /* Ponteiro para a cabeca da segunda lista de Finalizadas */

   } PFN_tpPecasFinalizadas;

   
/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   
   void DestruirPecasFinalizadas(void * pValor);


/***************************************************************************
*
*  Fun��o: PFN  &Criar lista de pe�as finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tpPecasFinalizadas ** pPecasFinalizadas, int indice){
	   
	   if (pPecasFinalizadas[indice] != NULL)
		   return PFN_CondRetEstruturaJaExiste;

	   pPecasFinalizadas[indice] = (PFN_tpPecasFinalizadas *)malloc(sizeof(PFN_tpPecasFinalizadas ));
	   if (pPecasFinalizadas[indice] == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas[indice]->pFinalizadasUm = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas[indice]->pFinalizadasUm == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas[indice]->pFinalizadasDois = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas[indice]->pFinalizadasDois == NULL)
		   return PFN_CondRetFaltouMemoria;


	   return PFN_CondRetOK;

   } /* Fim fun��o: PFN  &Criar estrutura das listas de finalizadas */


/***************************************************************************
*
*  Fun��o: PFN  &Destruir estrutura que cont�m lista das pe�as Finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tpPecasFinalizadas ** pPecasFinalizadas, int indice){

	   if (pPecasFinalizadas == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }
	   if ( pPecasFinalizadas[indice] == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }

	   LIS_DestruirLista(pPecasFinalizadas[indice]->pFinalizadasUm);

	   LIS_DestruirLista(pPecasFinalizadas[indice]->pFinalizadasDois);
	   
	   free(pPecasFinalizadas[indice]);
	   pPecasFinalizadas[indice]->pFinalizadasUm = NULL;
	   pPecasFinalizadas[indice]->pFinalizadasDois = NULL;
	   pPecasFinalizadas[indice] = NULL;
	   
	   return PFN_CondRetOK;
   
   } /* Fim fun��o: PFN  &Destruir estrutura de pe�as Finalizadas */


/***************************************************************************
*
*  Fun��o: PFN  &Inserir peca finalizada
*
****************************************************************************/

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tpPecasFinalizadas * pPecasFinalizadas, int jogador){

	   LIS_tpCondRet CondRet;
	   
	   if (pPecasFinalizadas == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }
	   if (jogador != 1 && jogador != 2)
	   {
		   return PFN_CondRetJogadorNaoExiste;
	   }   
	   if (jogador == 1 )
	   {
			CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasUm, NULL);
	   }
	   else
	   {
		   CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasDois, NULL);
	   }
	   if (CondRet != LIS_CondRetOK) // caso nao conseguiu inserir
	   {
		   return PFN_CondRetFaltouMemoria;
	   }
	   return PFN_CondRetOK;

   } /* Fim fun��o: PFN  &inserir peca finalizada*/

   
/***************************************************************************
*
*  Fun��o: PFN  &Contar peca finalizada
*  
***************************************************************************/
   
   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tpPecasFinalizadas * pPecasFinalizadas, int jogador, int *finalizadas){
	   int verificador = 0;
	   LIS_tpCondRet CondRet;
	   CondRet = LIS_CondRetOK;
	   
	   *finalizadas = 0;



	   if (pPecasFinalizadas == NULL)
		   return PFN_CondRetEstruturaNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PFN_CondRetJogadorNaoExiste;
	   	   
	   if (jogador == 1 ){
		  
		  IrInicioLista(pPecasFinalizadas->pFinalizadasUm);
		  
		 	  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente(pPecasFinalizadas->pFinalizadasUm, 1);
				if (CondRet == 1 && verificador == 0)
				{
					return PFN_CondRetListaVazia;
				}
				verificador++;
				(*finalizadas)++;
			  }		
	   }
	   else{
		  
			IrInicioLista(pPecasFinalizadas->pFinalizadasDois);
		  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente(pPecasFinalizadas->pFinalizadasDois, 1);
				if (CondRet == 1 && verificador == 0)
				{
					return PFN_CondRetListaVazia;
				}
			    verificador++;
				(*finalizadas)++;
			  }		
	   }


	   return PFN_CondRetOK;

   } /* Fim fun��o: PFN  &contar peca capturada*/


   
/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

   /********** Fim do m�dulo de implementa��o: PFN Pe�as Finalizadas **********/