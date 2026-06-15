#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LerDados.h"
#include "ListaLinearDE.h"

/*==================================================
Função para ler dados do banco de dados dos alunos
Parametros:
    1- Lista onde os dados serão armazenados
    2- Nome do arquivo csv a ser lido
=====================================================*/
void carregarDados(Tllde *lista, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    char linha[500]; 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        
        Aluno *novoAluno = (Aluno*) malloc(sizeof(Aluno));
        if (novoAluno == NULL) {
            printf("\nErro: Memoria insuficiente para carregar aluno!\n");
            continue;
        }
        /*==================================================================================================
             Separando as partes do arquivo csv usando strtok, usando ";" como delimitador
        ===================================================================================================*/

        // Matrícula
        char *token = strtok(linha, ";");
        if(token) novoAluno->matricula = atoi(token);

        // Nome
        token = strtok(NULL, ";");
        if(token) strcpy(novoAluno->nome, token);

        // Turno
        token = strtok(NULL, ";");
        if(token) strcpy(novoAluno->turno, token);

        // Período
        token = strtok(NULL, ";");
        if(token) novoAluno->periodo = atoi(token);

        // Ênfase
        token = strtok(NULL, ";");
        if(token) strcpy(novoAluno->enfase, token);

        // Curso
        token = strtok(NULL, "\r\n"); 
        if(token) strcpy(novoAluno->curso, token);

        inserirFimLLDE(lista, novoAluno); 
    }

    fclose(arquivo);
    printf("\n>>> Carga concluida! Total de %d alunos carregados na lista. <<<\n", lista->tamanho);
}