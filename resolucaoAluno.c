//Codigo para resolução aluno
#include "resolucaoAluno.h"

TAluno* criarAluno(char* matricula, char* nome) {
    TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        return NULL;
    }
    strcpy(novo->matricula, matricula);
    strcpy(novo->nome, nome);
    return novo;
}

void processarImprimirFila(TFila *fila) {
    printf("\n%-15s | %-20s\n", "MATRICULA", "NOME");
    printf("------------------------------------------\n");

    while (!filaEstaVazia(fila)) {
        TAluno *aluno = acessarFila(fila); 

        if (aluno != NULL) {
            printf("%-15s | %-20s\n", aluno->matricula, aluno->nome);
            
            free(aluno);
        }

        removerFila(fila); 
    }
}