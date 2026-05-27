#include "filaDinamica.h"
/**********************************************************
 * Funções da Fila Dinâmica
 **********************************************************/

 /*=========================================================
    Função para inicializar a fila
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void inicializarFila(TFila *const fila) {
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

/*=========================================================
    Função para verificar se a fila está vazia
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
int filaEstaVazia(TFila const * const fila) {
    return (fila->tamanho == 0);
}
/*=========================================================
    Função para inserir um elemento
     Parametros:   
     1- elemento - valor a ser inserido
     2- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void inserirFila(TFila *const fila, int elemento){
    TNo *pAux= malloc(sizeof(TNo));
    if(filaEstaVazia(fila)){
        fila->inicio = pAux;
        fila->fim = pAux;
        
    }
    fila->tamanho++;
  }
/*=========================================================
    Função para Acessar um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/

  int acessarFila(TFila *const fila){


  }


/*=========================================================
    Função para remover um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void removerFila(TFila *const fila){


  }