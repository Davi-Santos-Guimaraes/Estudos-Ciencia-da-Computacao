#include "pilhaDinamica.h"
/**********************************************************
 * Funções da Pilha Dinâmica
 **********************************************************/
void inicializarPilha(TPilhaDinamica *const pilha) {
    pilha->topo = NULL;
    pilha->quantidade = 0;
}
/*=========================================================
    Função para verificar se a pilha esta vazia
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     Retorno: 1 (True) ou 0 (False)
  =========================================================*/
int pilhaEstaVazia(TPilhaDinamica const * const pilha) {
    return (pilha->topo == NULL);
}
/*=========================================================
    Função para empilhar um elemento
     Parametros:   
     1- elemento - valor a ser empilhado
     2- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void empilhar(int elemento, TPilhaDinamica *const pilha) {
    // Aloca memória apenas para UM novo nó
    TNo *novoNo = (TNo*) malloc(sizeof(TNo));
    if (novoNo == NULL) return; // Erro de memória

    novoNo->dado = elemento;
    // O novo nó aponta para quem era o antigo topo
    novoNo->proximo = pilha->topo;
    // A pilha agora diz que o topo é este novo nó
    pilha->topo = novoNo;
    pilha->quantidade++;
}
/*=========================================================
    Função para desempilhar um elemento
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     Retorno: valor do elemento desempilhado ou 0 se a pilha estiver vazia
  =========================================================*/
int desempilhar(TPilhaDinamica *const pilha) {
    if (pilhaEstaVazia(pilha)) return 0;

    TNo *aux = pilha->topo; // Guarda o endereço do topo para apagar depois
    pilha->topo = aux->proximo; // O topo passa a ser o próximo elemento
    free(aux); // Libera a memória do nó removido
    pilha->quantidade--;
    return 1;
}
/*=========================================================
    Função para acessar o elemento no topo da pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
     2- valor - ponteiro para armazenar o valor do elemento no topo
     Retorno: 1 (True) se o acesso for bem-sucedido ou 0 (False) se a pilha estiver vazia
  =========================================================*/
int acessarTopo(TPilhaDinamica const * const pilha, int *valor) {
    if (pilhaEstaVazia(pilha)) return 0;
    *valor = pilha->topo->dado; // Recupera o dado via ponteiro
    return 1;
}
/*=========================================================
    Função para mostrar os elementos da pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void mostrarPilha(TPilhaDinamica const * const pilha) {
    printf("\nPilha Dinamica (Qtd: %d): ", pilha->quantidade);
    TNo *aux = pilha->topo;
    printf("Topo -> [ ");
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    }
    printf("]");
}
/*=========================================================
    Função para liberar a memória alocada pela pilha
     Parametros:   
     1- pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilhaDinamica *const pilha) {
    while (!pilhaEstaVazia(pilha)) {
        desempilhar(pilha);
    }
}
/*=========================================================
    Função para ordenar um vetor usando pilhas
     Parametros:   
     1- vetor - ponteiro para o vetor a ser ordenado
     2- tamanho - quantidade de elementos no vetor
  =========================================================*/
void ordenarComPilha(int *vetor, int tamanho) {
    TPilhaDinamica principal, auxiliar;
    inicializarPilha(&principal);
    inicializarPilha(&auxiliar);

    for (int i = 0; i < tamanho; i++) {
        int temp = vetor[i];
        int topoPrincipal;

        while (!pilhaEstaVazia(&principal) && acessarTopo(&principal, &topoPrincipal) && topoPrincipal > temp) {
            empilhar(topoPrincipal, &auxiliar);
            desempilhar(&principal);
        }

        empilhar(temp, &principal);

        // Devolve os elementos da auxiliar para a principal
        while (!pilhaEstaVazia(&auxiliar)) {
            int valorAux;
            acessarTopo(&auxiliar, &valorAux);
            empilhar(valorAux, &principal);
            desempilhar(&auxiliar);
        }
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        acessarTopo(&principal, &vetor[i]);
        desempilhar(&principal);
    }
}