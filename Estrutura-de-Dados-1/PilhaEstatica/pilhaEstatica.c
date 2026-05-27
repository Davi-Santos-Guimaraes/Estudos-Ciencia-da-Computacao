#include<stdio.h>
#include<stdlib.h>
#include "pilhaEstatica.h"

/**********************************************************
 * Funções da Pilha em Vetor
 **********************************************************/

/*=========================================================
    Função que cria e inicializa a pilha usando vetor
    Parametros: 
    1 - tamanho - quantidade de elementos que a pilha comporta
    2 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void criarPilha(int tamanho, TPilha *const pilha){

  pilha->array = malloc(tamanho * sizeof(int));
  pilha->tamanho = tamanho;
  pilha->topo = -1;

}

/*=========================================================
    Função que verifica se a pilha esta vazia
    Parametros:    
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: 1 - pilha esta vazia - 0 tem elementos não esta vazia
  =========================================================*/
int pilhaEstaVazia(TPilha const * const pilha){

  if(pilha->topo == -1)
    return 1;
  else
    return 0;

}

/*=========================================================
    Função para mostrar os dados da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void dadosDaPilha(TPilha const * const pilha){

  prinf("\n******************\n");
  printf("DADOS DA PILHA\n");
  printf("Tamanho: %d\n", pilha->tamanho);
  printf("Topo: %d\n", pilha->topo);
  printf("array da pilha: %p\n", pilha->array);
  printf("Pilha: {");
if (pilhaEstaVazia(pilha)) printf("}\n");
else {
  for (int i = 0; i <= pilha->topo; i++) {
    printf("%d", pilha->array[i]);
    if (i < pilha->topo) printf(", ");
  }
  printf("}\n");
}
  printf("******************\n");
  if(pilhaEstaCheia){
    printf("Pilha esta cheia\n");
  } else {
    printf("Elemento do topo da pilha: %d\n", acessar(pilha));
  }

}
  
  
/*=========================================================
    Função que libera o espaco de memória usado pela pilha 
    Parametros:
    1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilha * const pilha){

  free(pilha->array);
  pilha->array = NULL;
  pilha->tamanho = 0;
  pilha->topo = -1;

}

/*=========================================================
    Função que verifica se a pilha esta cheia  
    Parametros:  
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: 1 - pilha esta cheia - 0 não esta cheia
  =========================================================*/
int pilhaEstaCheia(TPilha const * const pilha){

  if(pilha->topo == pilha->tamanho - 1)
    return 1;
  else
    return 0;

}

/*=========================================================
    Função para acessar elemento do topo da pilha   
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno: -1 pilha esta vazia  - valor: elemento do topo da pilha
  =========================================================*/
int acessar(TPilha const * const pilha){

  if(pilhaEstaVazia(pilha))
    return -1;
  else
    return pilha->array[pilha->topo];
    //return *(pilha->array+pilha->topo);

}

/*=========================================================
    Função para incluir um elemento no topo da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void empilhar(int elemento, TPilha * const pilha){

  if(pilhaEstaCheia(pilha)){
    printf("Pilha esta cheia, nao e possivel empilhar\n");
  } else {
    pilha->topo++;
    pilha->array[pilha->topo] = elemento;
  }

}

/*=========================================================
    Função para retirar um elemento no topo da pilha
    Parametros:
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void desempilhar(TPilha * const pilha){

  if(pilhaEstaVazia(pilha)){
    printf("Pilha esta vazia, nao e possivel desempilhar\n");
  } else {
    pilha->topo--;
  }

}