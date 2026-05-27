#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct que representa a Fila
typedef struct{
	int tamanho;
	int quantidadeDeElementos;
	int inicio;
	int fim;
	int *array;
} TFila;

/*=========================================================
    Função que mostra os dados da struct de uma fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila);

/*=========================================================
    Função que cria e inicializaa uma fila
    Parametros: 
		1 - tamanho - define a quantidade de elementos que a fila contem
    	2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila);

/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila *const fila);

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		!= 0 	- fila esta vazia
		0 		- fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila);

/*=========================================================
    Função que verifica se a fila esta cheia
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		!= 0 	- fila esta cheia
		0 		-  fila não esta cheia
  =========================================================*/
int filaEstaCheia(TFila const *const fila);

/*=========================================================
    Função para mostrar a fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		ponteiro para a string com os dados da fila
  =========================================================*/
char* mostrarFila(TFila const *const fila);

/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
		1 - elemento a ser incluido na fila
    	2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila);

/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila *const fila);

/*=========================================================
    Função para acessar um elemento da fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila);
