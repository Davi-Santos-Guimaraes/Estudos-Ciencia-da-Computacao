#include <stdio.h>
#include <stdlib.h>
#include "ListaLinearDE.h"

/*Funções da lista*/

/*=========================================================
   Função para inicializar a lista
   Parametros:
      1- Lista
=========================================================*/

void inicializarLista(Tllde *const lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

/*==========================================================
   Função para verificar se a lista está vazia.
   Parametros:
      1- Lista
   =========================================================*/

int ListaVazia(Tllde const * const lista){
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
    pAux->anterior = NULL;
    return pAux;
}

/*=========================================================
   Função para mostrar Lista escolhendo qual direção seguir
   Parametros:
      1- Lista
      2- Direção (0 para início->fim, 1 para fim->inicio)
   =========================================================*/

void mostrarLista(Tllde const * const lista, int direcao){
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!\n");
        return;
    }

    TNo *pAux;
    if(direcao == 0){
        pAux = lista->inicio;
        printf("\nElementos da lista (inicio para fim): [ ");
    } else {
        pAux = lista->fim;
        printf("\nElementos da lista (fim para inicio): [ ");
    }

    while(pAux != NULL){
        printf("%d ", pAux->dado);
        if(direcao == 0){
            pAux = pAux->proximo;
        } else {
            pAux = pAux->anterior;
        }
    }
    printf("]\n");
}

/*=========================================================
   Função para inserir no inicio da Lista
   Parametros:
      1- Lista
      2- Elemento
   =========================================================*/

   void inserirInicioLLDE(Tllde *const lista, int elemento){
    //Criar no -> Paux
    TNo *pAux = criarNo(elemento);
    //Verificar se no foi criado
    if(pAux == NULL){
        printf("\nNo nao criado");
        return;
    }
    //iniciarNo(lista,valor)

    if(ListaVazia(lista)){
        lista->fim = lista->inicio = pAux;
        lista->tamanho++;
        return;
    } else {
        pAux->proximo = lista->inicio;
        lista->inicio->anterior = pAux;
        lista->inicio = pAux;
        lista->tamanho++;
    }
    return;
}

/*=========================================================
   Função para acessar o primeiro elemento da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Primeiro elemento da lista
   =========================================================*/

   int acessarInicioLLDE(Tllde const * const lista) {
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return -1;
    }
    return lista->inicio->dado;
}
/*=========================================================
   Função para apagar o primeiro elemento da Lista
   Parametros:
      1- Lista
   =========================================================*/
void retirarInicioLLDE(Tllde *const lista){
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return;
    }
    else if(lista->tamanho == 1){
        free(lista->inicio);
        inicializarLista(lista);
        return;
    }
    else{
        TNo *paux = lista->inicio;
        lista->inicio=paux->proximo;
        paux->proximo->anterior = NULL;
        free(paux);
        lista->tamanho--;
        return;
    }
    
}

/*=========================================================
   Função para inserir no fim da Lista
   Parametros:
      1- Lista
      2- Elemento
=========================================================*/

void inserirFimLLDE(Tllde *const lista, int elemento){
    //Criar no -> Paux
    TNo *pAux = criarNo(elemento);
    //Verificar se no foi criado
    if(pAux == NULL){
        printf("\nNo nao criado");
        return;
    }
    //iniciarNo(lista,valor)

    if(ListaVazia(lista)){
        lista->fim = lista->inicio = pAux;
        lista->tamanho++;
        return;
    } else {
        pAux->anterior = lista->fim;
        lista->fim->proximo = pAux;
        lista->fim = pAux;
        lista->tamanho++;
    }
    return;

}

/*=========================================================
   Função para acessar o ultimo elemento da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Ultimo elemento da lista
=========================================================*/
int acessarFimLLDE(Tllde const * const lista) {
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return -1;
    }
    return lista->fim->dado;
}

/*=========================================================
   Função para apagar o ultimo elemento da Lista
   Parametros:
      1- Lista
=========================================================*/

void retirarFimLLDE(Tllde *const lista){
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return;
    }
    else if(lista->tamanho == 1){
        free(lista->fim);
        inicializarLista(lista);
        return;
    }
    else{
        TNo *paux = lista->fim;
        lista->fim=paux->anterior;
        paux->anterior->proximo = NULL;
        free(paux);
        lista->tamanho--;
        return;
    }
    
}

/*=========================================================
   Função para inserir em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Elemento
      3- Posição
=========================================================*/

void inserirPosicaoLLDE(Tllde *const lista, int elemento, int posicao){
    if(posicao < 0 || posicao > lista->tamanho){
        printf("\nPosicao Invalida!\n");
        return;
    }
    else if(posicao == 0){
        inserirInicioLLDE(lista, elemento);
        return;
    }
    else if(posicao == lista->tamanho){
        inserirFimLLDE(lista, elemento);
        return;
    }
    else{
        TNo *pAux = criarNo(elemento);
        if(pAux == NULL){
            printf("\nNo nao criado");
            return;
        }
        TNo *pAux2 = lista->inicio;
        for(int i = 0; i < posicao - 1; i++){
            pAux2 = pAux2->proximo;
        }
        pAux->proximo = pAux2->proximo;
        pAux->anterior = pAux2;
        pAux2->proximo->anterior = pAux;
        pAux2->proximo = pAux;
        lista->tamanho++;
        return;
    }
}

/*=========================================================
   Função para acessar um elemento em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Posição
   Retorno:
      1- Elemento na posição especificada
=========================================================*/

int acessarPosicaoLLDE(Tllde const * const lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("\nPosicao Invalida!\n");
        return -1;
    }
    TNo *pAux = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        pAux = pAux->proximo;
    }
    return pAux->dado;
}

/*=========================================================
   Função para apagar um elemento em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Posição
=========================================================*/

void retirarPosicaoLLDE(Tllde *const lista, int posicao){
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("\nPosicao Invalida!\n");
        return;
    }
    else if(posicao == 0){
        retirarInicioLLDE(lista);
        return;
    }
    else if(posicao == lista->tamanho - 1){
        retirarFimLLDE(lista);
        return;
    }
    else{
        TNo *pAux = lista->inicio;
        for(int i = 0; i < posicao; i++){
            pAux = pAux->proximo;
        }
        pAux->anterior->proximo = pAux->proximo;
        pAux->proximo->anterior = pAux->anterior;
        free(pAux);
        lista->tamanho--;
        return;
    }
}