#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó da Pilha
typedef struct No {
    int dado;
    struct No *proximo;
} TNo;

// Estrutura da Pilha Dinâmica
typedef struct {
    TNo *topo;
    int quantidade;
} TPilhaDinamica;

// Funções

/*=========================================================
    Função para inicializar a pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void inicializarPilha(TPilhaDinamica *const pilha);
/*=========================================================
    Função para verificar se a pilha esta vazia
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     Retorno: 1 (True) ou 0 (False)
  =========================================================*/
int pilhaEstaVazia(TPilhaDinamica const * const pilha);
/*=========================================================
    Função para empilhar um elemento
     Parametros:   
     1- elemento - valor a ser empilhado
     2- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void empilhar(int elemento, TPilhaDinamica *const pilha);
/*=========================================================
    Função para desempilhar um elemento
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     Retorno: valor do elemento desempilhado ou 0 se a pilha estiver vazia
  =========================================================*/
int desempilhar(TPilhaDinamica *const pilha);
/*=========================================================
    Função para acessar o elemento no topo da pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     2- valor - ponteiro para armazenar o valor do elemento no topo
     Retorno: 1 (True) se o acesso for bem-sucedido ou 0 (False) se a pilha estiver vazia
  =========================================================*/
int acessarTopo(TPilhaDinamica const * const pilha, int *valor);
/*=========================================================
    Função para liberar a memória alocada pela pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilhaDinamica *const pilha);
/*=========================================================
    Função para mostrar os elementos da pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void mostrarPilha(TPilhaDinamica const * const pilha);

/*=========================================================
    Função para ordenar um vetor usando pilhas
     Parametros:   
     1- vetor - ponteiro para o vetor a ser ordenado
     2- tamanho - quantidade de elementos no vetor
  =========================================================*/
void ordenarComPilha(int *vetor, int tamanho);

#endif