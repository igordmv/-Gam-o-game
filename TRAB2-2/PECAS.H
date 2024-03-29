#if ! defined ( PEC_ )
#define PEC_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo de Pe�a
*
*  Arquivo gerado:              PECAS.h
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo de Gam�o
*
*  Projeto: Disciplina INF 1301 / 1628 
*  Autores: gac - Gabriel de Araujo Carvalho
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     2.0	  gac	16/09/2015  finaliza��o do modulo 
*     1.0     gac   15/09/2015  inicio do modulo 
*
*  $ED Descri��o do m�dulo
*     Cria, dado um indice, uma Pe�a.
*     Destroi, dado um indice, uma pe�a.
*     Obtem, dado um indice, a cor da pe�a.
*
***************************************************************************/


/*****************IMPORTANTE*********************/
/*AS CORES DA PE�A S�O CLASSIFICADAS COMO:
*
*0 - BRANCA
*1 - PRETA
*
*/
/*****************IMPORTANTE*********************/


  
#if defined( PEC_OWN )
#define PEC_EXT
#else
   #define PEC_EXT extern
#endif
 


/* Tipo referencia para uma pe�a */

typedef struct tpPeca * tppPeca;


/***********************************************************************
*
*  $TC Tipo de dados: PEC condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     condi��es de retorno das fun��es da pe�a
*
***********************************************************************/
typedef enum {
PEC_CondRetOK= 0,

PEC_CondRetFaltaMemoria = 1, 

PEC_CondRetPECNaoExiste = 2,

PEC_CondRetPECJaExiste = 3,

PEC_CondRetCorNaoVale = 4,

} PEC_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: PEC &Criar PEC
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a de indice i dentro de um vetor
*
*  $EP Parametros
*  * p - vetor de pe�as
*  ind - indice da pe�a no vetor
*  cor - cor da pe�a
*
*  $FV Valor retornado
*     Se executou corretamente retorna CondretOk
*     Se ocorreu falta de memoria, retorna CondretFaltaMemoria
*     Se ja houver elemento criado no indice dado retorna CondRetPECJaExiste
*     Se a cor passada pelo parametro for diferente de 1 ou 0 CondRetCorNaoVale
*
***********************************************************************/

/* Assertivas de Entrada PEC_criaPEC 
*  Existir m�moria para criacao da pe�a
*  A pe�a nao pode existir para que seja criada (p[ind] = NULL)
*  O indice dado tem que estar entre 0 e 23
*  A cor dada (int) tem que ser 0 ou 1
*
*  Fim Assertiva de Entrada PEC_criaPEC */

PEC_tpCondRet PEC_criaPEC(tppPeca *p,int ind, int cor);

/* Assertivas de Saida PEC_criaPEC
*  A memoria referente a estrutura da peca tem que ser alocada
*  Para todo p[ind] criado, p[ind] != NULL
*  Para todo p[ind] criado, p[ind]->cor = 0 OU p[ind]->cor = 1
*  A funcao retornara um PEC_tpCondRet
*
*  Fim Assertiva de Saida PEC_criaPEC */

/***********************************************************************
*
*  $FC Fun��o: PEC  &Obtem Cor
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a, informa a sua cor
*
*  $EP Parametros
*   p - pe�a que procura saber a cor
*  * obtemcor - ponteiro passado para receber a cor
*
*  $FV Valor retornado
*     Se executou corretamente retorna CndretOk
*     Se o indice dado no vetor for NULL retorna CondRetPECNaoExiste
*
***********************************************************************/

/* Assertivas de Entrada PEC_Obtemcor
*  Existir uma pe�a ja criada (para todo p, p != NULL)
*  Deve existir uma cor valida na peca (para todo p, p->cor = 1 || p->cor = 0)
*
*  Fim Assertiva de Entrada PEC_Obtemcor */

PEC_tpCondRet PEC_Obtemcor(tppPeca p, int *obtemcor);

/*  Assertiva de Saida PEC_Obtemcor
*   O endereco de *obtemcor possui a cor da peca passada
*   A funcao retorna um PEC_tpCondRet
*
*   Fim Assertiva de Saida PEC_Obtemcor */

/***********************************************************************
*
*  $FC fun��o: PEC &Destruir pe�a
*
*  $ED Descri��o da fun��o
*     Destroi uma pe�a dada 
*
*  $EP Parametros
*  p - vetor de pecas
*  ind - indice da peca a ser destruida
*
*  $FV Valor retornado
*     Se executou corretamente retorna CondretOk
*     Se o indice dado no vetor for NULL retorna CondRetPECNaoExiste
*
***********************************************************************/


/* Assertivas de Entrada PEC_DestroiPEC
*  Existir uma pe�a ja criada (para todo p[ind], p[ind] != NULL)
*  O indice dado tem que ser entre 0 e 23
*
*  Fim Assertiva de Entrada PEC_DestroiPEC */

PEC_tpCondRet PEC_DestroiPEC(tppPeca * p, int ind);
 
/* Assertiva de Saida PEC_DestroiPEC
*  A peca deve ser destruida (para todo p[ind], p[ind] = NULL)
*  A memoria alocada para peca ( p[ind] ) deve ser liberada 
*  A funcao retorna um PEC_tpCondRet
*
*  Fim Assertiva de Saida PEC_DestroiPEC */
 
 
#undef PEC_EXT

/********** Fim do m�dulo de defini��o: PEC M�dulo Pe�as **********/
 
#else
#endif
