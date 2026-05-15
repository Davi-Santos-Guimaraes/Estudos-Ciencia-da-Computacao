//Codigo para resolução aluno
#include "resolucaoAluno.h"


/*=========================================================
    Função para alocar memória para um novo aluno
     Parametros:   
     1- matricula - string contendo a matrícula do aluno
     2- nome - string contendo o nome do aluno
     Retorno:
     1- Ponteiro para a nova struct TAluno alocada
  =========================================================*/
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

/*=========================================================
    Função para percorrer a fila e imprimir o nome dos alunos
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
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