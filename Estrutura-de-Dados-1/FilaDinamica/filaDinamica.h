#include <stdio.h>
#include <stdlib.h>

/* Definição da estrutura do nó */
typedef struct No{
    int dado;
    struct No* proximo;
}TNo;
/* Definição da estrutura da fila */
typedef struct Fila{
    int tamanho;
    TNo* inicio;
    TNo* fim;
}TFila;

// funções

/*=========================================================
    Função para inicializar a fila
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void inicializarFila(TFila *const fila);
  /*=========================================================
    Função para verificar se a fila está vazia
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
int filaEstaVazia(TFila const * const fila);

/*=========================================================
    Função para inserir um elemento
     Parametros:   
     1- elemento - valor a ser inserido
     2- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void inserirFila(TFila *const fila, int elemento);