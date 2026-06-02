#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
#include <stdio.h>
#include <stdlib.h>

/*Definição do nó*/
typedef struct No{
    struct No* anterior;
    int dado;
    struct No* proximo;
}TNo;

/*Estrutura da Lista*/

typedef struct llde{
    int tamanho;
    TNo* inicio;
    TNo* fim;
}Tllde;

/*Funções da lista*/

/*=========================================================
   Função para inicializar a lista
   Parametros:
      1- Lista
=========================================================*/

void inicializarLista(Tllde *const lista);

/*==========================================================
   Função para verificar se a lista está vazia.
   Parametros:
      1- Lista
   =========================================================*/

int ListaVazia(Tllde const * const lista);

/*=========================================================
    Função para Criar e preencher um nó auxiliar
     Parametros:   
        1- Elemento a ser inserido no nó
     Retorno:
        1- Ponteiro para o novo nó criado
  =========================================================*/

TNo* criarNo(int elemento);

/*=========================================================
   Função para mostrar Lista escolhendo qual direção seguir
   Parametros:
      1- Lista
      2- Direção (0 para início, 1 para fim)
   =========================================================*/

void mostrarLista(Tllde const * const lista, int direcao);

/*=========================================================
   Função para inserir no inicio da Lista
   Parametros:
      1- Lista
      2- Elemento
   =========================================================*/

void inserirInicioLLDE(Tllde *const lista, int elemento);

/*=========================================================
   Função para acessar o primeiro elemento da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Primeiro elemento da lista
=========================================================*/

int acessarInicioLLDE(Tllde const * const lista);

/*=========================================================
   Função para apagar o primeiro elemento da Lista
   Parametros:
      1- Lista
   =========================================================*/
void retirarInicioLLDE(Tllde *const lista);


#endif