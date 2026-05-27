#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaArray.h"


/**********************************************************
 * Funções da Lista em Vetor
 **********************************************************/

/*=========================================================
    Função para mostrar dados da lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/

void mostrarDados(Tlista *lista) { 
    printf("\n--- Dados da Estrutura ---");
    printf("Tamanho: %d\n", lista->tamanho);
    printf("Ocupacao: %d\n", lista->ocupacao);
}
/*=========================================================
    Função para inicializar lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
    2- tamanho - quantidade de elementos que a lista comporta
  =========================================================*/
void inicializar(Tlista *const lista, int tamanho) {
    lista->tamanho = tamanho;
    lista->ocupacao = 0;
    lista->array = (int *)malloc(tamanho * sizeof(int));
}

/*=========================================================
    Função para mostrar elementos da lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrar(Tlista const * const lista) {
    printf("\nLista: {");
    if (listaEstaVazia(lista)) {
        printf("}\n");
    } else {
        for (int i = 0; i < lista->ocupacao; i++) {
            printf("%d", lista->array[i]);
            if (i < lista->ocupacao - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

/*=========================================================
    Função para liberar a memória alocada
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarLista(Tlista *const lista) {
    if (lista->array != NULL) {
        free(lista->array);
        lista->array = NULL;
    }
    lista->tamanho = 0;
    lista->ocupacao = 0;
}


/*=========================================================
    Função para verificar se a lista esta vazia
    Retorno: 1 (True) ou 0 (False)
  =========================================================*/
int listaEstaVazia(Tlista const * const lista) {
    return (lista->ocupacao == 0);
}

/*=========================================================
    Função para verificar se a lista esta cheia
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
int listaEstaCheia(Tlista const * const lista) {
    return (lista->ocupacao == lista->tamanho);
}

/*=========================================================
    Função para inserir elemento na lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- elemento - valor a ser inserido na lista
  =========================================================*/
int inserirFimLista(Tlista *const lista, int elemento) {
    if (listaEstaCheia(lista)) {
        printf("Lista esta cheia.");
        return 0; // Falha ao inserir, lista cheia
    }
    lista->array[lista->ocupacao] = elemento;
    lista->ocupacao++;
    return 1; 
}

/*=========================================================
    Função para acessar elemento no fim da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/

int acessarFimLista(Tlista const * const lista) {
    if (listaEstaVazia(lista)) {
        printf("Lista esta vazia.");
        return 0; //lista vazia
    }
    return lista->array[lista->ocupacao - 1];
}

/*=========================================================
    Função para remover elemento no fim da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void removerFimLista(Tlista *const lista) {
    if (listaEstaVazia(lista)) {
        printf("Lista esta vazia.");
        return; //lista vazia
    }
    lista->ocupacao--;
    return; // Elemento removido com sucesso
}

/*=========================================================
    Função para inserir no início da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- elemento - valor a ser inserido na lista
  =========================================================*/

  int inserirInicioLista(Tlista *const lista, int elemento) {
    if (listaEstaCheia(lista)) {
        printf("Lista esta cheia.");
        return 0; // Lista cheia
    }
    // Deslocar elementos para a direita
    for (int aux = lista->ocupacao; aux > 0; aux--) {
        lista->array[aux] = lista->array[aux - 1];
    }
    lista->array[0] = elemento;
    lista->ocupacao++;
    return 1;
}
    /*=========================================================
    Função para acessar no início da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
  int acessarInicioLista(Tlista const * const lista) {
    if (listaEstaVazia(lista)) {
        printf("Lista esta vazia.");
        return 0; // Lista vazia
    }
    return lista->array[0];
  }
    /*=========================================================
    Função para remover elemento no inicio da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void removerInicioLista(Tlista *const lista) {
    if (listaEstaVazia(lista)) {
        printf("Lista esta vazia.");
        return; // Lista vazia
    }
    // Deslocar elementos para a esquerda
    for (int aux = 0; aux < lista->ocupacao - 1; aux++) {
        lista->array[aux] = lista->array[aux + 1];
    }
    lista->ocupacao--;
    return; 
}

/*=========================================================
    Função para inserir em qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- posicao - índice onde o elemento será inserido
     3- elemento - valor a ser inserido na lista
  =========================================================*/

  void inserirPosicao (Tlista *const lista, int posicao, int elemento){
    if (listaEstaCheia(lista)) {
        printf("Lista esta cheia.");
        return; // Lista cheia
    }
    if (posicao < 0 || posicao > lista->ocupacao) {
        printf("Posicao invalida.");
        return; // Posição inválida
    }
    // Deslocar elementos para a direita
    for (int aux = lista->ocupacao; aux > posicao; aux--) {
        lista->array[aux] = lista->array[aux - 1];
    }
    lista->array[posicao] = elemento;
    lista->ocupacao++;
  }

  /*=========================================================
    Função para remover em qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- posicao - índice onde o elemento será removido
  =========================================================*/

  void removerPosicao (Tlista *const lista, int posicao){
    if (listaEstaVazia(lista)){
        printf("Lista esta vazia.");
        return; //lista vazia
    }
    if (posicao < 0 || posicao >= lista->ocupacao) {
        printf("Posicao invalida.");
        return; // Posição inválida
    }
    // Deslocar elementos para a esquerda
    for (; posicao < lista->ocupacao - 1; posicao++) {
        lista->array[posicao] = lista->array[posicao + 1];
    }   
    lista->ocupacao--;
    printf("Item removido");
  }
  /*=========================================================
    Função para acessar qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
  int acessarPosicao(Tlista const * const lista, int posicao) {
    if (listaEstaVazia(lista)) {
        printf("Lista esta vazia.");
        return 0; // Lista vazia
    }
    if (posicao < 0 || posicao >= lista->ocupacao) {
        printf("Posicao invalida.");
        return 0; // Posição inválida
    }
    return lista->array[posicao];
  }

  /* Funções da Prova*/

  
  /*=========================================================
    Função para remover qualquer elemento da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- Elemento - Valor a ser removido da lista
  =========================================================*/
  
  int removerElemento (Tlista *const lista, int elemento) {
    
    if(listaEstaVazia(lista)){
        printf("Lista esta vazia.");
        return 0; // Lista vazia
    }
    for (int i = 0; i < lista->ocupacao; i++){
        if (lista->array[i] == elemento){
            // Deslocar elementos para a esquerda
            for (; i < lista->ocupacao - 1; i++) {
                lista->array[i] = lista->array[i + 1];
            }   
            lista->ocupacao--;
            printf("Item removido");
            return 1; // Elemento removido com sucesso
        }
    }
    printf("Elemento nao encontrado.");
    return 0; // Elemento não encontrado

  }

     /*=========================================================
    Função para inserir um elemento de forma ordenada na lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- Elemento - Valor a ser inserido na lista
  =========================================================*/
  int inserirOrdenado (Tlista *const lista, int elemento){

    
    if (listaEstaCheia(lista)) {
        printf("Lista esta cheia.");
        return 0; // Lista cheia
    }
    int posicao = 0;
    while (posicao < lista->ocupacao && lista->array[posicao] < elemento) {
        posicao++;
    }
    // Deslocar elementos para a direita
    for (int aux = lista->ocupacao; aux > posicao; aux--) {
        lista->array[aux] = lista->array[aux - 1];
    }
    lista->array[posicao] = elemento;
    lista->ocupacao++;
    return 1; // Elemento inserido com sucesso


  }