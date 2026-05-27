#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

/*=========================================================
    Função que mostra os dados da struct de uma fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila){ // ok
  
    printf("\n--- Dados da Estrutura ---");
    printf("\nCapacidade: %d", fila->tamanho);
    printf("\nQtd Elementos: %d", fila->quantidadeDeElementos);
    printf("\nIndice Inicio: %d", fila->inicio);
    printf("\nIndice Fim: %d\n", fila->fim);

}

/*=========================================================
    Função que cria e inicializa uma fila
    Parametros: 
    1 - tamanho - define a quantidade de elementos que a fila contem
      2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila){
    fila->tamanho = tamanho;
    fila->quantidadeDeElementos = 0;
    fila->inicio = -1;
    fila->fim = -1;
    fila->array = (int*) malloc(tamanho * sizeof(int));
}

/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila *const fila){ // ok
    if (fila->array != NULL) {
        free(fila->array);
        fila->array = NULL;
    }
}

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  Retorno:
    != 0  - fila esta vazia
    0     - fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila){ // ok
    return (fila->quantidadeDeElementos == 0);
}

/*=========================================================
    Função que verifica se a fila esta cheia
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  Retorno:
    != 0  - fila esta cheia
    0     -  fila não esta cheia
  =========================================================*/
int filaEstaCheia(TFila const *const fila){ // ok
    return (fila->quantidadeDeElementos == fila->tamanho);
}

/*=========================================================
    Função para mostrar a fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  Retorno:
    ponteiro para a string com os dados da fila
  =========================================================*/
char* mostrarFila(TFila const *const fila){ // ok
    char *resultado = (char*) malloc(500 * sizeof(char));
    strcpy(resultado, "Fila: [ ");
  
    int pos = (fila->inicio + 1) % fila->tamanho;
    
    for (int i = 0; i < fila->quantidadeDeElementos; i++) {
        char temp[20];
        sprintf(temp, "%d ", fila->array[pos]);
        strcat(resultado, temp);
        
        pos = (pos + 1) % fila->tamanho;
    }
    
    strcat(resultado, "]");
    return resultado;
}

/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
    1 - elemento a ser incluido na fila
      2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila){ // ok
    if (filaEstaCheia(fila)) {
        printf("\nErro: Fila cheia!");
        return;
    }
    
    fila->fim = (fila->fim + 1) % fila->tamanho;
    fila->array[fila->fim] = elemento;
    fila->quantidadeDeElementos++;
}

/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila *const fila){
    if (filaEstaVazia(fila)) {
        printf("\nErro: Fila vazia!");
        return;
    }
    fila->inicio = (fila->inicio + 1) % fila->tamanho;
    
    fila->quantidadeDeElementos--;
}

/*=========================================================
    Função para acessar um elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  Retorno:
    elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila){
    if (filaEstaVazia(fila)) {
        return -1; 
    }
    int primeiro = (fila->inicio + 1) % fila->tamanho;
    return fila->array[primeiro];
}