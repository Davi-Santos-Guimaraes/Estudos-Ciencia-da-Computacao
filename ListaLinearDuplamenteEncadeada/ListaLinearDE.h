#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
#include <stdio.h>
#include <stdlib.h>

/* Forward declaration para evitar dependência circular */
typedef struct Aluno Aluno;

/*Definição do nó*/
typedef struct No{
    struct No* anterior;
    Aluno* aluno;
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

TNo* criarNo(Aluno* aluno);

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

void inserirInicioLLDE(Tllde *const lista, Aluno* aluno);

/*=========================================================
   Função para acessar o primeiro elemento da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Primeiro elemento da lista
=========================================================*/

Aluno* acessarInicioLLDE(Tllde const * const lista);

/*=========================================================
   Função para apagar o primeiro elemento da Lista
   Parametros:
      1- Lista
   =========================================================*/
void retirarInicioLLDE(Tllde *const lista);


/*=========================================================
   Função para inserir no fim da Lista
   Parametros:
      1- Lista
      2- Elemento
=========================================================*/

void inserirFimLLDE(Tllde *const lista, Aluno* aluno);

/*=========================================================
   Função para acessar o ultimo elemento da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Ultimo elemento da lista
=========================================================*/
Aluno* acessarFimLLDE(Tllde const * const lista);

/*=========================================================
   Função para apagar o ultimo elemento da Lista
   Parametros:
      1- Lista
=========================================================*/

void retirarFimLLDE(Tllde *const lista);

/*=========================================================
   Função para inserir em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Elemento
      3- Posição
=========================================================*/

void inserirPosicaoLLDE(Tllde *const lista, Aluno* aluno, int posicao);

/*=========================================================
   Função para acessar um elemento em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Posição
   Retorno:
      1- Elemento na posição especificada
=========================================================*/

Aluno* acessarPosicaoLLDE(Tllde const * const lista, int posicao);

/*=========================================================
   Função para apagar um elemento em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Posição
=========================================================*/

void retirarPosicaoLLDE(Tllde *const lista, int posicao);



    









#endif