/***************************************************************************
*  $MCI M�dulo de implementa��o: TDADO Teste  dados
*
*  Arquivo gerado:              TESTDADOS.c
*  Letras identificadoras:      TDADO
*
*  Nome da base de software:   Jogo de Gamao
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es 
*      1.0     idmv   15/09/2015     Codificacao e finalizacao
*	
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    <stdlib.h>
#include    "DADOS.h"
#include    "TST_Espc.h"

#include    "GENERICO.H"

#include    "LERPARM.H"


/***********************************************************************
*
*  $FC Fun��o: TDADO &Testar dado
*
*  $ED Descri��o da fun��o
*     Testar as funcoes do Modulo DADOS
*
*     Comandos dispon�veis:
*       
*     =criardado                    inxDado    CondRetEsp
*     =destruirdado                 inxDado    CondRetEsp
*     =gerarvalor                   inxDado    CondRetEsp
*
***********************************************************************/

static const char CRIAR_DADO_CMD          [ ] = "=criardado"     ;
static const char DESTRUIR_DADO_CMD       [ ] = "=destruirdado"  ;
static const char GERAR_VALOR_CMD         [ ] = "=gerarvalor"    ;

#define MAX_DADOS 1

/**********************************************************************
* 
*         Vetor de dados
*
***********************************************************************/
 DADO_tppDado  vtDados[MAX_DADOS];


/***********************************************************************/


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	   
      int inxDado  = -1 ;
      int numLidos   = -1 ;
      int CondRetEsp = -1  ;
	  int CondRetObtido = -1;  
      int ValEsp = -1 ;
      int numElem = -1 ;
	  
      /* Testar Criar Matriz */

          if ( strcmp( ComandoTeste , CRIAR_DADO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxDado ,&CondRetEsp) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            } 
            CondRetObtido = DADO_CriaDado( vtDados,inxDado) ;
            
            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");
            

         } /* fim ativa: Testar Criar Matriz */

      /* Testar Destruir matriz */

         else if ( strcmp( ComandoTeste , DESTRUIR_DADO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxDado, &CondRetEsp) ;

            if ( numLidos != 2 )
            {
               return TST_CondRetParm ;
            } 

            CondRetObtido = DADO_DestroiDado( vtDados[inxDado] ) ;
            vtDados[inxDado] = NULL;

            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");


         } /* fim ativa: Testar Destruir lista */

      /* Testar inserir elemento oeste */

         else if ( strcmp( ComandoTeste , GERAR_VALOR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &inxDado, &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = DADO_GeraValorDado( vtDados[inxDado] ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao inserir direita." ) ;

         } /* fim ativa: Testar inserir elemento oeste */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TDADO &Testar DADO */

/********** Fim do m�dulo de implementa��o: TDADO Teste do Modulo DADOS **********/

