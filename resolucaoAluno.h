#ifndef RESOLUCAO_ALUNO_H
#define RESOLUCAO_ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"

// Estrutura para armazenar os dados do aluno
typedef struct {
    char matricula[20];
    char nome[100];
} TAluno;

// Aloca memória e preenche um novo aluno
TAluno* criarAluno(char* matricula, char* nome);

// Percorre a fila, imprime cada aluno e limpa a memória
void processarImprimirFila(TFila *fila);

#endif