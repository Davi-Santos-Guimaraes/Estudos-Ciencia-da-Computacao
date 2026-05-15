#ifndef RESOLUCAO_ALUNO_H
#define RESOLUCAO_ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*=========================================================
    Estrutura para armazenar os dados do aluno
  =========================================================*/
struct TAluno {
    char matricula[30];
    char nome[200];
};

typedef struct TAluno TAluno;

#include "filaDinamica.h"

// funções

/*=========================================================
    Função para alocar memória para um novo aluno
     Parametros:   
     1- matricula - string contendo a matrícula do aluno
     2- nome - string contendo o nome do aluno
     Retorno:
     1- Ponteiro para a nova struct TAluno alocada
  =========================================================*/
TAluno* criarAluno(char* matricula, char* nome);

/*=========================================================
    Função para percorrer a fila e imprimir o nome dos alunos
     Parametros:   
     1- fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void processarImprimirFila(TFila *fila);

#endif