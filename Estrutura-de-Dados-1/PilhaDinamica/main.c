#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhaDinamica.h"


int main() {
    int n;
    srand(time(NULL));//comentário engraçado

    printf("--- Ordenacao com Pilha Dinamica ---\n");
    printf("Digite o tamanho do vetor (ou -1 para sair): ");
    scanf("%d", &n);

    while(n >= 0) {
        // Alocação dinâmica baseada no tamanho informado
        int *vetorOriginal = (int *)malloc(n * sizeof(int));
        int *vetorOrdenado = (int *)malloc(n * sizeof(int));

        if (vetorOriginal == NULL || vetorOrdenado == NULL) {
            printf("Erro ao alocar memoria.\n");
            break;
        }

        // Gerando elementos aleatórios entre 0 e 50
        for (int i = 0; i < n; i++) {
            vetorOriginal[i] = rand() % 51;
            vetorOrdenado[i] = vetorOriginal[i];
        }

        // Chamada da função de ordenação
        ordenarComPilha(vetorOrdenado, n);

        // Exibição dos resultados
        printf("\nVetor Original: { ");
        for (int i = 0; i < n; i++) printf("%d ", vetorOriginal[i]);
        printf("}");

        printf("\nVetor Ordenado: { ");
        for (int i = 0; i < n; i++) printf("%d ", vetorOrdenado[i]);
        printf("}\n");

        // Liberação de memória
        free(vetorOriginal);
        free(vetorOrdenado);

        printf("\n------------------------------------");
        printf("\nDigite o tamanho do proximo vetor (-1 para sair): ");
        scanf("%d", &n);
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}