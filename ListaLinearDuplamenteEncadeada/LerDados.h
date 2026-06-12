#ifndef LERDADOS_H
#define LERDADOS_H

#include <stdio.h>
#include <stdlib.h>
#include "ListaLinearDE.h"

/*==================================================
Estrutura para armazenar os dados dos alunos
=====================================================*/
typedef struct Aluno {
    int matricula;
    char nome[200];
    char turno[30];
    int periodo;
    char enfase[50];
    char curso[50];
} Aluno;

/*==================================================
Função para ler dados do banco de dados dos alunos
==================================================*/
void carregarDados(Tllde *lista, const char *nomeArquivo);

#endif