#include <stdio.h>
#include <stdlib.h>
#include "listaLinearSE.h"

/*Funções da lista*/

/*=========================================================
   Função para inicializar a lista
   Parametros:
      1- Lista
=========================================================*/

void inicializarLista(Tllse *const lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

/*==========================================================
   Função para verificar se a lista está vazia.
   Parametros:
      1- Lista
   =========================================================*/

int ListaVazia(Tllse const * const lista){
    return(!lista->tamanho);
}

/*=========================================================
    Função para Criar e preencher um nó auxiliar
     Parametros:   
        1- Elemento a ser inserido no nó
     Retorno:
        1- Ponteiro para o novo nó criado
  =========================================================*/

TNo* criarNo(int elemento) {
    TNo *pAux = malloc(sizeof(TNo));
    if (pAux == NULL) {
        printf("\nErro: Memória Insuficiente!\n");
        return NULL;
    }
    pAux->dado = elemento;
    pAux->proximo = NULL;
    return pAux;
}

/*=========================================================
   Função para inserir no inicio da Lista
   Parametros:
      1- Lista
      2- Elemento
   =========================================================*/

void inserirIniciollse(Tllse *const lista, int elemento){

    TNo *pAux = criarNo(elemento);
    
    if(ListaVazia(lista)){
        lista->fim = lista->inicio = pAux;
    } else {
        pAux->proximo = lista->inicio;
        lista->inicio = pAux;
    }
    
    lista->tamanho++;
}

/*=========================================================
   Função para acessar inicio da Lista
   parametros:
      1-Lista
=========================================================*/

int acessarIniciollse(Tllse const * const lista){
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!");
        return 0;
    }
    return(lista -> inicio -> dado);
}

/*=========================================================
   Função para remover inicio da Lista
   parametros:
      1-Lista
=========================================================*/

void retirarIniciollse(Tllse * const lista){
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!");
        return;
    }

    TNo *pAux = lista -> inicio;
    lista->inicio = pAux->proximo;
    free(pAux);
    lista->tamanho --;
    if(ListaVazia(lista)){
        lista->fim = NULL;
    }
}

/*=========================================================
   Função para inserir no fim da Lista
   parametros:
      1-Lista
      2-Elemento
=========================================================*/

void inserirFimllse(Tllse *const lista, int elemento){

     TNo *pAux = criarNo(elemento);
     if(pAux == NULL){
        printf("\nNo nao criado");
        return;
     }
    if(ListaVazia(lista)){
        
        lista->fim = lista->inicio = pAux;
        lista->tamanho++;
        return;

    }
    lista->fim->proximo = pAux;
    lista->fim = pAux;
    lista->tamanho++;
    printf("\nElemento Inserido com sucesso!");
}

/*=========================================================
   Função para acessar fim da Lista
   parametros:
      1-Lista
=========================================================*/

int acessarFimllse(Tllse const * const lista){
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!");
        return 0;
    }
    return(lista -> fim -> dado);
}

/*=========================================================
   Função para remover fim da Lista
   parametros:
      1-Lista
=========================================================*/

 void retirarFimllse(Tllse *const lista){

    if(ListaVazia(lista)){
        printf("\nLista esta vazia!");
        return;
    }
    if(lista->tamanho == 1){
        free(lista->fim);
        lista->fim = lista->inicio = NULL;
        lista->tamanho = 0;
        return;
    }

    TNo *pAux = lista -> inicio;
    for(int i = 0 ; pAux->proximo != lista->fim ; i++){
        pAux = pAux->proximo;
    }
    free(lista->fim);
    pAux->proximo = NULL;
    lista->fim = pAux;
    lista->tamanho--;
}

/*=========================================================
   Função para mostrar os elementos da Lista
   Parametros:
      1- Lista
=========================================================*/

void mostrarLista(Tllse const * const lista){
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!\n");
        return;
    }

    TNo *pAux = lista->inicio;
    
    printf("\nElementos da lista: [ ");
    while(pAux != NULL){
        printf("%d ", pAux->dado);
        pAux = pAux->proximo;
    }
    printf("]\n");
}

/*=========================================================
   Função para inserir na posição na Lista
   parametros:
      1-Lista
      2-Elemento
      3-Posição 
=========================================================*/
void inserirPosicaollse(Tllse *const lista, int elemento, int posicao){
    if(posicao < 0 || posicao > lista->tamanho){
        printf("\nPosicao invalida!");
        return;
    }
    if(posicao == 0){
        inserirIniciollse(lista, elemento);
        return;
    }
    if(posicao == lista->tamanho){
        inserirFimllse(lista, elemento);
        return;
    }

    TNo *pAux = criarNo(elemento);
    if(pAux == NULL){
        printf("\nNo nao criado");
        return;
     }

    TNo *pAnterior = lista->inicio;
    for(int i = 0 ; i < posicao - 1 ; i++){
        pAnterior = pAnterior->proximo;
    }
    pAux->proximo = pAnterior->proximo;
    pAnterior->proximo = pAux;
    lista->tamanho++;
    printf("\nElemento Inserido com sucesso!");
}

/*=========================================================
   Função para acessar posição na Lista
   parametros:
      1-Lista
      2-Posição
=========================================================*/
int acessarPosicaollse(Tllse const * const lista, int posicao){
    if(posicao < 0 || posicao >= lista->tamanho){
        printf("\nPosicao invalida!");
        return 0;
    }
    TNo *pAux = lista->inicio;
    for(int i = 0 ; i < posicao ; i++){
        pAux = pAux->proximo;
    }
    return(pAux->dado);
}

/*=========================================================
   Função para remover posição na Lista
   parametros:
      1-Lista
      2-Posição
=========================================================*/
void retirarPosicaollse(Tllse *const lista, int posicao){
    if(posicao < 0 || posicao >= lista->tamanho){
        printf("\nPosicao invalida!");
        return;
    }
    if(posicao == 0){
        retirarIniciollse(lista);
        return;
    }
    if(posicao == lista->tamanho - 1){
        retirarFimllse(lista);
        return;
    }

    TNo *pAnterior = lista->inicio;
    for(int i = 0 ; i < posicao - 1 ; i++){
        pAnterior = pAnterior->proximo;
    }
    TNo *pAux = pAnterior->proximo;
    pAnterior->proximo = pAux->proximo;
    free(pAux);
    lista->tamanho--;
}