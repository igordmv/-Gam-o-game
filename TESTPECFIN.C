/***************************************************************************
*  $MCI Modulo de implementa��o: TPFN Teste pecas finalizadas
*
*  Arquivo gerado:              TESPFIN.c
*  Letras identificadoras:      TPFN
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		01	   idmv	  20/10		In�cio do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"PECFIN.H"


#define     CRIAR_PECASFINALIZADAS_CMD       "=criarpecas"
#define     DESTRUIR_PECASFINALIZADAS_CMD    "=destruirpecas"
#define     INSERIR_PECAFINALIZADA_CMD		  "=inserirpeca"
#define     CONTAR_PECAFINALIZADA_CMD		  "=contarpecas"

#define     MAX_PECAS 1
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TPFN &Testar pecas finalizadas
*
*  $ED Descri��o da fun��o
*     a fun�ao tem objetivo de testar o modulo PECCAP.C
*
*     Comandos dispon�veis:
*
*     =criarpecas			indice      condret		  
*     =destruirpecas		indice      condret         
*	  =inserirpeca   		indice		int		  condret
*	  =contarpecas			indice      int	      int	     condret
*
***********************************************************************/

static PFN_tppPecasFinalizadas pPecasFinalizadas[MAX_PECAS];
      

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  int indice,
		  numLidos = -1,
		  CondRetEsp = -1,
		  jogador,
		  finalizadas,
		  finalizadasEsperadas,
		  inxPeca = -1;
		  
	  PFN_tpCondRet CondRet ;
	  TST_tpCondRet Ret;
	     
	  /* testar criar estrutura de pecas finalizadas */

         if ( strcmp( ComandoTeste , CRIAR_PECASFINALIZADAS_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "ii",&inxPeca ,
                       &CondRetEsp) ;

            if  ( numLidos != 2 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PFN_CriarPecasFinalizadas(pPecasFinalizadas,inxPeca);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao criar estrutura de pecas finalizadas.");

         } /* Fim ativa: Testar criar estrutura de pecas finalizadas */

      /* Testar destruir estrutura de pecas finalizadas */

         else if ( strcmp( ComandoTeste , DESTRUIR_PECASFINALIZADAS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii",&inxPeca ,
                       &CondRetEsp) ;

            if (  numLidos != 2 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PFN_DestruirPecasFinalizadas(pPecasFinalizadas,inxPeca);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao destruir estrutura de pecas finalizadas.");

         } /* Fim ativa: Testar destruir estrutura de pecas finalizadas  */

	  /* Testar inserir peca na estrutura de pecas finalizadas*/

		 else if (strcmp(ComandoTeste, INSERIR_PECAFINALIZADA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",&inxPeca,
				  &jogador, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = PFN_InserirPecaFinalizada (pPecasFinalizadas[inxPeca],jogador);


			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao inserir peca na estrutura de pecas finalizadas.");

		 } /* Fim ativa: Testar inserir peca na estrutura de pecas finalizadas */

	  /* Testar retirar peca da estrutura de pecas finalizadas */

		 else if (strcmp(ComandoTeste, CONTAR_PECAFINALIZADA_CMD) == 0)
		 {	
			 
			 numLidos = LER_LerParametros("iiii",&inxPeca,
				 &jogador, &finalizadasEsperadas, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } /* if */

			 finalizadas = 0;
			 CondRet = PFN_ContarPecaFinalizada(pPecasFinalizadas[inxPeca],jogador, &finalizadas);

			 if(finalizadasEsperadas != finalizadas && CondRet == 0)
				 CondRet = PFN_CondRetQuantidadeErrada;

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao contar pecas da estrutura de pecas finalizadas.");

		 } /* Fim ativa: Testar retirar peca da estrutura de pecas finalizadas */

	 

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TPFN &Testar pecas finalizadas */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/********** Fim do m�dulo de implementa��o: TPFN Teste pecas finalizadas **********/