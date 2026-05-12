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
    Função para Criar e preencher um nó auxiliar
     Parametros:   
     1- Elemento a ser inserido no nó
     Retorno:
     1- Ponteiro para o novo nó criado
  =========================================================*/
TNo* criarNo(TAluno* elemento) {
    TNo *pAux = malloc(sizeof(TNo));
    if (pAux == NULL) {
        printf("Erro: Memória Insuficiente!\n");
        return NULL;
    }
    pAux->dado = elemento;
    pAux->proximo = NULL;
    return pAux;
}
/*=========================================================
    Função para inserir um elemento
     Parametros:   
     1- elemento - valor a ser inserido
     2- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void inserirFila(TFila *const fila, TAluno* elemento){

   TNo *pAux = criarNo(elemento);
    if(filaEstaVazia(fila)){
        
        fila->fim = fila->inicio = pAux;
        fila->tamanho++;
        return;

    }
    fila->fim->proximo = pAux;
    fila->fim = pAux;
    fila->tamanho++;
    printf("Elemento Inserido com sucesso!");
}
/*=========================================================
    Função para Acessar um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  
  TAluno* acessarFila(TFila const * const fila){
    if(filaEstaVazia(fila)){
        printf("Fila Vazia\n");
        return NULL;
    }
    return(fila -> inicio -> dado);
  }


/*=========================================================
    Função para remover um elemento
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
  void removerFila(TFila *const fila){
    if(filaEstaVazia(fila)){
        printf("fila Vazia\n");
    } else {
        TNo *pAux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(pAux);
        fila->tamanho--;
        printf("Elemento Removido com sucesso!");
    }
    if(filaEstaVazia(fila))fila->fim = NULL;

  }