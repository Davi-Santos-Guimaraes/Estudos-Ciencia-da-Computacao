#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
#include <stdio.h>
#include <stdlib.h>

/*Definição do nó*/
typedef struct No{
    int dado;
    struct No* proximo;
}TNo;

/*Estrutura da Lista*/

typedef struct llse{
    int tamanho;
    TNo* inicio;
    TNo* fim;
}Tllse;

/*Funções da lista*/

/*=========================================================
   Função para inicializar a lista
   Parametros:
      1- Lista
=========================================================*/
void inicializarLista(Tllse *const lista);

/*==========================================================
   Função para verificar se a lista está vazia.
   Parametros:
      1- Lista
   =========================================================*/
int ListaVazia(Tllse const * const lista);

/*=========================================================
    Função para Criar e preencher um nó auxiliar
     Parametros:   
        1- Elemento a ser inserido no nó
     Retorno:
        1- Ponteiro para o novo nó criado
  =========================================================*/
TNo* criarNo(int elemento);

/*=========================================================
   Função para inserir no inicio da Lista
   Parametros:
      1- Lista
      2- Elemento
   =========================================================*/

void inserirIniciollse(Tllse *const lista, int elemento);

/*=========================================================
   Função para acessar inicio da Lista
   parametros:
      1-Lista
=========================================================*/

int acessarIniciollse(Tllse const * const lista);

/*=========================================================
   Função para remover inicio da Lista
   parametros:
      1-Lista
=========================================================*/
void retirarIniciollse(Tllse * const lista);

/*=========================================================
   Função para inserir no fim da Lista
   parametros:
      1-Lista
      2-Elemento
=========================================================*/

void inserirFimllse(Tllse *const lista, int elemento);

/*=========================================================
   Função para acessar fim da Lista
   parametros:
      1-Lista
=========================================================*/

int acessarFimllse(Tllse const * const lista);

/*=========================================================
   Função para remover fim da Lista
   parametros:
      1-Lista
=========================================================*/

void retirarFimllse(Tllse *const lista);

/*=========================================================
   Função para mostrar os elementos da Lista
   Parametros:
      1- Lista
=========================================================*/

void mostrarLista(Tllse const * const lista);


#endif