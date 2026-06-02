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