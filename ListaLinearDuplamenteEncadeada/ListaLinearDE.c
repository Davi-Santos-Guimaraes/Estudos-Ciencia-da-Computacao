#include <stdio.h>
#include <stdlib.h>
#include "ListaLinearDE.h"
#include "LerDados.h"

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
        1- aluno a ser inserido no nó
     Retorno:
        1- Ponteiro para o novo nó criado
  =========================================================*/

TNo* criarNo(Aluno* aluno) {
    TNo *pAux = malloc(sizeof(TNo));
    if (pAux == NULL) {
        printf("\nErro: Memória Insuficiente!\n");
        return NULL;
    }
    pAux->aluno = aluno;
    pAux->proximo = NULL;
    pAux->anterior = NULL;
    return pAux;
}

/*=========================================================
   Função para mostrar Lista de forma paginada (30 em 30)
   Parametros:
      1- Lista
      2- Direção (0 para início->fim, 1 para fim->inicio)
   =========================================================*/
void mostrarLista(Tllde const * const lista, int direcao) {
    if(ListaVazia(lista)){
        printf("\nLista esta vazia!\n");
        return;
    }

    TNo *pAux;
    if(direcao == 0){
        pAux = lista->inicio;
        printf("\n=== Listagem de Alunos (Inicio para Fim) ===\n");
    } else {
        pAux = lista->fim;
        printf("\n=== Listagem de Alunos (Fim para Inicio) ===\n");
    }
    
    int contador = 0;
    while(pAux != NULL){
        // Cria um ponteiro auxiliar menor apenas para facilitar a escrita
        Aluno *a = pAux->aluno;
        
        // Formatação alinhada em colunas
        printf("%-4d | %-35s | %-10s | P:%-2d | %-10s | %s\n", 
               a->matricula, 
               a->nome, 
               a->turno, 
               a->periodo, 
               a->enfase, 
               a->curso);
        
        contador++;
        // Verifica se atingiu 30 elementos para pausar
        if (contador % 30 == 0) {
            printf("\n--- Mostrando %d de %d elementos ---\n", contador, lista->tamanho);
            printf("Pressione ENTER para continuar ou digite 's' e ENTER para sair da listagem: ");
            
            char opcao = getchar();
            if (opcao == 's' || opcao == 'S') {
                while(getchar() != '\n'); // Limpa o buffer do teclado
                break; // Sai do loop (cancela a listagem)
            }
        }

        // Avança na direção escolhida
        if(direcao == 0){
            pAux = pAux->proximo;
        } else {
            pAux = pAux->anterior;
        }
    }
    printf("=============================================\n\n");
}

/*=========================================================
   Função para inserir no inicio da Lista
   Parametros:
      1- Lista
      2- aluno
   =========================================================*/

   void inserirInicioLLDE(Tllde *const lista, Aluno* aluno){
    //Criar no -> Paux
    TNo *pAux = criarNo(aluno);
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
   Função para acessar o primeiro aluno da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Primeiro aluno da lista
   =========================================================*/

   Aluno* acessarInicioLLDE(Tllde const * const lista) {
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return NULL;
    }
    return lista->inicio->aluno;
}
/*=========================================================
   Função para apagar o primeiro aluno da Lista
   Parametros:
      1- Lista
   =========================================================*/
void retirarInicioLLDE(Tllde *const lista){
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return;
    }
    else if(lista->tamanho == 1){
        if(lista->inicio->aluno != NULL) {
            free(lista->inicio->aluno); // Libera a struct Aluno primeiro
        }
        free(lista->inicio); // Libera o nó da lista
        inicializarLista(lista);
        return;
    }
    else{
        TNo *paux = lista->inicio;
        lista->inicio = paux->proximo;
        paux->proximo->anterior = NULL;
        
        if(paux->aluno != NULL) {
            free(paux->aluno); // Libera a struct Aluno primeiro
        }
        free(paux); // Libera o nó
        lista->tamanho--;
        return;
    }
}


/*==================================================================================================================*/


/*=========================================================
   Função para inserir no fim da Lista
   Parametros:
      1- Lista
      2- aluno
=========================================================*/

void inserirFimLLDE(Tllde *const lista, Aluno* aluno){
    //Criar no -> Paux
    TNo *pAux = criarNo(aluno);
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
   Função para acessar o ultimo aluno da Lista
   Parametros:
      1- Lista
   Retorno:
      1- Ultimo aluno da lista
=========================================================*/
Aluno* acessarFimLLDE(Tllde const * const lista) {
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return NULL;
    }
    return lista->fim->aluno;
}

/*=========================================================
   Função para apagar o ultimo aluno da Lista
   Parametros:
      1- Lista
=========================================================*/

void retirarFimLLDE(Tllde *const lista){
    if (ListaVazia(lista)) {
        printf("\nLista esta vazia!\n");
        return;
    }
    else if(lista->tamanho == 1){
        if(lista->fim->aluno != NULL) {
            free(lista->fim->aluno);
        }
        free(lista->fim);
        inicializarLista(lista);
        return;
    }
    else{
        TNo *paux = lista->fim;
        lista->fim = paux->anterior;
        paux->anterior->proximo = NULL;
        
        if(paux->aluno != NULL) {
            free(paux->aluno);
        }
        free(paux);
        lista->tamanho--;
        return;
    }
}

/*=========================================================
   Função para inserir em uma posição específica da Lista
   Parametros:
      1- Lista
      2- aluno
      3- Posição
=========================================================*/

void inserirPosicaoLLDE(Tllde *const lista, Aluno* aluno, int posicao){
    if(posicao < 0 || posicao > lista->tamanho){
        printf("\nPosicao Invalida!\n");
        return;
    }
    else if(posicao == 0){
        inserirInicioLLDE(lista, aluno);
        return;
    }
    else if(posicao == lista->tamanho){
        inserirFimLLDE(lista, aluno);
        return;
    }
    else{
        TNo *pAux = criarNo(aluno);
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
   Função para acessar um aluno em uma posição específica da Lista
   Parametros:
      1- Lista
      2- Posição
   Retorno:
      1- aluno na posição especificada
=========================================================*/

Aluno* acessarPosicaoLLDE(Tllde const * const lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("\nPosicao Invalida!\n");
        return NULL;
    }
    TNo *pAux = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        pAux = pAux->proximo;
    }
    return pAux->aluno;
}

/*=========================================================
   Função para apagar um aluno em uma posição específica da Lista
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
        
        if(pAux->aluno != NULL) {
            free(pAux->aluno); // Evita deixar o registro do aluno orfão na RAM
        }
        free(pAux);
        lista->tamanho--;
        return;
    }
}