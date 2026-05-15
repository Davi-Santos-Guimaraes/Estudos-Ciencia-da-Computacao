#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TAluno TAluno;

/* Definição da estrutura do nó */
typedef struct No{
    TAluno *dado;
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
    Função para Criar e preencher um nó auxiliar
     Parametros:   
     1- Elemento a ser inserido no nó
     Retorno:
     1- Ponteiro para o novo nó criado
  =========================================================*/
TNo* criarNo(TAluno* elemento);

/*=========================================================
    Função para inserir um elemento
     Parametros:   
     1- elemento - valor a ser inserido
     2- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void inserirFila(TFila *const fila, TAluno* elemento);

  /*=========================================================
    Função para Acessar um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  TAluno* acessarFila(TFila const * const fila);

  /*=========================================================
    Função para remover um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void removerFila(TFila *const fila);

  #endif