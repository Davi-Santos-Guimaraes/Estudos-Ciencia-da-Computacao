#include <stdio.h>
#include <stdlib.h>

/*==================================================
Função para ler dados do banco de dados dos alunos
=====================================================*/

/*==================================================
Estrutura para armazenar os dados dos alunos
=====================================================*/
struct Aluno
{
    int matricula;
    char nome[200];
    char turno[20];
    int periodo;
    char enfase[20];
    char curso[20];
};
