#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//codigo de uma lista
//struct que representa a lista 
typedef struct {
    int tamanho;
    int ocupacao;
    int *array;
} Tlista;

/*=========================================================
    Função para mostrar dados da lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrarDados(Tlista *lista);

/*=========================================================
    Função para inicializar lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
    2- tamanho - quantidade de elementos que a lista comporta
  =========================================================*/
void inicializar(Tlista *const lista, int tamanho);

/*=========================================================
    Função para mostrar elementos da lista
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrar(Tlista const * const lista);

/*=========================================================
    Função para liberar a memória alocada
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarLista(Tlista *const lista);

/*=========================================================
    Função para verificar se a lista esta vazia
    Retorno: 1 (True) ou 0 (False)
  =========================================================*/
int listaEstaVazia(Tlista const * const lista);

/*=========================================================
    Função para verificar se a lista esta cheia
    Parametros: 
    1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
int listaEstaCheia(Tlista const * const lista);

/*=========================================================
    Função para inserir elemento na lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- elemento - valor a ser inserido na lista
  =========================================================*/
int inserirFimLista(Tlista *const lista, int elemento);

/*=========================================================
    Função para acessar elemento no fim da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- elemento - ponteiro onde o valor encontrado será guardado
  =========================================================*/

int acessarFimLista(Tlista const * const lista);

/*=========================================================
    Função para remover elemento no fim da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void removerFimLista(Tlista *const lista);
/*=========================================================
    Função para inserir no início da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- elemento - valor a ser inserido na lista
  =========================================================*/

  int inserirInicioLista(Tlista *const lista, int elemento);

  /*=========================================================
    Função para acessar no início da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
  int acessarInicioLista(Tlista const * const lista);

  /*=========================================================
    Função para remover elemento no inicio da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void removerInicioLista(Tlista *const lista);

/*=========================================================
    Função para inserir em qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- posicao - índice onde o elemento será inserido
     3- elemento - valor a ser inserido na lista
  =========================================================*/

  void inserirPosicao (Tlista *const lista, int posicao, int elemento);

  /*=========================================================
    Função para remover em qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- posicao - índice onde o elemento será removido
  =========================================================*/

  void removerPosicao (Tlista *const lista, int posicao);

   /*=========================================================
    Função para acessar qualquer posição da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
  =========================================================*/
  int acessarPosicao(Tlista const * const lista, int posicao);

  /*=========================================================
    Função para remover qualquer elemento da lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- Elemento - Valor a ser removido da lista
  =========================================================*/
  
  int removerElemento (Tlista *const lista, int elemento);

   /*=========================================================
    Função para inserir um elemento de forma ordenada na lista
     Parametros:   
     1- lista - ponteiro para a struct com os dados da lista
     2- Elemento - Valor a ser inserido na lista
  =========================================================*/
  int inserirOrdenado (Tlista *const lista, int elemento);