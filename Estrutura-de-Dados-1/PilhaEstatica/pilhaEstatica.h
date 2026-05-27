#include<stdio.h>
#include<stdlib.h>
// Codigo de uma Pilha em Vetor
// Struct que representa a pilha
typedef struct{
	 int tamanho;
	 int topo;
	 int *array;
}TPilha;

/**********************************************************
 * Funções da Pilha em Vetor
 **********************************************************/

/*=========================================================
    Função que cria e inicializa a pilha usando vetor
    Parametros: 
    1 - tamanho - quantidade de elementos que a pilha comporta
    2 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void criarPilha(int tamanho, TPilha *const pilha);//ok

/*=========================================================
    Função que verifica se a pilha esta vazia
    Parametros:    
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: 1 - pilha esta vazia - 0 tem elementos não esta vazia
  =========================================================*/
int pilhaEstaVazia(TPilha const * const pilha);

/*=========================================================
    Função para mostrar os dados da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void dadosDaPilha(TPilha const * const pilha);

/*=========================================================
    Função que libera o espaco de memória usado pela pilha 
    Parametros:
    1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilha * const pilha);

/*=========================================================
    Função que verifica se a pilha esta cheia  
    Parametros:  
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: 1 - pilha esta cheia - 0 não esta cheia
  =========================================================*/
int pilhaEstaCheia(TPilha const * const pilha);

/*=========================================================
    Função para acessar elemento do topo da pilha   
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: -1 pilha esta vazia  - valor: elemento do topo da pilha
  =========================================================*/
int acessar(TPilha const * const pilha);

/*=========================================================
    Função para incluir um elemento no topo da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void empilhar(int elemento, TPilha * const pilha);

/*=========================================================
    Função para retirar um elemento no topo da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void desempilhar(TPilha * const pilha);

